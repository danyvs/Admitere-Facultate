#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int NMAX = 200005;

struct edge {
    int src, dest, cost;
};

int n, m;
vector<edge> vec;
int sum;
vector<edge> sol;
vector<int> par(NMAX, 0);
vector<int> ht(NMAX, 1);

void read() {
    fin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        edge temp;
        fin >> temp.src >> temp.dest >> temp.cost;
        vec.push_back(temp);
    }
}

struct compByCost {
    bool operator()(const edge& A, const edge& B) {
        return A.cost < B.cost;
    }
};

int root(int x) {
    while (par[x])
        x = par[x];
    return x;
}

void unite(int x, int y) {
    if (ht[x] > ht[y])
        par[y] = x;
    else {
        par[x] = y;
        if (ht[x] == ht[y])
            ++ ht[y];
    }
}

void kruskal() {
    sort(vec.begin(), vec.end(), compByCost());
    vector<edge>::iterator it = vec.begin();
    while ((int)sol.size() < n - 1) {
        int x = root(it->src);
        int y = root(it->dest);
        if (x != y) {
            sum += it->cost;
            unite(x, y);
            sol.push_back(*it);
        }
        ++ it;
    }
}

void print() {
    fout << sum << "\n";
    fout << sol.size() << "\n";
    for (auto it : sol)
        fout << it.src << " " << it.dest << "\n";
}

int main() {
    read();
    fin.close();
    kruskal();
    print();
    fout.close();
    return 0;
}
