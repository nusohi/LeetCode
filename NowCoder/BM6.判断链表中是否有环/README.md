# BM6.判断链表中是否有环

> 【简单】

**描述**

判断给定的链表中是否有环。如果有环则返回 true，否则返回 false。

**数据范围**：链表长度 $0 \le n \le 10000$，链表中任意节点的值满足 $|val| <= 100000$

**要求**：空间复杂度 $O(1)$，时间复杂度 $O(n)$

输入分为两部分，第一部分为链表，第二部分代表是否有环，然后将组成的 `head` 头结点传入到函数里面。-1 代表无环，其它的数字代表有环，这些参数解释仅仅是为了方便读者自测调试。实际在编程时读入的是链表的头节点。

例如输入{3,2,0,-4},1时，对应的链表结构如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20220110/423483716_1641800950920/0710DD5D9C4D4B11A8FA0C06189F9E9C)

可以看出环的入口结点为从头结点开始的第 1 个结点（注：头结点为第 0 个结点），所以输出 true。

**示例1**

```
输入：{3,2,0,-4},1
返回值：true
说明：x 第一部分{3,2,0,-4}代表一个链表，第二部分的1表示，-4到位置1（注：头结点为位置0），即-4->2存在一个链接，组成传入的head为一个带环的链表，返回true             
```

**示例2**

```
输入：{1},-1
返回值：false
说明：第一部分{1}代表一个链表，-1代表无环，组成传入head为一个无环的单链表，返回false       
```

**示例3**

```
输入：{-1,-7,7,-4,19,6,-9,-5,-2,-5},6
返回值：true
```

## 思路

### 思路一：破坏链表结构的解法

> 会破坏链表结构，兴许不能用（但题目没说不行？；）

遍历节点的同时，把节点的 `next` 指向 `head` 或者其他特定值，当后续某个节点的 `next` 为 `head` 时就说明遇到环了。

**执行时间**：***6ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=152320671)】

```cpp
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* node = head->next, *old;
		//head->next = head;

		while (true) {
			old = node;
			node = node->next;
			old->next = head;
			if (node == head) return true;
			else if (node == NULL) return false;
		}
	}
};
```

### 思路二：快慢指针

俩指针，一快一慢，相同则有环，因为快指针每次多走一步，所以在环上绕几圈就一定能赶上慢指针，但是要多绕几圈，兴许算得慢。

> 特殊情况：只有一个节点时注意判断 slow、fast 是否同时为 NULL.

**执行时间**：***7ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=152323850)】

```cpp
class Solution {
public:
	bool hasCycle_2(ListNode* head) {
		ListNode* slow = head, * fast = head;

		while (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
			if (fast)fast = fast->next;
			if (slow == fast && fast != NULL)return true;
		}
		return false;
	}
};
```

### 思路三：set 记录节点地址

用 `set` 记录已访问的节点，新节点已在 `set` 中则说明有环。空间复杂度 $O(n)$，不符合题目要求。
