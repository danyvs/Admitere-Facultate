// 4. Combinari
// - numar solutii = n! / (m! * (n - m)!)
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
/* Observatii: 
1. Vectorul seen nu mai este necesar.
2. X[0] trebuie initilizat cu 0 in main.
3. Apelul functiei in main este de forma bkt(1, X, n, m).
4. Ordinea elementelor nu are importanta.
*/


// 5. Submultimi
// - numar solutii = 2 ^ n
void bkt(int k, int X[], int n) {
    for (int i = X[k - 1] + 1; i <= n; ++ i) {
        X[k] = i;
        // prelucrare solutie
        bkt(k + 1, X, n);
    }
}
/* Observatii: 
1. Vectorul seen nu mai este necesar.
2. X[0] trebuie initilizat cu 0 in main.
3. Apelul functiei in main este de forma bkt(1, X, n).
4. Nu mai este necesara o conditie suplimentara in for, deoarece elementele sunt strict crescatoare din generare.
*/

// 6. Produs cartezian
// - numar solutii = card(A1) * card(A2) * ... * card(An)
void bkt(int k, int X[], int A[], int n) {
    for (int i = 1; i <= A[k]; ++ i) {
        X[k] = i;
        if (k == n) {
            // prelucrare solutie
        }
        else
            bkt(k + 1, X, A, n);
    }
}
/* Observatii: 
1. Vectorul seen nu mai este necesar.
2. Vectorul A memoreaza cardinalul celor n multimi.
3. Apelul functiei in main este de forma bkt(1, X, A, n).
*/

// 7. Partitiile unui numar
// - ca suma de numere naturale nenule
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
/* Observatii: 
1. Vectorul seen nu mai este necesar.
2. X[0] trebuie initializat cu 1.
3. Variabila sum trebuie initializata in main cu 0.
4. Variabila sum memoreaza suma numerelor pana la pasul curent.
5. Apelul functiei in main este de forma bkt(1, n, X, sum).
*/


// 8. Partitiile unei multimi
// - numar solutii = 2 ^ n - 1
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
        bkt(k + 1, n, X, mx);
    }
}
/* Observatii: 
1. Vectorul seen nu mai este necesar.
2. mx[k - 1] = cea mai mare volarea dintre x1, x2, ... xk-1
3. X[1] trebuie initializat cu 1.
4. mx[1] trebuie initializat cu 1.
5. Apelul functiei in main este de forma bky(2, n, X, mx)
*/


// 9. Backtracking in plan - asemanator cu Fill


