#include<vector>
#include"include/tree.hpp"

using namespace std;

class Solution {
public:
    bool dfs(TreeNode* root, int cur_sum, int targetSum) {
        if (root == nullptr)
            return false;

        cur_sum += root->val;
        if (root->left == nullptr &&
            root->right == nullptr) { // 当前结点为叶结点
            return cur_sum == targetSum;
        }

        return dfs(root->left, cur_sum, targetSum) ||
            dfs(root->right, cur_sum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};