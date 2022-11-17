#ifndef ALGOSANDDATASTRUCTURES_LINKEDLIST_H
#define ALGOSANDDATASTRUCTURES_LINKEDLIST_H

class LinkedList{
public:
    struct Node{
    public:
        int data;
        Node* next;
    };
    void addBeforeHead(Node*& head, int valueToAdd);
    void addAfterTail(Node*& head, int valueToAdd);
    void addAnywhere(Node*& head, int valueToAdd, int pos);
    void printLinkedList(Node* head);
    void removeFirst(Node*& head);
    void removeLast(Node*& head);

    void driverCodeLinkedList();
};

void LinkedList::driverCodeLinkedList() {

}

void LinkedList:: addBeforeHead(Node*& head, int valueToAdd) {
    Node* nodeToAdd = new Node;
    nodeToAdd->data = valueToAdd; //tworzenie nowego węzła
    nodeToAdd->next = head; //dopinamy wskaźnik nowego na starą głowę
    head = nodeToAdd; //głowę przepinamy na nowy węzeł
}

void LinkedList::addAfterTail(Node*& head, int valueToAdd){
    Node* nodeToAdd = new Node;
    nodeToAdd->data = valueToAdd; //tworzenie nowego węzła
    nodeToAdd->next = NULL;
    if (!head){ //jeśli lista jest pusta
        head = nodeToAdd;
        return;
    }
    Node* temp = head;
    while (temp->next) { //szukamy ostatniego elementu (następnik wskazuje na NULL)
        temp = temp->next; //analog i++ w tablicach
    }
    temp->next = nodeToAdd;
}

void LinkedList::addAnywhere(Node*& head, int valueToAdd, int pos){ //dodawanie na określonją pozycję
    if (pos == 0 || !head){
        addBeforeHead(head, valueToAdd);
        return;
    }
    Node* nodeToAdd = new Node;
    nodeToAdd->data = valueToAdd; //tworzenie nowego węzła
    int i = 0; //zliczamy ilość elementów aż trafimy na pos
    Node* temp = head;
    while (i < pos-1 && temp->next){
        temp = temp->next;
        i++;
    }
    nodeToAdd->next = temp->next; //zapisujemy wszytsko co było za wskaźnikiem pom do nodeToAdd->next
    temp->next = nodeToAdd;
}

void LinkedList::printLinkedList(Node* head){
    Node* temp = head;

    if (!head)
    {
        cout << "lista jest pusta" << endl;
        return;
    }

    while (temp->next)
    {
        cout << temp->data << "<-";
        temp = temp->next;
    }
}

void LinkedList::removeFirst(Node*& head){
    if (!head){
        cout << "Lista jest pusta" << endl;
        return;
    }
    Node* pom = head;
    head = head->next;
    delete pom;
}

void LinkedList::removeLast(Node *&head){
    if (!head){ //lista pusta, nic nie usuwamy
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (!head->next){ //lista jednoelementowa, usuwamy głowę, lista staje się pusta
        delete head;
        return;
    }
    Node* temp = head;
    while (temp->next->next){ //szukamy przedostatniego elementu (następnik wskazuje na NULL)
        temp = temp->next; //analog i++ w tablicach
    }
    delete temp->next; //usuwamy ostatni (nastepnika przedostatniego)
    temp->next = NULL; //ręcznie ustawiamy wskaźnik na NULL
}


#endif //ALGOSANDDATASTRUCTURES_LINKEDLIST_H
