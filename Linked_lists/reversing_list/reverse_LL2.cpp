#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//optimal but done  in three traversel through list
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     ListNode* leftp=head;
     ListNode* leftprev=nullptr;
     ListNode* rightp=head;
     for(int i=0;i<left-1;i++){
        leftprev=leftp;
        leftp=leftp->next;
     }
     for(int j=0;j<right-1;j++){
        rightp=rightp->next;
     }
     ListNode* prev=nullptr;
     ListNode*nextptr=nullptr;
     ListNode* curr=leftp;
     ListNode* Rn=rightp->next;
     while(curr!=Rn){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
     }
     if(left == 1){
        head = prev;
    } else {
        leftprev->next = prev;
    }
     leftp->next=Rn;
     return head;
    }
};

//follow up: do in one traversel through list