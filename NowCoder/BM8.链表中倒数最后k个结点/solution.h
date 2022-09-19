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
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode* fast = pHead, * slow = pHead;
        // fast 先走 k 步，
        while (k > 0 && fast != NULL) {
            fast = fast->next;
            k--;
        }

        if (fast == NULL) {
            // 头节点正好是倒 k 节点
            if (k == 0)
                return slow;
            else
                return NULL;
        }

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
