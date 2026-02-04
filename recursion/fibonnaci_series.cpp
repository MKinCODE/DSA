#include<iostream>
#include<vector>
using namespace std;

int fibbo(int n){
    if(n<=1) return n;
    return fibbo(n-1)+fibbo(n-2);
}
int main(){
    int a;
    cout<<"enter a number: ";
    cin>>a;
    cout<<endl<<fibbo(a)<<endl;
    return 0;
}

//less complexity
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        vector<int> s(n+1,0);
        s[0]=0;
        s[1]=1;
        
        for(int i=2;i<=n;i++){
            s[i]=s[i-1]+s[i-2];
        }
        return s[n];
    }
};