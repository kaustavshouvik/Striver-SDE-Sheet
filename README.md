# Striver SDE sheet solution approaches.

##### Only the **best** (sometimes **optimal**) solution would be included.

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