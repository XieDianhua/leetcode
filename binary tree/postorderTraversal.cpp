#include<vector>
#include<stack>
#include"include/tree.hpp"
#include<iostream>
#include<assert.h>

using namespace std;

void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;

    postorder(root, result);

    return result;
}

// vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> res;
//     if (root == nullptr) {
//         return res;
//     }

//     stack<TreeNode*> stk;
//     TreeNode* prev = nullptr;
//     while (root != nullptr || !stk.empty()) {
//         while (root != nullptr) {   //一直向左并将沿途结点压入堆栈
//             stk.emplace(root);
//             root = root->left;
//         }

//         // 记录栈顶数据并弹出堆栈
//         root = stk.top();
//         stk.pop();

//         if (root->right == nullptr || root->right == prev) {
//             res.emplace_back(root->val);    //访问结点
//             prev = root;
//             root = nullptr;
//         }
//         else {
//             stk.emplace(root);
//             root = root->right;
//         }
//     }
//     return res;
// }

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 期望的后序遍历结果
    std::vector<int> expected = { 4, 5, 2, 3, 1 };

    // 调用函数获取结果
    std::vector<int> result = postorderTraversal(root);

    // 检查结果是否与期望一致
    assert(result == expected);

    std::cout << "测试通过！" << std::endl;
}



