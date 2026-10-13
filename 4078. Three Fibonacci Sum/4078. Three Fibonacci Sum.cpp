1class Solution {
2public:
3    bool threeFibonacciSum(int n) {
4        int a=0,b=1,c=1;
5        while(a+b+c<=n){
6            if(a+b+c==n) return true;
7            int next = b+c;
8            a=b;
9            b=c;
10            c=next;
11        }
12        return false;
13    }
14};