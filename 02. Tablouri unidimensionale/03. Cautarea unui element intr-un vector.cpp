// 1. Cautare secventiala
// complexitate: O(n)
  bool found = false;
  for (int i = 1; i <= n && !found; ++ i)
      if (a[i] == elem)
          found = true;
