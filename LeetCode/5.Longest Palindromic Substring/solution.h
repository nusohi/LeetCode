#include <string>
#include <algorithm>
#include <regex>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len < 2) return s;

		s = Divider(s, '#');
		len = (len << 1)+ 1;

		int *p = new int[len];
		int mx = 0;
		int id = 0;
		int maxRadius = 1;
		string maxStr = s.substr(1, 2);

		for (int i = 0; i < len; i++) {
			// p 数组判断公式
			p[i] = i < mx ?
				min(p[2 * id - i], mx - i) :
				1;

			// 中心扩散
			while (i - p[i] >= 0 && i + p[i] < len && s[i - p[i]] == s[i + p[i]]) {
				p[i]++;
			}

			// mx 向右移动
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}

			// 判断回文半径是否较大
			if (p[i] - 1 > maxRadius) {
				maxRadius = p[i] - 1;
				maxStr = s.substr(i - p[i] + 1, 2 * p[i] - 1);
			}
		}
		return regex_replace(maxStr, regex("#"), "");
	}

	string Divider(string s, char divide) {
		int len = s.length();
		string newstr = "";
		if (s.find(divide) != string::npos) {
			throw new exception("分隔符已存在！");
		}
		newstr += divide;
		for (int i = 0; i < len; i++) {
			newstr += s[i];
			newstr += divide;
		}
		return newstr;
	}
};
