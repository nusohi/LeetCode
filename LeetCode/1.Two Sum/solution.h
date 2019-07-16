#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> nums_map;
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums_map.count(target - nums[i])) {
				return { nums_map[target - nums[i]], i };
			}
			nums_map[nums[i]] = i;
		}
		return {};
	}
};
