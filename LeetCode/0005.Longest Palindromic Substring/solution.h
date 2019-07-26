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
			// p �����жϹ�ʽ
			p[i] = i < mx ?
				min(p[2 * id - i], mx - i) :
				1;

			// ������ɢ
			while (i - p[i] >= 0 && i + p[i] < len && s[i - p[i]] == s[i + p[i]]) {
				p[i]++;
			}

			// mx �����ƶ�
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}

			// �жϻ��İ뾶�Ƿ�ϴ�
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
			throw new exception("�ָ����Ѵ��ڣ�");
		}
		newstr += divide;
		for (int i = 0; i < len; i++) {
			newstr += s[i];
			newstr += divide;
		}
		return newstr;
	}
};
