#include<iostream>
using namespace std;
double fact(double n){
    if(n==0) return 1;        //a base condition which will stop the recursion
    return n*fact(n-1);       //recursive call
}
int main(){
    double n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<fact(n)<<endl;
    return 0;
}