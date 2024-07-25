#include<vector>
#include"include/tree.hpp"
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    TreeNode* helper(int left, int right, vector<int>& inorder, vector<int>& postorder) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();

        int idx = idx_map[root->val];//在中序序列查找根结点

        root->right = helper(idx + 1, right, inorder, postorder);
        root->left = helper(left, idx - 1, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = 0;

        for (auto& val : inorder) idx_map[val] = idx++;

        return helper(0, inorder.size() - 1, inorder, postorder);
    }

private:
    unordered_map<int, int> idx_map;
};

