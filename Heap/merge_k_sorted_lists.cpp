#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//more optimal
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        for(ListNode* head:lists){
            if(head==nullptr) continue;
            pq.push({head->val,head});
        }
        if(pq.empty()) return nullptr;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            tail->next=curr.second;
            tail=curr.second;
            if(curr.second->next)
            pq.push({curr.second->next->val,curr.second->next});
        }
        return dummy.next;;
    }
};

//less optimal
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:lists){
            if(x==nullptr) continue;
            while(x!=nullptr){
                pq.push(x->val);
                x=x->next;
            }
        }
        if(pq.empty()) return nullptr;
        ListNode* head=new ListNode(pq.top());
        pq.pop();
        ListNode* temp=head;
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return head;
    }
};