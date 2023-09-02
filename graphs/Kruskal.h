//
// Created by szymo on 08.03.2023.
//

#ifndef ALGOSANDDATASTRUCTURES_KRUSKAL_H
#define ALGOSANDDATASTRUCTURES_KRUSKAL_H
// #####################################################################################################################
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

typedef  pair<int, int> iPair;

struct Graph
{
    int V, E;
    int cost = 0;

    vector< pair<int, iPair> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int w, int x)
    {
        edges.push_back({x, {u, w } });

    }
    vector<int> KruskalAlgorithm();
    int SortMerged(int k, vector<int> merged);
};

struct DisjointSets
{
    int* parent, * rnk;
    int n;

    DisjointSets(int n)
    {

        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //every element is parent of itself
            parent[i] = i;
        }
    }

    // Find the parent of a Sortings 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    //merge() function is used to merge two sorted ranges
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height
        a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

vector<int> Graph::KruskalAlgorithm(){

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;

    //ARRAY WITH MERGED EDGES
    vector <int> merged;

    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Update MST weight
            cost += it->first;

            // Current edge will be in the MST
            // so print it
            // spacerek pomiędzy połączeniami punktów
            cout << u << " <-> " << v << " Dotychczasowy koszt drogi to: " << cost << endl;

            //wrzucanie do tablicy wybranych krawędzi tworzących najmniejszy koszt
            merged.push_back(it->first);

            // Merge two sets
            //merge() function is used to merge two sorted ranges
            ds.merge(set_u, set_v);
        }
    }
    return merged;
}

//rekurencja
int Graph::SortMerged(int k, vector<int> merged) {
    static int temp = 0;
    int costOFconnection = accumulate(merged.begin(), merged.end(), 0);
    if (costOFconnection >= k) {
        int sizeOFmerged = merged.size();
        sort(merged.begin(), merged.end());
        merged[sizeOFmerged - 1] = 1;
        temp++;
        return SortMerged(k, merged);
        if (temp)
            cout << endl << "liczba wywolan: " << temp << endl;
        temp = 0;
    }
}


int driverCodeKruskal() {
    // N - WIERZCHOLKI - MIASTA
    // M - KRAWEDZIE - DROGI
    int N = 9;
    int M = 14;

    Graph temporary(N, M);

    //limit
    int K = 9;

    cout << "Liczba wierzcholkow wynosi v = " << N << " oraz liczba krawedzi to " << M << "." << endl;
    cout << "Natomiast limit k = " << K << "." << endl;

    /*temporary.addEdge(1, 2, 5);
    temporary.addEdge(2, 3, 4);
    temporary.addEdge(1, 3, 3);*/

    temporary.addEdge(0, 1, 4);
    temporary.addEdge(0, 7, 8);
    temporary.addEdge(1, 2, 8);
    temporary.addEdge(1, 7, 11);
    temporary.addEdge(2, 3, 7);
    temporary.addEdge(2, 8, 2);
    temporary.addEdge(2, 5, 4);
    temporary.addEdge(3, 4, 9);
    temporary.addEdge(3, 5, 14);
    temporary.addEdge(4, 5, 10);
    temporary.addEdge(5, 6, 2);
    temporary.addEdge(6, 7, 1);
    temporary.addEdge(6, 8, 6);
    temporary.addEdge(7, 8, 7);

    /*temporary.addEdge(4, 6, 1);
    temporary.addEdge(4, 5, 2);
    temporary.addEdge(2, 7, 3);
    temporary.addEdge(0, 6, 3);
    temporary.addEdge(2, 4, 4);
    temporary.addEdge(0, 1, 5);
    temporary.addEdge(2, 6, 5);
    temporary.addEdge(1, 5, 6);
    temporary.addEdge(5, 6, 6);
    temporary.addEdge(1, 7, 7);
    temporary.addEdge(1, 4, 8);
    temporary.addEdge(3, 6, 8);
    temporary.addEdge(0, 3, 9);
    temporary.addEdge(1, 2, 9);
    temporary.addEdge(2, 3, 9);
    temporary.addEdge(6, 7, 9);*/

    cout << "Drogi, ktore zostana wybudowane to:" << endl;

    vector<int> merged;
    merged = temporary.KruskalAlgorithm();
    int accumulationOFmerged = accumulate(merged.begin(), merged.end(), 0);
    cout << endl;
    cout << "Koszt drog przed wprowadzeniem superdrog wynosi: ";
    cout << accumulationOFmerged << endl;

    // W PRZYPADKU, GDY V > K KOMPILATOR ZWRACA BLAD
    // DLA K<=v KOD DZIALA POPRAWNIE
    // PONIEWAZ JEST TO MINIMALNE DRZEWO ROZPINAJACE
    if(K <= N) {
        if (accumulationOFmerged > K) {
            cout << "Koszt drog po wprowadzeniu superdrog, dla limitu k = " << K << " wynosi: " << temporary.SortMerged(K, merged) << endl;
        }
    } else{
        cout << "Superdrogi nie moga zostac wybudowane!" << endl;
        cout << "Musisz wybrac limit mniejszy lub rowny od liczby miast (wierzcholkow)! Sprobuj jeszcze raz." << endl;
    }
    return 0;
}
// #####################################################################################################################
#endif //ALGOSANDDATASTRUCTURES_KRUSKAL_H




