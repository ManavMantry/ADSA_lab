# 🔎 Binary vs Ternary Search Performance Comparison

This project compares the **execution time of Binary Search and Ternary Search** across different input sizes using **C** for implementation and **Python** for visualization.

---

## 📌 Features
- Implements **Binary Search** and **Ternary Search** in C.
- Benchmarks execution time per search with `clock()`.
- Stores results in a CSV file (`search_comparison.csv`).
- Uses Python (Matplotlib) to plot performance graphs.

---

## ⚙️ Algorithms Explained

### 📍 Binary Search
Binary Search works on **sorted arrays** by repeatedly dividing the search interval into halves.

#### Steps:
1. Start with two pointers: `low = 0`, `high = n-1`.
2. Find the middle index:  
   `mid = (low + high) / 2`
3. Compare:
   - If `arr[mid] == key`, return `mid`.
   - If `arr[mid] < key`, search in the **right half** (`low = mid + 1`).
   - If `arr[mid] > key`, search in the **left half** (`high = mid - 1`).
4. Repeat until `low > high`.  
   If not found, return `-1`.


#### Time Complexity:
- **Best Case:** O(1) (key found at mid in first step)  
- **Worst Case:** O(log₂ n)  
- **Space Complexity:** O(1) (iterative)

---

### 📍 Ternary Search
Ternary Search also works on **sorted arrays**, but divides the array into **three parts** instead of two.

#### Steps:
1. Start with `low = 0`, `high = n-1`.
2. Find two midpoints:  
   `mid1 = low + (high - low) / 3`  
   `mid2 = high - (high - low) / 3`
3. Compare:
   - If `arr[mid1] == key`, return `mid1`.
   - If `arr[mid2] == key`, return `mid2`.
   - If `key < arr[mid1]`, search in the **first third** (`high = mid1 - 1`).
   - If `key > arr[mid2]`, search in the **last third** (`low = mid2 + 1`).
   - Otherwise, search in the **middle third** (`low = mid1 + 1`, `high = mid2 - 1`).
4. Repeat until `low > high`.  
   If not found, return `-1`.


#### Time Complexity:
- **Best Case:** O(1)  
- **Worst Case:** O(log₃ n) (log base 3)  
- **Space Complexity:** O(1) (iterative)  

⚠️ Although `log₃ n < log₂ n`, Ternary Search performs **two comparisons per step** instead of one.  
This increases the constant factor, making it **slower in practice** than Binary Search.

---

## 📂 Project Structure
├── search_comparison.c # C code for benchmarking

├── plot_results.py # Python script for graph

├── search_comparison.csv # Generated results

└── README.md # Documentation

---

## 🚀 How to Run

1️⃣ Compile and Run C Code

    Lab01-2_Ternary&Binary.exe


This will generate search_comparison.csv.

2️⃣ Run Python Script
    
    python plotcompare.py


This will open a plot comparing Binary and Ternary search runtimes.

---

## 📊 Example Graph

(after running plotcompare.py)

<img width="1920" height="1020" alt="image" src="https://github.com/user-attachments/assets/4d83a948-cabb-4f85-b66f-adf19db25b8e" />


---

## 📈 Observations And Expected Result

Binary Search consistently performs better than Ternary Search, even though both are logarithmic.
Confirms that while both are logarithmic, Binary Search requires fewer comparisons per step.
Ternary Search requires more comparisons per step, which leads to higher constant factors.

Confirms the theoretical result: Binary Search is faster in practice.

