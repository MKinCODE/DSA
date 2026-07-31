#include<bits/stdc++.h>
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
    vector<string> ans;
public:
    void dfs(TreeNode* root, string temp){
        if(root==nullptr) return;

        if(temp.empty()) temp+=to_string(root->val);
        else temp+= "->"+ to_string(root->val);

        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(temp);
            return;
        } 

        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};