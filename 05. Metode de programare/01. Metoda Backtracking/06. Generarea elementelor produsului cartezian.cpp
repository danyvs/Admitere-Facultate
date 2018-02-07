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


/* 
1. Numar solutii = card(A1) * card(A2) * ... * card(An)
2. Vectorul A memoreaza cardinalul celor n multimi.
*/

