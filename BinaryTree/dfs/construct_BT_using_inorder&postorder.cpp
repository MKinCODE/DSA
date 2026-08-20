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
    vector<int> postod;
    vector<int> inod;
public:
    TreeNode* build(int poststart, int postend, int instart, int inend){
        if(poststart>postend) return nullptr;

        int root_val = postod[postend];
        TreeNode* root = new TreeNode(root_val);
        int rootindex=instart;
        while(inod[rootindex]!=root_val) {rootindex++;}
        int leftsize = rootindex-instart;
        root->left = build(poststart,poststart+leftsize-1,instart,instart+leftsize-1);
        root->right = build(poststart+leftsize,postend-1,rootindex+1,inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postod=postorder;
        inod=inorder;
        return build(0,postod.size()-1,0,inod.size()-1);

    }
};