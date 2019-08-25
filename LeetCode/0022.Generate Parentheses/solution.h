/*
 * @Description: 22. 括号生成
 * @Author: nuso
 * @Date: 2019-08-25 22:04:29
 * @LastEditTime: 2019-08-25 22:43:22
 * @LastEditors: nuso
 */
#include <vector>
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        fun(res, "", 0, 0, n);
        return res;
    }

    void fun(vector<string> &res, string str, int left, int right, int max) {
        if (str.length() == max * 2) {
            res.push_back(str);
            return;
        }
        if (left < max)
            fun(res, str + "(", left + 1, right, max);
        if (left > right)
            fun(res, str + ")", left, right + 1, max);
    }
};
