#include<vector>
using namespace std;
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited,int rows,int cols){
        if(i<0 || j<0 || i>=rows || j>=cols)
            return 0;
        if(grid[i][j]==0)
            return 0;
        if(visited[i][j]==1)
            return 0;

        visited[i][j]=1;

        int up=dfs(i-1,j,grid,visited,rows,cols);
        int down=dfs(i+1,j,grid,visited,rows,cols);
        int left=dfs(i,j-1,grid,visited,rows,cols);
        int right=dfs(i,j+1,grid,visited,rows,cols);
        
        return 1+up+down+left+right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area = dfs(i, j, grid, visited,rows,cols);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};