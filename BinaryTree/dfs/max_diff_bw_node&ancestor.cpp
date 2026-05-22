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
    void dfs(TreeNode* root, int mini, int maxi, int& ans){
        if(root==nullptr) return;
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        ans=max(maxi-mini,ans);
        dfs(root->left,mini,maxi,ans);
        dfs(root->right,mini,maxi,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        int mini=root->val;
        int maxi=root->val;
        dfs(root,mini,maxi,ans);
        return ans;
    }
};