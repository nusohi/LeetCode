#include <iostream>
#include "solution.h"
using std::cout;
using std::endl;


void T3() {
	Solution solution;
	string test_string = "abcabcbb";
	cout << test_string << " -> " << solution.lengthOfLongestSubstring(test_string) << endl;
}