#include <string>
#include <unordered_map>
#include <tuple>
using std::string;
using std::unordered_map;
using std::tuple;
using std::to_string;


class Solution {
public:
	bool isMatch(string s, string p) {
		int i = s.length(), j = p.length();
		if (j == 0)return i == 0;
		// 0->未计算 1->true -1->false
		short **dp = new short*[i];
		for (int k = 0; k < i; k++)
			dp[k] = new short[j] {0};

		return match(0, 0, s, p, dp);
	}

	bool match(int i, int j, string &s, string &p, short **dp) {
		if (j == p.length())return i == s.length();				// p=="" && s==""
		if (i < s.length() && j < p.length() && dp[i][j] != 0)	// dp 中已有计算值
			return dp[i][j] == 1;

		bool firstMatch = i != s.length() && (s[i] == p[j] || p[j] == '.');
		bool res;

		if (p.length() - j >= 2 && p[j + 1] == '*') {
			res = match(i, j + 2, s, p, dp)	
				|| (firstMatch&&match(i + 1, j, s, p, dp));
		}
		else {
			res = firstMatch && match(i + 1, j + 1, s, p, dp);
		}
		if (i < s.length() && j < p.length())
			dp[i][j] = res ? 1 : -1;
		return res;
	}
};