//brute for:- just count total node in first traversal and get to node just before middle in another traversal and delete the middle.

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* delnode=slow;
        prev->next=slow->next;
        delete delnode;
        return head;
    }
};