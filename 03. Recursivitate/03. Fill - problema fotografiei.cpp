/* Alina este pasionată de fotografiile alb-negru. Ea ales o imagine pe care a codificat-o binar într-o matrice de dimensiune nxm cu 
valori 0 corespunzătoare pentru alb (pe care le-a numit puncte luminoase) şi cu valori 1 corespunzătoare pentru negru (pe care le-a numit 
puncte întunecate). Astfel, ea identifică în imaginea codificată zone luminoase și zone întunecate, o zonă fiind o porțiune a matricei 
care conține elemente cu aceeași valoare, trecerea de la un element la altul al zonei făcându-se doar prin deplasări pe orizontală sau 
pe verticală. Ajutați-o pe Alina să găsească cea mai luminoasă zonă și determinați numărul de puncte luminoase ale acesteia.
*/

#include <fstream>

using namespace std;

ifstream fin("foto.in");
ofstream fout("foto.out");

const int NMAX = 105;

void read(int A[NMAX][NMAX], int& n, int& m) {
    // citirea datelor de intrare
    fin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            fin >> A[i][j];
}

void border(int A[NMAX][NMAX], int n, int m) {
    // bordare prima si ultima linie
    for (int j = 0; j <= m + 1; ++ j)
        A[0][j] = A[n + 1][j] = 1;
    // bordare prima si ultima coloana
    for (int i = 0; i <= n + 1; ++ i)
        A[i][0] = A[i][m + 1] = 1;
}

void fillDetS(int A[NMAX][NMAX], int x, int y, int& cnt) {
    // fill pentru determinarea suprafetei
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    A[x][y] = 1;
    ++ cnt;
    for (int i = 0; i < 4; ++ i) {
        int l = x + dx[i];
        int c = y + dy[i];
        if (!A[l][c])
            fillDetS(A, l, c, cnt);
    }
}

inline int max(const int& a, const int& b) {
    return a > b ? a : b;
}

void solve(int A[NMAX][NMAX], int n, int m) {
    int Smax = 0; // memoreaza suprafata maxima
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (!A[i][j]) {
                int S = 0;
                fillDetS(A, i, j, S);
                Smax = max(Smax, S);
            }
    fout << Smax << "\n";
}

int main() {
    int A[NMAX][NMAX], n, m;
    read(A, n, m);
    fin.close();
    border(A, n, m);
    solve(A, n, m);
    fout.close();
    return 0;
}
