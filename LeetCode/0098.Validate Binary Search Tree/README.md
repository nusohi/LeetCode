# 98. 验证二叉搜索树 | Validate Binary Search Tree

**题目:**

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

- 节点的左子树只包含小于当前节点的数。
- 节点的右子树只包含大于当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。

**示例:**

```
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
```

## 思路

### 中序遍历

在中序遍历的过程中检查是否前一数较小。运行时多个用例出错，还需考虑 `int` 的最小值以及两数不能相等，`INT_MIN` 无法同时解决这两个问题，应该改用 `LONG_MIN` 。下面代码中先找到树中最左节点来确定最小值，暂时避免了 `INT_MIN` 的问题，执行时间较长，为 ***28ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/24697841/))

```cpp
bool isValidBST(TreeNode* root) {
    if (!root)return true;
    stack<TreeNode*> s;

    // 先取到最小值 LOW
    while (root) {
        s.push(root);
        root = root->left;
    }
    root = s.top();
    s.pop();
    int LOW = root->val;
    root = root->right;


    while (true) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        if (s.empty())
            break;
        root = s.top();
        s.pop();

        if (root->val <= LOW)return false;
        LOW = root->val;

        root = root->right;
    }

    return true;
}
```

改进：用 `LONG_MIN` 来代替 `while` 循环前面查找最左节点的部分，执行时间 ***12ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/24698428/))

```cpp
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> s;
    long LOW = LONG_MIN;

    while (true) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        if (s.empty())
            break;
        root = s.top();
        s.pop();

        if (root->val <= LOW)return false;
        LOW = root->val;

        root = root->right;
    }

    return true;
}
```

