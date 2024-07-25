#include "include/tree.hpp"
#include <vector>
#include<limits.h>

using namespace std;

bool helper(TreeNode* root, long long left, long long right) {
    if (root == nullptr) return true;
    if (root->val <= left || root->val >= right) return false;

    return helper(root->left, left, root->val) &&//验证左子树，须保证左边界不变，右边界小于当前结点值
        helper(root->right, root->val, right);
}
bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}