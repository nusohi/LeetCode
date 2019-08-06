#include <vector>
using namespace std;


class Solution {
public:
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
};
