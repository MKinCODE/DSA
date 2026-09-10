1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13    int count=0;
14public:
15    pair<int,int> dfs(TreeNode* root){
16        if(root==nullptr) return {0,0};
17        auto left = dfs(root->left);
18        auto right = dfs(root->right);
19        if((left.first+right.first+root->val)/(left.second+right.second+1)==root->val){
20            count++;
21        }
22
23        return {left.first+right.first+root->val , 1+left.second+right.second};
24    }
25    int averageOfSubtree(TreeNode* root) {
26        dfs(root);
27        return count;
28    }
29};