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
    void check(int parentIndex, int childIndex){
        if(0 <= parentIndex) {
            int parent = vec[parentIndex], child = vec[childIndex];
            if (!onTop(parent, child)) {
                swap(vec[parentIndex], vec[childIndex]);
                check(this->parentIndex(parentIndex), parentIndex);
            }
        }
    }
    Heap(bool max = true){
        // max: if true the heap is a max-heap(max on top), if not is a min-heap.
        this->max = max;
    }
    void insert(int value){
        vec.push_back(value);
        int childIndex = size()-1, parentIndex = this->parentIndex(childIndex);
        check(parentIndex, childIndex);
        print();
    }

    int peek(){
        if(isEmpty()){
            throw std::out_of_range ("Empty heap");
        }
        return vec[0];
    }
    void grew_child(int parentIndex){
        int leftChildIndex = this->leftChildIndex(parentIndex), rightChildIndex = this->rightChildIndex(parentIndex);
        if(leftChildIndex < size()){
            int leftChild = vec[leftChildIndex];
            if(rightChildIndex < size()){
                int rightChild = vec[rightChildIndex];
                if(onTop(leftChild, rightChild)){
                    vec[parentIndex] = leftChild;
                    grew_child(leftChildIndex);
                }
                else{
                    vec[parentIndex] = rightChild;
                    grew_child(rightChildIndex);
                }
            }
            else{
                vec[parentIndex] = leftChild;
                vec.pop_back();
            }
        }
        else{
            vec.pop_back();
        }
    }
    int pop(){

        if(isEmpty()){
            throw std::out_of_range ("Empty heap");
        }
        int res = vec[0];
        grew_child(0);
        print();
        return res;
    }
    void print(){
        cout<<"[";
        for(int i = 0; i < size()-1; i++){
            cout<<vec[i]<<", ";
        }
        cout<<vec[size()-1]<<"]\n";
    }

};
