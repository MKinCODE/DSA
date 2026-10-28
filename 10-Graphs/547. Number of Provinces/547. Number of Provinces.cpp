1class Solution {
2    vector<int> parent;
3    vector<int> size;
4public:
5    int find(int x){
6        if(parent[x]==x) return x;
7
8        return parent[x]=find(parent[x]);
9    }
10    bool unite(int a, int b){
11        int rootA = find(a);
12        int rootB = find(b);
13
14        if(rootA==rootB) return false;
15
16        if(size[rootA]<size[rootB]) swap(rootA,rootB);
17
18        parent[rootB] = rootA;
19        size[rootA]+=size[rootB];
20
21        return true;
22    }
23    int findCircleNum(vector<vector<int>>& isConnected) {
24        int n = isConnected.size();
25        parent.resize(n);
26        size.resize(n,1);
27        for(int i=0; i<n; i++) parent[i]=i;
28        int components = n;
29        for(int i=0; i<n; i++){
30            for(int j=i+1; j<n; j++){
31                if(isConnected[i][j]){
32                    if(unite(i,j))
33                    components--;
34                }
35            }
36        }
37        return components;
38    }
39};