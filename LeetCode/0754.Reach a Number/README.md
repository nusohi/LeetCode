# 754. 到达终点数字 | Reach a Number

**题目:**

在一根无限长的数轴上，你站在`0`的位置。终点在`target`的位置。

你可以做一些数量的移动 `numMoves` :

- 每次你可以选择向左或向右移动。
- 第 `i` 次移动（从  `i == 1` 开始，到 `i == numMoves` ），在选择的方向上走 `i` 步。

给定整数 `target` ，返回 *到达目标所需的 **最小** 移动次数(即最小 `numMoves` )* 。

**示例1:**

```
输入: target = 2
输出: 3
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。
```

**示例2:**

```
输入: target = 3
输出: 2
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。
```

**提示：**

- `-109 <= target <= 109`
- `target != 0`

## 思路

> 参考思路：[https://leetcode.cn/problems/reach-a-number/solutions/1947300/by-muse-77-g0il/](https://leetcode.cn/problems/reach-a-number/solutions/1947300/by-muse-77-g0il/)

具体见下图和上面链接，推导后，**只需要找 `target` 之后的第一个偶数（`point`）即可**。

![示意图](https://pic.leetcode.cn/1667522745-klMjDB-image.png)

执行时间 ***0ms*** 。【[Submission Detail](https://leetcode.cn/submissions/detail/405535574/)】

```cpp
class Solution {
public:
    int reachNumber(int target) {
        // 正负都一样，取正值
        if (target < 0) target = -target;

        // 累加得到特殊点
        int point = 1, steps = 1;
        while (point < target) {
            point += ++steps;
        }

        // 最前面的特殊点已经等于 target
        if (point == target) return steps;
        // 该点差距是偶数的话就可以通过改变 + 号到达
        else if ((point - target) % 2 == 0)return steps;
        // 下一个点差距是偶数的话也可以
        else if ((point + ++steps - target) % 2 == 0) return steps;
        // 如果不是偶数则下下一个一定是偶数
        else return ++steps;
    }
};
```

