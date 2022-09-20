# BM10.两个链表的第一个公共结点

> 【简单】

**描述**

输入两个无环的单向链表，找出它们的第一个公共结点，如果没有公共节点则返回空。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

数据范围： $n \le 1000$
要求：空间复杂度 $O(1)$，时间复杂度 $O(n)$

例如，输入 {1,2,3},{4,5},{6,7} 时，两个无环的单向链表的结构如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20211104/423483716_1635999204882/394BB7AFD5CEA3DC64D610F62E6647A6)

可以看到它们的第一个公共结点的结点值为 6，所以返回结点值为 6 的结点。

**输入描述：**

输入分为是 3 段，第一段是第一个链表的非公共部分，第二段是第二个链表的非公共部分，第三段是第一个链表和第二个链表的公共部分。 后台会将这 3 个参数组装为两个链表，并将这两个链表对应的头节点传入到函数 `FindFirstCommonNode` 里面，用户得到的输入只有 `pHead1` 和 `pHead2`。

**返回值描述：**

返回传入的 `pHead1` 和 `pHead2` 的第一个公共结点，后台会打印以该节点为头节点的链表。

**示例1**

```
输入：{1,2,3},{4,5},{6,7}
返回值：{6,7}
说明：
第一个参数{1,2,3}代表是第一个链表非公共部分，第二个参数{4,5}代表是第二个链表非公共部分，最后的{6,7}表示的是2个链表的公共部分
这3个参数最后在后台会组装成为2个两个无环的单链表，且是有公共节点的          
```

**示例2**

```
输入：{1},{2,3},{}
返回值：{}
说明：2个链表没有公共节点 ,返回null，后台打印{}       
```

## 思路

如图。`a+c + b  == b+c + a`

![https://uploadfiles.nowcoder.com/files/20210621/908787715_1624289962297/36.gif](https://uploadfiles.nowcoder.com/files/20210621/908787715_1624289962297/36.gif)

**执行时间**：***4ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=400523485)】

```python
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    ListNode* A = pHead1, * B = pHead2;

    if (A == NULL || B == NULL) return NULL;

    while (A != B) {
        A = A->next;
        B = B->next;
        
        // 此时两链表没有交集，同时到达链表末尾
        // fix: 错误，未考虑两链表长度相同，在中间有交点的情况
        if (A == NULL && B == NULL) return NULL;

        if (A == NULL) A = pHead2;
        if (B == NULL) B = pHead1;
    }
    return A;
}
```

> 上面代码未考虑两链表长度相同，在中间有交点的情况，但例子都过了。

应用 `bool done_A` 代表 `A` 已换过链表，就不需要在 `while` 里考虑 `A` `B` 同时到达末尾了。

**执行时间**：***3ms*** 【[Submission Detail](https://www.nowcoder.com/profile/443580699/codeBookDetail?submissionId=400524170)】

```python
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    ListNode* A = pHead1, * B = pHead2;
    bool doneA = false, doneB = false;

    if (A == NULL || B == NULL) return NULL;

    while (A != B) {
        A = A->next;
        B = B->next;

        if (A == NULL && !doneA) {
            A = pHead2;
            doneA = true;
        }
        if (B == NULL && !doneB) {
            B = pHead1;
            doneB = true;
        }
    }
    return A;
}
```

