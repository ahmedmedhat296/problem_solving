# Manacher's Algorithm

## Problem Description
This is an implementation of **Manacher's Algorithm** for finding the **longest palindromic substring** in **linear time (O(n))** using C++.

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

* Keep track of the **biggest palindrome** and its **center**.

## Solution Approach

### Algorithm
Manacher's Algorithm finds the longest palindromic substring in O(n) time by using symmetry properties and reusing previously calculated palindrome lengths.

### Key Insights
- Uses symmetry property: if we know a palindrome centered at position i, we can reuse information for positions within that palindrome
- Inserts '#' characters between each character to handle both odd and even length palindromes uniformly
- Tracks the center and rightmost boundary of the current palindrome to optimize expansion

### Implementation Details
- Adds '#' characters between each character to create a transformed string
- Maintains an array P[i] representing the palindrome radius at position i
- Uses mirror index to reuse palindrome information when possible
- Expands palindrome only when necessary, avoiding redundant checks

### Time Complexity
O(n) - each character is processed at most once

### Space Complexity
O(n) for the transformed string and P array

## Code
See the `.cpp` file in this directory for the complete solution.

## Notes
<!-- Add any additional notes or observations here -->
