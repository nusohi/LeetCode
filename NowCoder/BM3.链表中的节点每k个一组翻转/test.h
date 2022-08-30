#include "solution.h"
#include <vector>
using namespace std;


void TBM3() {
	vector<int> nums{ 1,2 };
	int k = 2;

	ListNode* head = nums.size() > 0 ? new ListNode(nums[0]) : NULL,
		* p = head;
	for (int i = 1, size = nums.size(); i < size; i++) {
		p->next = new ListNode(nums[i]);
		p = p->next;
	}
	p->next = NULL;

	Solution solution;
	head = solution.reverseKGroup(head, k);

	p = head;
	while (p != NULL) {
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
}
