void mergeVec(int vec[], int lo, int mid, int hi) {
    int temp[NMAX], dim = 0;
    int i = lo, j = mid + 1;
    while (i <= mid && j <= hi)
        if (vec[i] < vec[j])
            temp[++ dim] = vec[i ++];
        else
            temp[++ dim] = vec[j ++];
    while (i <= mid)
        temp[++ dim] = vec[i ++];
    while (j <= hi)
        temp[++ dim] = vec[j ++];
    for (int it = 1; it <= dim; ++ it)
        vec[lo ++] = temp[it];

}

void mergeSort(int vec[], int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        mergeSort(vec, lo, mid);
        mergeSort(vec, mid + 1, hi);
        mergeVec(vec, lo, mid, hi);
    }
}
