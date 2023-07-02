#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> value2index;        // nums1
        vector<int> stack;
        vector<int> result(nums1.size(), -1);

        for (int i = 0, size = nums1.size(); i < size; i++) {
            value2index.insert(pair<int, int>(nums1[i], i));
        }

        for (int i = 0, size = nums2.size(); i < size; i++) {
            // 检查 stack 有元素则比较
            while (stack.size() > 0) {
                // while 到栈中元素比 nums2[i] 大时跳出
                if (stack.back() > nums2[i]) break;
                int index = value2index[stack.back()];
                result[index] = nums2[i];
                stack.pop_back();
            }

            // map 中没有则说明不在 Nums1 中，跳过
            if (value2index.find(nums2[i]) == value2index.end()) continue;
            // 在则入栈即可
            stack.push_back(nums2[i]);
        }

        return result;
    }
};
