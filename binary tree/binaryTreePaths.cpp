#include<vector>
#include"include/tree.hpp"
#include<string>
#include<queue>

using namespace std;

void construct_paths(TreeNode* root, string path, vector<string>& paths) {
    if (root == nullptr) return;

    path += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {  // 当前节点是叶子节点
        paths.push_back(path);
    }
    else {
        path += "->";  // 当前节点不是叶子节点，继续递归遍历
        construct_paths(root->left, path, paths);
        construct_paths(root->right, path, paths);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    construct_paths(root, "", paths);
    return paths;
}
