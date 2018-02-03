int majorityElement(int vec[], int n) {
    int majElem = vec[1], cnt = 1;
    for (int i = 2; i <= n; ++ i)
        if (vec[i] == majElem)
            ++ cnt;
        else {
            if (!cnt) {
                majElem = vec[i];
                cnt = 1;
            }
            else
                -- cnt;
        }
    cnt = 0;
    for (int i = 1; i <= n; ++ i)
        if (vec[i] == majElem)
            ++ cnt;
    return (cnt > n / 2 ? majElem : -1);
} 

// Un element este majoritar intr-un vector daca apare de mai mult de n / 2 ori.
// Complexitatea algoritmului: O(n)
