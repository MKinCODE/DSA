#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        int x=0;
        int y=0; 
        string key;
        key = to_string(x) + "," + to_string(y);
        s.insert(key);
        for(int i=0; i<path.length();i++){
            if(path[i]=='N'){y++;}
            else if(path[i]=='S'){y--;}
            else if(path[i]=='W'){x--;}
            else if(path[i]=='E'){x++;}
            
            key = to_string(x) + "," + to_string(y);
                if(s.find(key)!=s.end()) {
                    return true;
                }
                else{s.insert(key);}
        }
        return false;
    }
};