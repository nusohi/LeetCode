#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* node = head->next, *old;
		//head->next = head;

		while (true) {
			old = node;
			node = node->next;
			old->next = head;
			if (node == head) return true;
			else if (node == NULL) return false;
		}
	}

	bool hasCycle_2(ListNode* head) {
		ListNode* slow = head, * fast = head;

		while (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
			if (fast)fast = fast->next;
			if (slow == fast && fast != NULL)return true;
		}
		return false;
	}
};
