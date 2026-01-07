#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n;
        n=s.size();
        int l=n-1;
        int f=0;
        while(f<l){
            swap(s[l],s[f]);
            f++;
            l--;
        }}
};
