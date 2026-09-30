1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<vector<pair<int,int>>> adj(n+1);
5        for(int i=0; i<times.size(); i++){
6            int u = times[i][0];
7            int v = times[i][1];
8            int w = times[i][2];
9            adj[u].push_back({v,w});
10        }
11        vector<int> dist(n+1,INT_MAX);
12        priority_queue<
13            pair<int,int>,
14            vector<pair<int,int>>,
15            greater<pair<int,int>>
16        > pq;
17        pq.push({0,k});
18        dist[k]=0;
19
20        while(!pq.empty()){
21            auto [d,node] = pq.top();
22            pq.pop();
23
24            if(d>dist[node]) continue;
25
26            for(auto [nei,wt]:adj[node]){
27                if(dist[node]+wt < dist[nei]){
28                    dist[nei]=dist[node]+wt;
29                    pq.push({dist[nei],nei});
30                } 
31                
32            }
33        }
34        int ans = *max_element(dist.begin()+1,dist.end());
35        return ans==INT_MAX? -1:ans;
36    }
37};