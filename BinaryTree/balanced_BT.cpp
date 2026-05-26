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
    int height(TreeNode* root) {
        int lefth=0;
        int righth=0;
        if(root==nullptr) return 0;
        lefth=height(root->left);
        righth=height(root->right);
        if(abs(lefth-righth)>1 ||lefth==-1 ||righth==-1) return -1;
        return 1+max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        return height(root)!=-1;
    }
};