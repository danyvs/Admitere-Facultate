/* Parcul oraşului a fost neglijat mult timp, astfel că acum toate aleile sunt distruse. Prin urmare, anul acesta Primăria şi-a propus să 
facă reamenajări. Parcul are forma unui pătrat cu latura de n metri şi este înconjurat de un gard care are exact două porţi. Proiectanţii
de la Primărie au realizat o hartă a parcului şi au trasat pe hartă un caroiaj care împarte parcul în nxn zone pătrate cu latura de 1 
metru. Astfel harta parcului are aspectul unei matrice pătratice cu n linii şi n coloane. Liniile şi respectiv coloanele sunt numerotate
de la 1 la n. Elementele matricei corespund zonelor pătrate de latură 1 metru. O astfel de zonă poate să conţină un copac sau este liberă.
Edilii oraşului doresc să paveze cu un număr minim de dale pătrate cu latura de 1 metru zonele libere (fără copaci) ale parcului, astfel
încât să se obţină o alee continuă de la o poartă la alta. Scrieţi un program care să determine numărul minim de dale necesare pentru
construirea unei alei continue de la o poartă la cealaltă.
*/

#include <fstream>

using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

const int NMAX = 180;

struct elem {
    int x, y;
};

void initMatrix(int A[NMAX][NMAX], int n, int val) {
    // initilizarea matricei A de dimensiune n x n cu val
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            A[i][j] = val;
}

void read(int A[NMAX][NMAX], int& n, elem& posBegin, elem& posEnd) {
    // citirea datelor de intrare
    int cntObstacles;
    fin >> n >> cntObstacles;
    initMatrix(A, n, 0);
    for (int i = 1; i <= cntObstacles; ++ i) {
        int x, y;
        fin >> x >> y;
        A[x][y] = -1; // pozitiile inaccesibile sunt marcate cu -1
    }
    fin >> posBegin.x >> posBegin.y; // pozitia de plecare
    fin >> posEnd.x >> posEnd.y; // poztia de final
}

void border(int A[NMAX][NMAX], int n) {
    // bordarea matricei
    for (int i = 0; i <= n + 1; ++ i)
        A[i][0] = A[i][n + 1] = A[0][i] = A[n + 1][i] = -1;
}

void lee(int A[NMAX][NMAX], int n, elem posBegin, elem posEnd) {
    elem queueElem[NMAX * NMAX];
    int first = 0, dim = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queueElem[++ dim] = posBegin;
    first = 1;
    A[posBegin.x][posBegin.y] = 1;
    while (first <= dim) {
        int l = queueElem[first].x;
        int c = queueElem[first].y;
        ++ first;
        for (int i = 0; i < 4; ++ i) {
            int x = l + dx[i];
            int y = c + dy[i];
            if (!A[x][y]) {
                A[x][y] = A[l][c] + 1;
                ++ dim;
                queueElem[dim].x = x;
                queueElem[dim].y = y;
            }
        }
    }
}

int main() {
    int A[NMAX][NMAX], n;
    elem posBegin, posEnd;
    read(A, n, posBegin, posEnd);
    fin.close();
    border(A, n);
    lee(A, n, posBegin, posEnd);
    fout << A[posEnd.x][posEnd.y] << "\n";
    fout.close();
    return 0;
}
