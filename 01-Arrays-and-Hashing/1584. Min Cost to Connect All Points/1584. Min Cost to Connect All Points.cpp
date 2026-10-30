1class Solution {
2public:
3    //prims algo
4    int minCostConnectPoints(vector<vector<int>>& points) {
5        int n = points.size();
6
7        vector<int> mindist(n,INT_MAX);
8        vector<bool> visited(n,false);
9
10        mindist[0]=0;
11        int ans=0;
12
13        for(int i=0; i<n; i++){
14            int u=-1;
15
16            for(int j=0; j<n; j++){
17                if(!visited[j] && (u==-1 ||mindist[j]<mindist[u])) u=j;
18            }
19
20            visited[u]=true;
21            ans+=mindist[u];
22            for(int v=0; v<n; v++){
23                if(!visited[v]){
24                int dist=abs(points[v][0]-points[u][0]) + abs(points[v][1]-points[u][1]);
25                mindist[v]=min(mindist[v],dist);
26                }
27            }
28        }
29        return ans;
30    }
31};