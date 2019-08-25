#include <vector>
using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		int left = 1, right = 1;
		vector<int> res(size, 1);

		for (int i = 0; i < size; i++) {
			res[i] *= left;
			left *= nums[i];

			res[size - i - 1] *= right;
			right *= nums[size - i - 1];
		}

		return res;
	}
};
