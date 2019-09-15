#include <string>
using namespace std;


class Solution {
public:
	int myAtoi(string str) {
		int len = str.length(),
			start = -1,
			flag = -1;
		long res = 0;

		while (start + 1 < len && str[++start] == ' ');

		if (str[start] == '+')
			flag = 1;
		else if (str[start] == '-')
			flag = 0;
		else if (str[start] < '0' || str[start] > '9')
			return 0;

		start += flag == -1 ? 0 : 1;
		for (int i = start; i < len; i++) {
			if (str[i] < '0' || str[i] > '9') 
				break;
			res = res * 10 + (str[i] - '0');
			if (res - 1 > INT_MAX) 
				break;
		}

		if (flag == 1 || flag == -1)
			return res > INT_MAX ? INT_MAX : res;
		else
			return res - 1 > INT_MAX ? INT_MIN : 0 - res;
	}
};
