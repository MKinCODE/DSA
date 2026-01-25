#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> us(jewels.begin(),jewels.end());
        int count=0;
        for(int i = 0; i<stones.length(); i++){
            if(jewels.find(stones[i])!=string::npos){      //find for element of jewels in stones and increase count
                count++;
            }
        }
    return count;
    }
};

//brute force
// count = 0
// for each char s in stones:
//     for each char j in jewels:
//         if s == j:
//             count++
//             break
// return count
