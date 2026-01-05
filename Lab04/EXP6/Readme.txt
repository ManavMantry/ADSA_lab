README — Minimum Spanning Tree using Prim’s and Kruskal’s Algorithms
====================================================================

Program Overview
----------------
This C program finds the Minimum Spanning Tree (MST) of a connected, 
weighted, undirected graph using two algorithms:
1. Prim’s Algorithm
2. Kruskal’s Algorithm

Both algorithms generate the MST with the same minimum cost but use 
different strategies:
- Prim’s grows the MST vertex by vertex.
- Kruskal’s grows the MST edge by edge while avoiding cycles.


Input Format
-------------
The program accepts input in Simple Interaction Format (SIF).

Each edge is entered as:
<Source Vertex> <Destination Vertex> <Weight>

Vertices are labeled as A, B, C, D, ...
Enter -1 -1 -1 to stop entering edges.


Example Input
--------------
Enter number of vertices: 5
Enter edges in SIF format (u v w), enter -1 -1 -1 to stop:
A B 2
A C 3
B C 1
B D 4
C D 5
C E 6
D E 7
-1 -1 -1


Example Output
---------------
Edges in MST using Prim’s Algorithm:
B - C : 1
A - B : 2
B - D : 4
C - E : 6
Total cost of MST (Prim’s): 13

Edges in MST using Kruskal’s Algorithm:
B - C : 1
A - B : 2
B - D : 4
C - E : 6
Total cost of MST (Kruskal’s): 13




Time Complexity
----------------
Algorithm        Time Complexity     Explanation
-----------------------------------------------------------
Prim’s Algorithm    O(V²)            For each vertex, all edges are scanned.
Kruskal’s Algorithm O(E log E)       Sorting edges dominates; union-find is fast.

Where:
V = number of vertices
E = number of edges


Space Complexity
-----------------
Algorithm        Space Complexity    Explanation
-----------------------------------------------------------
Prim’s Algorithm    O(V²)            Uses adjacency matrix.
Kruskal’s Algorithm O(E)             Stores edge list and parent array.


Algorithm Notes
----------------
- Prim’s is efficient for dense graphs (many edges).
- Kruskal’s is efficient for sparse graphs (few edges).
- Both produce the same MST if edge weights are unique.


Output Interpretation
----------------------
Each line printed (e.g., "A - B : 2") represents an edge 
included in the MST with its weight. The total cost shown 
at the end is the sum of all selected MST edges.

====================================================================
