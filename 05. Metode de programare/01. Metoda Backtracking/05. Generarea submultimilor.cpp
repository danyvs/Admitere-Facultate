void bkt(int k, int X[], int n) {
    for (int i = X[k - 1] + 1; i <= n; ++ i) {
        X[k] = i;
        // prelucrare solutie
        if (X[k] < n)
            bkt(k + 1, X, n);
    }
}


/* 
1. Numar solutii: Cn0 + Cn1 + ... Cnn = 2 ^ n
2. X[0] trebuie initilizat cu 0 in main.
*/
