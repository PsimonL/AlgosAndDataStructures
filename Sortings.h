#ifndef ALGOSANDDATASTRUCTURES_SORTINGS_H
#define ALGOSANDDATASTRUCTURES_SORTINGS_H

// =====================================================================================================================
// =====================================================================================================================
// Below codes purely based on materials provided on AGH UST in Cracov classes
// =====================================================================================================================
// =====================================================================================================================

#include "BuiltInLibs.h"
using namespace std;

struct node
{
    node* next;
    node* prev;
    int data;
};

void wypisz(node* head)
{
    node* pom = new node;
    pom = head;

    while (pom != NULL)
    {
        cout << pom->data << " ";
        pom = pom->next;
    }
}

void wypisz2(node* head, node* tail)
{
    node* pom = new node;
    pom = head;

    while (pom != NULL && pom!=tail)
    {
        cout << pom->data << " ";
        pom = pom->next;
    }

}
void myswap(int &a, int &b)
{
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}

int partition(int tab[], int l, int r)
{
    int pivot = tab[l];
    int i = l+1;
    int j = r;

    while (i<j)
    {
        while (tab[i] >= pivot && i<=r) i++;

        while (tab[j] < pivot && j > l) j--;

        if (i >= j) break;

        else myswap(tab[i], tab[j]);
    }


    for (int k = l; k < r; k++)
    {
        cout << tab[k] << " ";
    }
    cout << endl;

    myswap(tab[l], tab[i - 1]);

    return i-1;
}

void quicksort(int tab[], int l, int r)
{
    if (l < r)
    {
        int p = partition(tab, l, r);
        quicksort(tab, l, p-1);
        quicksort(tab, p + 1, r);
    }
}

node* partition_lists(node* l, node* r)
{
    int pivot = l->data;

    node* i = l;
    node* j = r;

    bool isTimeToStop = false;

    while (1)
    {
        while (i && i->next && i->data < pivot)
        {
            i = i->next;
            if (j == i || !i)
            {
                isTimeToStop = true;
            }
        }

        while (j && j->prev && j->data >= pivot)
        {
            j = j->prev;
            if (j == i || !j) isTimeToStop = true;
        }

        if (isTimeToStop || !j || !i)
            break;
        else if (i && j) myswap(i->data, j->data);
    }
    myswap(l->data, i->prev->data);
    return i->prev;
}

void myswapNodes(node*& a, node*& b)
{
    node* pom = b;
    a->prev->next = b;
    b->next = a->next;
    a->next->prev = b;
    b->prev = a->prev;

    pom->prev->next = a;
    a->next = pom->next;
    pom->next->prev = a;
    a->prev = pom->prev;
}

node* partition_lists2(node* l, node* r)
{
    int pivot = r->data;
    node* i = l->prev;

    for (node* j = l; j != r; j = j->next)
    {
        if (j->data > pivot)
        {
            i = (i == NULL) ? l : i->next;
            myswap(i->data, j->data);
        }
    }
    i = (i == NULL) ? l : i->next;

    wypisz2(l,r);
    cout << endl;
    myswap(i->data, r->data);
    return i;
}

void quicksort_lists(node* l, node* r)
{
    if (r && l != r && l != r->next)
    {
        node* p = partition_lists2(l, r);
        quicksort_lists(l, p->prev);
        quicksort_lists(p->next, r);
    }
}

void addnode(int pos, int value, node*& head)
{
    node* pom = new node;
    pom = head;
    node* nodeToAdd = new node;
    nodeToAdd->data = value;
    nodeToAdd->next = NULL;
    nodeToAdd->prev = NULL;

    int i = 0;
    if (head == NULL)
    {
        head = nodeToAdd;
    }
    else
    {
        if (pos == 0)
        {
            nodeToAdd->next = head;
            nodeToAdd->prev = NULL;
            head->prev = nodeToAdd;
            head = nodeToAdd;
        }
        else {
            while (pom->next != NULL && i != pos)
            {
                pom = pom->next;
                i++;
            }
            nodeToAdd->next = pom->next;
            if (pom->next) pom->next->prev = nodeToAdd;
            nodeToAdd->prev = pom;
            pom->next = nodeToAdd;
        }
    }
}

void removeNode(int pos, node*& head)
{
    node* pom = new node;
    pom = head;


    int i = 0;
    if (head == NULL)
    {
        cout << "Pusta lista" << endl;
    }
    else
    {
        if (head->next == NULL)
        {
            if (pos == 0)
            {
                delete head;
            }
            cout << "brak elementu" << endl;
        }
        else
        {
            node* pom2 = new node;
            pom2 = head->next;
            while (pom2->next != NULL && i != pos - 1)
            {
                pom = pom->next;
                pom2 = pom2->next;
                i++;
            }

            pom->next = pom2->next;
            if (pom2->next) pom2->next->prev = pom;
            delete pom2;
        }
    }
}

