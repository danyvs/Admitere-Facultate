#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int NMAX = 50005;

int n, m;
vector<int> G[NMAX];
stack<int> stck;
vector<bool> seen(NMAX, false);

void read() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
}

void dfs(int node) {
    seen[node] = true;
    for (auto it : G[node])
        if (!seen[it])
            dfs(it);
    stck.push(node);
}

void topologicalSort() {
    for (int i = 1; i <= n; ++ i)
        if (!seen[i])
            dfs(i);
    while (!stck.empty()) {
        cout << stck.top() << " ";
        stck.pop();
    }
}

int main() {
    read();
    topologicalSort();
    return 0;
}
