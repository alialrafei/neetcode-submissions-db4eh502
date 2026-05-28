class Solution {
public:
    bool SameTree(TreeNode* root, TreeNode* sub_root) {

        if (root == nullptr && sub_root == nullptr) {

            return true;
        }

        if (root == nullptr || sub_root == nullptr) {

            return false;
        }

        if (root->val != sub_root->val) {

            return false;
        }

        return SameTree(root->left, sub_root->left) &&
               SameTree(root->right, sub_root->right);
    }

    bool IsSubTree(TreeNode* root, TreeNode* sub_root) {

        if (root == nullptr) {
            return false;
        }
        if (SameTree(root, sub_root)) {
            return true;
        }
         
        return IsSubTree(root->left, sub_root) || IsSubTree(root->right, sub_root);

       
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return IsSubTree(root, subRoot);
    }
};