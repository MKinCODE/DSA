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