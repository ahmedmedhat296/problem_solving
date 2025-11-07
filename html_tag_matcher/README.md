# HTML Tag Matcher

## Problem Description
This program demonstrates how to use a stack to validate the proper nesting and matching of tags in an HTML or XML document. It parses a string containing tags, pushes opening tags onto a stack, and pops them when the corresponding closing tag is encountered, ensuring correctness.

## Solution Approach

### Algorithm
Validates HTML/XML tag matching using a stack data structure.

### Key Insights
- Opening tags are pushed onto stack
- Closing tags pop from stack and must match the top element
- Valid if stack is empty after processing all tags

### Implementation Details
- Parses string to extract tags
- Uses stack to track opening tags
- Checks if closing tag matches top of stack

### Time Complexity
O(n) where n is string length

### Space Complexity
O(n) for stack in worst case

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
