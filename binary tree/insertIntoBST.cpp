#include<vector>
#include"include/tree.hpp"

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr)  //若原树为空，生成并返回一个结点的二叉搜索树
        return root = new TreeNode(val);

    //开始找要插入元素的位置
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}