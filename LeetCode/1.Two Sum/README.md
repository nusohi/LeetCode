# 1. 两数之和 | Two Sum

**题目:**

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

**示例:**

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

## 思路

### 1. 两遍哈希

***(20ms)***

将 `nums` 中数字作为 **key**，下标作为 **value**，构建哈希表，遍历 `nums` 数组，找 `map` 中匹配的数字。

执行 `[3,2,4]->6` 时返回 `[0,0]`，匹配的数字不能为自身，加一个判断 `i != iter->second`。

```cpp
vector<int> twoSum_twice_hash(vector<int>& nums, int target) {
	map<int, int> nums_map;
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		nums_map.insert(map<int, int>::value_type(nums[i], i));
	}

	map<int, int>::iterator iter;
	for (int i = 0; i < size; i++) {
		int num = target - nums[i];
		iter = nums_map.find(num);
		if (iter != nums_map.end() && i != iter->second) {
			return vector<int>{i, iter->second};
		}
	}
	return {};
}
```

### 2. 一遍哈希

***(16ms)***

在构建哈希表的时候同时检查是否有匹配的数字，一般在未建完表时都可以匹配成功。

返回的下标应该将匹配到的数字下标放在前面，因为 `i` 是还未插入哈希表的。

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> nums_map;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums_map.count(target - nums[i])) {
            return { nums_map[target - nums[i]], i };
        }
        nums_map[nums[i]] = i;
    }
    return {};
}
```

