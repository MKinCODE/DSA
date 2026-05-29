#include<queue>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        bool isLand=false;
        bool isWater=false;
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        int dist=-1;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==0) isWater=true;
                if(grid[i][j]==1){
                    q.push({i,j}); 
                    isLand=true;
                } 
            }
        }
        if(!isLand || !isWater) return -1;
        while(!q.empty()){
            int length=q.size();
            for(int i=0; i<length; i++){
                auto current=q.front();
                q.pop();
                int row=current.first;
                int col=current.second;

                for(int k=0; k<4; k++){
                    int nrow=row+drow[k];
                    int ncol=col+dcol[k];

                    if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == 0){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=1;
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};