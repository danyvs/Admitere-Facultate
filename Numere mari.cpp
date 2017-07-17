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

