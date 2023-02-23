#include <iostream>
using namespace std;


class Solution {
public:
    int reachNumber(int target) {
        // 正负都一样，取正值
        if (target < 0) target = -target;

        // 累加得到特殊点
        int point = 1, steps = 1;
        while (point < target) {
            point += ++steps;
        }

        // 最前面的特殊点已经等于 target
        if (point == target) return steps;
        // 该点差距是偶数的话就可以通过改变 + 号到达
        else if ((point - target) % 2 == 0)return steps;
        // 下一个点差距是偶数的话也可以
        else if ((point + ++steps - target) % 2 == 0) return steps;
        // 如果不是偶数则下下一个一定是偶数
        else return ++steps;
    }
};
