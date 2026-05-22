#include<iostream>
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
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int size=0;
            size=q.size();
            sum=0;
            for(int i=0; i<size; i++){
                TreeNode* f=q.front();
                q.pop();
                sum+=f->val;
                if(f->left!=nullptr) q.push(f->left);
                if(f->right!=nullptr) q.push(f->right);
            }
        }
        return sum;
    }
};