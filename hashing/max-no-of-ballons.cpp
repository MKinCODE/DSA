#include<iostream>
#include<unordered_map>
#include<algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        int count=0;
        for(char c:text){
            freq[c]++;
        }
        while(freq['b']>0 && freq['a']>0 && freq['l']>1 && freq['o']>1 && freq['n']>0){
            freq['b']--;
            freq['a']--;
            freq['l']-=2;
            freq['o']-=2;
            freq['n']--;
            count++;
        }
        return count;
    }
};

//even easier approach 

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        int count=0;
        for(char c:text){
            freq[c]++;
        }
        return min({
    freq['b'],
    freq['a'],
    freq['l'] / 2,
    freq['o'] / 2,
    freq['n']
});
    }
};

// not space optimistic but approach valid for any word
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string text2 = "balloon";

        int req = INT_MAX;
        int n = text2.size();
        unordered_map<char, int> mpp, mpp2;

        for(char c:text){
            mpp[c]++;
        }

        for(char c:text2){
            mpp2[c]++;
        }

        for(auto it: mpp2){
            char c = it.first;
            int need = it.second;

            req = min(req, mpp[c]/need);
        }

        return req;

    }
};