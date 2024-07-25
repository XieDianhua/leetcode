#include<vector>
#include"include/tree.hpp"
#include<queue>

using namespace std;

int countNodes(TreeNode* root) {
    if (!root)
        return 0;

    int cntNode = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        cntNode++;
        auto node = q.front();q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return cntNode;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}