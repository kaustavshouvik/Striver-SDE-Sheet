# Striver SDE sheet solution approaches.

##### Only the **best** (sometimes **optimal**) solution would be included.

### 1. Sort an array of 0s, 1s and 2s.
- Basic idea is to take 3 indices: **lo** = **0**, **mid** = **0** and **hi** = **n-1**.
- All elements from **[0 ... low]** will be **0**.
- All elements from **[hi ... n-1]** will be **2**.
- At each iteration you compare the **mid** element.