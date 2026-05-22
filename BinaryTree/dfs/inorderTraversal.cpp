#include<iostream>
#include<vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        vector<int> leftp;
        vector<int> rightp;
        leftp=inorderTraversal(root->left);
        ans.push_back(root->val);
        rightp=inorderTraversal(root->right);
        leftp.insert(leftp.end(),ans.begin(),ans.end());
        leftp.insert(leftp.end(),rightp.begin(),rightp.end());
        return leftp;
    }
};

//cleaner version: without using multiple vectors
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==nullptr) return;
        inorder(root->left,ans);
        inorder(root->right,ans);
        ans.push_back(root->val);
    }
};