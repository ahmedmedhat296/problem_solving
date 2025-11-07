# Game with Integers

## Problem
[Link to Codeforces problem](https://codeforces.com/problemset/problem/XXXX/XXXX)

## Solution Approach

### Algorithm
This is a game theory problem. The solution checks if a number can be made divisible by 3 by adding or subtracting 1.

### Key Insights
- If (n-1) % 3 == 0, we can subtract 1 to make it divisible by 3
- If (n+1) % 3 == 0, we can add 1 to make it divisible by 3
- Otherwise, the number is already divisible by 3, so the second player wins

### Implementation Details
- Simple modulo arithmetic check
- O(1) per test case

### Time Complexity
O(1) per test case

### Space Complexity
O(1)

## Code
See `Game_with_Integers.cpp` for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
