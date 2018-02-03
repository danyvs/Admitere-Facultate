int divideBigIntByInt(bigInt A, int x) {
    // împărţirea unui număr mare la un număr mic (scalar)
    // A = A / x
    // funcţia returnează A % x

    int r = 0; // restul
    // se împarte efectiv A la x
    for (int i = A[0]; i; -- i) {
        r = r * 10 + A[i];
        A[i] = r / x;
        r %= x;
    }

    // se elimină zerourile nesemnificative
    while (A[0] > 1 && !A[A[0]])
        -- A[0];

    // se returnează restul
    return r;
}
