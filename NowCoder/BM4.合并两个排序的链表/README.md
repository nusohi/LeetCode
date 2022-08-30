# BM4.合并两个排序的链表

> 【简单】

**描述**

输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。

**数据范围**： $0 \le n \le 1000$，$-1000 \le 节点值 \le 1000$
**要求**：空间复杂度 $O(1)$，时间复杂度 $O(n)$

如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6}，转换过程如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20211014/423483716_1634208575589/09DD8C2662B96CE14928333F055C5580)

或输入{-1,2,4},{1,3,4}时，合并后的链表为{-1,1,2,3,4,4}，所以对应的输出为{-1,1,2,3,4,4}，转换过程如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20211014/423483716_1634208729766/8266E4BFEDA1BD42D8F9794EB4EA0A13)

**示例1**

```
输入：{1,3,5},{2,4,6}
返回值：{1,2,3,4,5,6}
```

**示例2**

```
输入：{},{}
返回值：{}
```

**示例3**

```
输入：{-1,2,4},{1,3,4}
返回值：{-1,1,2,3,4,4}
```

## 思路

就是归并，注意链表是否为空即可。

**执行时间**：***5ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=152139783)】

```cpp
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL)return pHead2;
		if (pHead2 == NULL)return pHead1;

		ListNode* head = NULL, * tail = NULL;
		if (pHead1->val < pHead2->val) {
			head = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			head = pHead2;
			pHead2 = pHead2->next;
		}
		tail = head;

		while (pHead1 != NULL && pHead2 != NULL) {
			if (pHead1->val < pHead2->val) {
				tail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				tail->next = pHead2;
				pHead2 = pHead2->next;
			}
			tail = tail->next;
		}

		if (pHead1 == NULL)
			tail->next = pHead2;
		if (pHead2 == NULL)
			tail->next = pHead1;

		return head;
	}
};
```

