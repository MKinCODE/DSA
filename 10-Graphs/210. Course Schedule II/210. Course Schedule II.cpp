1class Solution {
2    vector<int> result;
3public:
4    bool dfs(int node, vector<vector<int>>& adj, vector<int>& states){
5        states[node]=1;
6        for(int neighbour:adj[node]){
7            if(states[neighbour]==1) return true;
8            else if(states[neighbour]==0){
9                if(dfs(neighbour,adj,states)) return true;
10            }
11        }
12        states[node]=2;
13        result.push_back(node);
14        return false;
15    };
16    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
17        vector<vector<int>> adj(numCourses);
18        for(int i = 0; i<prerequisites.size() ; i++){
19            int u = prerequisites[i][0];
20            int v = prerequisites[i][1];
21            adj[v].push_back(u);
22        }
23        vector<int> states(numCourses,0);
24        for(int i=0; i<numCourses; i++){
25            if(states[i]==0)
26                if(dfs(i,adj,states)) return {};
27        }
28        reverse(result.begin(),result.end());
29        return result;
30    }
31};