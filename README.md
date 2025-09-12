# C++ Problem Solving Exercises

This repository contains a selection of C++ solutions for various programming problems, showcasing different algorithms and data structures.

## Problems

Here are the problems included in this collection:

### 1. reachable coordinates (`coordiantes reachable.cpp`)

This program simulates movement on a grid based on a given sequence of directions (North, South, East, West). It determines if a target coordinate (a, b) is reached within a certain number of steps, following a repeating route pattern. This problem involves basic coordinate tracking and loop control.

### 2. Splitting Items Greedy (`splitting_items_greedy.cpp`)

This program implements a solution likely related to a resource allocation or item distribution problem. Based on the code structure, it seems to involve sorting items and distributing them between two parties (Alice and Bob) following a specific logic, potentially involving a greedy approach and a modification factor `k`. The goal appears to be calculating the difference in the total value of items received by each party.

### 3. Array Stack Implementation (`array_stack_implementation.cpp`)

This file provides a basic implementation of a stack data structure using a fixed-size array. It includes standard stack operations like `push`, `pop`, `top`, `size`, and `empty`. This serves as a fundamental example of implementing a common data structure in C++.
### 4. Merge Sort (`merge_sort.cpp`)

This file implements the classic Merge Sort algorithm, a highly efficient, comparison-based sorting algorithm. It follows the divide-and-conquer paradigm, recursively dividing the array into halves, sorting them, and then merging the sorted halves.

### 5. HTML Tag Matcher (`html_tag_matcher.cpp`)

This program demonstrates how to use a stack to validate the proper nesting and matching of tags in an HTML or XML document. It parses a string containing tags, pushes opening tags onto a stack, and pops them when the corresponding closing tag is encountered, ensuring correctness.

### 6. Array-Based Binary Search Tree (`array_based_bst.cpp`)

This solution provides an implementation of a Binary Search Tree (BST) using an array representation instead of pointers. It defines methods for adding elements (`Add`) and provides iterators (`POS`) to traverse the tree (specifically finding the beginning and end elements in an inorder traversal sense, though the implementation details might vary).

### 7. Maximum Subarray (Divide and Conquer) (`maximum_subarray_divide_conquer.cpp`)

This file implements an efficient solution to the maximum subarray problem using the divide-and-conquer approach. It finds the contiguous subarray within a one-dimensional array of numbers that has the largest sum. The code also includes functionality to time the execution.

### 8. Matrix Operations Class (`matrix_operations_class.cpp`)

This program defines a C++ class (`Array2d`) to represent and manipulate 2D matrices. It includes methods for getting/setting elements, resizing the matrix, retrieving rows, finding the row with the maximum sum, and overloading the addition operator (`+`) for matrix addition.
### 9. Manacher's Algorithm  

This is an implementation of **Manacher's Algorithm** for finding the **longest palindromic substring** in **linear time (O(n))** using C++.  

The algorithm is actually simple:  
We iterate over the string, and at each character we check for symmetry around this element.  
But if we do so naively, this will take more than **O(n)**.  

The trick is that we **keep track of all the palindromes we have already calculated** to efficiently calculate the upcoming ones.  

---

### How it works:
- We make an array of the same length as the string.  
  Each element of the array represents the **palindrome size centered at this element**.  
- We keep track of the **center** and the **rightmost character** of the last palindrome we have seen.  
- If the current character is inside the current palindrome:
  - We check its **mirror index** within the palindrome.  
  - We can **reuse its palindrome length** and determine (and here is the magic) **where to start checking for symmetry**.  

---

### For efficiency:
- Keep track of the **biggest palindrome** and its **center**.  
