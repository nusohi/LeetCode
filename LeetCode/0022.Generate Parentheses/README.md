# 22. 括号生成 | Generate Parentheses

**题目:**

给出 *n* 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且**有效的**括号组合。

**示例:**

```
给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

## 思路

### 回溯法

执行时间 ***12ms*** 。【[Submission Detail](https://leetcode-cn.com/submissions/detail/27223335/)】

```cpp
vector<string> generateParenthesis(int n) {
    vector<string> res;
    fun(res, "", 0, 0, n);
    return res;
}

void fun(vector<string> &res, string str, int left, int right, int max) {
    if (str.length() == max * 2) {
        res.push_back(str);
        return;
    }
    if (left < max)
        fun(res, str + "(", left + 1, right, max);
    if (left > right)
        fun(res, str + ")", left, right + 1, max);
}
```

