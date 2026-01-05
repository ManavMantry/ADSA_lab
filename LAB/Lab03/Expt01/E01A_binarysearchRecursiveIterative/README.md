
# 🔍 Binary Search in C (Recursive & Iterative)

This project demonstrates **Binary Search** implementation in C using both **Recursive** and **Iterative** approaches.  
Binary Search is an efficient algorithm for finding a target value within a **sorted array**, reducing the time complexity to **O(log n)**.

---

## 📘 Problem Statement

Write a program in C to perform **Binary Search** on a sorted array of integers using:
1. **Recursive approach**
2. **Iterative approach**

The user can choose which method to use at runtime.

---

## ⚙️ Features

- Accepts sorted integer array input from user  
- Provides choice between **Recursive** and **Iterative** binary search  
- Displays the result (index position of key if found)  
- Handles cases where the key is **not found**

---

## 🧠 Algorithm

### **1. Recursive Binary Search**
1. Calculate the middle index:  
   `mid = left + (right - left) / 2`
2. If `arr[mid] == key`, return `mid`
3. If `arr[mid] > key`, search the **left half**
4. Else, search the **right half**
5. Repeat until the element is found or the range becomes invalid

### **2. Iterative Binary Search**
1. Initialize `left = 0`, `right = n - 1`
2. While `left <= right`:  
   - Compute `mid = left + (right - left) / 2`
   - If `arr[mid] == key`, return `mid`
   - If `arr[mid] > key`, move `right = mid - 1`
   - Else, move `left = mid + 1`
3. If not found, return `-1`

---

## ⏱️ Time & Space Complexity

| Approach | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Recursive | O(log n) | O(log n) (due to recursion stack) |
| Iterative | O(log n) | O(1) |

---

## 🧩 Sample Input/Output

**Input:**

      Enter number of elements: 5
      Enter 5 sorted integers:
      2 4 6 8 10
      Enter key to search: 6
      
      Choose Search Method:
      
      1. Recursive Binary Search
      
      2. Iterative Binary Search
      1

**Output:**

      Key 6 found at position 2 (0-based index).


---






