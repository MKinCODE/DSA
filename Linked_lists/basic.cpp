#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int x){value=x;next=NULL;}
};
void traverse(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}
int count(Node* head){
    Node* temp=head;
    int counter=0;
    while(temp!=NULL){
        temp=temp->next;
        counter++;
    }
    return counter;
}
void insert_node(Node* &head){
    int n=count(head);
    int data,pos;
    cout<<"enter value to insert:";
    cin>>data;
    Node* newNode= new Node(data);
    cout<<"enter position to insert: ";
    cin>>pos;
    if(pos<1 || pos>n+1){cout<<"Invalid position";return;}
    if(pos==1){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
}
int main(){
    Node* head=NULL;

    insert_node(head);
    traverse(head);
    cout<<endl<<"Total nodes in LL: "<<count(head)<<endl;
    return 0;
}