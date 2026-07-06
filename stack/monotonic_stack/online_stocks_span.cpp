#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 //can also be solved using vector(stacks can be replaced using vector)
typedef pair<int, int> pii;
class StockSpanner {
public:
    vector<pii> st; 
    StockSpanner() {  
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.back().first<=price){
            span+=st.back().second;
            st.pop_back();
        }
        st.push_back({price,span});
        return span;
    }
};
