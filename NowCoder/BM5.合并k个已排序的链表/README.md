# BM5.合并k个已排序的链表

> 【较难】

**描述**

合并 $k$ 个升序的链表并将结果作为一个升序的链表返回其头节点。

数据范围：节点总数满足 $0 \le n \le 10^5$，链表个数满足 $1 \le k \le 10^5$ ，每个链表的长度满足 $1 \le len \le 200$ ，每个节点的值满足 $|val| <= 1000$

要求：时间复杂度 $O(nlogk)$

**示例1**

```
输入：[{1,2,3},{4,5,6,7}]
返回值：{1,2,3,4,5,6,7}
```

**示例2**

```
输入：[{1,2},{1,4,5},{6}]
返回值：{1,1,2,4,5,6}
```

## 思路

用最小堆 `priority_queue in <queue>` 存储每个链表的第一个元素，每次取最小的一个放入结果中，对应的链表下一个元素入堆。

> 题目的界限写错了，链表个数可以为 0，链表中的节点数也可以为 0.
>
> 也可以用两两归并的方法解。

**执行时间**：***59ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=152149519)】

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct HeapNode {
	int val;
	int index;
	HeapNode(int val, int index) :val(val), index(index) {}
	friend bool operator <(const HeapNode& a, const HeapNode& b) { return a.val < b.val; }
	friend bool operator >(const HeapNode& a, const HeapNode& b) { return a.val > b.val; }
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)return NULL;
		else if (lists.size() == 1)return lists[0];

		// 最小堆 初始化
		priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> heap;
		for (int i = 0, size = lists.size(); i < size; i++) {
			if (lists[i] != NULL)
				heap.push(HeapNode(lists[i]->val, i));
		}

		ListNode* head = NULL, * tail = NULL;

		// 初始化 head 和 tail
		int index = heap.top().index;
		heap.pop();
		ListNode* node = lists[index];
		head = tail = node;

		// 新元素入堆
		lists[index] = node->next;
		if (lists[index] != NULL) {
			heap.push(HeapNode(lists[index]->val, index));
		}

		while (!heap.empty()) {
			// 找到最小的节点 index
			index = heap.top().index;
			heap.pop();
			node = lists[index];
			// 节点接上 tail
			tail->next = node;
			tail = node;

			// 新元素入堆
			lists[index] = node->next;
			if (lists[index] != NULL) {
				heap.push(HeapNode(lists[index]->val, index));
			}
		}

		return head;
	}
};
```

