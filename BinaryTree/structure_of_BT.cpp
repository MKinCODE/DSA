/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;             //value at the node
 *     TreeNode *left;      //left node of it
 *     TreeNode *right;     //right node of it
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// done using recursion 
//func(root->left)
//func(root->right)