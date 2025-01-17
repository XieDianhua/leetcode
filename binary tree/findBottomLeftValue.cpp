#include<vector>
#include"include/tree.hpp"
#include<queue>

using namespace std;

int findBottomLeftValue(TreeNode* root) {
    TreeNode* node;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        node = q.front(); q.pop();
        if (node->right) q.push(node->right);
        if (node->left)  q.push(node->left);
    }
    return node->val;
}