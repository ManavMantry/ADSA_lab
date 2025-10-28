# 🌳 Binary Search Tree (BST) Implementation in C

This project implements a **Binary Search Tree (BST)** in C with basic operations such as **Insert**, **Delete**, and **Tree Traversals** (Inorder, Preorder, and Postorder).  
The program also supports **creating a tree from multiple user inputs** and provides a menu-driven interface for easy interaction.

---

## 📘 Problem Statement

Design and implement a **menu-driven C program** to perform the following operations on a Binary Search Tree (BST):

1. **Insert** a node  
2. **Delete** a node  
3. **Display** tree elements using:
   - Inorder Traversal  
   - Preorder Traversal  
   - Postorder Traversal  
4. **Create** a tree from multiple inputs  
5. **Exit**

---

## ⚙️ Features

✅ Create a Binary Search Tree dynamically  
✅ Insert new elements maintaining BST properties  
✅ Delete nodes safely (supports all 3 cases — leaf, one child, two children)  
✅ Display elements using **Inorder**, **Preorder**, and **Postorder** traversals  
✅ Menu-based user interaction for easy testing  
✅ Efficient memory management  

---

## 🧠 Algorithm Overview

### **1️⃣ Insertion**
- If the tree is empty → create a new node.  
- If value < root → insert into the **left** subtree.  
- If value > root → insert into the **right** subtree.  

### **2️⃣ Deletion**
- Find the node to delete:
  - **Case 1:** No child → delete node directly.  
  - **Case 2:** One child → connect child to parent and delete node.  
  - **Case 3:** Two children → find **inorder successor** (smallest in right subtree), copy its value, and delete the successor.

### **3️⃣ Traversals**
- **Inorder (L, Root, R):** Displays nodes in ascending order.  
- **Preorder (Root, L, R):** Used for copying or saving the tree structure.  
- **Postorder (L, R, Root):** Used for deleting/freeing the tree.  

---

## ⏱️ Time & Space Complexity

| Operation | Average Case | Worst Case | Space Complexity |
|------------|---------------|-------------|------------------|
| Insertion  | O(log n)      | O(n)        | O(h)             |
| Deletion   | O(log n)      | O(n)        | O(h)             |
| Traversal  | O(n)          | O(n)        | O(h)             |

> **h** = height of the tree  
> The worst case occurs when the BST becomes a skewed tree (like a linked list).

---

## 💻 Sample Input and Output

### 🧮 Example Run

**Input/Output:**

    --- Binary Search Tree Operations ---
    
    Insert
    
    Delete
    
    Inorder Traversal
    
    Preorder Traversal
    
    Postorder Traversal
    
    Exit
    
    Create (build tree from multiple inputs)
    Enter your choice: 7
    Enter number of nodes: 6
    Enter 6 values:
    50 30 20 40 70 60
    Tree created successfully.
    
    Enter your choice: 3
    Inorder Traversal: 20 30 40 50 60 70
    
    Enter your choice: 2
    Enter value to delete: 30
    
    Enter your choice: 3
    Inorder Traversal: 20 40 50 60 70
    
    Enter your choice: 4
    Preorder Traversal: 50 40 20 70 60
    
    Enter your choice: 5
    Postorder Traversal: 20 40 60 70 50
    
    Enter your choice: 6
    Exiting...

