Problem Statement:

There are n coins.
n−1 coins are perfectly identical in weight.
At most one coin may be lighter (defective).
You must identify the defective coin (if any) using a balance scale.


Algorithm Idea — Divide & Conquer:

1. This is like a binary search:
2. Divide the coins into two equal groups.
3. Weigh the groups:
4. If equal → defective coin (if it exists) must be in the leftover coin (when n is odd).
5. If left side lighter → defective is in left group.
6. If right side lighter → defective is in right group.
7. Recurse only into the lighter group.

Base cases:

If only 1 coin → it’s the defective one.
If 2 coins → compare them directly.
This reduces the search space by half each time → complexity O(log₂ n).

______________________________________________________________________________________________

OUTPUT 1:

Enter number of coins: 7
Enter weights of coins:
10 10 10 4 10 10 10
Defective coin found at no. 4 (0-based), weight = 4

OUTPUT 2:

Enter number of coins: 8
Enter weights of coins:
2 2 2 2 2 2 2 2
All coins are of equal weight. No defective coin.

OUTPUT 3:

Enter number of coins: 1
Enter weights of coins:
1
Defective coin found at no. 1 (0-based), weight = 1
