"""
Script to organize GitHub problem_solving repository.
Each problem will be moved to its own subfolder with README.md and problem.md files.
Run this script in the root directory of your GitHub repository.
"""

import os
import shutil
import re
from pathlib import Path

# Problem files from GitHub repo with their descriptions
problems = {
    "coordinates reachable.cpp": {
        "name": "Reachable Coordinates",
        "folder": "reachable_coordinates",
        "description": """This program simulates movement on a grid based on a given sequence of directions (North, South, East, West). It determines if a target coordinate (a, b) is reached within a certain number of steps, following a repeating route pattern. This problem involves basic coordinate tracking and loop control."""
    },
    "splitting_items_greedy.cpp": {
        "name": "Splitting Items Greedy",
        "folder": "splitting_items_greedy",
        "description": """This program implements a solution likely related to a resource allocation or item distribution problem. Based on the code structure, it seems to involve sorting items and distributing them between two parties (Alice and Bob) following a specific logic, potentially involving a greedy approach and a modification factor `k`. The goal appears to be calculating the difference in the total value of items received by each party."""
    },
    "array_stack_implementation.cpp": {
        "name": "Array Stack Implementation",
        "folder": "array_stack_implementation",
        "description": """This file provides a basic implementation of a stack data structure using a fixed-size array. It includes standard stack operations like `push`, `pop`, `top`, `size`, and `empty`. This serves as a fundamental example of implementing a common data structure in C++."""
    },
    "merge_sort.cpp": {
        "name": "Merge Sort",
        "folder": "merge_sort",
        "description": """This file implements the classic Merge Sort algorithm, a highly efficient, comparison-based sorting algorithm. It follows the divide-and-conquer paradigm, recursively dividing the array into halves, sorting them, and then merging the sorted halves."""
    },
    "html_tag_matcher.cpp": {
        "name": "HTML Tag Matcher",
        "folder": "html_tag_matcher",
        "description": """This program demonstrates how to use a stack to validate the proper nesting and matching of tags in an HTML or XML document. It parses a string containing tags, pushes opening tags onto a stack, and pops them when the corresponding closing tag is encountered, ensuring correctness."""
    },
    "array_based_bst.cpp": {
        "name": "Array-Based Binary Search Tree",
        "folder": "array_based_bst",
        "description": """This solution provides an implementation of a Binary Search Tree (BST) using an array representation instead of pointers. It defines methods for adding elements (`Add`) and provides iterators (`POS`) to traverse the tree (specifically finding the beginning and end elements in an inorder traversal sense, though the implementation details might vary)."""
    },
    "maximum_subarray_divide_conquer.cpp": {
        "name": "Maximum Subarray (Divide and Conquer)",
        "folder": "maximum_subarray_divide_conquer",
        "description": """This file implements an efficient solution to the maximum subarray problem using the divide-and-conquer approach. It finds the contiguous subarray within a one-dimensional array of numbers that has the largest sum. The code also includes functionality to time the execution."""
    },
    "matrix_operations_class.cpp": {
        "name": "Matrix Operations Class",
        "folder": "matrix_operations_class",
        "description": """This program defines a C++ class (`Array2d`) to represent and manipulate 2D matrices. It includes methods for getting/setting elements, resizing the matrix, retrieving rows, finding the row with the maximum sum, and overloading the addition operator (`+`) for matrix addition."""
    },
    "manacher.cpp": {
        "name": "Manacher's Algorithm",
        "folder": "manacher_algorithm",
        "description": """This is an implementation of **Manacher's Algorithm** for finding the **longest palindromic substring** in **linear time (O(n))** using C++.

The algorithm is actually simple:  
We iterate over the string, and at each character we check for symmetry around this element.  
But if we do so naively, this will take more than **O(n)**.

The trick is that we **keep track of all the palindromes we have already calculated** to efficiently calculate the upcoming ones.

### How it works:

* We make an array of the same length as the string.  
Each element of the array represents the **palindrome size centered at this element**.
* We keep track of the **center** and the **rightmost character** of the last palindrome we have seen.
* If the current character is inside the current palindrome:  
   * We check its **mirror index** within the palindrome.  
   * We can **reuse its palindrome length** and determine (and here is the magic) **where to start checking for symmetry**.

### For efficiency:

* Keep track of the **biggest palindrome** and its **center**."""
    }
}

