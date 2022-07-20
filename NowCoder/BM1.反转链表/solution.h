#include <vector>
using namespace std;


struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		// n == 0 or 1
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* p = pHead->next->next, * temp = NULL;
		pHead->next->next = pHead;
		pHead = pHead->next;
		pHead->next->next = NULL;

		while (p != NULL) {
			temp = p->next;
			p->next = pHead;
			pHead = p;
			p = temp;
		}

		return pHead;
	}
};
