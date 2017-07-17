// Sortarea elementelor unui vector presupune ordonarea acestora dupa o anumita regula.

// 1. Sortarea naiva
// - complexitate: O(n ^ 2)
void naiveSort(int vec[], int n) {
    for (int i = 1; i < n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            if (vec[i] > vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
        }
}

// 2. Bubble Sort
// complexitate: O(n ^ 2)
void bubbleSort(int vec[], int n) {
    bool ord = false;
    while (!ord) {
        ord = true;
        for (int i = 1; i < n; ++ i)
            if (vec[i] > vec[i + 1]) {
                int temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
                ord = false;
            }
    }
}
