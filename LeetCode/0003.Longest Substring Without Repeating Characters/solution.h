#include <unordered_map>
#include <string>
#include <math.h>
using std::string;
using std::unordered_map;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int map[256] = { 0 };
		int left = 0, maxLen = 0;

		for (int right = 0; right < s.length(); right++) {
			if (map[s[right]] != 0 && map[s[right]] >= left) {
				left = map[s[right]];
			}
			map[s[right]] = right + 1;	// µÚ¼¸¸ö
			maxLen = right - left + 1 > maxLen ? right - left + 1 : maxLen;
		}
		return maxLen;
	}
};