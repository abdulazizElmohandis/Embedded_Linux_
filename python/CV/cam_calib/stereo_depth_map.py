#!/usr/bin/env python3
import numpy as np
import cv2
import os
import pickle
import time

def load_calibration_data():
    """Load camera calibration data from file."""
    try:
        with open('calibration_data.pkl', 'rb') as f:
            data = pickle.load(f)
        return data['camera_matrix'], data['dist_coeffs']
    except FileNotFoundError:
        print("Calibration data not found. Run calibration first.")
        return None, None

def capture_stereo_images():
    """
    Capture two images with a slight horizontal displacement to simulate stereo vision.
    """
    # Load camera calibration data
    camera_matrix, dist_coeffs = load_calibration_data()
    if camera_matrix is None or dist_coeffs is None:
        print("Please run camera calibration first.")
        return None, None
    
    # Initialize webcam
    cap = cv2.VideoCapture(0)
    
    if not cap.isOpened():
        print("Error: Could not open webcam.")
        return None, None
    
    # Create directory to save stereo images if it doesn't exist
    if not os.path.exists('stereo_images'):
        os.makedirs('stereo_images')
    
    # Capture first image
    print("Position your camera for the LEFT image and press '1' to capture")
    print("Press 'q' to quit")
    
    left_img = None
    right_img = None
    
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Failed to grab frame")
            break
        
        # Undistort the frame using calibration data
        undistorted = cv2.undistort(frame, camera_matrix, dist_coeffs)
        
        # Display the frame
        cv2.imshow('Capture Stereo Images', undistorted)
        
        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break
        elif key == ord('1') and left_img is None:
            left_img = undistorted.copy()
            cv2.imwrite('stereo_images/left.jpg', left_img)
            print("Left image captured. Move the camera slightly to the right.")
            print("Press '1' again to capture the RIGHT image")
        elif key == ord('1') and left_img is not None:
            right_img = undistorted.copy()
            cv2.imwrite('stereo_images/right.jpg', right_img)
            print("Right image captured.")
            break
    
    cap.release()
    cv2.destroyAllWindows()
    
    if left_img is None or right_img is None:
        print("Failed to capture stereo images.")
        return None, None
    
    return left_img, right_img

def compute_depth_map(left_img, right_img):
    """
    Compute depth map from stereo images using Semi-Global Block Matching.
    """
    # Convert images to grayscale
    left_gray = cv2.cvtColor(left_img, cv2.COLOR_BGR2GRAY)
    right_gray = cv2.cvtColor(right_img, cv2.COLOR_BGR2GRAY)
    
    # Create stereo matcher
    # Using Semi-Global Block Matching for better results
    stereo = cv2.StereoSGBM_create(
        minDisparity=0,
        numDisparities=16*10,  # must be divisible by 16
        blockSize=5,
        P1=8 * 3 * 5**2,  # Control disparity smoothness
        P2=32 * 3 * 5**2,  # Control disparity smoothness
        disp12MaxDiff=1,
        uniquenessRatio=15,
        speckleWindowSize=100,
        speckleRange=32
    )
    
    # Compute disparity map
    disparity = stereo.compute(left_gray, right_gray)
    
    # Normalize disparity map for better visualization
    disparity_normalized = cv2.normalize(disparity, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_8U)
    
    # Apply colormap for better visualization
    disparity_color = cv2.applyColorMap(disparity_normalized, cv2.COLORMAP_JET)
    
    return disparity_normalized, disparity_color

def main():
    """Main function to run the stereo depth mapping process."""
    # Check if calibration data exists
    if not os.path.exists('calibration_data.pkl'):
        print("Camera calibration data not found.")
        print("Please run camera_calibration.py first.")
        return
    
    # Capture stereo images or load existing ones
    if os.path.exists('stereo_images/left.jpg') and os.path.exists('stereo_images/right.jpg'):
        print("Found existing stereo images.")
        choice = input("Do you want to capture new stereo images? (y/n): ")
        if choice.lower() == 'y':
            left_img, right_img = capture_stereo_images()
        else:
            left_img = cv2.imread('stereo_images/left.jpg')
            right_img = cv2.imread('stereo_images/right.jpg')
    else:
        left_img, right_img = capture_stereo_images()
    
    if left_img is None or right_img is None:
        return
    
    # Compute depth map
    print("Computing depth map...")
    disparity_map, disparity_color = compute_depth_map(left_img, right_img)
    
    # Save results
    cv2.imwrite('stereo_images/disparity_map.jpg', disparity_map)
    cv2.imwrite('stereo_images/disparity_color.jpg', disparity_color)
    
    # Display results
    cv2.imshow('Left Image', left_img)
    cv2.imshow('Right Image', right_img)
    cv2.imshow('Disparity Map (Grayscale)', disparity_map)
    cv2.imshow('Disparity Map (Color)', disparity_color)
    
    print("Press any key to exit")
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
