#include<vector>
#include"include/tree.hpp"
#include<algorithm>
#include<limits.h>

using namespace std;

// int helper(TreeNode* root, int& pre, int& ans) {
//     if (root == nullptr)
//         return;

//     helper(root->left, pre, ans);
//     if (pre == -1) {
//         pre = root->val;
//     }
//     else {
//         ans = min(ans, root->val - pre);
//     }

//     helper(root->right, pre, ans);

// }
// int getMinimumDifference(TreeNode* root) {
//     int ans = INT_MAX, pre = -1;    //用pre保存前驱结点的值

//     helper(root, pre, ans);

//     return ans;
// }

class Solution {
public:
    Solution() : prev(INT_MIN), res(INT_MAX) {}
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;

        dfs(root->left);

        if (prev != INT_MIN)
            res = min(res, root->val - prev);
        prev = root->val;

        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    int prev, res;
};

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = nullptr;
    root->right = new TreeNode(2236);
    root->right->left = new TreeNode(1277);
    root->right->right = new TreeNode(2776);
    root->right->left->left = new TreeNode(519);

    int min = 0;
    Solution test;
    min = test.getMinimumDifference(root);

    return 0;
}