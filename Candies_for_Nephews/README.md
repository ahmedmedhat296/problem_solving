# Candies for Nephews

## Problem
[Link to Codeforces problem](https://codeforces.com/problemset/problem/XXXX/XXXX)

## Solution Approach

### Algorithm
Calculates the minimum number of candies needed to distribute among nephews such that each gets a multiple of 3.

### Key Insights
- If n is already divisible by 3, no additional candies needed (answer = 0)
- Otherwise, we need to add (3 - n%3) candies to make it divisible by 3

### Implementation Details
- Uses modulo operation: n % 3 gives remainder
- If remainder is 0, answer is 0, else answer is 3 - remainder

### Time Complexity
O(1) per test case

### Space Complexity
O(1)

## Code
See `Candies_for_Nephews.cpp` for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
