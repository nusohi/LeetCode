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
		// 不需处理的情况： 1.k==1 2.没有节点
		if (k == 1 || head == NULL) return head;

		// 生成 fake_head 以便于执行
		ListNode* fake_head = new ListNode(0);
		fake_head->next = head;

		// ABC 三段的头尾
		ListNode* temp,
			* A_tail = NULL,
			* B_head = NULL,
			* B_tail = fake_head,	// 初始状态：假定 fake_head 前面为上一次循环的 B 段
			* C_head = NULL;
		int count;

		do {
			// 根据上一轮的 B_tail 初始化
			A_tail = B_tail;
			B_head = B_tail->next;
			B_tail = B_head;

			count = 0;	// 记录 B 段节点数
			while (++count < k) {
				B_tail = B_tail->next;
				// 剩余节点不够了
				if (B_tail == NULL) {
					break;
				}
			}
			// count != k 时剩余不需反转
			if (count != k) {
				return fake_head->next;
			}

			C_head = B_tail->next;
			// 分
			B_tail->next = NULL;
			A_tail->next = NULL;

			temp = ReverseList(B_head);
			B_tail = B_head;
			B_head = temp;

			// 合
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
