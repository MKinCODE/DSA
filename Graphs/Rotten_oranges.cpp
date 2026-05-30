#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int Fresh=0;
        bool isRotten=false;
        int rows=grid.size();
        int columns=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    isRotten=true;
                }
                else if(grid[i][j]==1){
                    Fresh++;
                }
                else continue;
            }
        }
        if(Fresh==0) return 0;
        if(!isRotten) return -1;
        int drow[4] = {-1,1,0,0};
        int dcol[4] = {0,0,-1,1};
        int minutes=-1;
        while(!q.empty()){
            int clength=q.size();
            for(int i=0; i<clength; i++){
                auto current=q.front();
                q.pop();
                int row=current.first;
                int col=current.second;

                for(int k=0; k<4; k++){
                    int nrows=row+drow[k];
                    int ncols=col+dcol[k];

                    if(nrows>=0 && nrows<rows && ncols>=0 && ncols<columns && grid[nrows][ncols]==1){
                        q.push({nrows,ncols});
                        grid[nrows][ncols]=2;
                        Fresh--;
                    }
                }
            }
            minutes++;
        }
        if(Fresh>0) return -1;
        return minutes;
    }
};