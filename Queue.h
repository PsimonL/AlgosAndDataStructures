#ifndef ALGORITHMS_GRAPHS_TREES_LISTS_QUEUE_H
#define ALGORITHMS_GRAPHS_TREES_LISTS_QUEUE_H

#include "BuiltInLibs.h"

#define MAXSIZE 10

class Queue {
public:
    int queue[MAXSIZE]{};
    int top;
    int rear;
    int front;

    Queue(int init = -1): rear(init), front(init){}

    void enqueue();
    void dequeue(int x);
    void peek();
    bool isEmpty();
    bool isFull();
    void printQueue();

    void driverCodeQueue();

};

void Queue::driverCodeQueue() {
    int ch, val;
    cout<<"1) Push in queue"<<endl;
    cout<<"2) Pop from queue"<<endl;
    cout<<"3) Display queue"<<endl;
    cout<<"4) Exit"<<endl;
    Queue ObjQueue{};
    ObjQueue.push(5);
    ObjQueue.push(10);
    ObjQueue.push(15);
    ObjQueue.printStack();
    ObjQueue.peek();
    ObjQueue.pop();
    ObjQueue.push(30);
    ObjQueue.printStack();
}

bool Queue::isEmpty() {
    if(front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}
bool Queue::isFull() {

}
void Queue::enqueue() { // insert only at rear or front, it depends xD

}
void Queue::dequeue(int x) {

}
void Queue::peek() {

}
void Queue::printQueue() {

}

#endif //ALGORITHMS_GRAPHS_TREES_LISTS_QUEUE_H
