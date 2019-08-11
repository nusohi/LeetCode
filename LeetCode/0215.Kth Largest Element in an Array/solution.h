#include <vector>
using namespace std;


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1, pivot;
		while (left <= right) {
			pivot = QuickSort(nums, left, right);
			if (pivot == k - 1) return nums[pivot];
			else if (pivot > k - 1) right = pivot - 1;
			else left = pivot + 1;
		}
		return -1;
	}

	int QuickSort(vector<int>& N, int start, int end) {
		if (start + 1 == end) {
			if (N[start] < N[end])swap(N[start], N[end]);
			return start;
		}
		swap(N[start], N[(start + end) / 2]);
		int left = start + 1, right = end, bound = N[start];

		while (left < right) {
			while (left < right && N[left] >= bound)
				left++;
			while (N[right] < bound) 
				right--;
			if (left < right)
				swap(N[left], N[right]);
			else 
				break;
		}

		swap(N[start], N[right]);
		return right;
	}
};
