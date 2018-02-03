int compBigInts(bigInt A, bigInt B) {
    // compararea a două numere mari
    // A < B => -1
    // A = B => 0
    // A > B => 1
    
    // se elimină zerourile nesemnificative, dacă există
    while (A[0] && !A[A[0]])
        -- A[0];
    while (B[0] && !B[B[0]])
        -- B[0];

    // se compară după numărul de cifre
    if (A[0] < B[0])
        return -1; // A < B
    if (A[0] > B[0])
        return 1; // A > B

    // se compară cifră cu cifră, pornind de la cea mai semnificativă
    for (int i = A[0]; i; -- i) {
        if (A[i] < B[i])
            return -1; // A < B
        if (A[i] > B[i])
            return 1; // A > B
    }

    return 0; // numerele sunt egale: A = B
}
