int binarySearch(int lo, int hi, int target) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (vec[mid] == target)
            return mid;
        else
            if (vec[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
    }
    return -1; // target not found
}
