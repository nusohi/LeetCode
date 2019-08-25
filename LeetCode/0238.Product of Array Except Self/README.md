# 238. 除自身以外数组的乘积 | Product of Array Except Self

**题目:**

给定长度为 *n* 的整数数组 `nums`，其中 *n* > 1，返回输出数组 `output` ，其中 `output[i]` 等于 `nums` 中除 `nums[i]` 之外其余各元素的乘积。

**示例:**

```
输入: [1,2,3,4]
输出: [24,12,8,6]
```

**说明：**

请**不要使用除法，**且在 O(*n*) 时间复杂度内完成此题。

**进阶：**
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组**不被视为**额外空间。）

## 思路

不能用除法，则 `res[i] = 左积[i] * 右积[i]`。

- 可以用两个数组分别计算并存储**左积**和**右积**，最后再相乘。
- 也可以用两个 `int` 变量 `left` 和 `right` 来存储**左积**和**右积**，分别从两头开始计算，每次计算得到新的**左积**和新的**右积**，不必将其单独记录在数组中，及时乘上**对应**的 `res[i]` 即可，`res[i]` 初始值设为 **1** 。

执行时间 ***52ms*** 。【[Submission Detail](https://leetcode-cn.com/submissions/detail/27144700/)】

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    int left = 1, right = 1;
    vector<int> res(size, 1);

    for (int i = 0; i < size; i++) {
        res[i] *= left;
        left *= nums[i];

        res[size - i - 1] *= right;
        right *= nums[size - i - 1];
    }

    return res;
}
```

