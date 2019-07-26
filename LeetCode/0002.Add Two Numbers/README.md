# 2. 两数相加 | Add Two Numbers

**题目:**

给出两个**非空**的链表用来表示两个非负的整数。其中，它们各自的位数是按照**逆序**的方式存储的，并且它们的每个节点只能存储**一位**数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 **0** 之外，这两个数都不会以 **0** 开头。

**示例:**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

## 思路

两个整数都是按位**逆序**存储的，正好可以从低位相加，记录进位再进行下一位计算。

三个 `while` 循环中的内容基本一致，看到其他人提交的代码都是一个 `while` 就解决，但是需要每次都判断指针是否为空，空的就加上**0**，所以每次执行代码一致。

执行用时一次为 ***60ms***，一次为 ***32ms***，代码没有改动，很神奇，应该是测试用例不一样的原因。

> 链表很久没用过，忘记先分配空间再将指针移向下一个节点。

```cpp
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
```



