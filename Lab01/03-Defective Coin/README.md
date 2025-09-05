# 🪙 Defective Coin Detection 

This project implements a **divide-and-conquer algorithm** in C to detect a **defective coin** (lighter coin) among a set of coins.  

The program simulates a balance weighing method and recursively finds the defective coin with minimal comparisons.

---

## 🚀 Features
- Implements **divide-and-conquer strategy**.
- Finds the **lighter (defective) coin** efficiently.
- Handles cases with:
  - One coin
  - Two coins
  - Odd and even numbers of coins
- Reports if **all coins are of equal weight** (no defective coin).

---

## 📚 Algorithm 

1. Start with `n` coins.
2. If only one coin → it is defective.
3. If two coins → return the lighter one (if unequal).
4. Otherwise:
   - Split coins into two halves.
   - Weigh both halves.
   - If equal → check extra coin (if any).
   - If unequal → recurse into the lighter half.
5. Continue until the defective coin is found.
6. Print result (index and weight or "no defective coin").


---

## 📂 Files
- `defective_coin.c` → Main source code.
- `README.md` → Project documentation.

---

## 🛠️ How to Compile & Run
### Compile
```bash
Lab01-3_DefectiveCoin.exe
```
---
## 📥 Input Format

Enter the number of coins (n).

Enter the weights of the coins separated by spaces.

## 📤 Output Format

If a defective coin is found:
    
    Defective coin found at index X (0-based), weight = W


If all coins are equal:

    All coins are of equal weight. No defective coin.
---

## 🧾 Example

    Enter number of coins: 8
    Enter weights of coins:
    7 7 7 7 7 6 7 7
    Defective coin found at no. 6 (0-based), weight = 6
