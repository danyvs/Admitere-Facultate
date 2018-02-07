// Partitiile unui numar ca suma de numere naturale nenule

void bkt(int k, int n, int X[], int sum) {
    for (int i = X[k - 1]; i <= n - sum; ++ i) {
        X[k] = i;
        sum += X[k];
        if (sum == n) {
            // prelucrare solutie
        }
        else {
            if (sum < n)
                bkt(k + 1, n, X, sum);
        }
        sum -= X[k];
    }
}


/* 
1. Pentru n = 4, partiriile lui n, IN ORDINE LEXICOGRAFICA, sunt: 1 + 1 + 1 + 1
                                                                  1 + 1 + 2
                                                                  1 + 3
                                                                  2 + 2
                                                                  4
2. X[0] trebuie initializat cu 1.
3. Variabila sum trebuie initializata in main cu 0.
4. Variabila sum memoreaza suma numerelor pana la pasul curent.
*/
