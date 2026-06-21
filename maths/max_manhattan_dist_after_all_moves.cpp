#include<string>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0,count=0;
        for(char ch:moves){
            if(ch=='U') x++;
            else if(ch=='D') x--;
            else if(ch=='L') y--;
            else if(ch=='R') y++;
            else if(ch=='_') count++;
        }
        return abs(x)+abs(y)+count;
    }
};