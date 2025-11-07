# Merge Sort

## Problem Description
This file implements the classic Merge Sort algorithm, a highly efficient, comparison-based sorting algorithm. It follows the divide-and-conquer paradigm, recursively dividing the array into halves, sorting them, and then merging the sorted halves.

## Solution Approach

### Algorithm
Merge Sort is a divide-and-conquer sorting algorithm that recursively divides the array into halves, sorts them, and merges the sorted halves.

### Key Insights
- Divide: Recursively split the array into two halves until each subarray has one element
- Conquer: Merge the sorted subarrays back together
- Stable sort: Maintains relative order of equal elements

### Implementation Details
- Recursively divides array into halves
- Merges two sorted subarrays by comparing elements
- Uses temporary arrays during merging

### Time Complexity
O(n log n) in all cases

### Space Complexity
O(n) for temporary arrays

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
