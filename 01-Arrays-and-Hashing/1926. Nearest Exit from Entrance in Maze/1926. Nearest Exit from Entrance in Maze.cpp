1class Solution {
2public:
3    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
4        queue<pair<int,int>> q;
5        q.push({entrance[0],entrance[1]});
6        int rows = maze.size();
7        int cols = maze[0].size();
8
9        vector<vector<int>> dist(rows, vector<int>(cols, -1));
10        dist[entrance[0]][entrance[1]]=0;
11        int drow[] = {-1,1,0,0};
12        int dcol[] = {0,0,-1,1};
13        while(!q.empty()){
14            auto curr = q.front();
15            q.pop();
16            int crow=curr.first;
17            int ccol=curr.second;
18            for(int k=0; k<4; k++){
19                int nrow = crow+drow[k];
20                int ncol = ccol+dcol[k];
21                if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols && maze[nrow][ncol]=='.' && dist[nrow][ncol]==-1){
22                    dist[nrow][ncol]=dist[crow][ccol]+1;
23                    q.push({nrow,ncol});
24                    if(nrow==0 || ncol==0 || nrow==rows-1 || ncol==cols-1 && (nrow!=entrance[0] || ncol!=entrance[1])) return dist[nrow][ncol];
25                }
26            }
27        }
28        return -1;
29    }
30};