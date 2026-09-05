1class Solution {
2public:
3
4    bool dfs(int node, int target, vector<vector<int>>& adj, vector<bool>& visited){
5        if(node==target) return true;
6        visited[node]=true;
7        for(int neighbour:adj[node]){
8            if(!visited[neighbour]){
9                if(dfs(neighbour,target,adj,visited))
10                    return true;
11            }
12            
13        }
14        return false;
15    }
16    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
17        int n = edges.size();
18        
19        vector<vector<int>> adj(n+1);
20        vector<int> ans;
21        for(auto edge:edges){
22            vector<bool> visited(n+1,false);
23            int u=edge[0];
24            int v=edge[1];
25
26            if(dfs(u,v,adj,visited)) ans=edge;
27            else{
28                adj[u].push_back(v);
29                adj[v].push_back(u);
30            }
31        }
32        return ans;
33    }
34};