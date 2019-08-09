# 136. 只出现一次的数字 | Single Number

**题目:**

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

**说明：**

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例:**

```
输入: [4,1,2,1,2]
输出: 4
```

## 思路

### 1. 哈希集

用**哈希集**（`unordered_set`）记录出现过**一次**的数字，**第二次**出现时将其删除，遍历数组后哈希集中剩下的数字即结果。

执行时间 ***28ms*** 。【[Submission Detail](https://leetcode-cn.com/submissions/detail/25373543/)】

```cpp
int singleNumber(vector<int>& nums) {
    unordered_set<int> set;
    for (int num : nums) {
        if (set.find(num) == set.end())
            set.insert(num);
        else
            set.erase(num);
    }
    return *set.begin();
}
```

### 2. 位运算（异或）

对数组中所有数字进行**异或运算**操作，相同的数字会抵消得 `0` ，最后的结果即为只出现过一次的数字。

执行时间 ***16ms*** 。【[Submission Detail](https://leetcode-cn.com/submissions/detail/25373988/)】

```cpp
int singleNumber(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)
        nums[0] ^= nums[i];
    return nums[0];
}
```

