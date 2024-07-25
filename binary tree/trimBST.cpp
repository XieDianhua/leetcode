#include <iostream>
#include"include/tree.hpp"

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return nullptr;

        if (root->val > high)
            return trimBST(root->left, low,
                high); // 当前根结点都大于high，直接去修剪左子树
        if (root->val < low)
            return trimBST(root->right, low, high);

        // 根结点值等于low/high，则分别递归修剪左右子树（等于边界值不会被修剪）
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
