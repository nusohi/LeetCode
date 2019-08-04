#include <vector>
using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, mid, right = nums.size() - 1;

		while (left < right) {
			mid = (right + left) / 2;
			if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && target <= nums[mid])
					right = mid;
				else
					left = mid + 1;
			}
			else {
				if (nums[mid] < target && target <= nums[right])
					left = mid + 1;
				else
					right = mid;
			}
		}
		return left == right && nums[left] == target ? left : -1;
	}
};
