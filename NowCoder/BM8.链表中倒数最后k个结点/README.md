# BM8.链表中倒数最后k个结点

> 【简单】

**描述**

输入一个长度为 n 的链表，设链表中的元素的值为 $a_i$ ，返回该链表中倒数第 k 个节点。

如果该链表长度小于 k，请返回一个长度为 0 的链表。

数据范围：$0 \leq n \leq 10^5$，$0 \leq a_i \leq 10^9$，$0 \leq k \leq 10^9$

要求：空间复杂度 $O(n)$，时间复杂度 $O(n)$

进阶：空间复杂度 $O(1)$，时间复杂度 $O(n)$

例如输入{1,2,3,4,5},2 时，对应的链表结构如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20211105/423483716_1636084313645/5407F55227804F31F5C5D73558596F2C)

其中蓝色部分为该链表的最后2个结点，所以返回倒数第2个结点（也即结点值为4的结点）即可，系统会打印后面所有的节点来比较。

**示例1**

```
输入：{1,2,3,4,5},2
返回值：{4,5}
说明：返回倒数第2个节点4，系统会打印后面所有的节点来比较。 
```

**示例2**

```
输入：{2},8
返回值：{}
```

## 思路

两个指针一前一后，相差 k 个节点。

**执行时间**：***33ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=400405891)】

```python
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
```

