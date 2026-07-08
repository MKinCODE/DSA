#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int dcount=0;
        int rcount=0;
        for(char a:senate){
            q.push(a);
            if(a=='R') rcount++;
            else dcount++;
        }
        int banD=0;
        int banR=0;
        while(rcount!=0 && dcount!=0){
            char curr=q.front();
            q.pop();
            if(curr=='R'){
                if(banR>0){
                    banR--;
                    continue;
                }
                else{
                    dcount--;
                    banD++;
                }
                
            }
            else {
                if(banD>0){
                    banD--;
                    continue;
                }
                else{
                    rcount--;
                    banR++;
                }
            }
            q.push(curr);
        }

        return dcount==0? "Radiant":"Dire";
    }
};