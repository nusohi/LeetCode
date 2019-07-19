# 4. 寻找两个有序数组的中位数 | Median of Two Sorted Arrays

**题目:**

给定两个大小为 *m* 和 *n* 的有序数组 `nums1` 和 `nums2`。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 **O(log(m + n))**。

你可以假设 `nums1` 和 `nums2` 不会同时为空。

**示例:**

```
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```

## 思路

### 解法一

第一个想到的是将两个数组合并，再排序，而且本身就是两个**有序**数组，就相当于归并排序的最后一步，只不过两个数组长度不定。

排序后的数组用 `vector` 来存储，执行时间 ***28ms***。

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int a = 0, b = 0;

    for (; a < nums1.size() && b < nums2.size();) {
        if (nums1[a] < nums2[b])
            res.push_back(nums1[a++]);
        else
            res.push_back(nums2[b++]);
    }

    while (a < nums1.size()) {
        res.push_back(nums1[a++]);
    }
    while (b < nums2.size()) {
        res.push_back(nums2[b++]);
    }

    int size_2 = res.size() / 2;
    return res.size() % 2 ?
        res[size_2] :
        (res[size_2] + res[size_2 - 1]) / 2.0;
}
```

换成数组 `int res[size]` 后，执行时间 ***12ms***。时间复杂度都是 ***O(m+n)***。

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int a = 0, b = 0, i = 0;
    int size = nums1.size() + nums2.size();
    int res[size] = { 0 };

    for (; a < nums1.size() && b < nums2.size();) {
        if (nums1[a] < nums2[b])
            res[i++] = nums1[a++];
        else
            res[i++] = nums2[b++];
    }

    while (a < nums1.size()) {
        res[i++] = nums1[a++];
    }
    while (b < nums2.size()) {
        res[i++] = nums2[b++];
    }

    int size_2 = size / 2;
    return size % 2 ?
        res[size_2] :
        (res[size_2] + res[size_2 - 1]) / 2.0;
}
```

### 解法二

利用寻找**第 k 小数**的方法找到中位数两侧相邻的数。`K(k,A,startA,endA,B,startB,endB)` 为找到 *A*、*B* 两数组第 *k* 小数的函数，且为尾递归函数，每次舍弃 *k* 的一半。执行时间 ***36ms***，时间复杂度 ***O(log(m+n))***。[解题来源(解法三)](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/)

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int lenA = nums1.size(), lenB = nums2.size();

    int left = (lenA + lenB + 1) / 2;	// 中位数左侧数的下标
    int right = (lenA + lenB + 2) / 2;	// 中位数右侧数的下标

    return (K(left, nums1, 0, lenA - 1, nums2, 0, lenB - 1) 
        + K(right, nums1, 0, lenA - 1, nums2, 0, lenB - 1)) / 2.0;
}

int K(int k, vector<int>& A, int startA, int endA, vector<int>& B, int startB, int endB) {
    int lenA = endA - startA + 1, lenB = endB - startB + 1;

    if (lenA > lenB)return K(k, B, startB, endB, A, startA, endA);	// 保证 A 长度较小
    if (lenA == 0)return B[startB + k - 1];
    if (k == 1)return min(A[startA], B[startB]);

    int i = startA + min(lenA, k / 2) - 1;	// i -> 第k/2个的下标 (len小于此数时 i取尾数)
    int j = startB + min(lenB, k / 2) - 1;	

    if (A[i] < B[j]) {
        return K(k - (i - startA + 1), A, i + 1, endA, B, startB, endB);
    }
    else {
        return K(k - (j - startB + 1), A, startA, endA, B, j + 1, endB);
    }
}
```

