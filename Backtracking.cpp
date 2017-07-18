/* Pentru ca o problema sa poate fi rezolvata cu ajutorul metodei backtracking, solutia trebuie sa poata fi reprezentata cu ajutorul unui
vector, fiecare element al vectorului trebuie sa ia valori intr-o multime ordonata si fininta.
Solutia problemei se contruieste pas cu pas, la fiecare pas verificandu-se daca solutia partiala este valida.
Metoda backtracking genereaza, de fapt, toate elementele prdosului carteziana unei multimi, renuntand din timp la toate combinatiile care 
nu pot fi solutii finale.
*/

// 1. Schema generala
void bkt(int k, int X[], int a, int b) {
    for (int i = a; i <= b; ++ i) {
        X[k] = i;
        if (valid(k)) {
            if (finalSolution(k))
                print(k);
            else
                bkt(k + 1, X, a, b);
        }
    }
}


// 2. Permutari
// - numar solutii = n!
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
1. Vectorul seen trebuie initializat cu false.
2. Apelul functiei in main este de forma bkt(1, X, n, seen).
*/


// 3. Aranjamente
// - numar solutii = n! / (n - m)!
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

/* Observatii:
1. Vectorul seen trebuie initializat cu false.
2. Apelul functiei in main este de forma bkt(1, X, n, m, seen).
3. Ordinea elementelor are importanta.
*/


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
3. Apelul functiei in main este de forma bkt(1, n, m).
4. Ordinea elementelor nu are importanta.
*/



