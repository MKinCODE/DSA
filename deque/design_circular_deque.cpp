#include<bits/stdc++.h>
using namespace std;

//less optimal, can be optimised by keeping start and size with no headache of rear
class MyCircularDeque {
    vector<int> dq;
    int front=-1;
    int rear=-1;
    int size=0;
    int capacity;
public:
    MyCircularDeque(int k) {
        capacity=k;
        dq.resize(k);
    }
    
    bool insertFront(int value) {
        if(size<capacity){
            if(front==-1 && rear==-1){
                front=0;
                rear=0;
            }
            else{
                front=(front-1+capacity)%capacity;
            }
            dq[front]=value;
            size++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(size<capacity){
            if(front==-1 && rear==-1){
                front=0;
                rear=0;
            }
            else{
                rear=(rear+1)%capacity;
            }
            dq[rear]=value;
            size++;
            return true;
        }
        return false;   
    }
    
    bool deleteFront() {
        if(size>0){
            if(size==1) {
                front=-1; 
                rear=-1;
            }
            else front=(front+1)%capacity;
            size--;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(size>0){
            if(size==1) {
                front=-1; 
                rear=-1;
            }
            else rear=(rear-1+capacity)%capacity;
            size--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(size==0) return -1;
        return dq[front];
    }
    
    int getRear() {
        if(size==0) return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        return size==0? true:false;
    }
    
    bool isFull() {
        return size==capacity? true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */