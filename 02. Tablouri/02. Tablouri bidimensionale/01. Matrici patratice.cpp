// O matrice patratica este o matrice care arer numarul de linii egal cu numarul de coloane.

// 1. Elementele de pe diagonala principala
  for (int i = 1; i <= n; ++ i)
      // prelucrare A[i][i]
      
// 2. Elementele de pe diagonala secundara
  for (int i = 1; i <= n; ++ i)
      // prelucrare A[i][n - i + 1]
    
// 3. Elementele aflate sub diagonala principala
  for (int i = 2; i <= n; ++ i)
      for (int j = 1; j <= i; ++ j)
          // prelucrare A[i][j]
          
// 4. Elemente aflate deasupra diagonalei principale
  for (int i = 1; i < n; ++ i)
      for (int j = i + 1; j <= n; ++ j)
          // prelucrare A[i][j]
          
// 5. Elementele aflate sub diagonala secundara
  for (int i = 2; i <= n; ++ i)
      for (int j = n + 2 - i; j <= n; ++ j)
          // prelucrare A[i][j]
          
// 6. Elementele aflate deasupra diagonalei secundare
  for (int i = 1; i < n; ++ i)
      for(int j = 1; j <= n - i; ++ j)
          // prelucrare A[i][j]
