#include<vector>
#include<stack>
#include"tree.hpp"

using namespace std;

class Solution {
public:
    // 辅助函数
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);   //1. 访问根结点
        preorder(root->left, res);  //2. 前序遍历左子树
        preorder(root->right, res); //3. 前序遍历右子树
    }

    // 递归遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        preorder(root, result);

        return result;
    }

    // 迭代遍历
    vector<int> preorderTraversal(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> stk;
        vector<int> result;
        TreeNode* T = root;

        // 1. 遍历树结点
        while (T || !stk.empty()) {
            // 1.1 一直向左将并沿途结点压入堆栈
            while (T) {
                result.push_back(T->val);
                stk.push(T);
                T = T->left;
            }

            // 1.2 到了左结点尽头，返回上一结点
            T = stk.top();
            stk.pop();
            T = T->right;
        }
        return result;
    }
};