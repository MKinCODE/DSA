#include<iostream>
using namespace std;
int main(){
    int arr[5]={5,2,-1,6,22};
    int smallest=__INT_MAX__;
   
    for(int i=0; i<5;i++){
        if (arr[i]<smallest){
            smallest=arr[i];
        }
    }
    cout<<smallest;
return 0;
}