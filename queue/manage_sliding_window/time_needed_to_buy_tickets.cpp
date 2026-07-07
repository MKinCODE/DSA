#include<bits/stdc++.h>
using namespace std;



//further more optimal can be done using single queue with saving index
//....

//more optimal
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int sold=0;
        int size=tickets.size();
        for(int i=0; i<size; i++){
            q.push({tickets[i],i});
        }
        while(!q.empty()){
            auto person = q.front();
            q.pop();

            sold++;
            if(person.first-1==0) {
                if(person.second==k) break;
                else continue;
            }
            else{
                q.push({person.first-1,person.second});
            }
        }
        return sold;
    }
};

//high complexity
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        while(tickets[k]!=0)
        for(int i=0; i<tickets.size(); i++){
            if(tickets[i]==0) continue;
            else{
                tickets[i]-=1;
                ans++;
                if(tickets[k]==0) break;
            }
        }
        return ans;
    }
};