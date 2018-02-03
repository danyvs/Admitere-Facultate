void multiplyBigIntByInt(bigInt A, int x) {
    // înmulţirea unui număr mare cu un număr mic (scalar)
    // A = A * x

    int t = 0; // transportul
    // se înmulţesc efectiv cele două numere
    for (int i = 1; i <= A[0]; ++ i) {
        A[i] = A[i] * x + t;
        t = A[i] / 10;
        A[i] %= 10;
    }

    // se adaugă transportul, care poate avea mai mult de o cifră (dacă există)
    while (t) {
        A[++ A[0]] = t % 10;
        t /= 10;
    }
}
