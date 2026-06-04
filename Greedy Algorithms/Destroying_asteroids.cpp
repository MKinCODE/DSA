#include<vector>
#include<algorithm>
using namespace std;

//standard approach:
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long currmass = mass;
        for(int x:asteroids){
            if(currmass<x) return false;
            currmass+=x;
        }
        return true;
    }
};

//can be done using bucket sort which is ok for small values only