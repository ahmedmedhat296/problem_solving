# Monocarp's String

## Problem
[Link to Codeforces problem](https://codeforces.com/problemset/problem/XXXX/XXXX)

## Solution Approach

### Algorithm
Finds the minimum length substring to remove so that remaining string has equal number of 'a' and 'b' characters.

### Key Insights
- Counts total 'a' and 'b' in the string
- If counts are equal, no removal needed (answer = 0)
- If only one type exists, impossible (answer = -1)
- Uses prefix sum with 'a' = +1, 'b' = -1
- Finds minimum substring where prefix_sum[i] - prefix_sum[j] == diff

### Implementation Details
- Counts 'a' and 'b' characters
- Calculates difference diff = cnta - cntb
- Builds prefix sum array with 'a' = 1, 'b' = -1
- Uses map to track prefix sum positions
- For each position, looks for needed = prefix_sum[i] - diff
- Finds minimum length substring that achieves the needed difference

### Time Complexity
O(n) where n is string length

### Space Complexity
O(n) for prefix sum and map

## Code
See `Monocarp's_String.cpp` for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
