# MEX Partition

## Problem
[Link to Codeforces problem](https://codeforces.com/problemset/problem/XXXX/XXXX)

## Solution Approach

### Algorithm
Finds the Minimum Excluded (MEX) value - the smallest non-negative integer not present in the array.

### Key Insights
- MEX is the smallest non-negative integer not in the array
- Use a boolean array to track which numbers exist
- Scan from 0 to find the first missing number

### Implementation Details
- Uses a boolean array `exist[101]` to mark present numbers
- Scans from 0 to 102 to find the first missing number
- If all numbers 0-100 exist, MEX is 101

### Time Complexity
O(n + 102) where n is array size

### Space Complexity
O(102) = O(1)

## Code
See `MEX_Partition.cpp` for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
