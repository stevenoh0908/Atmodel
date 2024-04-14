/*
numerical_diff.c

* Created on 14 Apr 2024
* Created by Yooshin Oh (stevenoh0908@snu.ac.kr)

- Utility Functions for Numerical Differencing
*/

#include <stdlib.h>
#include "numerical_diff.h"

void diff_forward_euler(float* dest, float* array, size_t length, float delta) {
	for (int i = 1; i < length; i++) {
		dest[i] = (array[i]-array[i-1])/delta;
	}
	// fill the first-element which can't be calculated from the array itself, put 0.
	dest[0] = 0;
	return;
}

void diff_backward_euler(float* dest, float* array, size_t length, float delta) {
	for (int i = 0; i < length-1; i++) {
		dest[i] = (array[i+1]-array[i])/delta;
	}
	// fill the last-element which can't be calculated from the array itself, put 0.
	dest[length-1] = 0;
	return;
}

void diff_trapezoidal(float* dest, float* array, size_t length, float delta) {
	for (int i = 1; i < length-1; i++) {
		dest[i] = (array[i+1]-array[i-1])/delta;
	}
	// fill the first-element and the last-element which can't be calculated from the array itself, put 0.
	dest[0] = 0;
	dest[length-1] = 0;
}

void diff(float* dest, float* array, size_t length, float delta) {
	// Use Trapezoidal for centers
	for (int i = 1; i < length-1; i++) {
		dest[i] = (array[i+1]-array[i-1])/delta;
	}
	// fill the first-element with backward-euler
	dest[0] = (array[1]-array[0])/delta;
	// fill the last-element wich forward-euler
	dest[length-1] = (array[length-1]-array[length-2])/delta;
	return;
}
