#include<iostream>
using namespace std;
bool checkpalindrome(string s,int i){
    int n=s.length();
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    return checkpalindrome(s,i+1); 
}
int main(){
    string s1="hello";
    if(checkpalindrome(s1,0)){
        cout<<s1<<" is a palindrome";
    }
    else{cout<<s1<<" not a palindrome";}

    string s2="madam";
    if(checkpalindrome(s2,0)){
        cout<<endl<<s2<<" is a palindrome"<<endl;
    }
    else{cout<<endl<<s2<<" not a palindrome"<<endl;}

    return 0;

}
