#include<vector>
#include"include/tree.hpp"
#include<algorithm>

using namespace std;

TreeNode* helper(int left, int right, const vector<int>& nums) {
    if (left > right) {
        return nullptr;
    }
    // 1. 从数组中获取根结点--给定序列最大值
    int max = left;
    for (int i = left + 1; i <= right; ++i) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }
    TreeNode* node = new TreeNode(nums[max]);

    // 2. 根据根结点位置将数组分为左右子树并递归构建树
    node->left = helper(left, max - 1, nums);
    node->right = helper(max + 1, right, nums);
    return node;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(0, nums.size() - 1, nums);
}