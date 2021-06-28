# Striver SDE sheet solution approaches.

##### Only the **best** (sometimes **optimal**) solution would be included.

| Arrays (Day 1)                                                        | Arrays (Day 2)  |
| --------------------------------------------------------------------- | --------------- |
| [Sort an arrray of 0s, 1s and 2s](#1-sort-an-array-of-0s-1s-and-2s)   | [Set matrix zeroes](#7-set-matrix-zeroes) |
| [Find repeat and missing number](#2-find-missing-and-repeat-number)   |
| [Merge without extra space](#3-merge-without-extra-space)             |
| [Kadane's algorithm](#4-kadanes-algorithm)                            |
| [Merge overlapping intervals](#5-merge-overlapping-intervals)         |
| [Find duplicates in array of n+1 elements](#6-find-duplicates-in-array-of-n1-elements)         |

### 1. Sort an array of 0s, 1s and 2s.
- Basic idea is to take 3 indices: **lo** = **0**, **mid** = **0** and **hi** = **n-1**.
- All elements from **[0 ... lo]** will be **0**.
- All elements from **[hi ... n-1]** will be **2**.
- At each iteration you compare the **mid** element.

### 2. Find missing and repeat number.
- The properties of xor are used-
  - **x ^ x = 0**.
  - **0 ^ x = x**.
- Let **A = [5, 1, 2, 2, 3]**.
- Take xor of whole array.
- Take xor of nums from **1 to n**.
- (5 ^ 1 ^ 2 ^ 2 ^ 3) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5) = **2 ^ 4** = **6**.
  - Which is of the form x ^ y.
  - One of them is the missing num and the other is repeating.
- We group the array elements into **2** groups-
  - 1st group: MSB of **A[i]** and resultant xor is **set**.
    - [5].
  - 2nd group: MSB of **A[i]** and resultant xor is **not set**.
    - [1, 2, 2, 3].
- We do the same thing for nums from 1 to n-
  - 1st group: [5] | [4, 5].
  - 2nd group: [1, 2, 2, 3] | [1, 2, 3].
- When we take the xor-
  - 1st group: (5) ^ (4 ^ 5) = **4**.
  - 2nd group: (1 ^ 2 ^ 2 ^ 3) ^ (1 ^ 2 ^ 3) = **2**.

### 3. Merge without extra space.
##### It is a modified version of shell sort a.k.a. the gap method:
- We take the first gap as, gap = ceil((m+n)/2).
- The next gap will be gap = ceil(gap/2) till the gap > 0.
- For each iteration of gap, we swap if the before element is bigger than the later element.
![The gap method](https://miro.medium.com/max/875/1*hbI5zUOcHIKjqprp4eHPqw.png)
- Few cases arises to find which array the left index (lets say 'i') and the right index (lets say 'j') will belong to [please, refer to code for detailed explanation]:
  - Both i and j belong to array 1.
  - i belong to array 1 and j belong to array 2.
  - Both i and j belong to array 2.

### 4. Kadane's algorithm.
- Finding the maximum sum sub-array.
- Basic idea is to keep summing the array elements till and taking the maximum among them and whenever the sum becomes negative we make it 0.
- Lets say at an index i the sum is negative, it means that the result upto i is **not any good** because even if there is a positive element after i the total sum will still be less than if we would've considered **only** the next element. If the next element is negative (or 0), adding it to a negative sum will give more negative result. Hence, we make the sum as 0.
- We initialize the result as a minimum value because if **all the numbers were negative**, then the result would be the **least negative** value which is how the algorithm is designed to produce.

### 5. Merge overlapping intervals.
- Make sure to **sort** the intervals.
- The basic idea is to compare the **end** of the last interval in result to the **start** of the ith interval. 
- Push the first interval into result.
- Now, for the next intervals there are few cases:
![](/Arrays1/merge-intervals.png)
- In the first case, you **skip** the interval as it completely lies inside.
- In the second case, you change the **end** of the last interval in result to the **end** of the current interval.
- In the third case, you push the **current** interval in the result.

### 6. Find duplicates in array of n+1 elements.
- All you need to know:
  - https://leetcode.com/problems/find-the-duplicate-number/solution/

### 7. Set matrix zeroes.
- Basic idea is to traverse the whole matrix and lets say the a[i][j] is 0:
  - We keep track of row i by marking the a[0][i] as 0.
  - We keep track of column j by marking the a[i][0] as 0.
![](/Arrays2/set-matrix-zeroes.png)
- Now, there is an edge case (this edge case can be vice-versa):
  - Suppose there is a 0 in the first row but there are no 0s in the first column.
  - In this case we would mark a[0][0] as 0 which in turn would mark the entire first column as 0 which is wrong.
  - To prevent that, we would only use a[0][0] to mark for the first row and we keep another boolean variable to mark if there are any zeroes in the first column.
- Then, we traverse from the end and we mark an element a[i][j] as 0 if a[0][j] == 0 or a[i][0] is 0 and we carefully mark the 0th column only if the boolean is false.