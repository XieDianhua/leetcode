#include<vector>
#include"include/tree.hpp"
#include<unordered_map>

using namespace std;

/* void helper(TreeNode* root, unordered_map<int, int>& hashTable) {
    if (root == nullptr) return;

    hashTable[root->val]++;
    helper(root->left, hashTable);
    helper(root->right, hashTable);
}

vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> hashTable;

    helper(root, hashTable);

    int maxFrequency = 0;
    for (const auto& [key, value] : hashTable) {
        if (value > maxFrequency)
            maxFrequency = value;
    }

    vector<int> res;
    for (const auto& [key, value] : hashTable) {
        if (value == maxFrequency)
            res.push_back(key);
    }

    return res;
} */


class Solution {
public:
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;

        dfs(root->left);

        prev_ == root->val ? cnt_++ : cnt_ = 1;
        prev_ = root->val;
        if (cnt_ == max_cnt_)
            res_.push_back(root->val);
        else if (cnt_ > max_cnt_) {
            max_cnt_ = cnt_;
            res_ = vector<int>{ root->val };
        }

        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        prev_ = root->val, cnt_ = 0, max_cnt_ = 0;
        dfs(root);
        return res_;
    }

private:
    int cnt_, max_cnt_, prev_;
    vector<int> res_;
};