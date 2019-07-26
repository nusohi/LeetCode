# 11. 盛最多水的容器 | Container With Most Water

**题目:**

给定 `n` 个非负整数 `a1`，`a2`，...，`an`，每个数代表坐标中的一个点 `(i, ai)` 。在坐标内画 `n` 条垂直线，垂直线 `i` 的两个端点分别为 `(i, ai)` 和 `(i, 0)`。找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

**说明**：你不能倾斜容器，且 `n` 的值至少为 2。

![图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

**示例:**

```
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
```

## 思路

### 双指针法

两个指针分别放在首尾，使得宽度最大，记录为此刻最大面积。此时缩小较短端，即短端指针向另一端移动，再次记录面积并比较，以此类推。执行时间 ***24ms***。（[Submission Detail](https://leetcode-cn.com/submissions/detail/24047719/)）

```cpp
int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int maxS = 0, S;
    while (j > i) {
        if (height[i] > height[j]) {
            S = height[j] * (j - i);
            j--;
        }
        else {
            S = height[i] * (j - i);
            i++;
        }
        maxS = S > maxS ? S : maxS;
    }
    return maxS;
}
```

**[正确性说明](https://leetcode-cn.com/problems/two-sum/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)：**

- 水槽的高度由两板中的短板决定，每次收缩，都会导致水槽底边宽度 -1
- 因此，若想找到比当前最大值更大的水槽，那么水槽的短板高必须要高于上一个水槽短板高，而只有向内移动短板，有可能达成这一条件（若移动长板，下个水槽的面积一定小于当前水槽面积）