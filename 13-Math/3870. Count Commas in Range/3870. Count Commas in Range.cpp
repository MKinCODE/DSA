1class Solution {
2public:
3    int countCommas(int n) {
4        if(n<1000) return 0;
5        return n-1000 + 1;
6    }
7};