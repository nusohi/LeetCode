#include "solution.h"


void printList(ListNode* list) {
	while (list != NULL) {
		std::cout << list->val << ' ';
		list = list->next;
	}
	std::cout << std::endl;
}

ListNode* createList(int num) {
	int cur = num % 10;
	num = num / 10;
	ListNode *res = new ListNode(cur), *head = res;

	while (num != 0) {
		cur = num % 10;
		num = num / 10;
		res->next = new ListNode(cur);
		res = res->next;
	};
	return head;
}


void T2() {
	ListNode* l1 = createList(342);
	ListNode* l2 = createList(465);

	Solution so;
	ListNode* res = so.addTwoNumbers(l1, l2);
	printList(res);
}