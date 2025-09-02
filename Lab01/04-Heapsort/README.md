Problem Statement: Heap Sort

Design and implement a program in C to sort a given list of n elements using the Heap Sort algorithm.

The program should:

      1.Take the number of elements n as input from the user.
      
      2.Accept n integers as input elements.
      
      3.Sort the elements in ascending order using the Heap Sort algorithm.
      
      4.Display the array before sorting and after sorting.

----------------------------------------------------------------------------------
Heap Sort Algorithm

Input:

    An array A of size n.

Output:

    Sorted array in ascending order.

Steps

Build Max Heap:

     Rearrange the array elements to form a max heap (largest element at root).

     Start heapifying from the last non-leaf node down to the root.

Repeat until the heap size is greater than 1:

     Swap the root element (A[0], largest) with the last element in the heap.

     Reduce the heap size by 1.



Call heapify on the root to restore the max heap property.

Heapify Procedure (for node i in heap of size n)

     Set largest = i.

     Find left child = 2*i + 1, right child = 2*i + 2.

     If left child exists and A[left] > A[largest], set largest = left.
    
     If right child exists and A[right] > A[largest], set largest = right.
     
     If largest != i, swap A[i] and A[largest], and recursively heapify largest.

Time Complexity

     Building heap: O(n)
    
     Each extraction + heapify: O(log n)
    
     Total: O(n log n)

-------------------------------------------------------------------------------------
OUTPUT 1:
    
     Enter number of elements: 7
     Enter 7 elements:
     12 14 1 123 9 01 0
     Original array: 12 14 1 123 9 1 0 
     Sorted array:   0 1 1 9 12 14 123 

OUTPUT 2:

     Enter number of elements: 5
     Enter 5 elements:
     1 3 4 6 7 
     Original array: 1 3 4 6 7 
     Sorted array:   1 3 4 6 7

OUTPUT 3:

     Enter number of elements: 8
     Enter 8 elements:
     13 456 143 12 45 81 12 4 
     Original array: 13 456 143 12 45 81 12 4 
     Sorted array:   4 12 12 13 45 81 143 456
