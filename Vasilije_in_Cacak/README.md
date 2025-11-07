# Vasilije in Cacak

## Problem
[Link to Codeforces problem](https://codeforces.com/problemset/problem/XXXX/XXXX)

## Solution Approach

### Algorithm
Checks if a value x can be expressed as the sum of k distinct integers from 1 to n.

### Key Insights
- Minimum sum of k distinct integers: k*(k+1)/2 (1+2+...+k)
- Maximum sum of k distinct integers: k*(2*n-k+1)/2 (n-k+1 + n-k+2 + ... + n)
- If x is between min and max (inclusive), answer is YES

### Implementation Details
- Calculates min = k*(k+1)/2
- Calculates max = k*(2*n-k+1)/2
- Checks if x >= min && x <= max

### Time Complexity
O(1) per test case

### Space Complexity
O(1)

## Code
See `Vasilije_in_Cacak.cpp` for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
