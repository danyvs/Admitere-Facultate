  Pentru a se construi matricea drumurilor, se pleaca de la matricea de adiacenta sise aplica algoritmul lui Roy-Warshall.
  A[i][j] = 1, daca exista drum de la i la j
            0, daca nu exista drum de la i la j
            
  Implementare:
  for (int k = 1; k <= n; ++ k)
    for (int i = 1; i <= n; ++ i)
      for (int j = 1; j <= n; ++ j)
        if (!A[i][j] && A[i][k] && A[k][j])
          A[i][j] = 1;
