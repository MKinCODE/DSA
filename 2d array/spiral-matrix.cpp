#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        vector<int> ans;
        while(left<=right && top<=bottom){
            // traverse from left to right and increase top by one
            for(int i=left; i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            //traverse from top to bottom and decrease right
            for(int i=top; i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            //if condition satisfies traverse from right to left and decrease bottom
            if(top<=bottom){
                for(int i=right; i>=left ;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            //if condition satisfies traverse from bottom to top and increase left
            if(left<=right){
                for(int i=bottom; i>=top ;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }
    return ans;

    }
};