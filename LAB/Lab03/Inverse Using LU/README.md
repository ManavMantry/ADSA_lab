
# Matrix Inversion Using LU Decomposition (C)

This repository contains a **C implementation of matrix inversion using LU Decomposition**.  
The program decomposes a square matrix **A** into **Lower (L)** and **Upper (U)** triangular matrices and computes the inverse using forward and backward substitution.

---

## Features

- Accepts user input for matrix size and elements
- Performs LU Decomposition without pivoting
- Computes inverse of a square matrix
- Displays:
  - Original matrix
  - Lower triangular matrix (L)
  - Upper triangular matrix (U)
  - Inverse matrix
- Implemented using standard C (no external libraries)

---

## Algorithm Description

1. Read square matrix **A (n × n)**
2. Perform LU Decomposition such that  
   **A = L × U**
3. Solve the system  
   **A X = I**  
   using:
   - Forward substitution: **L Y = I**
   - Backward substitution: **U X = Y**
4. The resulting matrix **X** is the inverse of **A**

---

## Compilation and Execution

### Compile

gcc Inverse_LU.c -o inverse_lu


### Run

./inverse_lu


---

## Input Format

- First line contains an integer **n**, the order of the square matrix  
- Next **n × n** values represent the elements of matrix **A**

### Sample Input
    3
    2 1 1
    1 3 2
    1 0 0


---

## Output Format

- Displays the **Lower Triangular Matrix (L)**
- Displays the **Upper Triangular Matrix (U)**
- Displays the **Inverse of the given matrix**

### Sample Output

    Lower Triangular Matrix (L):
    1.00 0.00 0.00
    0.50 1.00 0.00
    0.50 -0.20 1.00
    
    Upper Triangular Matrix (U):
    2.00 1.00 1.00
    0.00 2.50 1.50
    0.00 0.00 -0.20
    
    Inverse Matrix:
    0.00 0.00 1.00
    -2.00 1.00 3.00
    3.00 -1.00 -5.00
---

## Time Complexity

Let **n** be the order of the matrix.

- LU Decomposition: **O(n³)**
- Forward Substitution: **O(n³)**
- Backward Substitution: **O(n³)**

**Total Time Complexity: O(n³)**

---

## Space Complexity

- L matrix: **O(n²)**
- U matrix: **O(n²)**
- Inverse matrix: **O(n²)**

**Total Space Complexity: O(n²)**

---

## Limitations

- No partial pivoting (may be numerically unstable)
- Works only for non-singular square matrices
- Floating-point precision issues for large matrices

---



⭐ If you find this project useful, consider starring the repository!

