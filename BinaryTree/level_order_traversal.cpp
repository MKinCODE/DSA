#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        TreeNode* f;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int size=q.size();
            while(size!=0){
                f=q.front();
                q.pop();
                if(f->left!=nullptr) q.push(f->left);
                if(f->right!=nullptr) q.push(f->right);
                temp.push_back(f->val);
                size--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};