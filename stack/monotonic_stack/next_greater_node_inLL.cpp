#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//brute force using flag
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while(head!=nullptr){
            ListNode* temp=head->next;
            int flag=0;
            while(temp!=nullptr){
                if(temp->val>head->val){
                    ans.push_back(temp->val);
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0){ans.push_back(0);}
            head=head->next;
        }
        return ans;
    }
};

//brute force without using flag
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while(head!=nullptr){
            ListNode* temp=head->next;
            while(temp && temp->val <= head->val) {
                temp = temp->next;
            }

            if(temp) ans.push_back(temp->val);
            else ans.push_back(0);
            head=head->next;
        }
        return ans;
    }
};

//monotonic stack pattern
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> given;
        while(head!=nullptr){
           given.push_back(head->val);
           head=head->next; 
        }
        vector<int> ans(given.size(),0);
        for(int i=0;i<given.size();i++){
            while(!st.empty() && given[i]>given[st.top()]){
                ans[st.top()]=given[i];
                st.pop();
            }
            st.push(i);
        }
        // while(!st.empty()){
        //     ans[st.top()]=0;
        //     st.pop();
        // }
        return ans;
    }
};

//vector is faster than stack as they are more cache-friendly and have less abstraction overhead than stack hence reduces runtime
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> st;
        vector<int> given;
        while(head!=nullptr){
           given.push_back(head->val);
           head=head->next; 
        }
        vector<int> ans(given.size(),0);
        for(int i=0;i<given.size();i++){
            while(!st.empty() && given[i]>given[st.back()]){
                ans[st.back()]=given[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};