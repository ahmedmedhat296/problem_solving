# Array-Based Binary Search Tree

## Problem Description
This solution provides an implementation of a Binary Search Tree (BST) using an array representation instead of pointers. It defines methods for adding elements (`Add`) and provides iterators (`POS`) to traverse the tree (specifically finding the beginning and end elements in an inorder traversal sense, though the implementation details might vary).

## Solution Approach

### Algorithm
Implements a Binary Search Tree using array representation instead of pointers.

### Key Insights
- Left child at index 2*i + 1, right child at 2*i + 2
- Parent at index (i-1)/2
- More memory efficient but less flexible than pointer-based implementation

### Implementation Details
- Uses array to store tree nodes
- Calculates child/parent indices using formulas
- Maintains BST property: left < parent < right

### Time Complexity
O(log n) average case for insert/search, O(n) worst case

### Space Complexity
O(n) for array storage

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
