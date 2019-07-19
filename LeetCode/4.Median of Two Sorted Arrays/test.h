#include "solution.h"
#include <iostream>


void T4() {
	vector<int> nums1{ 1,3 };
	vector<int> nums2{ 2 };
	Solution solution;
	double res = solution.findMedianSortedArrays(nums1, nums2);
	std::cout << "中位数：" << res << std::endl;
}