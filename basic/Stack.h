// https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
// https://www.geeksforgeeks.org/stack-in-cpp-stl/


#ifndef ALGORITHMS_GRAPHS_TREES_LISTS_STACK_H
#define ALGORITHMS_GRAPHS_TREES_LISTS_STACK_H

#include "BuiltInLibs.h"

#define MAXSIZE 10

class Stack {
public:
    int stack[MAXSIZE]{};
    int top;

    Stack(int init = -1): top(init){}

    void pop();
    void push(int x);
    void peek();
    bool isEmpty();
    bool isFull();
    void printStack();

    void driverCodeStack();
};

void Stack::driverCodeStack(){
    Stack ObjStack{};
    ObjStack.push(5);
    ObjStack.push(10);
    ObjStack.push(15);
    ObjStack.printStack();
    ObjStack.peek();
    ObjStack.pop();
    ObjStack.push(30);
    ObjStack.printStack();
}

void Stack::push(int x){
    if(isFull()) cout << "stackmain OverFlow - FULL STACK! \n";
    else {
        top++;
        stack[top] = x;
    }
}

void Stack::pop(){
    int x{0};
    if(isEmpty()){
        printf("stackmain UnderFlow - EMPTY STACK! \n");
    }
    x = stack[top--];
    printf("Popped Value = %d\n", x);
}

bool Stack::isFull() {
    if(top == MAXSIZE) return true;
    else return false;
}

bool Stack::isEmpty() {
    if(top == -1) return true;
    else return false;
}

void Stack::peek() {
    printf("Peek Value = %d\n", stack[top]);
}

void Stack::printStack() {
    if (isEmpty()){
        cout << "Stack is empty!\n";
    } else {
        printf("\n");
        printf("CURRENT STACK: \n");
        cout
                << left
                << setw(10)
                << "ID"
                << left
                << setw(5)
                << "Value\n";
        int counter = 0;
        for (int i = 0; i <= top; i++) {
            if (stack[i] != 0)
                cout
                        << left
                        << setw(10)
                        << ++counter
                        << left
                        << setw(5)
                        << stack[i] << endl;
        }
        printf("\n");
    }
}


#endif //ALGORITHMS_GRAPHS_TREES_LISTS_STACK_H
