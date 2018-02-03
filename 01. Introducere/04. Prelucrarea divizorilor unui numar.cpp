// complexitate: O(n)
	for (int i = 1; i <= n; ++ i)
  		if (n % i == 0)
      		// prelucrare divizor i

                
// complexitate: O(sqrt{n})
	int i = 1;
	for (i = 1; i * i < n; ++ i)
  		if (n % i == 0)
        	// prelucrare divizor i si divizor n / i
	if (i * i == n) {
    	// n este patrat perfect, deci i si n / i au aceeasi valoare
    	// prelucrare divizor i
	}
