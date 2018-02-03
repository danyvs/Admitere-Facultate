void substractBigInt(bigInt A, bigInt B) {
    // scăderea a două numere mari
    // A = A - B (A ≥ B)

    // se completează numărul B cu zerourui, pentru a se evita un comportament necorespunzător
    for (int i = B[0] + 1; i <= A[0]; ++ i)
        B[i] = 0;
    B[0] = A[0];

    int t = 0; // transportul
    // se scad efectiv cele două numere
    for (int i = 1; i <= A[0]; ++ i) {
        A[i] -= (B[i] + t);
        t = (A[i] < 0 ? 1 : 0);
        if (t)
            A[i] += 10;
    }

    // se elimină zerourile nesemnificative
    while (A[0] && !A[A[0]])
        -- A[0];
}
