// 1. Cautare secventiala 
// - se poate aplica pe orice tip de vector
// - complexitate: O(n)
bool naiveSearch(int vec[], int n, int target) {
    for (int i = 1; i <= n; ++ i)
        if (vec[i] == target)
            return true;
    return false;
}


// 2. Cautare binara
// - se poate aplica doar pe un vector sortat
// - complexitate: O(log2n)
bool binarySearch(int vec[], int n, int target) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (vec[mid] == target)
            return true;
        else {
            if (vec[mid] > target)
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
    }
    return false;
}

// Vectorii sunt indexati de la 1
