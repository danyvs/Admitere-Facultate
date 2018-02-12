  /* Algoritmul lui Roy-Floyd determina drumurile de cost minim/ maxim intre oricare 2 noduri ale grafului, transformand matricea 
costurilor ascoata acestuia. */
  
void royFloyd(int A[NMAX][NMAX], int n) {
    for (int k = 1; k <= n; ++ k)
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
                if (A[i][k] && A[k][j] && (A[i][j] > A[i][k] + A[k][j] || !A[i][j]) && i != j)
                    A[i][j] = A[i][k] + A[k][j];
}
