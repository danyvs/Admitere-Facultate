#include <iostream>

using namespace std;

struct object {
    int idx, g, cost;
    double value;
};

const int NMAX = 105;

void read(object vec[], int& n, int& G) {
    cin >> n >> G;
    for (int i = 1; i <= n; ++ i) {
        cin >> vec[i].g >> vec[i].cost;
        vec[i].idx = i;
        vec[i].value = (double)vec[i].cost / vec[i].g;
    }
}

void swapObjects(object& A, object& B) {
    object temp = A;
    A = B;
    B = temp;
}

int part(object vec[], int lo, int hi) {
    double pivot = vec[hi].value;
    int i = lo - 1;
    for (int j = lo; j < hi; ++ j)
        if (vec[j].value > pivot)
            swapObjects(vec[++ i], vec[j]);
    if (vec[hi].value > vec[i + 1].value)
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

void greedy(object vec[], int n, int G) {
    int i = 1;
    double S = 0;
    quickSort(vec, 1, n);
    while (G) {
        if (vec[i].g <= G) {
            // se poate pune tot obiectul
            S += vec[i].cost;
            G -= vec[i].g;
            cout << vec[i].idx << " 100%\n";
        }
        else {
            // obiectul trebuie taiat
            S += G * vec[i].value;
            cout << vec[i].idx << " " << G * 100 / vec[i].g << " %\n";
            G = 0;
        }
        ++ i;
    }
    cout << S << "\n";
}

int main() {
    int n, G;
    object vec[NMAX];
    read(vec, n, G);
    greedy(vec, n, G);
    return 0;
}