def analyze_code(code, problem_name):
    """Analyze code to generate solution explanation"""
    explanation = {
        'algorithm': '',
        'insights': [],
        'implementation': [],
        'time_complexity': '',
        'space_complexity': ''
    }
    
    # Manacher's Algorithm
    if 'manacher' in problem_name.lower():
        explanation['algorithm'] = "Manacher's Algorithm finds the longest palindromic substring in O(n) time by using symmetry properties and reusing previously calculated palindrome lengths."
        explanation['insights'] = [
            "Uses symmetry property: if we know a palindrome centered at position i, we can reuse information for positions within that palindrome",
            "Inserts '#' characters between each character to handle both odd and even length palindromes uniformly",
            "Tracks the center and rightmost boundary of the current palindrome to optimize expansion"
        ]
        explanation['implementation'] = [
            "Adds '#' characters between each character to create a transformed string",
            "Maintains an array P[i] representing the palindrome radius at position i",
            "Uses mirror index to reuse palindrome information when possible",
            "Expands palindrome only when necessary, avoiding redundant checks"
        ]
        explanation['time_complexity'] = "O(n) - each character is processed at most once"
        explanation['space_complexity'] = "O(n) for the transformed string and P array"
    
    # Merge Sort
    elif 'merge' in problem_name.lower() and 'sort' in problem_name.lower():
        explanation['algorithm'] = "Merge Sort is a divide-and-conquer sorting algorithm that recursively divides the array into halves, sorts them, and merges the sorted halves."
        explanation['insights'] = [
            "Divide: Recursively split the array into two halves until each subarray has one element",
            "Conquer: Merge the sorted subarrays back together",
            "Stable sort: Maintains relative order of equal elements"
        ]
        explanation['implementation'] = [
            "Recursively divides array into halves",
            "Merges two sorted subarrays by comparing elements",
            "Uses temporary arrays during merging"
        ]
        explanation['time_complexity'] = "O(n log n) in all cases"
        explanation['space_complexity'] = "O(n) for temporary arrays"
    
    # Stack Implementation
    elif 'stack' in problem_name.lower():
        explanation['algorithm'] = "Implements a stack data structure using an array, following LIFO (Last In First Out) principle."
        explanation['insights'] = [
            "Stack operations: push (add to top), pop (remove from top), top (peek at top), size, empty",
            "Uses array with a top pointer/index to track the current position",
            "Fixed-size array requires checking for overflow/underflow"
        ]
        explanation['implementation'] = [
            "Uses array to store stack elements",
            "Maintains top index to track current position",
            "Checks bounds before push/pop operations"
        ]
        explanation['time_complexity'] = "O(1) for all operations"
        explanation['space_complexity'] = "O(n) where n is the maximum stack size"
    
    # Maximum Subarray
    elif 'maximum_subarray' in problem_name.lower() or 'maximum subarray' in problem_name.lower():
        explanation['algorithm'] = "Finds the contiguous subarray with maximum sum using divide-and-conquer approach."
        explanation['insights'] = [
            "Divide array into two halves",
            "Maximum subarray is either in left half, right half, or crosses the middle",
            "For crossing subarray, find maximum sum ending at middle from left, and starting at middle from right"
        ]
        explanation['implementation'] = [
            "Recursively divides array",
            "Finds maximum subarray in left and right halves",
            "Finds maximum crossing subarray",
            "Returns maximum of the three"
        ]
        explanation['time_complexity'] = "O(n log n)"
        explanation['space_complexity'] = "O(log n) for recursion stack"
    
    # BST
    elif 'bst' in problem_name.lower() or 'binary search tree' in problem_name.lower():
        explanation['algorithm'] = "Implements a Binary Search Tree using array representation instead of pointers."
        explanation['insights'] = [
            "Left child at index 2*i + 1, right child at 2*i + 2",
            "Parent at index (i-1)/2",
            "More memory efficient but less flexible than pointer-based implementation"
        ]
        explanation['implementation'] = [
            "Uses array to store tree nodes",
            "Calculates child/parent indices using formulas",
            "Maintains BST property: left < parent < right"
        ]
        explanation['time_complexity'] = "O(log n) average case for insert/search, O(n) worst case"
        explanation['space_complexity'] = "O(n) for array storage"
    
    # HTML Tag Matcher
    elif 'html' in problem_name.lower() or 'tag' in problem_name.lower():
        explanation['algorithm'] = "Validates HTML/XML tag matching using a stack data structure."
        explanation['insights'] = [
            "Opening tags are pushed onto stack",
            "Closing tags pop from stack and must match the top element",
            "Valid if stack is empty after processing all tags"
        ]
        explanation['implementation'] = [
            "Parses string to extract tags",
            "Uses stack to track opening tags",
            "Checks if closing tag matches top of stack"
        ]
        explanation['time_complexity'] = "O(n) where n is string length"
        explanation['space_complexity'] = "O(n) for stack in worst case"
    
    # Matrix Operations
    elif 'matrix' in problem_name.lower():
        explanation['algorithm'] = "Implements a 2D matrix class with various operations."
        explanation['insights'] = [
            "Uses 2D array or vector to store matrix elements",
            "Provides methods for element access, resizing, and operations",
            "Overloads operators for intuitive matrix operations"
        ]
        explanation['implementation'] = [
            "Class-based design for encapsulation",
            "Methods for get/set, resize, row operations",
            "Operator overloading for matrix addition"
        ]
        explanation['time_complexity'] = "Varies by operation: O(1) for access, O(n*m) for operations"
        explanation['space_complexity'] = "O(n*m) for n×m matrix"
    
    # Generic analysis
    else:
        if 'class' in code or 'struct' in code:
            explanation['implementation'].append("Uses class/struct for organization")
        if 'vector' in code or 'array' in code:
            explanation['implementation'].append("Uses vector/array for data storage")
        if 'recursive' in code.lower() or 'recursion' in code.lower():
            explanation['implementation'].append("Uses recursion")
        if 'sort' in code.lower():
            explanation['implementation'].append("Involves sorting")
        
        if not explanation['algorithm']:
            explanation['algorithm'] = "<!-- Explain your algorithm here -->"
        if not explanation['insights']:
            explanation['insights'] = ["<!-- Add your key insights here -->"]
        if not explanation['time_complexity']:
            explanation['time_complexity'] = "O(<!-- Add time complexity -->)"
        if not explanation['space_complexity']:
            explanation['space_complexity'] = "O(<!-- Add space complexity -->)"
    
    return explanation

