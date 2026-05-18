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
class Solution{
public:
    void InorderTraversal(TreeNode* root,vector<int>& inorder_tree){
        if(root == NULL)
            return;
        //right 
        if(root->left)
            InorderTraversal(root->left,inorder_tree);
        inorder_tree.push_back(root->val);
        //left
        if(root->right)
            InorderTraversal(root->right,inorder_tree);
    }
    vector<int> inorderTraversal(TreeNode* root){
        if(root == NULL)
            return {};
        vector<int> inorder_tree; 
        InorderTraversal(root,inorder_tree);

        return inorder_tree;
    }
};