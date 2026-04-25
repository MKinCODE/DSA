#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<int> hash;
        for(int i=0;i<sentence.length();i++){
            hash.insert(sentence[i]);
        }
        return hash.size()==26;
    }
};