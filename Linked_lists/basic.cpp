#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int x){value=x;next=NULL;}
};
int main(){
    Node* head = new Node(5);
    cout<<endl<<head->value<<endl;
    return 0;
}