1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<int> dist(n,INT_MAX);
5        dist[src]=0;
6        for(int i=0; i<k+1; i++){
7            vector<int> temp = dist;
8
9            for(auto flight:flights){
10                int u = flight[0];
11                int v = flight[1];
12                int w = flight[2];
13
14                if(dist[u]!=INT_MAX && dist[u]+w<temp[v]){
15                    temp[v]=dist[u]+w;
16                }
17            }
18
19            dist=temp;
20        }
21        return dist[dst]==INT_MAX? -1:dist[dst];
22    }
23};