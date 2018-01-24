void createCostMatrix(int A[NMAX][NMAX], int n, int m) {
    cin >> n >> m;
    // initializare matrice costuri
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            A[i][j] = ±INF;
    // construire matrice costuri
    for (int i = 1; i <= m; ++ i) {
        int x, y, cost;
        cin >> x >> y >> cost;
        A[x][y] = cost;
        A[y][x] = cost; // pentru grafuri neorientate
    }
}
