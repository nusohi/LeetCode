
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1->val == 0 && l1->next == NULL)return l2;
		if (l2->val == 0 && l2->next == NULL)return l1;

		ListNode *res = new ListNode(l1->val + l2->val),
			*head = res;
		bool carry = res->val / 10;
		res->val = carry ? res->val % 10 : res->val;

		while (l1->next != NULL && l2->next != NULL) {
			l1 = l1->next;
			l2 = l2->next;

			res->next = new ListNode(l1->val + l2->val + (int)carry);
			res = res->next;
			carry = res->val / 10;
			res->val = carry ? res->val % 10 : res->val;
		}

		while (l1->next != NULL) {
			l1 = l1->next;

			res->next = new ListNode(l1->val + (int)carry);
			res = res->next;
			carry = res->val / 10;
			res->val = carry ? res->val % 10 : res->val;	
		}
		while (l2->next != NULL) {
			l2 = l2->next;

			res->next = new ListNode(l2->val + (int)carry);
			res = res->next;
			carry = res->val / 10;
			res->val = carry ? res->val % 10 : res->val;
		}
		if (carry) {
			res->next = new ListNode(1);
		}

		return head;
	}
};