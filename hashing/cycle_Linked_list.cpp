#include<iostream>
#include<unordered_set>
using namespace std;
struct ListNode{public:
 int val;
ListNode* next;
ListNode(int x){val=x;next=NULL;}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> us;
        ListNode* temp=head;
        while(temp!=NULL){
            if(us.find(temp)!=us.end()){
                return true;
            }
            us.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};