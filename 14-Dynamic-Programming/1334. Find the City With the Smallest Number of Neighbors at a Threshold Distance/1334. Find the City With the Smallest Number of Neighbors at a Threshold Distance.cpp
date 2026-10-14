1class Solution {
2public:
3    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
4        const int INF = 1e9;
5        vector<vector<int>> dist(
6            n,
7            vector<int>(n,INF)
8        );
9
10        for(int i=0; i<n; i++){
11            dist[i][i]=0;
12        }
13
14        for(auto edge:edges){
15            int u = edge[0];
16            int v = edge[1];
17            int wt = edge[2];
18
19            dist[u][v] = wt;
20            dist[v][u] = wt;
21        }
22
23        for(int k=0; k<n; k++){
24            for(int i=0; i<n; i++){
25                for(int j=0; j<n; j++){
26                    if(dist[i][k]!=INF && dist[k][j]!=INF){
27                        dist[i][j] = min(
28                            dist[i][j],
29                            dist[i][k]+dist[k][j]
30                        );
31                    }
32                }
33            }
34        }
35        int prev = INF;
36        int ans = -1;
37        for(int i=0; i<n; i++){
38                int count=0;
39                for(int j=0; j<n; j++){
40                    if(i!=j && dist[i][j]<=distanceThreshold) count++;
41                }
42                if(count<=prev){
43                    ans=i;
44                    prev=count;
45                }
46        }
47        return ans;
48    }
49};