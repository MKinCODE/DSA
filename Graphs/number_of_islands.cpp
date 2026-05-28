#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid,int rows,int cols){
        if(i<0 || j<0 || i>=rows || j>=cols)
            return ;
        if(grid[i][j]=='0')
            return ;

        grid[i][j]='0';

        dfs(i-1,j,grid,rows,cols);
        dfs(i+1,j,grid,rows,cols);
        dfs(i,j-1,grid,rows,cols);
        dfs(i,j+1,grid,rows,cols);
        
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i, j, grid,rows,cols);
                }
            }
        }
        return count;
    }
};