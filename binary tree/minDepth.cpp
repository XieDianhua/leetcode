#include"include/tree.hpp"
#include<climits>

int minDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;  //空树的深度为0
    if (root->left == nullptr && root->right == nullptr)
        return 1;   //无子树的结点深度为1

    int minD = INT_MAX;
    if (root->left != nullptr) {
        minD = minDepth(root->left) < minD ? minDepth(root->left) : minD;
    }
    if (root->right != nullptr) {
        minD = minDepth(root->right) < minD ? minDepth(root->right) : minD;
    }

    return (minD + 1);  //返回树的深度
}