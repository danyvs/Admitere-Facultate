// Ciurul lui Eratostene se foloseste pentru a verifica daca un numar este prim sau nu

void sieveOfEratosthenes(bool prime[]) {
    for (int i = 0; i < VMAX; ++ i)
        prime[i] = false;
    prime[2] = true;
    for (int i = 3; i < VMAX; i += 2)
        prime[i] = true;
    for (int i = 3; i * i < VMAX; i += 2)
        if (prime[i])
            for (int j = i * i; j < VMAX; j += i)
                prime[j] = false;
}

*/ Observatii:
1. prime[i] = true, daca i este prim.
2. prime[i] = false, daca i este compus.
3. Ciurul lui Eratostene raspunde in O(1) la intrebarea daca un numar este prim sau nu.
4. Ciurul lui Eratostene se foloseste, in general, atunci cand se doreste sa se afle daca mai multe numere sunt prime sau nu.
*/
