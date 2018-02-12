/* Algoritmul lui Dijkstra construieste drumurile cu costul minim care pornesc de la un nod oarecare (nod sursa) pana la fiecare nod 
din graf (noduri destinatie) */

#include <iostream>

using namespace std;

const int NMAX = 105;
const int INF = 1000000000;

struct node {
    int info, cost;
    node* next;
};

void add(node* &first, int val, int cost) {
    node* p = new node;
    p->info = val;
    p->cost = cost;
    p->next = first;
    first = p;
}

void read(node* G[NMAX], int& n, int& m, int& sourceNode) {
    cin >> n >> m >> sourceNode;
    for (int i = 1; i <= m; ++ i) {
        int x, y, cost;
        cin >> x >> y >> cost;
        add(G[x], y, cost);
        add(G[y], x, cost); // doar pentru grafuri neorientate
    }
}

void dijkstra(int sourceNode, node* G[NMAX], int n, int dist[NMAX], int par[NMAX]) {
    bool done[NMAX];

    // initializari
    for (int i = 1; i <= n; ++ i) {
        dist[i] = INF;
        par[i] = 0;
    }
    for (node* p = G[sourceNode]; p; p = p->next) {
        dist[p->info] = p->cost;
        par[p->info] = sourceNode;
    }
    dist[sourceNode] = 0;
    par[sourceNode] = 0;
    for (int i = 1; i <= n; ++ i)
        done[i] = false;

    for (int it = 1; it < n; ++ it) {
        int dmin = INF, v;
        for (int i = 1; i <= n; ++ i)
            if (!done[i] && dist[i] < dmin) {
                v = i;
                dmin = dist[i];
            }
        done[v] = true;
        for (node* p = G[v]; p; p = p->next)
            if (!done[p->info] && dist[p->info] > dist[v] + p->cost) {
                dist[p->info] = dist[v] + p->cost;
                par[p->info] = v;
            }
    }
}

void track(int par[NMAX], int x) {
    if (par[x])
        track(par, par[x]);
    cout << x << " ";
}

void print(int n, int sourceNode, int dist[NMAX], int par[NMAX]) {
    for (int i = 1; i <= n; ++ i)
        if (dist[i] != INF) {
            cout << "Drumul minim de la " << sourceNode << " la " << i << " are lungimea " << dist[i] << " si este ";
            track(par, i);
            cout << "\n";
        }
        else
            cout << "Nu exista drum de la " << sourceNode << " la " << i << "\n";
}

int main() {
    int n, m, sourceNode;
    node* G[NMAX] = {};
    int dist[NMAX], par[NMAX];
    read(G, n, m, sourceNode);
    dijkstra(sourceNode, G, n, dist, par);
    print(n, sourceNode, dist, par);
    return 0;
}
