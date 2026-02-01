#include<iostream>
using namespace std;
void func(int i,int n){
    if(i>n){
        return;
    }
    cout<<"base case is required to be handled"<<endl;  
    func(i+1,n);
}
int main(){
    func(1,3);
    return 0;
}