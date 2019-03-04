#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

const int NMAX = 50005;
const int INF = 0x3f3f3f3f;

int n, m;
vector<pair<int, int>> G[NMAX];
vector<int> dist(NMAX, INF);

void read() {
    fin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        int from, to, cost;
        fin >> from >> to >> cost;
        G[from].push_back(make_pair(to, cost));
    }
}

void dijkstra() {
    set<pair<int, int>> heap;
    dist[1] = 0;
    heap.insert(make_pair(0, 1));
    while (!heap.empty()) {
        int from = heap.begin()->second;
        int d = heap.begin()->first;
        heap.erase(heap.begin());
        for (auto it : G[from]) {
            int to = it.first;
            int cost = it.second;
            if (dist[to] > dist[from] + cost) {
                if (dist[to] != INF)
                    heap.erase(heap.find(make_pair(dist[to], to)));
                dist[to] = dist[from] + cost;
                heap.insert(make_pair(dist[to], to));
            }
        }
    }
}

void print() {
    for (int i = 2; i <= n; ++ i)
        fout << (dist[i] != INF ? dist[i] : 0) << " ";
    fout << "\n";
}

int main() {
    read();
    fin.close();
    dijkstra();
    print();
    fout.close();
    return 0;
}
