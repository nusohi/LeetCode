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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode* A = pHead1, * B = pHead2;

        if (A == NULL || B == NULL) return NULL;

        while (A != B) {
            A = A->next;
            B = B->next;

            // 此时两链表没有交集，同时到达链表末尾
            // fix: 错误，未考虑两链表长度相同，在中间有交点的情况
            if (A == NULL && B == NULL) return NULL;

            if (A == NULL) A = pHead2;
            if (B == NULL) B = pHead1;
        }
        return A;
    }

    ListNode* FindFirstCommonNode_2(ListNode* pHead1, ListNode* pHead2) {
        ListNode* A = pHead1, * B = pHead2;
        bool doneA = false, doneB = false;

        if (A == NULL || B == NULL) return NULL;

        while (A != B) {
            A = A->next;
            B = B->next;

            if (A == NULL && !doneA) {
                A = pHead2;
                doneA = true;
            }
            if (B == NULL && !doneB) {
                B = pHead1;
                doneB = true;
            }
        }
        return A;
    }
};
