// 1. Inserarea valorii x pe pozitia p 
void insertElemOnPos(int vec[], int& n, int x, int p) {
    for (int i = n; i >= p; -- i)
        vec[i + 1] = vec[i];
    vec[p] = x;
    ++ n;
}

// 2. Inserarea valorii x dupa fiecare numar cu o anumita proprietate (numar par, de exemplu)
// - nu se aloca memorie suplimentara
// - complexitate: O(n ^ 2)
void insertElem(int vec[], int& n, int x) {
    for (int i = 1; i <= n; ++ i)
        if (vec[i] % 2 == 0) {
            for (int j = n; j >= i + 1; -- j)
                vec[j + 1] = vec[j];
            vec[i + 1] = x;
            ++ n;
            ++ i; // se trece peste elementul inserat
        }
}

// 3. Inserarea valorii x dupa fiecare numar cu o anumita proprietate (numar par, de exemplu)
// - se aloca memorie suplimentara
// - complexitate: O(n)
void insertElem(int vec[], int& n, int x) {
    int temp[NMAX], dim = 0;
    for (int i = 1; i <= n; ++ i) {
        temp[++ dim] = vec[i];
        if (vec[i] % 2 == 0)
            temp[++ dim] = x;
    }
    n = dim;
    for (int i = 1; i <= n; ++ i)
        vec[i] = temp[i];
}


// 4. Stergerea elementului de pe pozitia p
void deleteElemOnPos(int vec[], int& n, int p) {
    for (int i = p; i < n; ++ i)
        vec[i] = vec[i + 1];
    -- n;
}

// 5. Stergerea tuturor elementelor cu o anumita proprietate (egale cu valoarea x, de exemplu)
// - nu se aloca memorie suplimentara
// - complexitate: O(n ^ 2)
void deleteElem(int vec[], int& n, int x) {
    for (int i = 1; i <= n; ++ i)
        if (vec[i] == x) {
            for (int j = i; j < n; ++ j)
                vec[j] = vec[j + 1];
            -- n;
            -- i; // se ramane pe aceeasi pozitie, deoarece este un nou element
        }
}

// 6. Stergerea tuturor elementelor cu o anumita proprietate (egale cu valoarea x, de exemplu)
// - se aloca memorie suplimentara
// - complexitate: O(n)
void deleteElem(int vec[], int& n, int x) {
    int temp[NMAX], dim = 0;
    for (int i = 1; i <= n; ++ i)
        if (vec[i] != x)
            temp[++ dim] = vec[i];
    n = dim;
    for (int i = 1; i <= n; ++ i)
        vec[i] = temp[i];
}

// 7. Stergerea tuturor elementelor cu o anumita proprietate (egale cu valoarea x, de exemplu)
// - nu se aloca memorie suplimentara
// - complexitate: O(n)
void deleteElem(int vec[], int& n, int x) {
    int p = 1;
    while (vec[p] != x)
        ++ p;
    for (int i = p + 1; i <= n; ++ i)
        if (vec[i] != x) {
            vec[p] = vec[i];
            vec[i] = x;
            ++ p;
        }
    n = p - 1;
}
