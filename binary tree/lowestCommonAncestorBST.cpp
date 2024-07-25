#include<vector>
#include"include/tree.hpp"

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root->val == p->val || root->val == q->val) return root;    //根结点等于p或q

    // p或q位于同一子树
    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

    return root;
}