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
    void removeAnywhere(Node*& head, int pos);
    void removeAllData(Node*& head, int target);

    Node* find(Node* head, int target){ //zwracamy cały nzaleziony element
        if (!head){ //pusta lista
            cout << "Lista jest pusta" << endl;
            return NULL;
        }
        Node* temp = head;
        while (temp->data!=target && temp->next){ //szukamy wartości lub ostatniego elementu
            temp = temp->next;
        }
        if (temp->data == target) { //jeśli wartośc znaleziona - zwróć element
            return temp;
        }
        else{ //jeśli nie to jesteśmy na końcu listy, brak szukanego elementu
            cout << "Brak elementu o podanej wratości"<<endl;
        }
        return NULL;
    }

    void driverCodeLinkedList();
};

void LinkedList::driverCodeLinkedList() {
    Node* head = new Node();
    head->data = 0;
    head->next = NULL;

    cout << "In order to Head-> ... ->Tail->NULL\n";

//    printLinkedList(head);
//    addBeforeHead(head, 1);
//    addBeforeHead(head, 2);
//    addBeforeHead(head, 3);
//    addBeforeHead(head, 4);
//    addBeforeHead(head, 5);
//    printLinkedList(head);

//    printLinkedList(head);
//    addAfterTail(head, 1);
//    addAfterTail(head, 2);
//    addAfterTail(head, 3);
//    addAfterTail(head, 4);
//    addAfterTail(head, 5);
//    printLinkedList(head);

    // !!! Not working in all cases
//    printLinkedList(head);
//    addAnywhere(head, 1, 2);
//    addAnywhere(head, 9, 1);
//    addAnywhere(head, 5, 0);
//    printLinkedList(head);

//    printLinkedList(head);
//    removeFirst(head);

//    printLinkedList(head);
//    removeLast(head);

//    printLinkedList(head);
//    removeAnywhere(head, 1);

//    printLinkedList(head);
//    Node* temp;
//    temp = find(head, 3);
//    removeAllData(head, temp->data);
//    printLinkedList(head);

    cout << "\nLinked List done\n";
}

void LinkedList::printLinkedList(Node* head){
    cout << "\n";
    cout << "New print procedure\n";
    Node* temp = head;
    if (!head){
        cout << "lista jest pusta" << endl;
        return;
    }
    while (temp->next){
        cout << temp->data;
        cout << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
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

void LinkedList::removeAnywhere(Node*& head, int pos){
    if (!head){ //lista pusta, nic nie usuwamy
        cout << "Lista jest pusta" << endl;
        return;
    }
    if (pos == 0){
        removeFirst(head);
    }
    Node* temp = head;
    int i = 0; //zliczamy ilość elementów aż trafimy na pos
    while (i < pos - 1 && temp->next->next){ //szukamy elementu, który jest położony przed tym, który chemy usunąć
        temp = temp->next;
        i++;
    }
    //usuwamy pom->next
    Node* temp2 = temp->next; //zapisujemy element który chemy usunąć
    temp->next = temp2->next; //pom->next ma teraz wskazywać na to co jestpo usuwanym  elemencie
    delete temp2;
}

void LinkedList::removeAllData(Node *&head, int target){
    if (!head){ //pusta lista
        cout << "Lista jest pusta" << endl;
        return;
    }
    if (!head->next){ //1-elementowa lista
        if (head->data == target)
            delete head;
        return;
    }
    while (head && head->data == target){ //usuwamy wszytskie głowy po kolei dopóki sa równe target
        removeFirst(head);
    }
    Node* temp = head;
    Node* temp2 = NULL;
    while (temp->next && temp->next->next){ //pom ma wskazywać na element przed usuwanym
        if (temp->next->data == target){
            temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        temp = temp->next;
    }
    if (temp->next->data = target){ //jesli ostatnie element (następnik pom) jest równy target to usuwamy
        removeLast(head);
    }
}
//Node* find(Node* head, int target){ //zwracamy cały nzaleziony element
//    if (!head){ //pusta lista
//        cout << "Lista jest pusta" << endl;
//        return NULL;
//    }
//    Node* temp = head;
//    while (temp->data!=target && temp->next){ //szukamy wartości lub ostatniego elementu
//        temp = temp->next;
//    }
//    if (temp->data == target) { //jeśli wartośc znaleziona - zwróć element
//        return temp;
//    }
//    else{ //jeśli nie to jesteśmy na końcu listy, brak szukanego elementu
//        cout << "Brak elementu o podanej wratości"<<endl;
//    }
//    return NULL;
//}
#endif //ALGOSANDDATASTRUCTURES_LINKEDLIST_H
