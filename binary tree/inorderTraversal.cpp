#include<vector>
#include"tree.hpp"
#include<stack>

using namespace std;

class Solution {
public:

    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        inorder(root, result);

        return result;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* T;
        stack<TreeNode*> stk;
        vector<int> result;

        T = root;
        while (T || !stk.empty()) {
            while (T) {
                stk.push(T);
                T = T->left;
            }

            T = stk.top();
            stk.pop();
            result.push_back(T->val);
            T = T->right;
        }
    }
};