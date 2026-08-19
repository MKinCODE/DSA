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
    vector<tuple<int,int,int>> matrix;
public:
    void recurse(TreeNode* root, int row, int col){
    	if(root==nullptr) return;
    	matrix.push_back({root->val,row,col});
    	recurse(root->left,row+1,col-1);
    	recurse(root->right,row+1,col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        recurse(root,0,0);
        sort(matrix.begin(), matrix.end(), [](const auto& a, const auto& b) {
            if (get<2>(a) != get<2>(b))
                return get<2>(a) < get<2>(b);   

            if (get<1>(a) != get<1>(b))
                return get<1>(a) < get<1>(b);   

            return get<0>(a) < get<0>(b);       
        });
        int curr = get<2>(matrix[0]);
        for(int i=0; i<matrix.size(); i++){
            vector<int> temp;
            while(i<matrix.size() && get<2>(matrix[i])==curr){
                temp.push_back(get<0>(matrix[i]));
                i++;
            }
            ans.push_back(temp);
            if(i<matrix.size())curr=get<2>(matrix[i--]);
            
        }
        return ans;
    }
};