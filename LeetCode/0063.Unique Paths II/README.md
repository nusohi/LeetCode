# 62. 不同路径 II | Unique Paths II

**题目:**

一个机器人位于一个 *m x n* 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。

**说明：** *m* 和 *n* 的值均不超过 100。

**示例:**

```
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

## 思路

### 动态规划

> 没有障碍物的 【[T62](../0062.Unique%20Paths)】 类似 `F[i] = F[i-1] + F[i-2]` 的问题，从起点到第 `(i, j)` 块的路径数 **=** 到 `(i-1, j)` 的路径数 **+** 到 `(i, j-1)` 的路径数，即左面和上面两块的路径和。

加上了障碍物需要在计算 `dp` 数组时判断左面和上面的块是否有障碍，有障碍则不加上其路径数。

- 矩阵过大时 `int` 无法表示，需要换成 `long`。
- 第一个格子有障碍物时没有路径，返回 `0`。

执行时间 ***8ms***。【[Submission Detail](https://leetcode-cn.com/submissions/detail/25163250/)】

```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1)return 0;
    int m = obstacleGrid.size(),
        n = obstacleGrid[0].size();

    long **dp = new long*[m];
    for (int i = 0; i < m; i++)
        dp[i] = new long[n] {0};
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1)continue;

            if (i > 0 && obstacleGrid[i - 1][j] == 0) dp[i][j] += dp[i - 1][j];
            if (j > 0 && obstacleGrid[i][j - 1] == 0) dp[i][j] += dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}
```

