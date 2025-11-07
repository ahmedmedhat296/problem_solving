# Abraham's Great Escape

## Problem
[Link to Codeforces problem](https://codeforces.com/problemset/problem/XXXX/XXXX)

## Solution Approach

### Algorithm
Constructs a grid path where cells are marked 'U' (up) for the first k cells, then 'D' (down), 'L' (left), or 'R' (right) based on position.

### Key Insights
- If k == n*n - 1, it's impossible (outputs NO)
- Otherwise, constructs a grid where first k cells are 'U'
- After k cells, fills remaining cells with 'D', 'L', or 'R' based on row/column position

### Implementation Details
- Checks if k == n*n - 1, if so outputs NO
- Otherwise, iterates through grid cells
- If i*n + j < k, outputs 'U'
- Else if i*n < n*(n-1), outputs 'D'
- Else if j == n-1, outputs 'L'
- Otherwise outputs 'R'

### Time Complexity
O(n²) to construct the grid

### Space Complexity
O(1) excluding output

## Code
See `Abraham's_Great_Escape.cpp` for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
