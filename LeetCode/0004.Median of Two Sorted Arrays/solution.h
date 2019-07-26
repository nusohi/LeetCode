#include <vector>
#include <algorithm>
using std::vector;
using std::min;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int lenA = nums1.size(), lenB = nums2.size();

		int left = (lenA + lenB + 1) / 2;	// 中位数左侧数的下标
		int right = (lenA + lenB + 2) / 2;	// 中位数右侧数的下标
		
		return (K(left, nums1, 0, lenA - 1, nums2, 0, lenB - 1) 
			+ K(right, nums1, 0, lenA - 1, nums2, 0, lenB - 1)) / 2.0;
	}

	int K(int k, vector<int>& A, int startA, int endA, vector<int>& B, int startB, int endB) {
		int lenA = endA - startA + 1, lenB = endB - startB + 1;

		if (lenA > lenB)return K(k, B, startB, endB, A, startA, endA);	// 保证 A 长度较小
		if (lenA == 0)return B[startB + k - 1];
		if (k == 1)return min(A[startA], B[startB]);

		int i = startA + min(lenA, k / 2) - 1;	// i -> 第k/2个的下标 (len小于此数时 i取尾数)
		int j = startB + min(lenB, k / 2) - 1;	

		if (A[i] < B[j]) {
			return K(k - (i - startA + 1), A, i + 1, endA, B, startB, endB);
		}
		else {
			return K(k - (j - startB + 1), A, startA, endA, B, j + 1, endB);
		}
	}
};


/*
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int a = 0, b = 0, i = 0;
	int size = nums1.size() + nums2.size();
	int res[size] = { 0 };

	for (; a < nums1.size() && b < nums2.size();) {
		if (nums1[a] < nums2[b])
			res[i++] = nums1[a++];
		else
			res[i++] = nums2[b++];
	}

	while (a < nums1.size()) {
		res[i++] = nums1[a++];
	}
	while (b < nums2.size()) {
		res[i++] = nums2[b++];
	}

	int size_2 = size / 2;
	return size % 2 ?
		res[size_2] :
		(res[size_2] + res[size_2 - 1]) / 2.0;
}
*/