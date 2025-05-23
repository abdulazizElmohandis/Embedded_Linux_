#!/usr/bin/env python3
"""
Simple Stereo Vision Project
----------------------------
This script provides a simple interface to:
1. Calibrate your camera using a chessboard pattern
2. Capture stereo images using your laptop's webcam
3. Generate a depth map from the stereo images

Usage:
    python simple_stereo_vision.py
"""

import os
import cv2
import numpy as np
from cam_calibration import calibrate_camera, load_calibration_data
from stereo_depth_map import capture_stereo_images, compute_depth_map

def print_header(title):
    """Print a formatted header."""
    print("\n" + "=" * 50)
    print(f" {title} ".center(50, "="))
    print("=" * 50 + "\n")

def main_menu():
    """Display the main menu and handle user input."""
    while True:
        print_header("SIMPLE STEREO VISION")
        print("1. Camera Calibration")
        print("2. Capture Stereo Images")
        print("3. Generate Depth Map")
        print("4. Run Complete Pipeline")
        print("5. Exit")
        
        choice = input("\nEnter your choice (1-5): ")
        
        if choice == '1':
            print_header("CAMERA CALIBRATION")
            print("You'll need a chessboard pattern for calibration.")
            print("Hold the chessboard in front of the camera at different angles.")
            print("Press '1' to capture an image when the chessboard is detected.")
            input("Press Enter to continue...")
            calibrate_camera()
        
        elif choice == '2':
            print_header("CAPTURE STEREO IMAGES")
            if not os.path.exists('calibration_data.pkl'):
                print("Camera calibration data not found.")
                print("Please run camera calibration first (Option 1).")
                input("Press Enter to continue...")
                continue
            
            print("You'll capture two images with a slight horizontal displacement.")
            print("This simulates stereo vision using a single camera.")
            input("Press Enter to continue...")
            capture_stereo_images()
        
        elif choice == '3':
            print_header("GENERATE DEPTH MAP")
            if not os.path.exists('calibration_data.pkl'):
                print("Camera calibration data not found.")
                print("Please run camera calibration first (Option 1).")
                input("Press Enter to continue...")
                continue
            
            if not (os.path.exists('stereo_images/left.jpg') and os.path.exists('stereo_images/right.jpg')):
                print("Stereo images not found.")
                print("Please capture stereo images first (Option 2).")
                input("Press Enter to continue...")
                continue
            
            print("Generating depth map from stereo images...")
            left_img = cv2.imread('stereo_images/left.jpg')
            right_img = cv2.imread('stereo_images/right.jpg')
            
            disparity_map, disparity_color = compute_depth_map(left_img, right_img)
            
            # Save results
            if not os.path.exists('stereo_images'):
                os.makedirs('stereo_images')
            cv2.imwrite('stereo_images/disparity_map.jpg', disparity_map)
            cv2.imwrite('stereo_images/disparity_color.jpg', disparity_color)
            
            # Display results
            cv2.imshow('Left Image', left_img)
            cv2.imshow('Right Image', right_img)
            cv2.imshow('Disparity Map (Grayscale)', disparity_map)
            cv2.imshow('Disparity Map (Color)', disparity_color)
            
            print("Results saved to 'stereo_images' directory.")
            print("Press any key in the image windows to continue...")
            cv2.waitKey(0)
            cv2.destroyAllWindows()
        
        elif choice == '4':
            print_header("COMPLETE STEREO VISION PIPELINE")
            print("This will run the complete pipeline:")
            print("1. Camera Calibration (if needed)")
            print("2. Capture Stereo Images")
            print("3. Generate Depth Map")
            input("Press Enter to continue...")
            
            # Check if calibration is needed
            if not os.path.exists('calibration_data.pkl'):
                print_header("STEP 1: CAMERA CALIBRATION")
                print("You'll need a chessboard pattern for calibration.")
                print("Hold the chessboard in front of the camera at different angles.")
                print("Press '1' to capture an image when the chessboard is detected.")
                input("Press Enter to continue...")
                calibrate_camera()
            else:
                print("Camera calibration data found. Skipping calibration step.")
            
            # Capture stereo images
            print_header("STEP 2: CAPTURE STEREO IMAGES")
            print("You'll capture two images with a slight horizontal displacement.")
            print("This simulates stereo vision using a single camera.")
            input("Press Enter to continue...")
            left_img, right_img = capture_stereo_images()
            
            if left_img is None or right_img is None:
                print("Failed to capture stereo images. Aborting pipeline.")
                input("Press Enter to continue...")
                continue
            
            # Generate depth map
            print_header("STEP 3: GENERATE DEPTH MAP")
            print("Generating depth map from stereo images...")
            
            disparity_map, disparity_color = compute_depth_map(left_img, right_img)
            
            # Save results
            if not os.path.exists('stereo_images'):
                os.makedirs('stereo_images')
            cv2.imwrite('stereo_images/disparity_map.jpg', disparity_map)
            cv2.imwrite('stereo_images/disparity_color.jpg', disparity_color)
            
            # Display results
            cv2.imshow('Left Image', left_img)
            cv2.imshow('Right Image', right_img)
            cv2.imshow('Disparity Map (Grayscale)', disparity_map)
            cv2.imshow('Disparity Map (Color)', disparity_color)
            
            print("Pipeline complete! Results saved to 'stereo_images' directory.")
            print("Press any key in the image windows to continue...")
            cv2.waitKey(0)
            cv2.destroyAllWindows()
        
        elif choice == '5':
            print("Exiting program. Goodbye!")
            break
        
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")
            input("Press Enter to continue...")

if __name__ == "__main__":
    main_menu()
