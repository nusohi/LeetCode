

class Solution {
public:
	bool isPalindrome(int X) {
		if (X < 0 || (X % 10 == 0 && X != 0))
			return false;
		int reverse = 0;
		while (X > reverse) {
			reverse = reverse * 10 + X % 10;
			X = X / 10;
		}
		return X == reverse || X == reverse / 10;
	}
};