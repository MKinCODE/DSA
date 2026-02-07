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
    int data,pos;
    cout<<"enter value to insert:";
    cin>>data;
    Node* newNode= new Node(data);
    cout<<"enter position to insert: ";
    cin>>pos;
    int n=count(head);

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
int delete_node(Node* &head){
    int pos;
    cout<<"enter node position to delete: ";
    cin>>pos;
    if(head==NULL){cout<<"nothing to delete. list is empty"<<endl; return -1;}
    if(pos<1){cout<<"invalid position"<<endl;return -1;}
    if(pos==1){// without using temp creates memory leak
        Node* temp = head;
        int deletedvalue=head->value;
        head=head->next;
        delete temp;
        return deletedvalue;
    }
    

    Node* temp=head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position is out of bounds." << endl;
        return -1;
    }
    Node* delnode=temp->next;
    int deletednode = delnode->value;
    temp->next=temp->next->next;
    delete delnode;
    return deletednode;
}
int main(){
    Node* head=new Node(5);
    head->next= new Node(10);

    insert_node(head);
    traverse(head);
    cout<<endl<<"Total nodes in LL: "<<count(head)<<endl;
    int delval= delete_node(head);
    cout<<"Node deleted at the position with value: "<<delval<<endl;
    return 0;
}