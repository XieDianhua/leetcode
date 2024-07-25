#include<vector>
#include"include/tree.hpp"

using namespace std;

TreeNode* findMin(TreeNode* root) {
    if (root == nullptr) return nullptr;
    else if (root->left == nullptr) return root;
    else return findMin(root->left);
}
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* tmp;
    if (root == nullptr)
        return nullptr;
    else {
        //查找操作
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        //找到了目标值，进行删除操作
        else {//待删除结点有左右子树
            if (root->left && root->right) {
                tmp = findMin(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }//待删除结点为叶结点或只有一个子结点（其不一定是叶结点，可能是子树的根）
            else {
                tmp = root;
                if (root->left == nullptr)
                    root = root->right;
                else
                    root = root->left;
                delete tmp;
            }
        }
    }

    return root;
}