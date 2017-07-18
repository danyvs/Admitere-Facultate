// Permutarea circulara a elementelor unui vector inseamna generarea tuturor permutarilor cu o pozitie spre stanga sau spre drepta

// 1. Permutare circulara spre dreapta
// - nu se aloca memorie suplimentara
// - complexitate: O(n ^ 2)
void circularPerm(int vec[], int n) {
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j)
            // prelucrare permutare
        int temp = vec[n];
        for (int j = n; j > 1; -- j)
            vec[j] = vec[j - 1];
        vec[1] = temp;
    }
}

// 2. Permutare circulara spre stanga
// - se aloca memorie suplimentara (se dubleaza vectorul initial)
// - complexitate: O(n ^ 2)
void circularPerm(int vec[], int n) {
    // dublarea vectorului
    for (int i = 1; i <= n; ++ i)
        vec[i + n] = vec[i];
    for (int i = 1; i <= n; ++ i) {
        for (int j = i; j <= n + i - 1; ++ j)
            // prelucrare permutare
    }
}

/* Observatii: 
1. Varianta 1 se poate face si pentru permutare spre stanga: se memoreaza primul element si se modifica pozitia celorlalte;
2. Varianta 2 se poate face si pentru permutare spre dreapta: vectorul este dublat invers.
*/
