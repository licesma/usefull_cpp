//
// Created by lices on 03/02/2022.
//


#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
class Heap {
private:
bool max = true;
vector<int> vec;
public:
    int size(){
        return vec.size();
    }
    bool isEmpty(){
        return vec.empty();
    }
    int parentIndex(int childIndex){
        return (childIndex-1)/2;
    }
    int leftChildIndex(int parentIndex){
        return 2*parentIndex+1;
    }
    int rightChildIndex(int parentIndex){
        return 2*parentIndex+2;
    }
    bool onTop(int parent, int child){
        //returns if first should be on top of second, depends on max;
        if(max){
            return child <= parent;
        }
        else{
            return parent <= child;
        }
    }
    void siftUp(int childIndex){
        int parentIndex = this->parentIndex(childIndex);
        if(0 <= parentIndex) {
            int parent = vec[parentIndex], child = vec[childIndex];
            if (!onTop(parent, child)) {
                swap(vec[parentIndex], vec[childIndex]);
                siftUp(parentIndex);
            }
        }
    }
    Heap(bool max = true){
        // max: if true the heap is a max-heap(max on top), if not is a min-heap.
        this->max = max;
    }
    void insert(int value){
        vec.push_back(value);
        int childIndex = size()-1;
        siftUp(childIndex);
    }

    int peek(){
        if(isEmpty()){
            throw std::out_of_range ("Empty heap");
        }
        return vec[0];
    }
    void sift_down(int parentIndex = 0){
        int leftChildIndex = this->leftChildIndex(parentIndex), rightChildIndex = this->rightChildIndex(parentIndex);
        int topChildIndex = -1;
        if(leftChildIndex < size()){
            int leftChild = vec[leftChildIndex];
            if(rightChildIndex < size()){
                int rightChild = vec[rightChildIndex];
                topChildIndex = onTop(leftChild, rightChild)? leftChildIndex: rightChildIndex;
            }
            else{
                topChildIndex = leftChildIndex;
            }
        }
        if(0 < topChildIndex && !onTop(vec[parentIndex], vec[topChildIndex])){
            swap(vec[parentIndex], vec[topChildIndex]);
            sift_down(topChildIndex);
        }
    }
    int pop(){
        if(isEmpty()){
            throw std::out_of_range ("Empty heap");
        }
        int res = vec[0];
        vec[0] = vec[size()-1];
        vec.pop_back();
        sift_down();
        return res;
    }
};