node* getTail(node* head)
{
    node* pom = head;
    if (!pom) return NULL;

    while (pom->next)
        pom = pom->next;

    return pom;
}

void splitList(node* head, node*& front, node*& back)
{
    node* fast;
    node* slow;
    slow = head;
    fast = head->next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = head;
    back = slow->next;
    //back->prev = NULL;
    slow->next = NULL;
}

node* merge(node* a, node* b)
{
    node* result = NULL;
    if (!a) return (b);
    else if (!b) return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    wypisz(result);
    cout << endl;
    return result;
}

void mergesort(node*& head)
{
    node* a;
    node* b;

    if (!head || !head->next)
        return;
    splitList(head, a, b);

    mergesort(a);
    mergesort(b);

    head = merge(a, b);
}

void heapify(int tab[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<n && tab[l] > tab[largest])
        largest = l;

    if (r< n && tab[r] > tab[largest])
        largest = r;

    if (largest != i)
    {
        myswap(tab[i], tab[largest]);
        heapify(tab, n, largest);
    }
}

void heapsort(int tab[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(tab, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    for (int i = n - 1; i > 0; i--)
    {
        myswap(tab[0], tab[i]);
        heapify(tab, i, 0);
    }
}

void partialheapsort(int tab[], int n, int k)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(tab, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    for (int i = n - 1; i > n-1-k; i--)
    {
        myswap(tab[0], tab[i]);
        heapify(tab, i, 0);
    }
}

int getmax(int tab[], int n)
{
    int max = tab[0];
    for (int i = 0; i < n; i++)
    {
        if (tab[i] > max) max = tab[i];
    }
    return max;
}

void bucketsort(int tab[], int n)
{
    int max = getmax(tab, n);
    int b_nr;
    node** buckets;
    buckets = new node * [n];

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++)
    {
        b_nr = tab[i] * n / (max + 1);
        addnode(0, tab[i], buckets[b_nr]);
    }

    for (int i = 0; i < n; i++)
    {
        if (buckets[i] && buckets[i]->next) mergesort(buckets[i]);
    }

    b_nr=0;
    int i = 0;
    while (i<n)
    {
        if (buckets[b_nr])
        {
            tab[i] = buckets[b_nr]->data;
            buckets[b_nr] = buckets[b_nr]->next;
            i++;
        }
        else b_nr++;
    }
}

void countingsort(int tab[], int n)
{
    int* frequency;
    int* output;

    int k = getmax(tab, n);

    frequency = new int[k + 1];
    output = new int[n];

    for (int i = 0; i <= k; i++)
    {
        frequency[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        frequency[tab[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        frequency[i] += frequency[i - 1];
    }

    for (int i = n-1; i >= 0; i--)
    {
        output[frequency[tab[i]] - 1] = tab[i];
        frequency[tab[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        tab[i] = output[i];
    }
}

void countingsort(int tab[], int n, int exp)
{
    int frequency[10] = { 0 };
    int* output;
    output = new int[n];

    for (int i = 0; i < n; i++)
    {
        frequency[(tab[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
        frequency[i] += frequency[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[frequency[(tab[i] / exp) % 10] - 1] = tab[i];
        frequency[(tab[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        tab[i] = output[i];
}

void radixsort(int tab[], int n)
{
    int m = getmax(tab, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingsort(tab, n, exp);
}


//

void selectionSort(int *&tab, int n)
{
    int i, j, min_id;

    for (i = 0; i < n - 1; i++)
    {
        min_id = i;
        for (j = i + 1; j < n; j++)
        {
            if (tab[j] < tab[min_id])
                min_id = j;
        }
        myswap(tab[min_id], tab[i]);
    }
}

void insertionSort(int*& tab, int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        k = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > k)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = k;
    }
}

void driverCodeSort()
{
    int tab[40];
    int size = 40;
    node* head = new node;
    head = NULL;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % 50;
        addnode(0, tab[i], head);
    }

    //radixsort(tab, size);
    //bucketsort(tab, size);
    countingsort(tab, size);
    //heapsort(tab, size);
    //partialheapsort(tab, size,5);
    //quicksort(tab, 0, size - 1);
    //quicksort_lists(head, getTail(head));
    //mergesort(head);
    //selectionSort(tab, size); // not formated
    // insertionSort(tab, size); // not formated
    system("pause");
}


#endif
