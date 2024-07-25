#include<vector>
#include"include/tree.hpp"
#include<queue>
#include<iostream>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;  //定义一个二维向量，即每个向量元素又是一个向量
        if (!root) {
            return ret;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(std::vector<int>());  //每遍历一层，就添加一个向量存储该层的值

            // i 当前层级已遍历结点数 currentLevelSize 当前层级包含结点数
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);    //将当前节点的值 node->val 添加到 ret 向量的最后一个向量中
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ret;
    }
};

