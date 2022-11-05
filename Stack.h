#ifndef ALGORITHMS_GRAPHS_TREES_LISTS_STACK_H
#define ALGORITHMS_GRAPHS_TREES_LISTS_STACK_H


#include "iostream"
#include <iomanip>

using namespace std;
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
    int ch, val;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    Stack obj{};
    obj.push(5);
    obj.push(10);
    obj.push(15);
    obj.printStack();
    obj.peek();
    obj.pop();
    obj.push(30);
    obj.printStack();
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
    printf("\n");
    printf("CURRENT STACK: \n");
    cout
            <<left
            << setw(10)
            << "ID"
            << left
            << setw(5)
            << "Value\n";
    int counter = 0;
    for(int i = 0; i <= top; i++){
        if(stack[i] != 0)
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


#endif //ALGORITHMS_GRAPHS_TREES_LISTS_STACK_H
