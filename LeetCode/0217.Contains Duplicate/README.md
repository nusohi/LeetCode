# 217. 存在重复元素 | Contains Duplicate

**题目:**

给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

**示例:**

```
输入: [1,2,3,1]
输出: true
```

## 思路

### 哈希 Set

执行时间 ***48ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/25852560/))

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set(nums.size());
    for (int num : nums) {
        if (set.find(num) != set.end())
            return true;
        else
            set.insert(num);
    }
    return false;
}
```

> 48ms 最高的一次了，换成 hash map 也没有更快。
>
> 20ms 的那些提交示例大多是先排序再比较相邻数字是否有重复的。

