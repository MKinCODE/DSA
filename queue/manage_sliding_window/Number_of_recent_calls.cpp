#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class RecentCounter {
public:
queue<int> q;
    RecentCounter() {}
    
    int ping(int t) {
        q.push(t);
        while(q.front()<t-3000){
            q.pop();
        }
        return q.size();
    }
};

//brute force
class RecentCounter {
public:
vector<int> v;
    RecentCounter() {
    }
    
    int ping(int t) {
    v.push_back(t);
    int count = 0;

    for(int x : v) {
        if(x >= t - 3000) count++;
    }

    return count;
}
};