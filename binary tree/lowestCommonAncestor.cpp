#include<vector>
#include<iostream>
#include"include/tree.hpp"

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root->val == p->val || root->val == q->val) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr) return right;
    if (right == nullptr) return left;

    return root;
}

int main() {
    // 构建一个示例二叉树
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // 定义要查找最近公共祖先的节点
    TreeNode* p = root->left;        // 节点5
    TreeNode* q = root->left->right->right; // 节点4

    // 调用函数并输出结果
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << std::endl;
    }
    else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    // 释放内存（这一步在实际应用中需要更完善的内存管理）
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}