# 10. 正则表达式匹配 | Regular Expression Matching

**题目:**

给你一个字符串 `s` 和一个字符规律 `p`，请你来实现一个支持 `'.'` 和 `'*'` 的正则表达式匹配。

`'.'` 匹配任意单个字符
`'*'` 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个字符串 `s` 的，而不是部分字符串。

> **说明**:
>
> `s` 可能为空，且只包含从 `a-z` 的小写字母。
> `p` 可能为空，且只包含从 `a-z` 的小写字母，以及字符 `.` 和 `*`。

**示例:**

```
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
```

## 思路

### 解法一：回溯

执行时间 ***460+ms***。

```cpp
bool isMatch(string s, string p) {
    if (p == "")return s == "";

    bool firstMatch = s != "" && (s[0] == p[0] || p[0] == '.');

    if (p.length() >= 2 && p[1] == '*') {
        return isMatch(s, p.substr(2))
            || (firstMatch && isMatch(s.substr(1), p));
    }
    else {
        return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
}
```

### 解法二：动态规划

回溯法中的递归是可以省略一部分的，利用计算过的值来节省计算时间。

利用 `unorderd_map` 来记录已经计算过的 `bool` 值。执行时间 ***24ms***。

```cpp
bool isMatch(string s, string p) {
    unordered_map<string, bool> map;
    return match(0, 0, s, p, map);
}

bool match(int i, int j, string &s, string &p, unordered_map<string, bool> &map) {
    if (map.find(strKey(i, j)) != map.end())	// map 中已有计算值
        return map[strKey(i, j)];
    if (j == p.length())return i == s.length();	// p=="" && s==""

    bool firstMatch = i != s.length() && (s[i] == p[j] || p[j] == '.');
    bool res;

    if (p.length() - j >= 2 && p[j + 1] == '*') {
        res = match(i, j + 2, s, p, map)
            || (firstMatch&&match(i + 1, j, s, p, map));
    }
    else {
        res = firstMatch && match(i + 1, j + 1, s, p, map);
    }
    map[strKey(i, j)] = res;
    return res;
}

string strKey(int i, int j) {
    return to_string(i) + '-' + to_string(j);
}
```

利用二维数组 `dp` 替换 `unorderd_map` 来记录。执行时间 ***8ms***。

```cpp
bool isMatch(string s, string p) {
    int i = s.length(), j = p.length();
    if (j == 0)return i == 0;
    // 0->未计算 1->true -1->false
    short **dp = new short*[i];
    for (int k = 0; k < i; k++)
        dp[k] = new short[j] {0};

    return match(0, 0, s, p, dp);
}

bool match(int i, int j, string &s, string &p, short **dp) {
    if (j == p.length())return i == s.length();				// p=="" && s==""
    if (i < s.length() && j < p.length() && dp[i][j] != 0)	// dp 中已有计算值
        return dp[i][j] == 1;

    bool firstMatch = i != s.length() && (s[i] == p[j] || p[j] == '.');
    bool res;

    if (p.length() - j >= 2 && p[j + 1] == '*') {
        res = match(i, j + 2, s, p, dp)
            || (firstMatch&&match(i + 1, j, s, p, dp));
    }
    else {
        res = firstMatch && match(i + 1, j + 1, s, p, dp);
    }
    if (i < s.length() && j < p.length())
        dp[i][j] = res ? 1 : -1;
    return res;
}
```

