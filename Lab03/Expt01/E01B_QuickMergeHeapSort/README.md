# ⚡ Sorting Algorithms in C (Quick Sort, Merge Sort, Heap Sort)

This project demonstrates three popular **sorting algorithms** — **Quick Sort**, **Merge Sort**, and **Heap Sort** — implemented in **C language**.  
It allows users to input an array of integers and choose which sorting algorithm to apply.

---

## 📘 Problem Statement

Write a C program that:
1. Accepts `n` integers from the user.
2. Allows the user to choose one of the following sorting methods:
   - Quick Sort  
   - Merge Sort  
   - Heap Sort
3. Displays the sorted array as output.

---

## ⚙️ Features

- Implements **three efficient sorting algorithms**
- Dynamic choice for sorting method at runtime
- Clear user input and output format
- Simple and modular C code with separate functions for each algorithm

---

## 🧠 Algorithms Overview

### **1️⃣ Quick Sort**
- Divide-and-conquer approach
- Selects a **pivot element**
- Partitions the array into elements **less than** and **greater than** the pivot
- Recursively sorts both partitions  
**Time Complexity:** O(n log n) average, O(n²) worst  
**Space Complexity:** O(log n)

### **2️⃣ Merge Sort**
- Recursively divides array into halves
- Merges sorted halves  
**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

### **3️⃣ Heap Sort**
- Builds a **max heap**
- Repeatedly extracts the maximum element
- Reheapifies the remaining array  
**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

---

## ⏱️ Time & Space Complexity Summary

| Algorithm   | Best Case | Average Case | Worst Case | Space Complexity |
|--------------|------------|----------------|----------------|------------------|
| Quick Sort   | O(n log n) | O(n log n)     | O(n²)         | O(log n) |
| Merge Sort   | O(n log n) | O(n log n)     | O(n log n)    | O(n) |
| Heap Sort    | O(n log n) | O(n log n)     | O(n log n)    | O(1) |

---

## 💻 Sample Input and Output

### 🧮 Example 1 — Quick Sort

**Input:**

    Enter number of elements: 5
    Enter 5 integers:
    8 3 1 7 2
    
    Choose Sorting Method:
    
    Quick Sort
    
    Merge Sort
    
    Heap Sort
    1


**Output:**

    Sorted array using Quick Sort:
    1 2 3 7 8
