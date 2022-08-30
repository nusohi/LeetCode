#include <iostream>
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL)return pHead2;
		if (pHead2 == NULL)return pHead1;

		ListNode* head = NULL, * tail = NULL;
		if (pHead1->val < pHead2->val) {
			head = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			head = pHead2;
			pHead2 = pHead2->next;
		}
		tail = head;

		while (pHead1 != NULL && pHead2 != NULL) {
			if (pHead1->val < pHead2->val) {
				tail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				tail->next = pHead2;
				pHead2 = pHead2->next;
			}
			tail = tail->next;
		}

		if (pHead1 == NULL)
			tail->next = pHead2;
		if (pHead2 == NULL)
			tail->next = pHead1;

		return head;
	}
};
