#include<vector>
using namespace std;
class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>>& graph, vector<int>& visited){
        if(node==destination) return true;
        if(visited[node]) return false;
        visited[node]=1;
        for(int neighbour:graph[node]){
            if(dfs(neighbour,destination,graph,visited))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(n,0);

        return dfs(source,destination,graph,visited);
    }
};