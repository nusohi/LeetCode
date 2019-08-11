#include "solution.h"
#include <iostream>
using namespace std;


void T215() {
	Solution solution;
	vector<int> nums = {
		3,3,3,3
	};

	cout << solution.findKthLargest(nums, 1) << endl;
}
