1class Solution {
2public:
3    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
4        vector<vector<pair<int,double>>> adj(n);
5        for(int i=0; i<edges.size(); i++){
6            int u=edges[i][0];
7            int v= edges[i][1];
8            double w=succProb[i];
9
10            //remember when graph is undirected
11            adj[u].push_back({v,w});
12            adj[v].push_back({u,w});
13        }
14        vector<double> prob(n,0.0);
15        priority_queue<pair<double,int>> pq;
16        pq.push({1.0,start_node});
17        //at start the prob to reach start is 1
18        prob[start_node]=1.0;
19        while(!pq.empty()){
20            auto [p,node] = pq.top();
21            pq.pop();
22
23            for(auto [nei,pb]:adj[node]){
24                if(prob[node]*pb>prob[nei]){
25                    prob[nei]=prob[node]*pb;
26                    pq.push({prob[nei],nei});
27                }
28            }
29        }
30        if(prob[end_node]>0.0) return prob[end_node];
31        return 0;
32    }
33};