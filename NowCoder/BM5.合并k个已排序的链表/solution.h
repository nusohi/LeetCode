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
