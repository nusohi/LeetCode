# BM1 反转列表

> 【**简单**】

**描述**

给定一个单链表的头结点 `pHead` (该头节点是有值的，比如在下图，它的 `val` 是 1)，长度为 n，反转该链表后，返回新链表的表头。

**数据范围**：$0 \leq n \leq 1000$

**要求**：空间复杂度 `O(1)`，时间复杂度 `O(n)` 。

如当输入链表 `{1,2,3}` 时，

经反转后，原链表变为 `{3,2,1}`，所以对应的输出为 `{3,2,1}`。

以上转换过程如下图所示：

![NowCoder BM1 反转列表](https://uploadfiles.nowcoder.com/images/20211014/423483716_1634206291971/4A47A0DB6E60853DEDFCFDF08A5CA249)

**示例1**

```
输入：{1,2,3}
返回值：{3,2,1}
```

**示例2**

```
输入：{}
返回值：{}
说明：空链表则输出空
```

## 思路

1. `n = 0` 时返回空指针；`n = 1` 时不用反转，直接返回。这两种情况合并。
2. 此时 `n >= 2`，先反转前两个，并将链表分成两支。
3. `pHead` 指向反转后的链表头；`p` 指向剩余的链表头；`temp` 用来暂存。
4. `while` 中每次只需将 `p` 指向的节点移动到 `pHead` 链表头。

**执行时间**：***3ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=146554711)】

```cpp
class Solution {
public:
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
```

