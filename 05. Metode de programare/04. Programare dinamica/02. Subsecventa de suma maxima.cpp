void maxSum(int vec[], int n, int& smax, int& lo, int& hi) {
    smax = 0;
    int s = vec[1], idx = 1;
    for (int i = 2; i <= n; ++ i) {
        if (s > 0)
            s += vec[i];
        else {
            s = vec[i];
            idx = i;
        }
        if (s > smax) {
            smax = s;
            lo = idx;
            hi = i;
        }
    }
}

// - complexitate: O(n)
// Functia returneaza prin intermediul parametrului smax suma maxima.
// Functia returneaza prin intermediul parametrilor lo si hi pozitia de inceput si de sfarsit a subsecventei de suma maxima.
