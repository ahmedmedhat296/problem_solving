# Maximum Subarray (Divide and Conquer)

## Problem Description
This file implements an efficient solution to the maximum subarray problem using the divide-and-conquer approach. It finds the contiguous subarray within a one-dimensional array of numbers that has the largest sum. The code also includes functionality to time the execution.

## Solution Approach

### Algorithm
Finds the contiguous subarray with maximum sum using divide-and-conquer approach.

### Key Insights
- Divide array into two halves
- Maximum subarray is either in left half, right half, or crosses the middle
- For crossing subarray, find maximum sum ending at middle from left, and starting at middle from right

### Implementation Details
- Recursively divides array
- Finds maximum subarray in left and right halves
- Finds maximum crossing subarray
- Returns maximum of the three

### Time Complexity
O(n log n)

### Space Complexity
O(log n) for recursion stack

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
