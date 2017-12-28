void bkt(int k, int X[], int n, bool seen[]) {
    for (int i = 1; i <= n; ++ i)
        if (!seen[i]) {
            X[k] = i;
            seen[i] = true;
            if (k == n) {
                // prelucrare solutie
            }
            else
                bkt(k + 1, X, n, seen);
            seen[i] = false;
        }
}

/* Observatii:
1. Pn = n!
  Pentru n = 3 => permutarile, IN ORDINE LEXICOGRAFICA, sunt : 1 2 3
                                                               1 3 2
                                                               2 1 3
                                                               2 3 1
                                                               3 1 2
                                                               3 2 1
2. Vectorul seen trebuie initializat cu false.
3. seen[i] = true, daca valoarea i este folosita in permutare pana la pasul curent; seen[i] = false, in caz contrar
4. Apelul functiei in main este de forma bkt(1, X, n, seen).
*/
