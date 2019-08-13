#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> set(nums.size());
		for (int num : nums) {
			if (set.count(num) > 0)
				return true;
			else
				set.insert(num);
		}
		return false;
	}
};
