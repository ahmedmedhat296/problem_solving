# C++ Problem Solving Repository

This repository contains a collection of C++ solutions for various programming problems, showcasing different algorithms, data structures, and problem-solving techniques. Each problem is organized in its own subfolder with detailed documentation including solution explanations, algorithm analysis, and problem descriptions.

## 📁 Repository Structure

Each problem in this repository is organized in its own subfolder containing:
- **Solution file** (`.cpp`) - The complete C++ implementation
- **README.md** - Detailed solution explanation with algorithm analysis, key insights, implementation details, and complexity analysis
- **problem.md** - Problem description, input/output format, constraints, and examples

## 🎯 Problems Included

### 1. [Reachable Coordinates](./reachable_coordinates/)
Simulates movement on a grid based on a given sequence of directions (North, South, East, West). Determines if a target coordinate (a, b) is reached within a certain number of steps, following a repeating route pattern. This problem involves basic coordinate tracking and loop control.

### 2. [Splitting Items Greedy](./splitting_items_greedy/)
Implements a solution for resource allocation or item distribution problem. Involves sorting items and distributing them between two parties (Alice and Bob) following a specific logic, using a greedy approach with a modification factor `k`. Calculates the difference in the total value of items received by each party.

### 3. [Array Stack Implementation](./array_stack_implementation/)
A basic implementation of a stack data structure using a fixed-size array. Includes standard stack operations like `push`, `pop`, `top`, `size`, and `empty`. This serves as a fundamental example of implementing a common data structure in C++.

### 4. [Merge Sort](./merge_sort/)
Implementation of the classic Merge Sort algorithm, a highly efficient, comparison-based sorting algorithm. Follows the divide-and-conquer paradigm, recursively dividing the array into halves, sorting them, and then merging the sorted halves.

### 5. [HTML Tag Matcher](./html_tag_matcher/)
Demonstrates how to use a stack to validate the proper nesting and matching of tags in an HTML or XML document. Parses a string containing tags, pushes opening tags onto a stack, and pops them when the corresponding closing tag is encountered, ensuring correctness.

### 6. [Array-Based Binary Search Tree](./array_based_bst/)
Implementation of a Binary Search Tree (BST) using an array representation instead of pointers. Defines methods for adding elements (`Add`) and provides iterators (`POS`) to traverse the tree, finding the beginning and end elements in an inorder traversal.

### 7. [Maximum Subarray (Divide and Conquer)](./maximum_subarray_divide_conquer/)
Efficient solution to the maximum subarray problem using the divide-and-conquer approach. Finds the contiguous subarray within a one-dimensional array of numbers that has the largest sum. Includes functionality to time the execution.

### 8. [Matrix Operations Class](./matrix_operations_class/)
Defines a C++ class (`Array2d`) to represent and manipulate 2D matrices. Includes methods for getting/setting elements, resizing the matrix, retrieving rows, finding the row with the maximum sum, and overloading the addition operator (`+`) for matrix addition.

### 9. [Manacher's Algorithm](./manacher_algorithm/)
Implementation of **Manacher's Algorithm** for finding the **longest palindromic substring** in **linear time (O(n))** using C++.

The algorithm uses symmetry properties to efficiently calculate palindromes by keeping track of previously calculated palindromes and reusing that information.

#### How it works:
- Creates an array of the same length as the string, where each element represents the palindrome size centered at that position
- Tracks the center and rightmost character of the last palindrome seen
- For characters inside the current palindrome, checks the mirror index and reuses palindrome length information
- Keeps track of the biggest palindrome and its center

## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ahmedmedhat296/problem_solving.git
   ```

2. **Navigate to a problem folder:**
   ```bash
   cd problem_solving/merge_sort
   ```

3. **Read the documentation:**
   - Check `README.md` for solution explanation
   - Check `problem.md` for problem description

4. **Compile and run:**
   ```bash
   g++ -o solution *.cpp
   ./solution
   ```

## 📚 Topics Covered

- **Data Structures**: Stack, Binary Search Tree, Arrays
- **Algorithms**: Sorting (Merge Sort), String Algorithms (Manacher's Algorithm)
- **Problem-Solving Techniques**: Divide and Conquer, Greedy Algorithms
- **C++ Features**: Classes, Operator Overloading, Templates

## 📝 Notes

- All solutions are written in C++
- Each solution includes detailed documentation
- Time and space complexity analysis is provided for each problem
- Solutions are organized for easy navigation and learning

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
