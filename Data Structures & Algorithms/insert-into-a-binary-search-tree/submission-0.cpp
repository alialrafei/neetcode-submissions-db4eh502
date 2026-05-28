/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void InsertIntoBST(TreeNode*& root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return;
        }

        if (root->val < val) {
            if (root->right)
                InsertIntoBST(root->right, val);
            else
                root->right = new TreeNode(val);
        } else {
            if (root->left)
                InsertIntoBST(root->left, val);
            else
                root->left = new TreeNode(val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        InsertIntoBST(root, val);
        return root;
    }
};