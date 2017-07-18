// Vectori
// 1. Declararea unui vector: tip_elemente denumire: int vec[105]; float x[1000] ...
// 2. Vectorii pot fi indexati de la 0 sau de la 1.
// 3. Citirea si afisarea unui vector se face prin parcurgerea pozitiilor: for (int i = 1; i <= n; ++ i) cin >> vec[i];

// Prelucrarea elementelor unui vector

// 1. Prelucrarea fiecarui element
void prelElementsOfVector(int vec[], int n) {
    for (int i = 1; i <= n; ++ i) {
        // prelucrare vec[i]
    }
}

// 2. Prelucrarea perechilor de elemente aflate pe pozitii consecutive
void prelElementsOfVector(int vec[], int n) {
    for (int i = 1; i < n; ++ i) {
        // prelucrare (vec[i], vec[i + 1])
    }
}

// 3. Prelucrarea perechilor de elemente aflate pe pozitii egal departate de mijloc
void prelElementsOfVector(int vec[], int n) {
    for (int i = 1; i <= n / 2; ++ i) {
        // prelucrare (vec[i], vec[n - i + 1])
    }
}

// 4. Prelucrarea tuturor perechilor de elemente
void prelElementsOfVector(int vec[], int n) {
    for (int i = 1; i < n; ++ i)
        for (int j = i + 1; j <= n; ++ j) {
            // prelucrare (vec[i], vec[j])
        }
}
