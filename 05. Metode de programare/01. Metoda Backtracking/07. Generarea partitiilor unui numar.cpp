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
1. X[0] trebuie initializat cu 1.
2. Variabila sum trebuie initializata in main cu 0.
3. Variabila sum memoreaza suma numerelor pana la pasul curent.
*/
