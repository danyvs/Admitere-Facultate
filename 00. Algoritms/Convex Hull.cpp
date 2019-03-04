int n;
pair < double, double > points[NMAX];
int head;
pair < double, double > st[NMAX];

inline double crossProduct(const pair < double, double >& A, const pair < double, double >& B, const pair < double, double >& C) {
    return (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
}

inline bool cmp(const pair < double, double >& A, const pair < double, double >& B) {
    return crossProduct(points[0], A, B) < 0;
}

void sortPoints() {
    int pos = 0;
    for (int i = 1; i < n; ++ i)
        if (points[i] < points[pos])
            pos = i;
    swap(points[0], points[pos]);
    sort(points + 1, points + n, cmp);
}

void convexHull() {
    sortPoints();
    st[head ++] = points[0];
    st[head ++] = points[1];
    for (int i = 2; i < n; ++ i) {
        while (head >= 2 && crossProduct(st[head - 2], st[head - 1], points[i]) > 0)
            -- head;
        st[head ++] = points[i];
    }
}
