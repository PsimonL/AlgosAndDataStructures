// https://www.geeksforgeeks.org/queue-cpp-stl/
// https://en.wikipedia.org/wiki/Queue_(abstract_data_type)





#ifndef ALGORITHMS_GRAPHS_TREES_LISTS_QUEUE_H
#define ALGORITHMS_GRAPHS_TREES_LISTS_QUEUE_H

#include "BuiltInLibs.h"

#define MAXSIZE 10

class Queue {
public:
    int queue[MAXSIZE]{};
    int rear;
    int front;

    Queue(int init = 0): rear(init), front(init){}

    void enqueue(int x);
    void dequeue();
    void peek();
    bool isEmpty();
    bool isFull();
    void printQueue();

    void driverCodeQueue();

};

void Queue::driverCodeQueue() {
    Queue ObjQueue{};
    ObjQueue.printQueue();
    ObjQueue.enqueue(4);
    ObjQueue.enqueue(1);
    ObjQueue.enqueue(3);
    ObjQueue.enqueue(8);
    ObjQueue.enqueue(17);
    ObjQueue.printQueue();
    ObjQueue.dequeue();
    ObjQueue.printQueue();
    ObjQueue.peek();
}

bool Queue::isFull() {
    if(rear == MAXSIZE) return true;
    else return false;
}
void Queue::enqueue(int x) { // insert only at rear or front, it depends on xD
    if(isFull()){
        cout << "Queue is full!!!\n";
        return;
    }else{
        queue[rear] = x;
        rear++;
    }
}
bool Queue::isEmpty() {
    if(front == rear) return true;
    else return false;
}
void Queue::dequeue() {
    if(isEmpty()){
        cout << "Queue is empty!!!\n";
    }else{
        if(front == rear) front = rear = 0;
        else front++;
    }
}
void Queue::peek() {
    if(isEmpty()){
        cout << "Queue is empty!\n";
    }else{
        cout << "Peek data = " << queue[front];
    }
}
void Queue::printQueue() {
    cout << "Printing Queue...\n";
    if (isEmpty()) {
        cout << "Queue is empty!\n";
    } else {
        printf("\n");
        printf("CURRENT QUEUE: \n");
        for (int i = front; i <= rear; i++) {
            if(queue[i] != 0) {
                cout << queue[i] << " ";
            }
        }
        cout << "\n";
    }
}
#endif //ALGORITHMS_GRAPHS_TREES_LISTS_QUEUE_H
