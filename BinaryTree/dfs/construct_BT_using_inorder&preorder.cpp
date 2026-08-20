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
    vector<int> preod;
    vector<int> inod;
public:
    TreeNode* build(int prestart, int preend, int instart, int inend){
        if(prestart>preend) return nullptr;

        int root_val = preod[prestart];
        TreeNode* root = new TreeNode(root_val);

        int rootindex = instart;
        while(inod[rootindex]!=root_val){
            rootindex++;
        }
        int leftsize = rootindex - instart;
        root->left = build(prestart+1,prestart+leftsize,instart,rootindex-1);
        root->right = build(prestart+leftsize+1,preend,rootindex+1,inend);

        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preod = preorder;
        inod = inorder;

        return build(0,preod.size()-1,0,inod.size()-1);
    }
};
