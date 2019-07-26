# 3. 无重复字符的最长子串 | Longest Substring Without Repeating Characters

**题目:**

给定一个字符串，请你找出其中不含有重复字符的**最长子串**的长度。

**示例:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

## 思路

利用**滑动窗口**即记录最长字串的左右下标并不断向右移动。执行时间是（***44ms***）。

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        if (map.find(s[right]) != map.end()) {
            int repeatIndex = map[s[right]];
            for (int i = left; i <= repeatIndex; i++) {
                map.erase((char)s[i]);
            }
            left = repeatIndex + 1;
        }
        map[s[right]] = right;
        maxLen = right - left + 1 > maxLen ? right - left + 1 : maxLen;
    }
    return maxLen;
}
```

去掉 `map.erase()` 的执行时间为（***36ms***），仍不理想。

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        if (map.find(s[right]) != map.end() && map[s[right]] >= left) {
            left = map[s[right]] + 1;
        }
        map[s[right]] = right;
        maxLen = right - left + 1 > maxLen ? right - left + 1 : maxLen;
    }
    return maxLen;
}
```

将 `unorderd_map` 用 `int map[256]` 替换，执行时间为（***12ms***）。`map` 中存的为对应字符在字符串`s`中是第几个，即 `下标 + 1`。

```cpp
int lengthOfLongestSubstring(string s) {
    int map[256] = { 0 };
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        if (map[s[right]] != 0 && map[s[right]] >= left) {
            left = map[s[right]];
        }
        map[s[right]] = right + 1;	// 第几个
        maxLen = right - left + 1 > maxLen ? right - left + 1 : maxLen;
    }
    return maxLen;
}
```



