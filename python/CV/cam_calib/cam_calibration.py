#!/usr/bin/env python3
import numpy as np
import cv2
import glob
import os
import pickle

def calibrate_camera(chessboard_size=None):
    """
    Calibrate the camera using a chessboard pattern.
    Captures multiple images of a chessboard from different angles.

    Args:
        chessboard_size: Tuple (width, height) of inner corners in the chessboard.
                         If None, will use default (9, 6) or prompt user.
    """
    # Chessboard dimensions (number of inner corners)
    if chessboard_size is None:
        # Ask user to confirm or change the chessboard size
        print("Default chessboard size is (9, 6) inner corners.")
        change_size = input("Do you want to use a different size? (y/n): ")
        if change_size.lower() == 'y':
            try:
                width = int(input("Enter number of inner corners width: "))
                height = int(input("Enter number of inner corners height: "))
                CHESSBOARD_SIZE = (width, height)
                print(f"Using chessboard size: {CHESSBOARD_SIZE}")
            except ValueError:
                print("Invalid input. Using default size (9, 6).")
                CHESSBOARD_SIZE = (9, 6)
        else:
            CHESSBOARD_SIZE = (9, 6)
    else:
        CHESSBOARD_SIZE = chessboard_size

    print(f"Looking for a chessboard with {CHESSBOARD_SIZE[0]}x{CHESSBOARD_SIZE[1]} inner corners")

    # Termination criteria for corner detection
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

    # Prepare object points (0,0,0), (1,0,0), (2,0,0) ... (8,5,0)
    objp = np.zeros((CHESSBOARD_SIZE[0] * CHESSBOARD_SIZE[1], 3), np.float32)
    objp[:, :2] = np.mgrid[0:CHESSBOARD_SIZE[0], 0:CHESSBOARD_SIZE[1]].T.reshape(-1, 2)

    # Arrays to store object points and image points
    objpoints = []  # 3D points in real world space
    imgpoints = []  # 2D points in image plane

    # Create directory to save calibration images if it doesn't exist
    if not os.path.exists('calibration_images'):
        os.makedirs('calibration_images')

    # Initialize webcam
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error: Could not open webcam.")
        return None, None

    img_count = 0
    max_images = 20  # Number of calibration images to capture
    frame_count = 0  # Counter for frame processing

    print("\n=== CHESSBOARD DETECTION TIPS ===")
    print("1. Ensure good, even lighting on the chessboard")
    print("2. Hold the chessboard flat and completely visible in the frame")
    print("3. Try different angles and distances")
    print("4. Avoid reflections and shadows on the chessboard")
    print("5. Make sure all corners are visible in the frame")
    print("\nPress '1' to capture a chessboard image (need", max_images, "images)")
    print("Press 'q' to quit")

    while img_count < max_images:
        ret, frame = cap.read()
        if not ret:
            print("Failed to grab frame")
            break

        # Process frames at a reduced rate for better performance
        frame_count += 1

        # Only process every 3rd frame for detection
        if frame_count % 3 == 0:
            # Try to detect chessboard in real-time for feedback
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            flags = cv2.CALIB_CB_FAST_CHECK  # Use fast check for real-time feedback
            ret, corners = cv2.findChessboardCorners(gray, CHESSBOARD_SIZE, flags)

            # Create a copy of the frame for display
            display_frame = frame.copy()

            # Add status text to the frame
            status_text = "CHESSBOARD NOT DETECTED"
            color = (0, 0, 255)  # Red

            if ret:
                # Draw the corners (simplified for speed)
                cv2.drawChessboardCorners(display_frame, CHESSBOARD_SIZE, corners, ret)
                status_text = "CHESSBOARD DETECTED - Press '1' to capture"
                color = (0, 255, 0)  # Green

            # Add text with background for better visibility
            cv2.rectangle(display_frame, (0, 0), (display_frame.shape[1], 30), (0, 0, 0), -1)
            cv2.putText(display_frame, status_text, (10, 20),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
        else:
            # Just show the frame without detection for better performance
            display_frame = frame.copy()
            cv2.rectangle(display_frame, (0, 0), (display_frame.shape[1], 30), (0, 0, 0), -1)
            cv2.putText(display_frame, "PREVIEW MODE", (10, 20),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

        # Display the frame with feedback (use a smaller window size for better performance)
        display_frame_small = cv2.resize(display_frame, (0, 0), fx=0.75, fy=0.75)
        cv2.imshow('Calibration', display_frame_small)

        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break
        elif key == ord('1'):
            # Convert to grayscale
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

            # Apply preprocessing to improve contrast (but don't display)
            # Try adaptive thresholding if normal detection fails
            gray_processed = cv2.adaptiveThreshold(
                gray,
                255,
                cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                cv2.THRESH_BINARY,
                11,
                2
            )

            # Find chessboard corners with improved flags
            flags = cv2.CALIB_CB_ADAPTIVE_THRESH + cv2.CALIB_CB_NORMALIZE_IMAGE + cv2.CALIB_CB_FAST_CHECK
            ret, corners = cv2.findChessboardCorners(gray, CHESSBOARD_SIZE, flags)

            # If detection fails, try with the processed image
            if not ret:
                print("Standard detection failed, trying with processed image...")
                ret, corners = cv2.findChessboardCorners(gray_processed, CHESSBOARD_SIZE, flags)
                if ret:
                    print("Detection successful with processed image!")

            if ret:
                # Refine corner positions
                corners2 = cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)

                # Save the image
                img_name = f'calibration_images/chessboard_{img_count}.jpg'
                cv2.imwrite(img_name, frame)
                print(f"Captured {img_name}")

                # Add to our calibration data
                objpoints.append(objp)
                imgpoints.append(corners2)

                img_count += 1

    cap.release()
    cv2.destroyAllWindows()

    if img_count == 0:
        print("No calibration images captured.")
        return None, None

    print(f"Calibrating camera with {img_count} images...")

    # Calibrate camera
    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(
        objpoints, imgpoints, gray.shape[::-1], None, None
    )

    if ret:
        # Calculate reprojection error
        mean_error = 0
        for i in range(len(objpoints)):
            imgpoints2, _ = cv2.projectPoints(objpoints[i], rvecs[i], tvecs[i], mtx, dist)
            error = cv2.norm(imgpoints[i], imgpoints2, cv2.NORM_L2) / len(imgpoints2)
            mean_error += error

        print(f"Calibration complete! Mean reprojection error: {mean_error/len(objpoints)}")

        # Save calibration parameters
        calibration_data = {
            'camera_matrix': mtx,
            'dist_coeffs': dist
        }

        with open('calibration_data.pkl', 'wb') as f:
            pickle.dump(calibration_data, f)

        print("Calibration data saved to 'calibration_data.pkl'")

        return mtx, dist
    else:
        print("Calibration failed.")
        return None, None

def load_calibration_data():
    """Load camera calibration data from file."""
    try:
        with open('calibration_data.pkl', 'rb') as f:
            data = pickle.load(f)
        return data['camera_matrix'], data['dist_coeffs']
    except FileNotFoundError:
        print("Calibration data not found. Run calibration first.")
        return None, None

if __name__ == "__main__":
    print("\n=== CAMERA CALIBRATION TOOL ===")
    print("This tool will help you calibrate your camera using a chessboard pattern.")

    # Check if calibration data already exists
    if os.path.exists('calibration_data.pkl'):
        print("\nCalibration data already exists.")
        choice = input("Do you want to recalibrate? (y/n): ")
        if choice.lower() != 'y':
            mtx, dist = load_calibration_data()
            print("Loaded existing calibration data.")
            exit()

    print("\n=== CHESSBOARD INFORMATION ===")
    print("By default, this program looks for a standard chessboard with 9x6 inner corners.")
    print("Inner corners are the points where four squares meet (not the outer edges).")
    print("If your chessboard has a different size, you can specify it when prompted.")

    # Ask if user wants to use a custom chessboard size
    custom_size = input("\nDo you want to specify a custom chessboard size? (y/n): ")
    if custom_size.lower() == 'y':
        try:
            width = int(input("Enter number of inner corners width: "))
            height = int(input("Enter number of inner corners height: "))
            chessboard_size = (width, height)
        except ValueError:
            print("Invalid input. Using default size (9, 6).")
            chessboard_size = (9, 6)
    else:
        chessboard_size = (9, 6)

    # Run calibration with the specified or default chessboard size
    mtx, dist = calibrate_camera(chessboard_size)