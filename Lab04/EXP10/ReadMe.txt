Strassen Matrix Multiplication
==============================

This program implements **Strassen’s Algorithm** for multiplying two square matrices.
It divides matrices recursively to reduce the number of multiplications and improve performance
compared to the standard O(n³) matrix multiplication.


-----------------------------------
Input Format
-----------------------------------
1. Enter the matrix size (must be a power of 2, e.g., 2, 4, 8).
2. Enter elements of Matrix A (row by row).
3. Enter elements of Matrix B (row by row).

Example Input:
----------------
Enter the size of the square matrices (power of 2, e.g., 2, 4, 8): 2
Enter elements of Matrix A:
1 2
3 4
Enter elements of Matrix B:
5 6
7 8

Example Output:
----------------
Resultant Matrix after Strassen Multiplication:
   19   22
   43   50

-----------------------------------
Explanation:
-----------------------------------
Matrix A =
[1 2]
[3 4]

Matrix B =
[5 6]
[7 8]

A × B =
[19 22]
[43 50]

-----------------------------------
Algorithm Details
-----------------------------------
Strassen’s Algorithm divides each matrix into 4 submatrices of size (n/2 × n/2)
and performs 7 recursive multiplications instead of 8 (as in normal matrix multiplication).

The 7 computed products (M1 to M7) are combined to form the resulting matrix.

-----------------------------------
Time Complexity
-----------------------------------
- Standard Matrix Multiplication: O(n³)
- Strassen’s Algorithm: O(n^(log₂7)) ≈ O(n^2.81)

This results in better performance for large matrices (especially when n ≥ 8).

-----------------------------------
Constraints and Notes
-----------------------------------
- n must be a power of 2 (2, 4, 8, 16, etc.).
- Maximum supported size (as per code): 10 × 10.
- All matrix elements should be integers.
- For non-power-of-2 matrix sizes, padding with zeros can be added (not implemented here).

-----------------------------------
Sample Test
-----------------------------------
Input:
4
1 2 3 4
5 6 7 8
9 1 2 3
4 5 6 7
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4

Output:
Resultant Matrix after Strassen Multiplication:
   30   30   30   30
   70   70   70   70
   21   21   21   21
   63   63   63   63

-----------------------------------
