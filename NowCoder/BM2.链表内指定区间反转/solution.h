#include <iostream>
using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
};


class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)return head;

        ListNode* A_tail, * B_head, * B_tail, * p, * temp;
        int count;

        // 1. 链表拆分成 ABC 三段，`p === C_head`
        // 1.1 找 A_tail 和 B_head, m==1 时不需要 A 段
        if (m == 1) {
            B_head = head;
        }
        else if (m >= 2) {
            count = 1;
            A_tail = head;
            temp = NULL;

            while (++count < m)
                A_tail = A_tail->next;      // A_tail 指向第 m-1 个
            B_head = A_tail->next;
        }
        // 1.2 得到 B_tail 和 C_head（p）
        B_tail = B_head;
        p = B_head->next;

        // 2. B 段不断添加 C 段的头
        count = m;
        while (++count <= n) {
            temp = p;
            p = p->next;
            temp->next = B_head;
            B_head = temp;
        }

        // 3. 拼接三段
        if (m >= 2) {
            A_tail->next = B_head;
        }
        B_tail->next = p;


        return m == 1 ? B_head : head;
    }
};
