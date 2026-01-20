#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
       for(int i=num.length()-1;i>=0;i--){
        //converting ascii value to int
        int digit = num[i]-'0';
        if(digit%2==1){
            //use to take substring, substr(int start-index, int length)
            return num.substr(0,i+1);
        }
       }
       return "";
    }
};