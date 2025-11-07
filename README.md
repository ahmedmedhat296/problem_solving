# C++ Problem Solving Repository

This repository contains a collection of C++ solutions for various programming problems, showcasing different algorithms, data structures, and problem-solving techniques. Each problem is organized in its own subfolder with detailed documentation including solution explanations, algorithm analysis, and problem descriptions.

## 📁 Repository Structure

Each problem in this repository is organized in its own subfolder containing:
- **Solution file** (`.cpp`) - The complete C++ implementation
- **README.md** - Detailed solution explanation with algorithm analysis, key insights, implementation details, and complexity analysis
- **problem.md** - Problem description, input/output format, constraints, and examples

## 🎯 Problems Included

### Algorithm & Data Structure Problems

#### 1. [Reachable Coordinates](./reachable_coordinates/)
Simulates movement on a grid based on a given sequence of directions (North, South, East, West). Determines if a target coordinate (a, b) is reached within a certain number of steps, following a repeating route pattern. This problem involves basic coordinate tracking and loop control.

#### 2. [Splitting Items Greedy](./splitting_items_greedy/)
Implements a solution for resource allocation or item distribution problem. Involves sorting items and distributing them between two parties (Alice and Bob) following a specific logic, using a greedy approach with a modification factor `k`. Calculates the difference in the total value of items received by each party.

#### 3. [Array Stack Implementation](./array_stack_implementation/)
A basic implementation of a stack data structure using a fixed-size array. Includes standard stack operations like `push`, `pop`, `top`, `size`, and `empty`. This serves as a fundamental example of implementing a common data structure in C++.

#### 4. [Merge Sort](./merge_sort/)
Implementation of the classic Merge Sort algorithm, a highly efficient, comparison-based sorting algorithm. Follows the divide-and-conquer paradigm, recursively dividing the array into halves, sorting them, and then merging the sorted halves.

#### 5. [HTML Tag Matcher](./html_tag_matcher/)
Demonstrates how to use a stack to validate the proper nesting and matching of tags in an HTML or XML document. Parses a string containing tags, pushes opening tags onto a stack, and pops them when the corresponding closing tag is encountered, ensuring correctness.

#### 6. [Array-Based Binary Search Tree](./array_based_bst/)
Implementation of a Binary Search Tree (BST) using an array representation instead of pointers. Defines methods for adding elements (`Add`) and provides iterators (`POS`) to traverse the tree, finding the beginning and end elements in an inorder traversal.

#### 7. [Maximum Subarray (Divide and Conquer)](./maximum_subarray_divide_conquer/)
Efficient solution to the maximum subarray problem using the divide-and-conquer approach. Finds the contiguous subarray within a one-dimensional array of numbers that has the largest sum. Includes functionality to time the execution.

#### 8. [Matrix Operations Class](./matrix_operations_class/)
Defines a C++ class (`Array2d`) to represent and manipulate 2D matrices. Includes methods for getting/setting elements, resizing the matrix, retrieving rows, finding the row with the maximum sum, and overloading the addition operator (`+`) for matrix addition.

#### 9. [Manacher's Algorithm](./manacher_algorithm/)
Implementation of **Manacher's Algorithm** for finding the **longest palindromic substring** in **linear time (O(n))** using C++.

The algorithm uses symmetry properties to efficiently calculate palindromes by keeping track of previously calculated palindromes and reusing that information.

##### How it works:
- Creates an array of the same length as the string, where each element represents the palindrome size centered at that position
- Tracks the center and rightmost character of the last palindrome seen
- For characters inside the current palindrome, checks the mirror index and reuses palindrome length information
- Keeps track of the biggest palindrome and its center

### Codeforces Problems

#### 10. [Abraham's Great Escape](./Abrahams_Great_Escape/)
A Codeforces problem solution involving grid path construction and movement simulation.

#### 11. [Against the Difference](./Against_the_Difference/)
A dynamic programming solution for a Codeforces problem that tracks occurrences and maximizes values based on element frequencies.

#### 12. [Bitwise Reversion](./Bitwise_Reversion/)
A Codeforces problem solution involving bitwise operations and reversals.

#### 13. [Candies for Nephews](./Candies_for_Nephews/)
A Codeforces problem solution calculating the minimum number of candies needed for distribution among nephews.

#### 14. [Circle of Apple Trees](./Circle_of_Apple_Trees/)
A Codeforces problem solution involving circular arrangements and tree structures.

#### 15. [Deck of Cards](./Deck_of_Cards/)
A Codeforces problem solution involving card game logic and deck manipulation.

#### 16. [Distinct Elements](./Distincit_Elements/)
A Codeforces problem solution for finding or working with distinct elements in arrays.

#### 17. [Game with Integers](./Game_with_Integers/)
A game theory problem from Codeforces. The solution checks if a number can be made divisible by 3 by adding or subtracting 1, determining the winner of the game.

#### 18. [Math Problem](./Math_Problem/)
A Codeforces problem solution involving mathematical computations and problem-solving.

#### 19. [MEX Partition](./MEX_Partition/)
A Codeforces problem solution that finds the Minimum Excluded (MEX) value - the smallest non-negative integer not present in the array.

#### 20. [Monocarp's String](./Monocarps_String/)
A Codeforces problem solution that finds the minimum length substring to remove so that the remaining string has an equal number of 'a' and 'b' characters.

#### 21. [Need More Arrays](./Need_More_Arrays/)
A Codeforces problem solution involving array operations and manipulations.

#### 22. [Split](./Split/)
A Codeforces problem solution involving string or array splitting operations.

#### 23. [Symmetrical Polygons](./Symmetrical_Polygons/)
A Codeforces problem solution involving geometric calculations with symmetrical polygon structures.

#### 24. [The Ancient Wizards' Capes](./The_Ancient_Wizards_Capes/)
A Codeforces problem solution involving wizard-themed problem-solving.

#### 25. [Vasilije in Cacak](./Vasilije_in_Cacak/)
A Codeforces problem solution that checks if a value x can be expressed as the sum of k distinct integers from 1 to n.

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

- **Data Structures**: Stack, Binary Search Tree, Arrays, Maps
- **Algorithms**: Sorting (Merge Sort), String Algorithms (Manacher's Algorithm), Dynamic Programming
- **Problem-Solving Techniques**: Divide and Conquer, Greedy Algorithms, Game Theory, Bitwise Operations
- **C++ Features**: Classes, Operator Overloading, Templates, STL Containers
- **Competitive Programming**: Codeforces problems covering various difficulty levels

## 📊 Statistics

- **Total Problems**: 25
- **Algorithm & Data Structure Problems**: 9
- **Codeforces Problems**: 16
- **Languages**: C++

## 📝 Notes

- All solutions are written in C++
- Each solution includes detailed documentation
- Time and space complexity analysis is provided for each problem
- Solutions are organized for easy navigation and learning
- Codeforces problems include links to the original problems (to be added in problem.md files)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
