#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int rows=maze.size();
        int cols=maze[0].size();
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        while(!q.empty()){
            int length=q.size();
            for(int i=0; i<length; i++){
                auto current = q.front();
                q.pop();
                int row=current.first;
                int col=current.second;
                if((row==0 || row==rows-1 || col==0 || col==cols-1) && !(row==entrance[0] && col==entrance[1])) return steps;

                for(int k = 0; k < 4; k++) {
                
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];

                    if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && maze[nrow][ncol] == '.') {
                        q.push({nrow, ncol});
                        maze[nrow][ncol] = '+';
                    }
                }  
            }
            steps++;
        }
    return -1;
    }
};