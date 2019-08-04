#include "solution.h"
#include <iostream>
using namespace std;


void T33() {
	Solution solution;
	vector<vector<int>> nums{
		{4,5,6,7,0,1,2},
		{4,5,6,7,0,1,2}
	};
	vector<int> targets{
		0,
		4
	};

	for (int i = 0; i < nums.size(); i++) {
		for (int n : nums[i])
			cout << n << ' ';
		cout << " ->  " << targets[i] << "  ->  " << solution.search(nums[i], targets[i]) << endl;
	}
}
