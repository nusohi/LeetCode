#include "solution.h"
#include <iostream>
#include <vector>


void T5() {
	vector<string> s = {
		"abba",
		"",
		"--daadd",
		"ac"
	};

	Solution solution;

	for (string str : s)
	{
		std::cout << str << " -> " << solution.longestPalindrome(str) << std::endl;
	}
}