// Based on: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
// https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
//// C++ program for Kruskal's algorithm to find Minimum
//// Spanning Tree of a given connected, undirected and
//// weighted graph
//#include<bits/stdc++.h>
//using namespace std;
//
//// Creating shortcut for an integer pair
//typedef  pair<int, int> iPair;
//
//// Structure to represent a graph
//struct Graph
//{
//    int V, E;
//    vector< pair<int, iPair> > edges;
//
//    // Constructor
//    Graph(int V, int E)
//    {
//        this->V = V;
//        this->E = E;
//    }
//
//    // Utility function to add an edge
//    void addEdge(int u, int v, int w)
//    {
//        edges.push_back({w, {u, v}});
//    }
//
//    // Function to find MST using Kruskal's
//    // MST algorithm
//    int kruskalMST();
//};
//
//// To represent Disjoint Sets
//struct DisjointSets
//{
//    int *parent, *rnk;
//    int n;
//
//    // Constructor.
//    DisjointSets(int n)
//    {
//        // Allocate memory
//        this->n = n;
//        parent = new int[n+1];
//        rnk = new int[n+1];
//
//        // Initially, all vertices are in
//        // different sets and have rank 0.
//        for (int i = 0; i <= n; i++)
//        {
//            rnk[i] = 0;
//
//            //every element is parent of itself
//            parent[i] = i;
//        }
//    }
//
//    // Find the parent of a node 'u'
//    // Path Compression
//    int find(int u)
//    {
//        /* Make the parent of the nodes in the path
//           from u--> parent[u] point to parent[u] */
//        if (u != parent[u])
//            parent[u] = find(parent[u]);
//        return parent[u];
//    }
//
//    // Union by rank
//    void merge(int x, int y)
//    {
//        x = find(x), y = find(y);
//
//        /* Make tree with smaller height
//           a subtree of the other tree  */
//        if (rnk[x] > rnk[y])
//            parent[y] = x;
//        else // If rnk[x] <= rnk[y]
//            parent[x] = y;
//
//        if (rnk[x] == rnk[y])
//            rnk[y]++;
//    }
//};
//
///* Functions returns weight of the MST*/
//
//int Graph::kruskalMST()
//{
//    int mst_wt = 0; // Initialize result
//
//    // Sort edges in increasing order on basis of cost
//    sort(edges.begin(), edges.end());
//
//    // Create disjoint sets
//    DisjointSets ds(V);
//
//    // Iterate through all sorted edges
//    vector< pair<int, iPair> >::iterator it;
//    for (it=edges.begin(); it!=edges.end(); it++)
//    {
//        int u = it->second.first;
//        int v = it->second.second;
//
//        int set_u = ds.find(u);
//        int set_v = ds.find(v);
//
//        // Check if the selected edge is creating
//        // a cycle or not (Cycle is created if u
//        // and v belong to same set)
//        if (set_u != set_v)
//        {
//            // Current edge will be in the MST
//            // so print it
//            cout << u << " - " << v << endl;
//
//            // Update MST weight
//            mst_wt += it->first;
//
//            // Merge two sets
//            ds.merge(set_u, set_v);
//        }
//    }
//
//    return mst_wt;
//}
//
//// Driver program to test above functions
//int main()
//{
//    /* Let us create above shown weighted
//       and unidrected graph */
//    int V = 9, E = 14;
//    Graph g(V, E);
//
//    //  making above shown graph
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);
//
//    cout << "Edges of MST are \n";
//    int mst_wt = g.kruskalMST();
//
//    cout << "\nWeight of MST is " << mst_wt;
//
//    return 0;
//}