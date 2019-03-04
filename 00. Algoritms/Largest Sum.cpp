void largestSum() {
    int sum_max = -0x3f3f3f3f, l, r;
    int sum = 0, idx = 0;
    for (int i = 0; i < n; ++ i) {
        if (sum >= 0)
            sum += vec[i];
        else {
            sum = vec[i];
            idx = i;
        }
        if (sum > sum_max) {
            sum_max = sum;
            l = idx;
            r = i;
        }
    }
}
