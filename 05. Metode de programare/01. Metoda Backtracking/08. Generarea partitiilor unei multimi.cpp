void bkt(int k, int n, int X[], int mx[]) {
    for (int i = 1; i <= mx[k - 1] + 1; ++ i) {
        X[k] = i;
        if (i < mx[k - 1])
            mx[k] = mx[k - 1];
        else 
            mx[k] = mx[k - 1] + 1;
        if (k == n) {
            // prelucrare solutie
        }
        else 
            bkt(k + 1, n, X, mx);
    }
}


/*
1. Numar solutii = 2 ^ n - 1
2. mx[k - 1] = cea mai mare volarea dintre x1, x2, ... xk-1
3. X[1] trebuie initializat cu 1.
4. mx[1] trebuie initializat cu 1.
*/
