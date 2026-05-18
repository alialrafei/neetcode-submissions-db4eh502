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
    void PostOrderTraversal(TreeNode* root,vector<int>& ordered_tree){
        if(root == NULL)
            return;
        
        if(root->left)
            PostOrderTraversal(root->left,ordered_tree);

        if(root->right)
            PostOrderTraversal(root->right,ordered_tree);
            
        ordered_tree.push_back(root->val);

        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ordered_tree;
        PostOrderTraversal(root,ordered_tree);
        return ordered_tree;
    }
};