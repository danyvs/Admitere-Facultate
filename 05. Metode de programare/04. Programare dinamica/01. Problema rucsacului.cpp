struct object {
    int g; // greutate
    int c; // castig
};

void read(object vec[NMAX], int& n, int& G) {
    cin >> n >> G;
    for (int i = 1; i <= n; ++ i)
        cin >> vec[i].g >> vec[i].c;
}

void swapObject(object& a, object& b) {
    object temp = a;
    a = b;
    b = temp;
}

int part(object vec[], int lo, int hi) {
    int pivot = vec[hi].c;
    int i = lo - 1;
    for (int j = lo; j < hi; ++ j)
        if (vec[j].c < pivot)
            swapObject(vec[++ i], vec[j]);
    if (vec[hi].c < vec[i + 1].c)
        swapObject(vec[hi], vec[i + 1]);
    return i + 1;
}

void quickSort(object vec[], int lo, int hi) {
    if (lo < hi) {
        int p = part(vec, lo, hi);
        quickSort(vec, lo, p - 1);
        quickSort(vec, p + 1, hi);
    }
}

inline int max(const int& a, const int& b) {
    return a > b ? a : b;
}

void knapsack(object vec[], int n, int G) {
    int C[NMAX][NMAX];
    for (int j = 1; j <= G; ++ j)
        C[0][j] = 0;
    for (int i = 1; i <= n; ++ i)
        C[i][0] = 0;
    quickSort(vec, 1, n);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= G; ++ j)
            if (vec[i].g > j)
                C[i][j] = C[i - 1][j];
            else
                C[i][j] = max(C[i - 1][j], vec[i].c + C[i - 1][j - vec[i].g]);
    cout << C[n][G] << "\n";
}

// C[x][y] = castigul maxim obtinut prin umplerea rucsacului de greutate y folosing obiecte din multimea 1 ... x
