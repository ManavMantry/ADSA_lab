import csv
import matplotlib.pyplot as plt

x = []
binary = []
ternary = []

with open("search_comparison.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        x.append(int(row["n"]))  # <-- use "n" instead of "ArraySize"
        binary.append(float(row["Binary"]))
        ternary.append(float(row["Ternary"]))

plt.plot(x, binary, label="Binary Search", marker='o')
plt.plot(x, ternary, label="Ternary Search", marker='s')
plt.xlabel("Array Size (n)")
plt.ylabel("Average Time per Search (seconds)")
plt.title("Binary vs Ternary Search Comparison")
plt.legend()
plt.grid(True)
plt.show()
