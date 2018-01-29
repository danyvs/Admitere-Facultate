#include <iostream>

using namespace std;

const int NMAX = 105;
const int MMAX = 50005;

struct edge {
    int x, y, cost;
};

void read(edge vec[MMAX], int& n, int& m) {
    cin >> n >> m;
    for (int i = 0; i < m; ++ i)
        cin >> vec[i].x >> vec[i].y >> vec[i].cost;
}

void swapEdge(edge& a, edge& b) {
    edge c = a;
    a = b;
    b = c;
}

int part(edge vec[NMAX], int lo, int hi) {
    int pivot = vec[hi].cost;
    int i = lo - 1;
    for (int j = lo; j < hi; ++ j)
        if (vec[j].cost < pivot)
            swapEdge(vec[++ i] , vec[j]);
    if (vec[hi].cost < vec[i + 1].cost)
        swapEdge(vec[hi], vec[i + 1]);
    return i + 1;
}

void quickSort(edge vec[NMAX], int lo, int hi) {
    if (lo < hi) {
        int p = part(vec, lo, hi);
        quickSort(vec, lo, p - 1);
        quickSort(vec, p + 1, hi);
    }
}

int root(int par[NMAX], int x) {
    while (par[x])
        x = par[x];
    return x;
}

void unite(int par[NMAX], int ht[NMAX], int x, int y) {
    if (ht[x] > ht[y])
        par[y] = x;
    else {
        par[x] = y;
        if (ht[x] == ht[y])
            ++ ht[y];
    }
}

void kruskal(edge vec[MMAX], int n, int m, edge sol[MMAX]) {
    int par[NMAX], ht[NMAX];
    for (int i = 1; i <= n; ++ i) {
        par[i] = 0;
        ht[i] = 1;
    }
    quickSort(vec, 0, m - 1);
    int i = 0, dim = 0;
    while (dim < n - 1) {
        int x = root(par, vec[i].x);
        int y = root(par, vec[i].y);
        if (x != y) {
            sol[dim ++] = vec[i];
            unite(par, ht, x, y);
        }
        ++ i;
    }
}

void print(edge sol[NMAX], int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; ++ i)
        sum += sol[i].cost;
    cout << sum << "\n";
    cout << n - 1 << "\n";
    for (int i = 0; i < n - 1; ++ i)
        cout << sol[i].x << " " << sol[i].y << "\n";
}

int main() {
    int n, m;
    edge vec[NMAX], sol[NMAX];
    read(vec, n, m);
    kruskal(vec, n, m, sol);
    print(sol, n);
    return 0;
}
