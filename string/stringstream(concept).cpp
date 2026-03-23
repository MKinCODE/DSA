#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
int main(){
    string path= "/a/b///c//..././d/../e/";
    stringstream ss(path);
    string token;
    while(getline(ss,token,'/')){
        cout << token << endl;
    }
    return 0;
}