#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx = i*n + j;      //converting to 1D

                int newindex = (idx+k)%(m*n);    //after k operations newindex in 1D
                
                //converting 1D to 2D
                int row=newindex/n;     
                int col=newindex%n;

                //putting to ans
                ans[row][col]=grid[i][j];
            }
        }
    return ans;
    }
};