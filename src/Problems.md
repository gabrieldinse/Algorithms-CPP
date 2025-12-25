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

## Problem 2-3: Correctness of Horner’s rule
### a)
It's O(n).

### b)
It would be O(n^2), because an additional loop would be needed to compute the power of x, i times.

### c)


## Problem 2-4: Inversions
### a)
(1, 5), (2, 5), (3, 5), (4, 5), (3, 4)

### b)
The array with the elements sorted in decreasing order. In this scenario, every pair of elements in the array (where i < j) are an inversion.
(3, 2, 1) = 3
(4, 3, 2, 1) = 6
(5, 4, 3, 2, 1) = 10

This is the same as "choosing 2 from n" combination formula:
n! / 2!(n - 2)!
= n(n - 1)(n - 2)! / 2!(n - 2)!
= n(n - 1) / 2

### c)
Insertion sort works by moving elements to the left until they reach reach the correct position, making the initial portion of the array sorted. In this sorted portion of the array, there are no invertions.
This shift in positions actually targets two elements that are out of position, and each time adjacent elements are swapped, the number of inversions is reduced by 1. The algorithm continues executing until zero inversions are left. A sorted array has zero inversions.
