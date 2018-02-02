// O multime se poate reprezenta cu ajutorul unui tablou unidimensional.

// 1. Reuniunea a 2 multimi
void reunion(int A[], int n, int B[], int m, int C[], int& p) {
    // C = A ∪ B
    for (int i = 1; i <= n; ++ i)
        C[i] = A[i];
    p = n;
    for (int i = 1; i <= m; ++ i) {
        bool found = false;
        for (int j = 1; j <= n && !found; ++ j)
            if (B[i] == A[j])
                found = true;
        if (!found)
            C[++ p] = B[i];
    }
}

// 2. Intersectia a 2 multimi
void intersection(int A[], int n, int B[], int m, int C[], int& p) {
    // C = A n B
    p = 0;
    for (int i = 1; i <= n; ++ i) {
        bool found = false;
        for (int j = 1; j <= m && !found; ++ j)
            if (B[j] == A[i])
                found = true;
        if (found)
            C[++ p] = A[i];
    }
}

// 3. Diferenta a 2 multimi
void disjunction(int A[], int n, int B[], int m, int C[], int& p) {
    // C = A \ B
    p = 0;
    for (int i = 1; i <= n; ++ i) {
        bool found = false;
        for (int j = 1; j <= m && !found; ++ j)
            if (B[j] == A[i])
                found = true;
        if (!found)
            C[++ p] = A[i];
    }
}

/* Observatii:
1. Pentru reuniune, dimensiunea vectorului C, la declarare, trebuie sa fie egala cu dimensiunea vectorului A + dimensiunea vectorului B.
2. Pentru intersectie, dimensiunea vectorului C, la declarare, trebuie sa fie egala cu maximul dimensiunilor vectorilor A si B.
3. Pentru diferenta, dimensiunea vectorului C, la declarare, trebuie sa fie egala cu dimensiunea vectorului din care se face diferenta.
*/