def create_readme(problem_info, code):
    """Create README.md file"""
    problem_name = problem_info['name']
    folder_name = problem_info['folder']
    description = problem_info['description']
    
    # Analyze code
    analysis = analyze_code(code, problem_name)
    
    readme_content = f"""# {problem_name}

## Problem Description
{description}

## Solution Approach

### Algorithm
{analysis['algorithm']}

### Key Insights
"""
    
    for insight in analysis['insights']:
        readme_content += f"- {insight}\n"
    
    readme_content += "\n### Implementation Details\n"
    
    for detail in analysis['implementation']:
        readme_content += f"- {detail}\n"
    
    if not analysis['implementation']:
        readme_content += "- Standard implementation\n"
    
    readme_content += f"""
### Time Complexity
{analysis['time_complexity']}

### Space Complexity
{analysis['space_complexity']}

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
"""
    
    return readme_content

def create_problem_description(problem_info):
    """Create problem.md file"""
    problem_name = problem_info['name']
    description = problem_info['description']
    
    problem_content = f"""# {problem_name}

## Problem Statement
{description}

## Input Format
<!-- Describe input format -->

## Output Format
<!-- Describe output format -->

## Constraints
<!-- List constraints -->

## Examples

### Example 1
**Input:**
```
<!-- Input here -->
```

**Output:**
```
<!-- Output here -->
```

### Example 2
**Input:**
```
<!-- Input here -->
```

**Output:**
```
<!-- Output here -->
```

## Approach
<!-- Describe your approach to solving this problem -->
"""
    
    return problem_content

def main():
    base_dir = Path(__file__).parent
    
    print("Organizing GitHub problem_solving repository...")
    print("=" * 60)
    
    organized_count = 0
    skipped_count = 0
    
    for filename, problem_info in problems.items():
        source_file = base_dir / filename
        
        # Check if file exists (with or without spaces)
        if not source_file.exists():
            # Try alternative names
            alt_names = [
                filename.replace(" ", "_"),
                filename.replace("_", " "),
                filename.lower(),
                filename.upper()
            ]
            found = False
            for alt_name in alt_names:
                alt_file = base_dir / alt_name
                if alt_file.exists():
                    source_file = alt_file
                    filename = alt_name
                    found = True
                    break
            
            if not found:
                print(f"⚠️  Skipping {filename} - file not found")
                skipped_count += 1
                continue
        
        # Create folder
        folder_name = problem_info['folder']
        folder_path = base_dir / folder_name
        folder_path.mkdir(exist_ok=True)
        print(f"\n📁 Processing: {problem_info['name']}")
        print(f"   Folder: {folder_name}")
        
        # Read code
        try:
            with open(source_file, 'r', encoding='utf-8') as f:
                code = f.read()
        except Exception as e:
            print(f"   ❌ Error reading {filename}: {e}")
            skipped_count += 1
            continue
        
        # Move file to folder
        dest_file = folder_path / filename
        if source_file != dest_file:
            shutil.move(str(source_file), str(dest_file))
            print(f"   ✓ Moved {filename} to {folder_name}/")
        else:
            print(f"   ✓ File already in {folder_name}/")
        
        # Create README.md
        readme_content = create_readme(problem_info, code)
        readme_path = folder_path / "README.md"
        with open(readme_path, 'w', encoding='utf-8') as f:
            f.write(readme_content)
        print(f"   ✓ Created README.md")
        
        # Create problem.md
        problem_content = create_problem_description(problem_info)
        problem_path = folder_path / "problem.md"
        with open(problem_path, 'w', encoding='utf-8') as f:
            f.write(problem_content)
        print(f"   ✓ Created problem.md")
        
        organized_count += 1
    
    print("\n" + "=" * 60)
    print(f"✅ Organization complete!")
    print(f"   Organized: {organized_count} problems")
    print(f"   Skipped: {skipped_count} problems (not found)")
    print("\n💡 Tip: You can now commit and push these changes to GitHub!")

if __name__ == "__main__":
    main()
