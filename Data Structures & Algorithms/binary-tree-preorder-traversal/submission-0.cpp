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
    void PreorderTraversal(TreeNode* root,vector<int>& ordered_tree){
        if(root == NULL)
            return;

        ordered_tree.push_back(root->val);
        
         if(root->left)
            PreorderTraversal(root->left,ordered_tree);

        if(root->right)
            PreorderTraversal(root->right,ordered_tree);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ordered_tree;
        PreorderTraversal(root,ordered_tree);
        return ordered_tree;
    }
};

