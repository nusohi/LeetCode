#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int len = nums.size(), left, right, sum;
		if (len < 3)return res;
		// 排序
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len - 2; i++) {
			if (nums[i] > 0)break;							// 正数之和一定大于 0
			if (i > 0 && nums[i] == nums[i - 1])continue;	// 避免重复

			// 至此得到第一个数 nums[i]

			left = i + 1;
			right = len - 1;

			while (left < right) {
				sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
					while (left < right && nums[left] == nums[left + 1])left++;
					while (left < right && nums[right] == nums[right - 1])right--;
					left++;
					right--;
				}
				else if (sum < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}

		return res;
	}
};
