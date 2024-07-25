#include<vector>
#include<queue>
#include"tree.hpp"

using namespace std;

// 层序遍历实现
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front(); q.pop();

        TreeNode* tmpNode = node->left;
        node->left = node->right;
        node->right = tmpNode;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return root;
}

// 递归前序遍历实现
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return;

    // 翻转子树
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    // 交换已翻转的子树（翻转了整棵树）
    root->left = right;
    root->right = left;

    return root;

}