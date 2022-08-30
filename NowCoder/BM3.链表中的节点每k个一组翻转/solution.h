#include <iostream>
using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
	ListNode(int val) {
		this->val = val;
	}
};
 

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		// ���账�������� 1.k==1 2.û�нڵ�
		if (k == 1 || head == NULL) return head;

		// ���� fake_head �Ա���ִ��
		ListNode* fake_head = new ListNode(0);
		fake_head->next = head;

		// ABC ���ε�ͷβ
		ListNode* temp,
			* A_tail = NULL,
			* B_head = NULL,
			* B_tail = fake_head,	// ��ʼ״̬���ٶ� fake_head ǰ��Ϊ��һ��ѭ���� B ��
			* C_head = NULL;
		int count;

		do {
			// ������һ�ֵ� B_tail ��ʼ��
			A_tail = B_tail;
			B_head = B_tail->next;
			B_tail = B_head;

			count = 0;	// ��¼ B �νڵ���
			while (++count < k) {
				B_tail = B_tail->next;
				// ʣ��ڵ㲻����
				if (B_tail == NULL) {
					break;
				}
			}
			// count != k ʱʣ�಻�跴ת
			if (count != k) {
				return fake_head->next;
			}

			C_head = B_tail->next;
			// ��
			B_tail->next = NULL;
			A_tail->next = NULL;

			temp = ReverseList(B_head);
			B_tail = B_head;
			B_head = temp;

			// ��
			A_tail->next = B_head;
			B_tail->next = C_head;
		} while (C_head != NULL);

		return fake_head->next;
	}

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
