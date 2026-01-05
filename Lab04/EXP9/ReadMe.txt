README — String Pattern Matching using KMP and Rabin-Karp Algorithms
====================================================================

Program Overview
----------------
This program implements two classic string matching algorithms:

1. **Knuth–Morris–Pratt (KMP) Algorithm**  
   → Efficient pattern searching using prefix-suffix preprocessing.

2. **Rabin–Karp (Fingerprinting) Algorithm**  
   → Pattern searching using hash values (rolling hash or fingerprinting).

The program reads a **text string** and a **pattern**, then searches for 
all occurrences of the pattern in the text using both algorithms.

--------------------------------------------------------------------

Algorithms Used
---------------
### A) Knuth–Morris–Pratt (KMP) Algorithm
- Uses an auxiliary **LPS (Longest Prefix Suffix)** array.
- The LPS array tells how many characters can be skipped when a mismatch occurs.
- Ensures that no character in the text is compared more than once.

### B) Rabin–Karp (Fingerprinting) Algorithm
- Computes a **hash value** for the pattern and each substring of the text.
- If hash values match, the substring is checked character by character.
- Efficient for multiple pattern matches and plagiarism detection.

--------------------------------------------------------------------

Input and Output Format
-----------------------
**Input:**
- Text string (the main string to search in)
- Pattern string (the substring to find)

**Output:**
- Index positions in the text where the pattern occurs, 
  displayed separately for KMP and Rabin–Karp.

--------------------------------------------------------------------

Example Input
-------------
Enter the text string: ABABDABACDABABCABAB  
Enter the pattern to search: ABABCABAB  

Example Output
--------------
--- Knuth-Morris-Pratt (KMP) Algorithm ---
Pattern found at index 10

--- Rabin-Karp (Fingerprinting) Algorithm ---
Pattern found at index 10

--------------------------------------------------------------------


Functions Used
--------------

1. **computeLPSArray(pat, M, lps)**
   - Builds the LPS array used by KMP.
   - LPS[i] stores the longest proper prefix of pat[0..i]
     which is also a suffix of pat[0..i].

2. **KMP_Search(pat, txt)**
   - Implements the main KMP search algorithm.

3. **RabinKarp_Search(pat, txt)**
   - Implements Rabin-Karp using rolling hash and modular arithmetic.

--------------------------------------------------------------------

Algorithmic Steps
-----------------
### KMP Algorithm:
1. Preprocess pattern to create the LPS array.
2. Compare pattern characters with text characters.
3. If a mismatch occurs, use the LPS array to skip redundant checks.
4. Report all indices where the pattern is found.

### Rabin–Karp Algorithm:
1. Compute hash of pattern and first window of text.
2. Slide pattern across text one character at a time:
   - Update hash using the rolling hash formula.
3. If hash matches, verify characters.
4. Report all valid match indices.

--------------------------------------------------------------------

Example Run
-----------
Input:
    Enter the text string: AABAACAADAABAABA
    Enter the pattern to search: AABA

Output:
    --- Knuth-Morris-Pratt (KMP) Algorithm ---
    Pattern found at index 0
    Pattern found at index 9
    Pattern found at index 12

    --- Rabin-Karp (Fingerprinting) Algorithm ---
    Pattern found at index 0
    Pattern found at index 9
    Pattern found at index 12

--------------------------------------------------------------------

Time and Space Complexity
-------------------------

| Algorithm     | Best / Avg Time | Worst Time | Space Complexity | Remarks |
|----------------|----------------|-------------|------------------|----------|
| KMP            | O(n + m)       | O(n + m)    | O(m)             | Very efficient, deterministic |
| Rabin–Karp     | O(n + m) avg   | O(nm) worst | O(1)             | Depends on hash collisions |

where  
n = length of text  
m = length of pattern

--------------------------------------------------------------------

Applications
------------
- Text editors and search engines
- DNA sequence pattern matching
- File comparison and plagiarism detection
- Syntax validation in compilers
- Network intrusion detection systems

--------------------------------------------------------------------

Advantages and Limitations
---------------------------

| Algorithm   | Advantages | Limitations |
|--------------|-------------|-------------|
| **KMP** | Fast and deterministic; avoids rechecking | Requires preprocessing (LPS array) |
| **Rabin–Karp** | Efficient for multiple patterns | Collisions can cause false matches |

--------------------------------------------------------------------

Sample Demonstration
--------------------
Input:
    Text: BANANA
    Pattern: ANA

Output:
    --- KMP Algorithm ---
    Pattern found at index 1
    Pattern found at index 3

    --- Rabin-Karp Algorithm ---
    Pattern found at index 1
    Pattern found at index 3

--------------------------------------------------------------------

