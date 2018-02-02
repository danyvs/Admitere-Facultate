// Interclasarea prespune unirea a 2 vectori sortati intr-unul singur, dar tot sortat.
// - complexitate: O(n + m)

void merge2SortedVectors(int A[], int n, int B[], int m, int C[], int& p) {
    int i = 1, j = 1;
    p = 0;
    while (i <= n && j <= m)
        if (A[i] < B[j])
            C[++ p] = A[i ++];
        else 
            C[++ p] = B[j ++];
    while (i <= n)
        C[++ p] = A[i ++];
    while (j <= m)
        C[++ p] = B[j ++];
}

/* Observatii:
1. Vectorii initiali trebuie sa fie sortati.
2. Vectorul obtinut este sortat.
3. Dimensiunea vectorului sortat este egala cu suma dimensiunilor celor 2 vectori intiali.
*/
