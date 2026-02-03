#include<iostream>
using namespace std;
void reversearray(int*,int,int);
void reverse(int *arr,int l,int r){
    if(l>=r) return;
    swap(arr[l],arr[r]);
    reverse(arr,l+1,r-1);
} 
int main(){
    int arr[5]={4,7,2,8,1};
    reverse(arr,0,4);
    for(int i : arr){
        cout<<i<<" ";
    }
    reversearray(arr,0,5);
    cout<<endl<<"once more: ";
    for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
}

//another way
void reversearray(int* arr,int i,int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reversearray(arr,i+1,n);
}