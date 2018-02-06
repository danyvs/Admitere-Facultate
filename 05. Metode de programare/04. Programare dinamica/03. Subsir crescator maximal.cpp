void lis(int vec[], int n, int lg[], int par[]) {
    for (int i = 1; i <= n; ++ i) {
        lg[i] = 1;
        par[i] = 0;
        for (int j = 1; j < i; ++ j)
            if (vec[i] > vec[j] && lg[j] + 1 > lg[i]) {
                lg[i] = lg[j] + 1;
                par[i] = j;
            }
    }
}

void buildSol(int vec[], int par[], int x) {
    if (par[x])
        buildSol(vec, par, par[x]);
    cout << vec[x] << " ";
}

void print(int vec[], int n, int lg[], int par[]) {
    int lgmax = 0, idx;
    for (int i = 1; i <= n; ++ i)
        if (lg[i] > lgmax) {
            lgmax = lg[i];
            idx = i;
        }
    cout << lgmax << "\n";
    buildSol(vec, par, idx);
}

// complexitate: O (n ^ 2)
