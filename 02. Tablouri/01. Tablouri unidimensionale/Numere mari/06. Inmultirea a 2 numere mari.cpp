void multiplyBigIntByBigInt(bigInt A, bigInt B, bigInt C) {
    // înmulţirea unui număr mare cu un alt număr mare
    // C = A * B

    C[0] = A[0] + B[0] - 1; // se iniţializează numărul de cifre
    // se completează produsul iniţial cu 0
    for (int i = 1; i <= A[0] + B[0]; ++ i)
        C[i] = 0;

    // se efectuează produsele intermediare şi se adună cele de pe aceeşi poziţie
    for (int i = 1; i <= A[0]; ++ i)
        for (int j = 1; j <= B[0]; ++ j)
            C[i + j - 1] += A[i] * B[j];

    int t = 0; // transportul
    // se corectezã rezultatul
    for (int i = 1; i <= C[0]; ++ i) {
        C[i] += t;
        t = C[i] / 10;
        C[i] %= 10;
    }

    // se adaugã transportul rãmas (dacă există)
    if (t)
        C[++ C[0]] = t;
}
