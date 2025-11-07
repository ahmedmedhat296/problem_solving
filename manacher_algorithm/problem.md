# Manacher's Algorithm

## Problem Statement
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
