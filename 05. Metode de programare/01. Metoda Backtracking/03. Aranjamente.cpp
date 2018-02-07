void bkt(int k, int X[], int n, int m, bool seen[]) {
    for (int i = 1; i <= n; ++ i)
        if (!seen[i]) {
            X[k] = i;
            seen[i] = true;
            if (k == m) {
                // prelucrare solutie
            }
            else
                bkt(k + 1, X, n, m, seen);
            seen[i] = false;
        }
}


/* 1. Numar solutii: Anm = n! / (n - m)!
      Pentru n = 3 si m = 2 => aranjamentele, IN ORDINE LEXICOGRAFICA, sunt : 1 2
                                                                              1 3
                                                                              2 1
                                                                              2 3
                                                                              3 1
                                                                              3 2
2. Ordinea elementelor ARE importanta.
3. seen[i] = true, daca valoarea i este folosita in aranjament pana la pasul curent; seen[i] = false, in caz contrar 
*/


