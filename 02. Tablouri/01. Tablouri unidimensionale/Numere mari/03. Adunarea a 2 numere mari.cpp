void addBigInt(bigInt A, bigInt B) {
    // adunarea a două numere mari
    // A = A + B

    // se completează cu zerouri numărul mai mai mic, pentru a se evita un comportament necorespunzător
    if (A[0] < B[0]) {
        for (int i = A[0] + 1; i <= B[0]; ++ i)
            A[i] = 0;
        A[0] = B[0];
    }
    else {
        for (int i = B[0] + 1; i <= A[0]; ++ i)
            B[i] = 0;
        B[0] = A[0];
    }

    int t = 0; // transportul
    // se adună efectiv cele două numere
    for (int i = 1; i <= A[0]; ++ i) {
        A[i] += B[i] + t;
        t = A[i] / 10;
        A[i] %= 10;
    }

    // se adaugă transportul rămas (dacă există)
    if (t)
        A[++ A[0]] = t;
}
