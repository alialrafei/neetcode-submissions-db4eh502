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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> tree_1;
        queue<TreeNode*> tree_2;
        tree_1.push(p);
        tree_2.push(q);
        while (!tree_1.empty() && !tree_2.empty()) {
            TreeNode* node_1 = tree_1.front();
            TreeNode* node_2 = tree_2.front();
            tree_1.pop();
            tree_2.pop();
            if((node_1 == NULL && node_2 != NULL )|| (node_2 == NULL && node_1 != NULL))
                return false;
            if(node_1 == NULL && node_2 == NULL)
                continue;
            if (node_1->val != node_2->val)
                return false;

            tree_1.push(node_1->right);

            tree_1.push(node_1->left);

            tree_2.push(node_2->right);

            tree_2.push(node_2->left);
        }
        return tree_2.empty() && tree_1.empty();
    }
};