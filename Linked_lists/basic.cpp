#include<iostream>
using namespace std;
class Node{
    int value;
    Node* next;
    public:
    Node();
    Node(int x){value=x;next=NULL;}
    Node(int x, Node* pointer){value=x;next=pointer;}
};
int main(){
    


    return 0;
}