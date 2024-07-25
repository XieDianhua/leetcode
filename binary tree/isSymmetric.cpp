#include<vector>
#include"include/tree.hpp"

using namespace std;

bool isMirror(TreeNode* left, TreeNode* right) {
    // 1. 排除含空结点情况
    if (!left && !right) return true;//左右都是空
    else if (!left || !right) return false; //左子树或右子树有一个为空

    // 2. 非空但值不相等
    if (left->val != right->val) return false;

    // 左右都不为空，且数值相同的情况
    bool outSide = isMirror(left->left, right->right);
    bool inSide = isMirror(left->right, right->left);
    bool isSame = outSide && inSide;

    return isSame;
}

//
bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}
