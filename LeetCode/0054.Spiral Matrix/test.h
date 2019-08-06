#include "solution.h"
#include <iostream>
using namespace std;


void T54() {
	Solution solution;
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	vector<int> res = solution.spiralOrder(matrix);

	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
}
