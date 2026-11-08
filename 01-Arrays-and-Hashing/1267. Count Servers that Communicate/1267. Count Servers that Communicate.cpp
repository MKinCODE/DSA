1class Solution {
2public:
3    bool isConnect(int m,int n, int x, int y, vector<vector<int>>& grid){
4        for(int j=0; j<n; j++){
5            if(j==y) continue;
6            if(grid[x][j]==1) return true;
7        }
8        for(int i=0; i<m; i++){
9            if(i==x) continue;
10            if(grid[i][y]==1) return true;
11        }
12        return false;
13        
14    }
15    int countServers(vector<vector<int>>& grid) {
16        int m=grid.size();
17        int n=grid[0].size();
18        int count=0;
19        for(int i=0; i<m; i++){
20            for(int j=0; j<n; j++){
21                if(grid[i][j]==1 && isConnect(m,n,i,j,grid)) count++;
22            }
23        }
24        return count;
25    }
26};