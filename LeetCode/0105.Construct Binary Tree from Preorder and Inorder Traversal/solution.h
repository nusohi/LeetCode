#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
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
};
