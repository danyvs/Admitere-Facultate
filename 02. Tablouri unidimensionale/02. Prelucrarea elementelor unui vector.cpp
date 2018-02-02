// 1. Prelucrarea tuturor elementelor unui vector
  for (int i = 1; i <= n; ++ i)
      // prelucrare a[i]
      
// 2.Prelucrarea perechilor de elemente aflat pe pozitii consecutive
  for (int i = 1; i < n; ++ i)
      // prelucrare (a[i], a[i + 1])
      
// 3. Prelucrarea elementelor egale departate de mijloc
  for (int i = 1; i <= n / 2; ++ i)
      // prelucrare (a[i], a[n - i + 1])
      
// 4. Prelucrarea tuturor perechilor de elemente
  for (int i = 1; i < n; ++ i)
      for (int j = i + 1; j <= n; ++ j)
          // prelucrare (a[i], a[j])  
