# 215. 数组中的第K个最大元素 | Kth Largest Element in an Array

**题目:**

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例:**

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**说明:**

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

## 思路

### 1. K 次冒泡排序

每次冒泡排序会确定一个最大值，K次冒泡排序会确定第K大的元素，时间复杂度 **O(kN)**，效果很差。

执行时间 ***324ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/25592633/))

```cpp
int findKthLargest(vector<int>& nums, int k) {
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
            }
        }
    }
    return nums[nums.size() - k];
}
```

### 2. 快速排序

类似**快速排序**的方法从大到小排序，每次判断分割点是否为第 `k` 个。

- `QuickSort()` 每次处理两个元素的数组时无法使用原逻辑，因此单独考虑。
- `left` 和 `right` 指针移动时的判断条件很麻烦，`left` 指针移动时不能大于 `right` ，而 `right` 指针移动时不限制。
- `left` 满足条件 `N[left] == bound` 时也应可以右移，才能通过例如 `[3,3,3,3,3]` 的用例。

执行时间 ***16ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/25600623/))

```cpp
int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1, pivot;
    while (left <= right) {
        pivot = QuickSort(nums, left, right);
        if (pivot == k - 1) return nums[pivot];
        else if (pivot > k - 1) right = pivot - 1;
        else left = pivot + 1;
    }
    return -1;
}

int QuickSort(vector<int>& N, int start, int end) {
    if (start + 1 == end) {
        if (N[start] < N[end])swap(N[start], N[end]);
        return start;
    }
    swap(N[start], N[(start + end) / 2]);
    int left = start + 1, right = end, bound = N[start];

    while (left < right) {
        while (left < right && N[left] >= bound)
            left++;
        while (N[right] < bound) 
            right--;
        if (left < right)
            swap(N[left], N[right]);
        else 
            break;
    }

    swap(N[start], N[right]);
    return right;
}
```

