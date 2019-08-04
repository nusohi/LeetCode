# 33. 搜索旋转排序数组 | Search in Rotated Sorted Array

**题目:**

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 `O(log n)` 级别。

**示例:**

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```

## 思路

### 二分法

时间复杂度 `O(log n)` 考虑用二分法。

- `nums[left] <= nums[mid]`：左半部分没有旋转，正常升序。
  - `target` 在左半部分：舍弃右半，`right = mid`。
  - `target` 在右半部分：舍弃左半，`left = mid+1`。
- `nums[left] > nums[mid]`：左半部分有旋转。
  - 同上。

执行时间 ***8ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/24833118/))

```cpp
int search(vector<int>& nums, int target) {
    int left = 0, mid, right = nums.size() - 1;

    while (left < right) {
        mid = (right + left) / 2;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target <= nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid;
        }
    }
    return left == right && nums[left] == target ? left : -1;
}
```

解题中有一个人将几种判断情况合并成了三项异或 `(nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])`。[[来源](https://leetcode-cn.com/problems/two-sum/solution/ji-jian-solution-by-lukelee/)]

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
}
```

