#include<vector>
#include"include/tree.hpp"

using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return nullptr;

    if (val > root->val)
        return searchBST(root->right, val);
    else if (val < root->val)
        return searchBST(root->left, val);
    else
        return root;
}