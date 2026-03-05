#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=nullptr;
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* fnode=nullptr;
        ListNode* snode=nullptr;
         while(head!=nullptr && head->next!=nullptr){
            fnode=head;
            snode=head->next;

            prev->next=snode;
            fnode->next=snode->next;
            snode->next=fnode;

            prev=fnode;
            head=fnode->next;
         }
    return dummy->next;
}