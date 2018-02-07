void bkt(int k, int X[], int n, int m) {
    for (int i = X[k - 1] + 1; i <= n - m + k; ++ i) {
        X[k] = i;
        if (k == m) {
           // prelucrare solutie
        }
        else
            bkt(k + 1, X, n, m);
    }
}


/* 1. Numar solutii: Cnm = n! / (m! * (n - m)!)
      Pentru n = 4 si m = 3 => combinarile, IN ORDINE LEXICOGRAFICA, sunt : 1 2 3
                                                                            1 2 4
                                                                            1 3 4
                                                                            2 3 4
2. Ordinea elementelor NU are importanta.
3. X[0] trebuie initilizat cu 0 in main.
*/


