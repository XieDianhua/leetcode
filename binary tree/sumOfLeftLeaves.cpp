#include<vector>
#include"include/tree.hpp"

using namespace std;

int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;

    int sum_of_left_leaves = 0;

    if (root->left != nullptr) {   //左结点不为空
        if (root->left->left != nullptr && root->left->right != nullptr) {
            sum_of_left_leaves += root->left->val;
        }
        else {
            sumOfLeftLeaves(root->left);
        }
    }
    if (root->right != nullptr) {
        if (root->right->left != nullptr && root->right->right != nullptr) {
            sum_of_left_leaves += sumOfLeftLeaves(root->right);
        }
    }

    return sum_of_left_leaves;

}