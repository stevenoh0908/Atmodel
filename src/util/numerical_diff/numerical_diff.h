/*
numerical_diff.h

* Created on 14 Apr 2024
* Created by Yooshin Oh (stevenoh0908@snu.ac.kr)

- Utility Functions for Numerical Differencing
*/

typedef enum DiffMode {
	DIFFMODE_FORWARD_EULER = 0,
	DIFFMODE_BACKWARD_EULER,
	DIFFMODE_TRAPEZOIDAL
} DiffMode;

// Forward-euler calculation for whole array
void diff_forward_euler(float* dest, float* array, size_t length, float delta);

// Backward-euler calculation for whole array
void diff_backward_euler(float* dest, float* array, size_t length, float delta);

// Trapezoidal calculation for whole array
void diff_trapezoidal(float* dest, float* array, size_t length, float delta);

// Whole differential calculation (use trapezoidal, but backward-euler for first-elem, forward-euler for last-elem)
void diff(float* dest, float* array, size_t length, float delta);
