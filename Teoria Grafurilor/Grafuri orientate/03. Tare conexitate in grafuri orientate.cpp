	/*Graful orientat G = (V, E) este TARE CONEX, daca ∀ x, y ∈ V, exista drum de la x la y si de la y la x.
		
	3 3
	1 2
	2 3
	3 1
	Graf orientat tare conex
	
	6 7
	1 2
	2 1
	2 3
	3 4
	4 5
	5 6
	6 4
	Graful nu este tare conex, dar contine 3 componente tare conexe; {1, 2}, {3}, {4, 5, 6}.
*/
	

// Algoritmul lui Kosaraju-Sharir
	
#include <iostream>

using namespace std;

const int NMAX = 15;

struct node {
    int info;
    node* next;
};

void add(node* &first, int val) {
    node* p = new node;
    p -> info = val;
    p -> next = first;
    first = p;
}

void read(int& n, int& m, node* G[NMAX], node* Gt[NMAX]) {
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        int x, y;
        cin >> x >> y;
        add(G[x], y);
        add(Gt[y], x);
    }
}

void dfs1(int currNode, node* G[NMAX], bool seen[NMAX], int stck[NMAX], int& dim) {
    seen[currNode] = true;
    for (node* p = G[currNode]; p != NULL; p = p -> next)
        if (!seen[p -> info])
            dfs1(p -> info, G, seen, stck, dim);
    stck[++ dim] = currNode;
}

void dfs2(int currNode, node* Gt[NMAX], bool seen[NMAX], int idx) {
    seen[currNode] = true;
    // prelucrare nodul currNode din componenta idx
    cout << currNode << " ";
    for (node* p = Gt[currNode]; p != NULL; p = p -> next)
        if (!seen[p -> info])
            dfs2(p -> info, Gt, seen, idx);
}

void solve(int n, node* G[NMAX], node* Gt[NMAX]) {
    bool seen[NMAX];
    int stck[NMAX], dim = 0;
    for (int i = 1; i <= n; ++ i)
        seen[i] = false;
    for (int i = 1; i <= n; ++ i)
        if (!seen[i])
            dfs1(i, G, seen, stck, dim);

    int idx = 0;
    for (int i = 1; i <= n; ++ i)
        seen[i] = false;
    while (dim) {
        if (!seen[stck[dim]]) {
            ++ idx;
            cout << idx << " ";
            dfs2(stck[dim], Gt, seen, idx);
            cout << "\n";
        }
        -- dim;
    }
}

int main() {
    int n, m;
    node* G[NMAX] = {};
    node* Gt[NMAX] = {};
	read(n, m, G, Gt);
	solve(n, G, Gt);
	return 0;
}
