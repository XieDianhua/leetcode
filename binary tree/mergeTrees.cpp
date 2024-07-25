#include<vector>
#include"include/tree.hpp"

using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;

        int v1 = 0, v2 = 0;
        root1 ? v1 = root1->val : v1 = 0;
        root2 ? v2 = root2->val : v2 = 0;
        TreeNode* merge_root = new TreeNode(v1 + v2);

        merge_root->left = mergeTrees(root1 ? root1->left : nullptr,
            root2 ? root2->left : nullptr);
        merge_root->right = mergeTrees(root1 ? root1->right : nullptr,
            root2 ? root2->right : nullptr);

        return merge_root;
    }
};

int main() {
    Solution sol;

    // 示例树
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    // 合并树
    TreeNode* mergedTree = sol.mergeTrees(root1, root2);

    return 0;
}