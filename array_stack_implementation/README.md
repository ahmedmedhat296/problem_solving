# Array Stack Implementation

## Problem Description
This file provides a basic implementation of a stack data structure using a fixed-size array. It includes standard stack operations like `push`, `pop`, `top`, `size`, and `empty`. This serves as a fundamental example of implementing a common data structure in C++.

## Solution Approach

### Algorithm
Implements a stack data structure using an array, following LIFO (Last In First Out) principle.

### Key Insights
- Stack operations: push (add to top), pop (remove from top), top (peek at top), size, empty
- Uses array with a top pointer/index to track the current position
- Fixed-size array requires checking for overflow/underflow

### Implementation Details
- Uses array to store stack elements
- Maintains top index to track current position
- Checks bounds before push/pop operations

### Time Complexity
O(1) for all operations

### Space Complexity
O(n) where n is the maximum stack size

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
