# Problems
## Problem 2-2: Correctness of bubblesort
### a)
To show that the algorithm actually sorts, we should also prove that the elements of the A' are the same elements of A, but permutated. If  the input A was [3, 1, 2] and the output was [5, 6, 7], that would satisfy (2.5) and the algorihtm would be correct, but the elements of A' wouldn't be the elements of A sorted.

### c)
#### Initialization
After the initialization, prior to the loop, no portion of the array A is considered (empty array), and this empty array contains 0 elements of A sorted.

#### Maintainance
i is initilized with 1, and j is initialized with n. For i=1, the inner loop will iterate over A decrementing j, moving the smallest element from the right side until it reaches A[1]. The next iteration will set A[2] (using i) with the second smallest element in A[1:n], or the smallest element in A[2:n]. After each iteration of the outter loop (using i) finished, the array A'[1:i] contains the i elements of A sorted.

#### Termination
The main loop finished when i reaches n - 1. At this point, the inner loop will compare the elements A[n-1] and A[n] (the last elements of A), and swap them if A[n] is bigger than A[n-1]. This guarantees the loop stops and A'[1:n] is sorted.

### d)
The presented Bubblesort has no differentiation between worst, average and best case. The termination conditions in the inner and outter loops are always the same, no matter if the array is sorted, shuffled, or sorted in reverse order. This is also what makes this algorithm inefficient. The worst and best case complexity is always O(n^2).