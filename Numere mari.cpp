/* Numerele mari sunt numere care nu se pot reprezenta pe tipurile de date simple standard. Ele se vor memora cu ajutorul tablourilor 
unidimensionale. Pe pozitia 0 se va memora numarul de cifre, iar pe urmatoarele pozitii - cifrele in ordine inversa. */

// 1. Initializarea unui numar mare cu un scalar
void atribValue(int vec[], int x) {
    vec[0] = 0;
    while (x) {
        vec[++ vec[0]] = x % 10;
        x /= 10;
    }
}

// 2. Initializarea unui numar mare cu un alt numar mare
void atribHuge(int dest[], int src[]) {
    // dest este initializat cu src
    for (int i = 0; i <= src[0]; ++ i)
        dest[i] = src[i];
}

// 3. Compararea a 2 numere mari
// - -1, daca vec1 < vec2
// - 0, daca vec1 = vec2
// - 1, daca vec1 > vec2
int comp(int vec1[], int vec2[]) {
    // se elimina zerourile nesemnificative
    while (vec1[0] && !vec1[vec1[0]])
        -- vec1[0];
    while (vec2[0] && !vec2[vec2[0]])
        -- vec2[0];
    if (vec1[0] < vec2[0])
        return -1;
    if (vec1[0] > vec2[0])
        return 1;
    for (int i = vec1[0]; i; -- i) {
        if (vec1[i] < vec2[i])
            return -1;
        if (vec1[i] > vec2[i])
            return 1;
    }
    return 0;
}

// 4. Adunarea unui numar mare cu un scalar

// 5. Adunarea a 2 numere mari

// 6. Scaderea unui scalar dintr-un numar mare

// 7. Scaderea a 2 numere mari

// 8. Inmultirea unui numar mare cu un scalar

// 9. Inmultirea a 2 numere mari

// 10. Impartirea unui numar mare la un scalar

// 11. Impartirea a 2 numere mari
