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

// 1. Ciurul lui Eratostene se foloseste pentru a verifica daca un numar dintr-un interval este prim sau nu in timp constant
// 2. prime[i] = true, daca i este prim si prime[i] = false, daca i este compus.
