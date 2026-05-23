/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int DiameterOfBinaryTree(TreeNode* root, int& tree_diameter) {
        if (root == NULL)
            return -1;

        int right = DiameterOfBinaryTree(root->right, tree_diameter);
        int left = DiameterOfBinaryTree(root->left, tree_diameter);

        tree_diameter = max(tree_diameter, left + right + 2);

        return 1 + max(right, left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int tree_diameter = 0;
        return max(tree_diameter, DiameterOfBinaryTree(root, tree_diameter));
    }
};