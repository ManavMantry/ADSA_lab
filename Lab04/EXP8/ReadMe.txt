README — Longest and All Common Subsequences
============================================

Program Overview
----------------
This C program finds:
1. The **Longest Common Subsequence (LCS)** between two strings.
2. **All Common Subsequences** (not just the longest ones).

A *subsequence* is a sequence that appears in the same relative order 
but not necessarily contiguous.  
Example: For string "ABC", subsequences include "A", "B", "C", "AB", "AC", "BC", and "ABC".

The LCS problem is widely used in bioinformatics (DNA sequence analysis),
file comparison tools, and version control systems.

------------------------------------------------------------

Algorithm Explanation
---------------------
### A) Longest Common Subsequence (LCS)
- Uses **Dynamic Programming**.
- `dp[i][j]` stores the length of LCS between the first `i` characters of X
  and the first `j` characters of Y.
- The table is filled iteratively, and then the LCS is reconstructed
  by tracing back from the bottom-right corner.

### B) All Common Subsequences
- Uses **Recursive Backtracking**.
- Generates all possible subsequences that appear in both strings.
- May include duplicates (as overlapping subsequences are found).
- For simplicity, this implementation focuses on correctness, not uniqueness.

------------------------------------------------------------

Input and Output
----------------
The program takes **two strings** as input from the user and prints:
1. The **Longest Common Subsequence** and its **length**.
2. A list of **All Common Subsequences** (may include duplicates).

------------------------------------------------------------

Example Input
-------------
Enter first string: ABCDGH  
Enter second string: AEDFHR

Example Output
--------------
Longest Common Subsequence (LCS): ADH  
Length of LCS: 3

All Common Subsequences (may include duplicates):
A
AD
AH
D
H
...

------------------------------------------------------------


Functions Used
--------------
1. **LCS_Length(X, Y, m, n, dp)**  
   → Builds the DP table and returns the LCS length.

2. **print_LCS(X, Y, m, n, dp)**  
   → Prints the actual Longest Common Subsequence.

3. **generateAllSubsequences(X, m, Y, n, res, i, j, index)**  
   → Recursively generates all common subsequences.

4. **printAllCommonSubsequences(X, Y)**  
   → Wrapper to print all common subsequences.

------------------------------------------------------------

Algorithmic Steps
-----------------
1. Read two strings X and Y.
2. Use DP to compute LCS length.
3. Backtrack to find one LCS sequence.
4. Use recursion to list all common subsequences.

------------------------------------------------------------

Time and Space Complexity
-------------------------
| Operation                | Time Complexity | Space Complexity |
|---------------------------|----------------|------------------|
| LCS Length Calculation    | O(m × n)       | O(m × n)         |
| LCS Reconstruction        | O(m + n)       | O(m + n)         |
| All Common Subsequences   | Exponential    | O(n)             |

where  
m = length of first string  
n = length of second string

------------------------------------------------------------

Sample Run
-----------
Input:
    Enter first string: ABAC
    Enter second string: CAB

Output:
    Longest Common Subsequence (LCS): AB
    Length of LCS: 2

    All Common Subsequences:
    A
    B
    AB

------------------------------------------------------------

Applications
------------
- DNA or protein sequence comparison
- Diff tools (file comparison)
- Spell checking
- Data synchronization
- Compiler design and version control

------------------------------------------------------------

