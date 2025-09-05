# ⚙️ Heap Sort in C

This project implements the **Heap Sort algorithm** in C.  
Heap Sort is a **comparison-based sorting technique** based on a **binary heap data structure**.  
It works by first building a **max heap** and then repeatedly extracting the maximum element to sort the array.

---

## 🚀 Features
- Implementation of **Heap Sort** in C.
- Uses **max heap** to sort in ascending order.
- Handles user input for array size and elements.
- Prints both the **original array** and the **sorted array**.

---

## 📚 Algorithm: Heap Sort

1. **Start**
2. Input number of elements `n` and the array.
3. **Build a max heap**:
   - For each non-leaf node from `n/2 - 1` down to `0`, call `heapify`.
4. **Heap sort process**:
   - Swap the root element (largest) with the last element.
   - Reduce the heap size by 1.
   - Call `heapify` on the root to maintain max heap property.
   - Repeat until the heap size is 1.
5. The array is now sorted in ascending order.
6. **End**


---

## 🛠️ How to Compile & Run
### Compile
```bash
Lab01-4_Heapsort.exe
```
## 📥 Input Format

Enter the number of elements (n).

Enter n integers (array elements).

## 📤 Output Format

Prints the original array.

Prints the sorted array after applying heap sort.

---

## 🧾 Example

      Enter number of elements: 6
      Enter 6 elements:
      12 11 13 5 6 7
      Original array: 12 11 13 5 6 7 
      Sorted array:   5 6 7 11 12 13
