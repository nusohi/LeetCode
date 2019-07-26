#include <vector>
using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int maxS = 0, S;
		while (j > i) {
			if (height[i] > height[j]) {
				S = height[j] * (j - i);
				j--;
			}
			else {
				S = height[i] * (j - i);
				i++;
			}
			maxS = S > maxS ? S : maxS;
		}
		return maxS;
	}
};