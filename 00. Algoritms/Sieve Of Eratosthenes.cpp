void sieveOfEratosthenes() {
    bool prime[NMAX];
    memset(prime, false, sizeof(prime));
    prime[2] = true;
    for (int i = 3; i <= NMAX; i += 2)
        prime[i] = true;
    for (int i = 3; i * i <= NMAX; i += 2)
        if (prime[i])
            for (int j = i * i; j <= NMAX; j += i)
                prime[j] = false;
}
