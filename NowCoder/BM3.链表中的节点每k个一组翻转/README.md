# **BM3** 链表中的节点每k个一组翻转

> 【**中等**】

**描述**

将给出的链表中的节点每 $k$ 个一组翻转，返回翻转后的链表
如果链表中的节点数不是 $k$ 的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。

**数据范围**： $0 \le n \le 2000$ ， $1 \le k \le 2000$，链表中每个元素都满足 $0 \le val \le 1000$
要求空间复杂度 $O(1)$，时间复杂度 $O(n)$

**例如**：

给定的链表是 $1\to2\to3\to4\to5$

对于 $k = 2$ , 你应该返回 $2\to 1\to 4\to 3\to 5$

对于 $k = 3$ , 你应该返回 $3\to2 \to1 \to 4\to 5$

**示例1**

```
输入：{1,2,3,4,5},2
返回值：{2,1,4,3,5}
```

**示例2**

```
输入：{},1
返回值：{}
```

## 思路

复用 [BM1.反转链表](../BM1.反转链表) 中的单链表逆置函数。



**执行时间**：***4ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=146837275)】

```cpp
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		// 不需处理的情况： 1.k==1 2.没有节点
		if (k == 1 || head == NULL) return head;

		// 生成 fake_head 以便于执行
		ListNode* fake_head = new ListNode(0);
		fake_head->next = head;

		// ABC 三段的头尾
		ListNode* temp,
			* A_tail = NULL,
			* B_head = NULL,
			* B_tail = fake_head,	// 初始状态：假定 fake_head 前面为上一次循环的 B 段
			* C_head = NULL;
		int count;

		do {
			// 根据上一轮的 B_tail 初始化
			A_tail = B_tail;
			B_head = B_tail->next;
			B_tail = B_head;

			count = 0;	// 记录 B 段节点数
			while (++count < k) {
				B_tail = B_tail->next;
				// 剩余节点不够了
				if (B_tail == NULL) {
					break;
				}
			}
			// count != k 时剩余不需反转
			if (count != k) {
				return fake_head->next;
			}

			C_head = B_tail->next;
			// 分
			B_tail->next = NULL;
			A_tail->next = NULL;

			temp = ReverseList(B_head);
			B_tail = B_head;
			B_head = temp;

			// 合
			A_tail->next = B_head;
			B_tail->next = C_head;
		} while (C_head != NULL);

		return fake_head->next;
	}

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

