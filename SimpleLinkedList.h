#ifndef ALGOSANDDATASTRUCTURES_SIMPLELINKEDLIST_H
#define ALGOSANDDATASTRUCTURES_SIMPLELINKEDLIST_H

#include "BuiltInLibs.h"
struct node
{
    int value;
    node* next;
};

void add_before_head(node*& head, int valueToAdd)
{
    node* nodeToAdd = new node;
    nodeToAdd->value = valueToAdd; //tworzenie nowego węzła

    nodeToAdd->next = head; //dopinamy wskaźnik nowego na starą głowę
    head = nodeToAdd; //głowę przepinamy na nowy węzeł
}

void add_to_tail(node*& head, int valueToAdd)
{
    node* nodeToAdd = new node;
    nodeToAdd->value = valueToAdd; //tworzenie nowego węzła
    nodeToAdd->next = NULL;

    if (!head) //jeśli lista jest pusta
    {
        head = nodeToAdd;
        return;
    }

    node* pom = head;

    while (pom->next) //szukamy ostatniego elementu (następnik wskazuje na NULL)
    {
        pom = pom->next; //analog i++ w tablicach
    }

    pom->next = nodeToAdd; //dodajemy jako następnika ostatniego elementu
}

void add_to_pos(node*& head, int valueToAdd, int pos) //dodawanie na określonją pozycję
{
    if (pos == 0 || !head)
    {
        add_before_head(head, valueToAdd);
        return;
    }

    node* nodeToAdd = new node;
    nodeToAdd->value = valueToAdd; //tworzenie nowego węzła

    int i = 0; //zliczamy ilość elementów aż trafimy na pos

    node* pom = head;

    while (i < pos-1 && pom->next)
    {
        pom = pom->next;
        i++;
    }

    nodeToAdd->next = pom->next; //zapisujemy wszytsko co było za wskaźnikiem pom do nodeToAdd->next
    pom->next = nodeToAdd;
}

void print_list(node* head)
{
    node* pom = head;

    if (!head)
    {
        cout << "lista jest pusta" << endl;
        return;
    }

    while (pom->next)
    {
        cout << pom->value << "<-";
        pom = pom->next;
    }
}

void remove_first(node*& head)
{
    if (!head)
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    node* pom = head;
    head = head->next;
    delete pom;
}

void remove_last(node*& head)
{
    if (!head) //lista pusta, nic nie usuwamy
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (!head->next) //lista jednoelementowa, usuwamy głowę, lista staje się pusta
    {
        delete head;
        return;
    }

    node* pom = head;

    while (pom->next->next) //szukamy przedostatniego elementu (następnik wskazuje na NULL)
    {
        pom = pom->next; //analog i++ w tablicach
    }

    delete pom->next; //usuwamy ostatni (nastepnika przedostatniego)
    pom->next = NULL; //ręcznie ustawiamy wskaźnik na NULL
}

void remove_pos(node*& head, int pos)
{
    if (!head) //lista pusta, nic nie usuwamy
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (pos == 0)
    {
        remove_first(head);
    }

    int i = 0; //zliczamy ilość elementów aż trafimy na pos

    node* pom = head;

    while (i < pos - 1 && pom->next->next) //szukamy elementu, który jest położony przed tym, który chemy usunąć
    {
        pom = pom->next;
        i++;
    }
    //usuwamy pom->next
    node* pom2 = pom->next; //zapisujemy element który chemy usunąć
    pom->next = pom2->next; //pom->next ma teraz wskazywać na to co jestpo usuwanym  elemencie
    delete pom2;
}

node* find(node* head, int target) //zwracamy cały nzaleziony element
{
    if (!head) //pusta lista
    {
        cout << "Lista jest pusta" << endl;
        return NULL;
    }

    node* pom = head;

    while (pom->value!=target && pom->next) //szukamy wartości lub ostatniego elementu
    {
        pom = pom->next;
    }

    if (pom->value == target) //jeśli wartośc znaleziona - zwróć element
        return pom;
    else //jeśli nie to jesteśmy na końcu listy, brak szukanego elementu
    {
        cout << "Brak elementu o podanej wratości"<<endl;
    }

    return NULL;
}

void remove_all_values(node*& head, int target)
{
    if (!head) //pusta lista
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (!head->next) //1-elementowa lista
    {
        if (head->value == target)
            delete head;
        return;
    }

    while (head && head->value == target) //usuwamy wszytskie głowy po kolei dopóki sa równe target
    {
        remove_first(head);
    }

    node* pom = head;
    node* pom2 = NULL;

    while (pom->next && pom->next->next) //pom ma wskazywać na element przed usuwanym
    {
        if (pom->next->value == target)
        {
            pom2 = pom->next;
            pom->next = pom2->next;
            delete pom2;
        }
        pom = pom->next;
    }

    if (pom->next->value = target) //jesli ostatnie element (następnik pom) jest równy target to usuwamy
    {
        remove_last(head);
    }
}

void driverCodeSimpleLinkedList(){

}

#endif //ALGOSANDDATASTRUCTURES_SIMPLELINKEDLIST_H
