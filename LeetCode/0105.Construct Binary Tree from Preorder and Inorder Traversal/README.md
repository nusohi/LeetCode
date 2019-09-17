# 105. 从前序与中序遍历序列构造二叉树 | Construct Binary Tree from Preorder and Inorder Traversal

**题目:**

根据一棵树的前序遍历与中序遍历构造二叉树。

**注意:**

你可以假设树中没有重复的元素。

**示例:**

```
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
```

## 思路

### 递归

对于每一个子树：

- 先从**先序遍历序列**中找到根节点 `root`，即第一个数，建立节点 `TreeNode`；
- 找到**中序遍历序列**中根节点的下标 `root_inorder`；
- 用 `root_inoder` 将**中序遍历子序列**分成左右子树，再递归调用自身函数找到左右子树。

执行时间 ***24ms*** 。【[Submission Detail](https://leetcode-cn.com/submissions/detail/30128538/)】

```cpp
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return constructor(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

TreeNode* constructor(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left, int in_right) {
    if (pre_left == pre_right)
        return NULL;

    TreeNode* root = new TreeNode(preorder[pre_left]);
    int root_inoder = in_left;
    for (; root_inoder < in_right; root_inoder++) {
        if (preorder[pre_left] == inorder[root_inoder])
            break;
    }

    root->left = constructor(preorder, pre_left + 1, root_inoder - in_left + pre_left + 1, inorder, in_left, root_inoder);
    root->right = constructor(preorder, root_inoder - in_left + pre_left + 1, pre_right, inorder, root_inoder + 1, in_right);

    return root;
}
```

数组 `inoder` 的作用在于找到根节点在其中的下标，来将左子树和右子树的范围确定下来。然而每次需要从头遍历**中序遍历子序列**来找到根节点下标，用**字典**来存储 `inoder` 各数字和其下标，可以省略这些重复的遍历。

执行时间 ***20ms*** 。【[Submission Detail](https://leetcode-cn.com/submissions/detail/30134862/)】

```cpp
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int size = inorder.size();
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < size; i++) {
        inorder_map.insert({ inorder[i], i });
    }
    return constructor(preorder, 0, size, inorder_map, 0, size);
}

TreeNode* constructor(vector<int>& preorder, int pre_left, int pre_right, unordered_map<int, int>& inorder_map, int in_left, int in_right) {
    if (pre_left == pre_right)
        return NULL;

    TreeNode* root = new TreeNode(preorder[pre_left]);
    int root_inoder = inorder_map[preorder[pre_left]];

    root->left = constructor(preorder, pre_left + 1, root_inoder - in_left + pre_left + 1, inorder_map, in_left, root_inoder);
    root->right = constructor(preorder, root_inoder - in_left + pre_left + 1, pre_right, inorder_map, root_inoder + 1, in_right);

    return root;
}
```

