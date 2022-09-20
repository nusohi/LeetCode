# BM9.删除链表的倒数第n个节点

> 【中等】

**描述**

给定一个链表，删除链表的倒数第 $n$ 个节点并返回链表的头指针
例如，

给出的链表为: $1\to 2\to 3\to 4\to 5$, $n= 2$.
删除了链表的倒数第 $n$ 个节点之后,链表变为 $1\to 2\to 3\to 5$.

数据范围： 链表长度 $0\le n \le 1000$，链表中任意节点的值满足 $0 \le val \le 100$

要求：空间复杂度 $O(1)$，时间复杂度 $O(n)$
备注：

题目保证 $n$ 一定是有效的

**示例1**

```
输入：{1,2},2    
返回值：{2} 
```

## 思路

基于 BM8 修改：`slow` 指向 `倒 k 节点` 的前一个节点，也就是说 `fast` 先多走 `k+1` 步。注意边界即可。

**执行时间**：***6ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=400435321)】

```python
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
```

