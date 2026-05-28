#include<vector>
using namespace std;
class Solution {
public:
    int solver(int node, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[node]) return 0;
        visited[node]=1;
        int a=0;
        for(int neighbour:graph[node]){
            a+=solver(neighbour,graph,visited);
        }
        return 1+a;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(n,0);
        for(int r:restricted){
            visited[r]=1;
        }
        return solver(0,graph,visited);
    }
};