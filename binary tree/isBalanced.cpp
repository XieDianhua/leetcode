#include<vector>
#include"include/tree.hpp"
#include<algorithm>

using namespace std;

int getDepth(TreeNode* root) {
    int leftDepth, rightDepth, D;

    if (root) {
        leftDepth = getDepth(root->left);   //求左子树深度
        rightDepth = getDepth(root->right);
        D = leftDepth > rightDepth ? leftDepth : rightDepth;

        return (D + 1);  //返回树的深度
    }
    else return 0;  //空树的深度为0
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;  //递归终止条件,遍历到叶结点了
    else {
        return (abs(getDepth(root->left) - getDepth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
}