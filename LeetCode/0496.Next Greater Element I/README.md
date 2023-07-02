# 496. 下一个更大元素 I | Next Greater Element I

**题目:**

`nums1` 中数字 `x` 的 **下一个更大元素** 是指 `x` 在 `nums2` 中对应位置 **右侧** 的 **第一个** 比 `x` 大的元素。

给你两个 **没有重复元素** 的数组 `nums1` 和 `nums2` ，下标从 **0** 开始计数，其中`nums1` 是 `nums2` 的子集。

对于每个 `0 <= i < nums1.length` ，找出满足 `nums1[i] == nums2[j]` 的下标 `j` ，并且在 `nums2` 确定 `nums2[j]` 的 **下一个更大元素** 。如果不存在下一个更大元素，那么本次查询的答案是 `-1` 。

返回一个长度为 `nums1.length` 的数组 `ans` 作为答案，满足 `ans[i]` 是如上所述的 **下一个更大元素** 。

**示例1:**

```
输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
```

**示例2:**

```
输入：nums1 = [2,4], nums2 = [1,2,3,4].
输出：[3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
```

**提示：**

- `1 <= nums1.length <= nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 104`
- `nums1` 和 `nums2` 中所有整数 **互不相同**
- `nums1` 中的所有整数同样出现在 `nums2` 中

**进阶：**你可以设计一个时间复杂度为 `O(nums1.length + nums2.length)` 的解决方案吗？

## 思路

> map + 栈

用 map 存储 `nums1` 中元素和下标的映射关系；

用栈 stack 存储**尚未找到更大元素**的 `nums2[i]`；

用 `vector<int> result(nums1.size(), -1)` 保存结果，默认为 `-1`。

- 遍历 `nums2`，检查每个元素是否在 `nums1` 中（在 map 中），在则入栈等后面确定更大值；
- 遍历每个 `nums2[i]` 元素时，检查栈，若比栈中元素大则写到 `result` 数组中，下标通过 map 查找。

执行时间 ***8ms*** 。【[Submission Detail](https://leetcode.cn/problems/next-greater-element-i/submissions/443648075/)】

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> value2index;        // nums1
        vector<int> stack;
        vector<int> result(nums1.size(), -1);

        for (int i = 0, size = nums1.size(); i < size; i++) {
            value2index.insert(pair<int, int>(nums1[i], i));
        }

        for (int i = 0, size = nums2.size(); i < size; i++) {
            // 检查 stack 有元素则比较
            while (stack.size() > 0) {
                // while 到栈中元素比 nums2[i] 大时跳出
                if (stack.back() > nums2[i]) break;
                int index = value2index[stack.back()];
                result[index] = nums2[i];
                stack.pop_back();
            }

            // map 中没有则说明不在 Nums1 中，跳过
            if (value2index.find(nums2[i]) == value2index.end()) continue;
            // 在则入栈即可
            stack.push_back(nums2[i]);
        }

        return result;
    }
};
```

