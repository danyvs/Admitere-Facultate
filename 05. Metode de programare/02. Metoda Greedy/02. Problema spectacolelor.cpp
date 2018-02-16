#include <iostream>

using namespace std;

struct object {
    int idx, ti, tf;
};

const int NMAX = 105;

void read(object vec[], int& n) {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        vec[i].ti = h1 * 60 + m1;
        vec[i].tf = h2 * 60 + m2;
        vec[i].idx = i;
    }
}

void swapObjects(object& A, object& B) {
    object temp = A;
    A = B;
    B = temp;
}

int part(object vec[], int lo, int hi) {
    int pivot = vec[hi].tf;
    int i = lo - 1;
    for (int j = lo; j < hi; ++ j)
        if (vec[j].tf > pivot)
            swapObjects(vec[++ i], vec[j]);
    if (vec[hi].tf > vec[i + 1].tf)
        swapObjects(vec[hi], vec[i + 1]);
    return i + 1;
}

void quickSort(object vec[], int lo, int hi) {
    if (lo < hi) {
        int p = part(vec, lo, hi);
        quickSort(vec, lo, p - 1);
        quickSort(vec, p + 1, hi);
    }
}

void greedy(object vec[], int n) {
    int i, last = 1, ans = 1;
    cout << vec[1].idx << "\n";
    for (int i = 2; i <= n; ++ i)
        if (vec[i].ti >= vec[last].tf) {
            cout << vec[i].idx << "\n";
            last = i;
            ++ ans;
        }
    cout << ans << "\n";
}

int main() {
    int n;
    object vec[NMAX];
    read(vec, n);
    greedy(vec, n);
    return 0;
}
