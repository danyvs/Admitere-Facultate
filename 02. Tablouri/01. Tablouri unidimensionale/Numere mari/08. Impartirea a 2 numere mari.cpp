void divideBigIntByBigInt(bigInt A, bigInt B, bigInt C, bigInt R) {
    // împărţirea unui număr mare la un alt număr mare
    // A / B = C, rest R

    // iniţializări
    R[0] = 1; R[1] = 0;
    C[0] = A[0];

    // se împart efectiv cele două numere mari
    for (int i = A[0]; i; -- i) {
        multiplyBigIntByInt(R, 10);
        R[1] = A[i];
        C[i] = 0;
        while (compBigInts(B, R) != 1) {
            ++ C[i];
            substractBigInt(R, B);
        }
    }

    // se elimină zerourile nesemnificative
    while (C[0] > 1 && !C[C[0]])
        -- C[0];
}
