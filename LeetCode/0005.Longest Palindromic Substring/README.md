# 5. 最长回文子串 | Longest Palindromic Substring

**题目:**

给定一个字符串 `s`，找到 `s` 中最长的回文子串。你可以假设 `s` 的最大长度为 1000。

**示例:**

```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```

## 思路

### 解法一：动态规划

- “**状态**” 存储在二维数组 `dp[len][len]` 中，`s[i][j]` 表示子串 `s[i:j]` 是否为回文子串。
- 程序执行完的数组 `dp` 应该是一个上三角形矩阵，程序的主要内容就是按序填满这个矩阵，并在这个过程中得到最长的一个子串，即 `j-i` 最大的子串。
- **状态转移方程**： `dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])` 。首先 `s[i:j]` 为回文串的条件必须满足 `s[i] == s[j]` ，其次就是除了 `s[i]` 和 `s[j]` 之外的子串 `s[i+1:j-1]` 必须是回文串，但是如果 `s[i:j]` 本身长度小于等于 ***3*** 则一定是回文串。
- `dp` 数组的计算顺序应该是**从左到右，从上到下**，才能保证每次使用 *状态转移方程* 时所需的**子串状态**(即 `dp[i+1][j-1]` ) 是已经计算过的。
- 时间复杂度 **O(N^2)**，空间复杂度 **O(N^2)​**，执行时间竟然 ***184ms*** 。

```cpp
string longestPalindrome(string s) {
    int len = s.length();
    int a = 0, b = 0;
    if (len <= 1)return s;

    bool **dp = new bool*[len];
    for (int i = 0; i < len; i++) {
        dp[i] = new bool[len] {false};
    }

    for (int j = 1; j < len; j++) {
        for (int i = 0; i < j; i++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (j - i > b - a) {
                    a = i;
                    b = j;
                }
            }
        }
    }

    return s.substr(a, b - a + 1);
}
```

### 解法二：Manacher 算法

> **Manacher 算法的基本流程：**
>
> 首先还是“中心扩散法”的思想：回文串可分为奇数回文串和偶数回文串，它们的区别是：奇数回文串关于它的“中点”满足“中心对称”，偶数回文串关于它“中间的两个点”满足“中心对称”。为了避免对于回文串字符个数为奇数还是偶数的套路。首先对原始字符串进行预处理，方法也很简单：添加分隔符。
>
> **解题来源：[Leetcode解题](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/)**

#### 1. 添加分隔符

#### 2. P 数组

**回文半径**：以 `char[i]` 作为回文中心，同时向左边、向右边进行“中心扩散”，直到“不能构成回文串”或“触碰到字符串边界”为止，能扩散的步数 + 1（这个 1 表示“中心”） ，即定义为 `p` 数组的值，也称之为回文半径。

![](https://pic.leetcode-cn.com/c20bc530f81355d92fab674cdbc0c1aeb1fa3ee2f453e078c339fe5dc1ed20d3-image.png)

`id` 和 `mx` 的含义：

- **id** ：从开始到现在使用“中心扩散法”能得到的“最长回文子串”的**中心**的位置；

- **mx**：从开始到现在使用“中心扩散法”能得到的“最长回文子串”能延伸到的**最右端**的位置。容易知道 `mx = id + p[id]`。

![](https://pic.leetcode-cn.com/81320a9c88191b52b0c3ee15d84b881baf6ab0a4319da2049f143aad380f6f0c-image.png)

**p 数组的计算公式**:

1. 当 `id < i < mx` 的时候，此时 `id` 之前的 `p` 值都已经计算出来了，我们利用已经计算出来的 `p` 值来计算当前位置的 `p` 值。

2. 当` i >= mx` 的时候，此时也只能老老实实使用“中心扩散法”来逐渐得到 `p` 数组的值，同时记录 `id` 和 `mx`。

以上可以合并成一行代码：

``` cpp
p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
```

这一行代码拆开来看就是：如果 `mx > i`, 则 `p[i] = min(p[2 * id - i], mx - i)`，否则 `p[i] = 1`。

```cpp
string longestPalindrome(string s) {
    int len = s.length();
    if (len < 2) return s;

    s = Divider(s, '#');
    len = (len << 1)+ 1;

    int *p = new int[len];
    int mx = 0;
    int id = 0;
    int maxRadius = 1;
    string maxStr = s.substr(1, 2);

    for (int i = 0; i < len; i++) {
        // p 数组判断公式
        p[i] = i < mx ?
            min(p[2 * id - i], mx - i) :
            1;

        // 中心扩散
        while (i - p[i] >= 0 && i + p[i] < len && s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }

        // mx 向右移动
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }

        // 判断回文半径是否较大
        if (p[i] - 1 > maxRadius) {
            maxRadius = p[i] - 1;
            maxStr = s.substr(i - p[i] + 1, 2 * p[i] - 1);
        }
    }
    return regex_replace(maxStr, regex("#"), "");
}

string Divider(string s, char divide) {
    int len = s.length();
    string newstr = "";
    if (s.find(divide) != string::npos) {
        // throw new exception("分隔符已存在！");
    }
    newstr += divide;
    for (int i = 0; i < len; i++) {
        newstr += s[i];
        newstr += divide;
    }
    return newstr;
}
```

> **时间复杂度：O(N)**，由于 Manacher 算法只有在遇到还未匹配的位置时才进行匹配，已经匹配过的位置不再匹配，所以对于对于字符串S 的每一个位置，都只进行一次匹配，所以算法的总体复杂度为 O(N)。
> **空间复杂度：O(N)**