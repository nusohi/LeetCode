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
    ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        ListNode* fast = head, * slow = head;
        // fast 先走 n+1 步，slow 指向 `倒 n 节点` 的前一个节点
        while (n >= 0 && fast != NULL) {
            fast = fast->next;
            n--;
        }

        // 头节点就是倒 n 节点
        if (fast == NULL && n == 0) {
            return head->next;
        }

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};
