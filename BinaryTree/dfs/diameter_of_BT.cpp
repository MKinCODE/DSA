#include<iostream>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
    int height(TreeNode* root){
        int lefth=0;
        int righth=0;
        if(root==nullptr) return 0;
        lefth=height(root->left);
        righth=height(root->right);
        diameter=max(diameter,lefth+righth);
        return 1+max(lefth,righth);
    }
};