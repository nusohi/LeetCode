#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
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
};
