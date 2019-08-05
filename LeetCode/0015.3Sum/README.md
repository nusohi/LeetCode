# 15. 三数之和 | 3Sum

**题目:**

给定一个包含 *n* 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c，* 使得 *a + b + c* = 0 ？找出所有满足条件且不重复的三元组。

**注意**：答案中不可以包含重复的三元组。	

**示例:**

```
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## 思路

先排序，然后遍历数组，`i` 作为第一个数的下标，然后用两个指针 `left` 和 `right` 指向 `i` 之后的数组的首尾两端，两个指针向中间移动，将所有三数之和等于 **0** 的情况纳入结果中。

第一个数 `i` 的遍历要注意：

- 如果 `nums[i]` **大于 0**，则不需要再继续计算，后面没有符合条件的情况了。
- 如果当前 `nums[i]` **与前一数相等**，也无需重复计算，跳过即可。

查找第二、三个数 `left` 和 `right` 时也要注意**去重**，得到新结果 `res` 后，如果 `left` 与下一个数相等则需要跳过，`right` 与前面的数相等时也需要跳过。

执行时间 ***136ms***。([Submission Detail](https://leetcode-cn.com/submissions/detail/24913938/))

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int len = nums.size(), left, right, sum;
    if (len < 3)return res;
    // 排序
    sort(nums.begin(), nums.end());

    for (int i = 0; i < len - 2; i++) {
        if (nums[i] > 0)break;							// 正数之和一定大于 0
        if (i > 0 && nums[i] == nums[i - 1])continue;	// 避免重复

        // 至此得到第一个数 nums[i]

        left = i + 1;
        right = len - 1;

        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({ nums[i], nums[left], nums[right] });
                while (left < right && nums[left] == nums[left + 1])left++;
                while (left < right && nums[right] == nums[right - 1])right--;
                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return res;
}
```

