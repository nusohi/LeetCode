# 9. 回文数 | Palindrome Number

**题目:**

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

**示例:**

```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
```

## 思路

翻转数字，从头比较。只需翻转一半的数字即可，翻转的数字记录在 `reverse` 中，`while(X > reverse)` 的条件不符合时即是翻转至一半，此时比较 `X` 和 `reverse` 即可。

执行时间 ***16ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/24699462/))

```cpp
bool isPalindrome(int X) {
    if (X < 0 || (X % 10 == 0 && X != 0))
        return false;
    int reverse = 0;
    while (X > reverse) {
        reverse = reverse * 10 + X % 10;
        X = X / 10;
    }
    return X == reverse || X == reverse / 10;
}
```

