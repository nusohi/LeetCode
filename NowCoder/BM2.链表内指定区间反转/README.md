# BM2 链表内指定区间反转

> 【**中等**】

**描述**

将一个节点数为 $size$ 链表 $m$ 位置到 $n$ 位置之间的区间反转，要求时间复杂度 $O(n)$，空间复杂度 $O(1)$。

**例如**：

给出的链表为 $1\to 2 \to 3 \to 4 \to 5 \to NULL$, $m=2$, $n=4$,

返回 $1\to 4\to 3\to 2\to 5\to NULL$.

**数据范围**： 链表长度 $0 < size \le 10000$，$0 < m \le n \le size$，链表中每个节点的值满足 $|val| \le 1000$

**要求**：时间复杂度 $O(n)$，空间复杂度 $O(n)$

**进阶**：时间复杂度 $O(n)$，空间复杂度 $O(1)$

**示例1**

```
输入：{1,2,3,4,5},2,4
返回值：{1,4,3,2,5}
```

**示例2**

```
输入：{5},1,1
返回值：{5}
```

## 思路

将链表分成 *A B C* 三段，不断填充 *B* 段即可。

- `m == n` 时不用反转，直接返回，也避免了 `size == 1` 的讨论。
- `m == 1` 的情况没有 *A* 段，需要特殊讨论。*可以添加一个空的头节点，就能避免这种情况的讨论*。

**执行时间**：***4ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=146689998)】

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)return head;

        ListNode* A_tail, * B_head, * B_tail, * p, * temp;
        int count;

        // 1. 链表拆分成 ABC 三段，`p === C_head`
        // 1.1 找 A_tail 和 B_head, m==1 时不需要 A 段
        if (m == 1) {
            B_head = head;
        }
        else if (m >= 2) {
            count = 1;
            A_tail = head;
            temp = NULL;

            while (++count < m)
                A_tail = A_tail->next;      // A_tail 指向第 m-1 个
            B_head = A_tail->next;
        }
        // 1.2 得到 B_tail 和 C_head（p）
        B_tail = B_head;
        p = B_head->next;

        // 2. B 段不断添加 C 段的头
        count = m;
        while (++count <= n) {
            temp = p;
            p = p->next;
            temp->next = B_head;
            B_head = temp;
        }

        // 3. 拼接三段
        if (m >= 2) {
            A_tail->next = B_head;
        }
        B_tail->next = p;


        return m == 1 ? B_head : head;
    }
};
```

