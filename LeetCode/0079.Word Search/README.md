# 79. 单词搜索 | Word Search

**题目:**

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

**示例:**

```
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
```

## 思路

### 回溯

类似迷宫的解法，`visited` 数组标记已访问的位置。返回的条件修改了好多次。执行时间 ***32ms***。

> [Submission Detail](https://leetcode-cn.com/submissions/detail/24001008/)

```cpp
bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) return word == "";

    bool** visited = new bool*[board.size()];
    for (int i = 0; i < board.size(); i++) {
        visited[i] = new bool[board[0].size()]{ false };
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++)
            if (search(i, j, 0, visited, board, word))
                return true;
    }

    return false;
}

bool search(int i, int j, int key, bool **visited, vector<vector<char>>& board, string& word) {
    // 下标越界或者已访问 -> 返回
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j])
        return false;

    // 单词正确 -> 继续 | 不正确 -> 返回
    if (board[i][j] == word[key])
        key++;
    else
        return false;

    // 单词读完 -> 返回 true
    if (key == word.length()) 
        return true;

    visited[i][j] = true;	// 标记

    // 检查右下左上
    if (search(i + 1, j, key, visited, board, word)) return true;
    if (search(i, j - 1, key, visited, board, word)) return true;
    if (search(i - 1, j, key, visited, board, word)) return true;
    if (search(i, j + 1, key, visited, board, word)) return true;

    visited[i][j] = false;	// 取消标记

    return false;
}
```

