void swapInts(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int part(int vec[], int lo, int hi) {
    int pivot = vec[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++ j)
        if (vec[j] < pivot)
            swapInts(vec[++ i], vec[j]);
    if (vec[hi] < vec[i + 1])
        swapInts(vec[hi], vec[i + 1]);
    return i + 1;
}

void quickSort(int vec[], int lo, int hi) {
    if (lo < hi) {
        int p = part(vec, lo, hi);
        quickSort(vec, lo, p - 1);
        quickSort(vec, p + 1, hi);
    }
}

void printSol(int S, bool used[], int par[]) {
    while (!used[S])
        -- S;
    while (S) {
        cout << S - par[S] << " ";
        S = par[S];
    }
    cout << "\n";
}

void dp(int vec[], int n, int S) {
    int par[NMAX], last;
    bool used[NMAX];
    quickSort(vec, 1, n);
    for (int i = 1; i <= S; ++ i)
        used[i] = false;
    used[vec[1]] = true;
    par[vec[1]] = 0;
    last = vec[1];
    for (int i = 2; i <= n; ++ i) {
        for (int j = last; j >= 1; -- j)
            if (used[j]) {
                used[vec[i] + j] = true;
                par[vec[i] + j] = j;
            }
        last += vec[i];
        used[vec[i]] = true;
    }
    printSol(S, used, par);
}
