# 54. 螺旋矩阵 | Spiral Matrix

**题目:**

给定一个包含 *m* x *n* 个元素的矩阵（*m* 行, *n* 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

**示例:**

```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
```

## 思路

### 按层循环

一圈一圈输出。`while` 循环中**每一圈**都按顺序输出**上右下左**四条线的数，循环之后剩下**一行**或**一列**的情况时分别**从左向右**、**从上向下**输出。

执行时间 ***4ms***。([Submission Detail](https://leetcode-cn.com/submissions/detail/25110533/))

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int left = 0, up = 0, down = matrix.size() - 1;
    if (down < 0) return res;
    int right = matrix[0].size() - 1;

    while (left < right && up < down) {
        // 上
        for (int j = left; j <= right; j++)
            res.push_back(matrix[up][j]);
        up++;
        // 右
        for (int i = up; i <= down; i++)
            res.push_back(matrix[i][right]);
        right--;
        // 下
        for (int j = right; j >= left; j--)
            res.push_back(matrix[down][j]);
        down--;
        // 左
        for (int i = down; i >= up; i--)
            res.push_back(matrix[i][left]);
        left++;
    }

    if (left == right) {
        for (int i = up; i <= down; i++)
            res.push_back(matrix[i][right]);
    }
    else if (up == down) {
        for (int j = left; j <= right; j++)
            res.push_back(matrix[up][j]);
    }

    return res;
}
```

