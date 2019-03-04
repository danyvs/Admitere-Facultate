void pascalTriangle() {
    for (int line = 0; line < NMAX; ++ line) {
        comb[line][0] = 1;
        for (int col = 1; col < line; ++ col)
            comb[line][col] = comb[line - 1][col - 1] + comb[line - 1][col];
        comb[line][line] = 1;
    }
}
