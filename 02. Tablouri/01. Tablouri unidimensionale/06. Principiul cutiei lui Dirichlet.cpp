void dirichlet(int vec[], int n, int& lo, int& hi) {
    int sum[NMAX] = {0}, rest[NMAX] = {0};
    for (int i = 1; i <= n; ++ i) {
        sum[i] = sum[i - 1] + vec[i];
        if (sum[i] % n == 0) {
            lo = 1;
            hi = n;
            return;
        }
        else {
            if (rest[sum[i] % n]) {
                lo = rest[sum[i] % n] + 1;
                hi = i;
                return;
            }
            else 
                rest[sum[i] % n] = i;
        }
    } 
}


// Principiul cutiei lui Dirichlet determina o submultime a unei multime care este divizbila cu numarul de elemente
// Exista intotdeauna o solutie formata din elementele de pe pozitiile lo, lo + 1 ... hi - 1, hi.
