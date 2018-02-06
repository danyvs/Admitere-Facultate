void swapInt(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int part(int vec[], int lo, int hi) {
    int pivot = vec[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++ j)
        if (vec[j] < pivot)
            swapInt(vec[++ i], vec[j]);
    if (vec[hi] < vec[i + 1])
        swapInt(vec[hi], vec[i + 1]);
    return i + 1;
}

void quickSort(int vec[], int lo, int hi) {
    if (lo < hi) {
        int p = part(vec, lo, hi);
        quickSort(vec, lo, p - 1);
        quickSort(vec, p + 1, hi);
    }
}
