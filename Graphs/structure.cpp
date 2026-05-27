#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:

    void graphTemplate(vector<vector<int>>& edges) {

        // Graph
        unordered_map<int, vector<int>> graph;

        // Build Graph
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Undirected Graph
            graph[u].push_back(v);
            graph[v].push_back(u);

            // Directed Graph
            // graph[u].push_back(v);
        }

        
        // Visited Set
        unordered_set<int> visited;


        // Traverse Graph
        for(auto it : graph) {

            int node = it.first;

            if(visited.find(node) == visited.end()) {

                // DFS/BFS call here
            }
        }
    }
};

//using vector instead of umap and uset
class Solution {
public:

    void graphTemplate(int n, vector<vector<int>>& edges) {

        // Graph
        vector<vector<int>> graph(n);

        
        // Build Graph
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Undirected Graph
            graph[u].push_back(v);
            graph[v].push_back(u);

            // Directed Graph
            // graph[u].push_back(v);
        }


        // Visited Array
        vector<int> visited(n, 0);


        // Traverse Graph
        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                // DFS/BFS call here
            }
        }
    }
};