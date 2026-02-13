#include<iostream>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// not space optimal
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* reversed=nullptr;

        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* newnode=new ListNode(curr->val);

            newnode->next=reversed;
            reversed=newnode;

            curr=curr->next;
        }
        int ans=0;
        while(head!=nullptr){
            ans=max(ans,(head->val)+(reversed->val));
            head=head->next;
            reversed=reversed->next;
        }
        return ans;
    }
};

// optimistic solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if(head==nullptr || head->next==nullptr){return 0;}
        ListNode* slow=head;
        ListNode* prevslow=nullptr;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            prevslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        ListNode* nextptr=nullptr;
        // prevslow->next=nullptr;  no need to separate still it works
        while(curr!=nullptr){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
       // prevslow->next=prev; no need to join them again
        ListNode*temp=head;
        int ans=0;
        while(prev!=nullptr){   // we have to use prev cause it is the first node of second half
            ans=max(ans,((temp->val)+(prev->val)));
            prev=prev->next;
            temp=temp->next;
        }
        return ans;
    }
};