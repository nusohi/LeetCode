#include <string>
using namespace std;


class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0')return 0;

		int *dp = new int[s.length() + 1]{ 0 };
		dp[0] = dp[1] = 1;

		for (int i = 1; i < s.length(); i++) {
			if (s[i - 1] == '0') {
				if (s[i] == '0')
					return 0;
				else
					dp[i + 1] = dp[i - 2];	// i-2 不会出界，首位就是 0 的情况已经返回
			}
			else {
				if (s[i] == '0') {
					if (s[i - 1] > '2')
						return 0;
					else
						dp[i + 1] = dp[i - 1];
				}
				else {
					if (s[i - 1] < '2' || (s[i - 1] == '2'&&s[i] <= '6'))
						dp[i + 1] = dp[i] + dp[i - 1];
					else
						dp[i + 1] = dp[i];
				}
			}
		}
		return dp[s.length()];
	}
};
