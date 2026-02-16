#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=nullptr){
            slow=slow->next;
        }
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        while(slow!=nullptr){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        while(prev!=nullptr){
            if(head->val!=prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};