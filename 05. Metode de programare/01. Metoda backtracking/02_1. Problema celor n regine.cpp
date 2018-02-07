/* Sa se determine toate posibilitatile de aranjare a n regine pe o table de sah cu n linii si n coloane astfel incat sa nu existe 2 
regine care sa se atace (2 regine se ataca sunt pe aceeasi linie, pe aceeasi coloana sau pe aceeasi diagonala). 
Observatie: Daca n <= 3, nu exista solutii.
*/

#include <iostream>

using namespace std;

const int NMAX = 20;

inline int abs(int x) {
    return ((x) > (-x)) ? (x) : (-x);
}

inline bool valid(int k, int X[]) {
    for (int i = 1; i < k; ++ i)
        if (k - i == abs(X[k] - X[i]))
            return false;
    return true;
}

void print(int X[], int n) {
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j)
            cout << (X[i] == j ? 'R' : '*') << " ";
        cout << "\n";
    }
    cout << "\n";
}

void bkt(int k, int X[], int n, bool seen[]) {
    for (int i = 1; i <= n; ++ i)
        if (!seen[i]) {
            X[k] = i;
            seen[i] = true;
            if (valid(k, X)) {
                if (k == n)
                    print(X, n);
                else
                    bkt(k + 1, X, n, seen);
            }
            seen[i] = false;
        }
}

int main() {
    int n;
    int X[NMAX];
    bool seen[NMAX] = {false};
    cin >> n;
    bkt(1, X, n, seen);
    return 0;
}
