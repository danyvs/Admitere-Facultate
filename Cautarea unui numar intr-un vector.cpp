// Cautarea unui numar intr-un vector se poate face in mai multe moduri
// Observatie: Vectorii sunt indexati de la 1

// 1. Cautare secventiala 
// - se poate aplica pe orice tip de vector
// - complexitate: O(n)
bool naiveSearch(int target, int vec[], int n) {
    for (int i = 1; i <= n; ++ i)
        if (vec[i] == target)
            return true;
    return false;
}

// 2. Cautare binara
// - se poate aplica doar pe un vector sortat
// - complexitate: O(log2n)
bool binarySearch(int target, int vec[], int n) {
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

/* Observatii:
1. Ambele cautari pot fi modificate astfel incat sa nu caute in tot vectorul, ci doar intre anumiti indici.
2. Ambele cautari pot fi modificate astfel incat sa returneze pozitia unde apare vectorul cautat.
3. Cautarea binara poate fi modificata astfel incat sa returneze pozitia sau cel mai mare element mai mic decat target.
4. Cautarea binara poate fi modificata astfel incat sa returneze pozitia sau cel mai mic element mai mare decat target.
*/
