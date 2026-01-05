# Pattern Matching Algorithms  
## Knuth–Morris–Pratt (KMP) and Boyer–Moore (BM)

This repository contains a detailed study and implementation of two classic **string pattern matching algorithms**:  
- **Knuth–Morris–Pratt (KMP) Algorithm**  
- **Boyer–Moore (BM) Algorithm**

These algorithms are fundamental in computer science and are widely used in text processing, compilers, bioinformatics, and search engines.

---

## 📌 Project Overview

Given a **text string** `T` and a **pattern string** `P`, the goal of pattern matching is to find all occurrences of `P` within `T` efficiently.

The naive approach has a worst-case time complexity of **O(n × m)**.  
This project demonstrates how **KMP** and **Boyer–Moore** improve performance using preprocessing techniques.

---

## 🚀 Algorithms Covered

### 1️⃣ Knuth–Morris–Pratt (KMP)

**Core Idea**  
KMP avoids redundant comparisons by using information from previous matches.

**Key Concept**
- Uses **LPS (Longest Proper Prefix which is also Suffix)** array
- Never moves the text pointer backward

**Time Complexity**
- Preprocessing: `O(m)`
- Searching: `O(n)`
- Overall: **O(n + m)**

**Best Used When**
- Small alphabets
- Streaming or real-time text processing

---

### 2️⃣ Boyer–Moore (BM)

**Core Idea**  
Boyer–Moore matches the pattern **from right to left** and skips sections of text intelligently.

**Heuristics Used**
- **Bad Character Rule**
- **Good Suffix Rule**

**Time Complexity**
- Best Case: `O(n / m)`
- Worst Case: `O(n)`
- Average Case: Sub-linear

**Best Used When**
- Large alphabets
- Natural language text
- Large documents

---

## 📊 Comparison

| Feature | KMP | Boyer–Moore |
|------|------|-------------|
| Matching Direction | Left → Right | Right → Left |
| Preprocessing | LPS Table | Bad Char + Good Suffix |
| Worst Case | O(n) | O(n) |
| Best Case | O(n) | O(n/m) |
| Practical Speed | Moderate | Very Fast |

---

## 🛠️ Implementation

- Language: **C / C++** (can be extended)
- Input:
  - Text string
  - Pattern string
- Output:
  - All matching indices of the pattern in the text

---

## 📚 Applications

- Text editors (Find / Replace)
- Plagiarism detection
- DNA sequence matching
- Network intrusion detection
- Search engines

---

## 📄 References

1. T. H. Cormen et al., *Introduction to Algorithms*, MIT Press  
2. D. E. Knuth, J. H. Morris, V. R. Pratt, *Fast Pattern Matching in Strings*  
3. R. S. Boyer, J. S. Moore, *A Fast String Searching Algorithm*  
4. D. Gusfield, *Algorithms on Strings, Trees, and Sequences*

---

## 👨‍💻 Presented By

- **Raag Arya**  
- **Manav Mantry**  
- **Priyanshu Mishra**  

Department of Computer Science  
**IIIT Bhubaneswar**

---

## ⭐ Conclusion

Both KMP and Boyer–Moore significantly outperform naive string matching by using preprocessing and intelligent shifts.  
Choosing the right algorithm depends on the **alphabet size**, **input characteristics**, and **application requirements**.


