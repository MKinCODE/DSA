1class Solution {
2    vector<int> parent;
3    vector<int> size;
4public:
5    int find(int x){
6        if(parent[x]==x) return x;
7
8        return parent[x]=find(parent[x]);
9    }
10    void unite(int a, int b){
11        int rootA = find(a);
12        int rootB = find(b);
13
14        if(rootA==rootB) return;
15
16        if(size[rootA]<size[rootB]) swap(rootA,rootB);
17
18        parent[rootB]=rootA;
19        size[rootA]+=size[rootB];
20    }
21    int minCostConnectPoints(vector<vector<int>>& points) {
22        int n = points.size();
23        parent.resize(n);
24        size.resize(n,1);
25
26        for(int i=0; i<n;i++) parent[i]=i;
27
28        vector<tuple<int,int,int>> edges;
29        for(int i=0; i<n; i++){
30            for(int j=i+1; j<n; j++){
31                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
32                edges.push_back({dist,i,j});
33            }
34        }
35        
36        sort(edges.begin(),edges.end());
37        int ans=0;
38        for(auto [cost,u,v] : edges){
39            if(find(u)!=find(v)){
40                unite(u,v);
41                ans+=cost;
42            }
43        }
44        return ans;
45    }
46};