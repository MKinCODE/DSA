#include<iostream>
#include<queue>
using namespace std;
class MovingAverage{
    public:
    queue<int> q;
    double sum;
    int size;

    MovingAverage(int size){
        this->size=size;
        sum=0;
    }
    double next(int val){
        q.push(val);
        sum+=val;
        if(q.size()>size){
            sum-=q.front();
            q.pop();
        }
        return sum/q.size();
    }
};