# ⚡ Quick Sort in C (with Median-of-Three Pivot and Insertion Sort Optimization)

This project implements an **optimized Quick Sort algorithm** in C using the **Median-of-Three** method for pivot selection and **Insertion Sort** for small subarrays.  
This hybrid approach improves performance and stability on partially sorted or small datasets.

---

## 📘 Problem Statement

Write a C program that sorts an array of integers using **Quick Sort** with the **Median-of-Three pivot selection strategy**.  
When the size of the subarray becomes small (≤ 10 elements), switch to **Insertion Sort** for efficiency.

---

## ⚙️ Features

- Uses **Median-of-Three** to select a better pivot and reduce the chance of worst-case O(n²)
- Switches to **Insertion Sort** for small subarrays to improve efficiency
- Handles any integer input array
- Clean and modular implementation

---

## 🧠 Algorithm Overview

### **Quick Sort with Median-of-Three**
1. Choose the **first**, **middle**, and **last** elements.
2. Find the **median** of these three as the **pivot**.
3. Partition the array such that:
   - Elements smaller than pivot are on the left.
   - Elements larger than pivot are on the right.
4. Recursively sort both subarrays.

### **Insertion Sort (for small partitions)**
- Used when subarray size ≤ 10.
- Efficient for small datasets since it has low overhead.

---

## ⏱️ Time & Space Complexity

| Case | Time Complexity | Description |
|------|------------------|-------------|
| Best Case | O(n log n) | Well-balanced partitions |
| Average Case | O(n log n) | Typical case |
| Worst Case | O(n²) | Highly unbalanced partitions (rare due to median pivot) |
| Space Complexity | O(log n) | Due to recursion stack |

---

## 💻 Sample Input and Output

### 🧮 Example 1

**Input:**

    Enter number of elements: 7
    Enter 7 integers:
    34 7 23 32 5 62 32

**Output:**

    Sorted array using Quick Sort (Median-of-Three Pivot):
    5 7 23 32 32 34 62
