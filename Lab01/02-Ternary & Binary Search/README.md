Concept of Ternary Search :

Binary search: divides the array into 2 halves each time.
Ternary search: divides the array into 3 nearly equal parts each time.

At each step in ternary search:

Find two mid points:
𝑚𝑖𝑑1=𝑙+(𝑟−𝑙)/3
mid1=l+(r−l)/3
𝑚𝑖𝑑2=𝑟−(𝑟−𝑙)/3
mid2=r−(r−l)/3

Compare x with arr[mid1] and arr[mid2].
If x == arr[mid1] or x == arr[mid2] → found.
If x < arr[mid1] → search left segment.
If x > arr[mid2] → search right segment.
Otherwise → search middle segment.


Complexity Analysis:

Binary Search

At each step, the array is divided into 2 parts.
T(n) = T(n/2) + O(1) 
By Master Theorem / recurrence solving:
T(n) = O(log₂ n)


Ternary Search

At each step, the array is divided into 3 parts.
T(n) = T(n/3) + O(1)
So,
T(n) = O(log₃ n)


Converting to same base

Using the base-change rule:
log₃ n = (log₂ n) / (log₂ 3)
Since
log₂ 3 ≈ 1.585
we get:
O(log₃ n) = O((1 / 1.585) * log₂ n)

__________________________________________________________________________

Approach :

A loop systematically increases array size from 1000 to 200000,
builds a sorted array for each size, and records how long both search algorithms take.
The result is a dataset that can graph to see which algorithm is faster.

Program Explanation

The main() function runs an experiment:

1.CSV file output creates search_comparison.csv with columns:
2.ArraySize, BinaryTime(ms), TernaryTime(ms)
3.Loop over different array sizes (1000 → 100000)
4.Creates a sorted array [1, 2, 3, …, n].
5.Search target = last element (worst case)
6.Both algorithms traverse all recursion/iteration levels.
7.Measure execution time Using clock() function from <time.h>.
8.Records how long each search takes in milliseconds.
8.Store results
9.Writes timings into CSV → which can be plotted later in Python.


Key Findings :

Binary Search: O(log₂ n) comparisons.
Ternary Search: O(log₃ n) levels, but each level requires 2 comparisons instead of 1.
Therefore, Binary Search is faster in practice, even though log₃ n < log₂ n, because ternary search doubles the comparisons per step.
But the OUTPUTS says otherwise due to some internal optimisations.

__________________________________________________________________________

OUTPUT 1:

n=1000 | Binary=0.0000000400 | Ternary=0.0000000300
n=5000 | Binary=0.0000000600 | Ternary=0.0000000500
n=10000 | Binary=0.0000000700 | Ternary=0.0000000500
n=50000 | Binary=0.0000000900 | Ternary=0.0000000600
n=100000 | Binary=0.0000000900 | Ternary=0.0000000600
n=200000 | Binary=0.0000000900 | Ternary=0.0000000700
Results saved to search_comparison.csv

OUTPUT 2:

n=1000 | Binary=0.0000000500 | Ternary=0.0000000400
n=5000 | Binary=0.0000000700 | Ternary=0.0000000500
n=10000 | Binary=0.0000000800 | Ternary=0.0000000700
n=50000 | Binary=0.0000000900 | Ternary=0.0000000700
n=100000 | Binary=0.0000000900 | Ternary=0.0000000700
n=200000 | Binary=0.0000001000 | Ternary=0.0000000700
Results saved to search_comparison.csv

OUTPUT 3:

n=1000 | Binary=0.0000000500 | Ternary=0.0000000300
n=5000 | Binary=0.0000000500 | Ternary=0.0000000400
n=10000 | Binary=0.0000000600 | Ternary=0.0000000600
n=50000 | Binary=0.0000000800 | Ternary=0.0000000600
n=100000 | Binary=0.0000000700 | Ternary=0.0000000700
n=200000 | Binary=0.0000000800 | Ternary=0.0000000500
Results saved to search_comparison.csv
