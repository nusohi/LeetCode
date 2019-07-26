# 23. 合并K个排序链表 | Merge k Sorted Lists

**题目:**

合并 *k* 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```

## 思路

将链表两两合并，直至只剩一个链表。执行时间 ***56ms***。([Submission Detail](https://leetcode-cn.com/submissions/detail/24019981/))

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int len = lists.size();	// len = 5	len/2 = 2	| 0-1   2-3   4
    if (len < 1)return NULL;

    while (len > 1) {
        for (int i = 0; i < len >> 1; i++) {
            lists[i] = merge(lists[i << 1], lists[(i << 1) + 1]);
        }
        // 奇数个链表时，最后一个链表不合并，直接赋给 lists[len/2]  e.g. 5/2=2 7/2=3
        if (len % 2) {
            lists[len >> 1] = lists[len - 1];
            len = (len >> 1) + 1;		// e.g. 3 = 5/2 + 1 (5个 -> 3个)
        }
        else {
            len = len >> 1;
        }
    }

    return lists[0];
}

ListNode* merge(ListNode* A, ListNode* B) {
    ListNode *head = new ListNode(0), *node = head;
    while (A != NULL && B != NULL) {
        if (A->val <= B->val) {
            // 接上 A 的头
            node->next = A;

            // 再找到 A 中下一个不比 B 小的，循环结束后 A 为最后一个比 B 小的
            while (A->next && A->next->val <= B->val) {
                A = A->next;
            }

            node = A;
            A = A->next;
        }
        else {
            node->next = B;
            while (B->next && B->next->val <= A->val) {
                B = B->next;
            }
            node = B;
            B = B->next;
        }
    }

    if (A)
        node->next = A;
    else
        node->next = B;

    return head->next;
}
```

