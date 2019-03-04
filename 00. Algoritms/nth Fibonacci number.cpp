#include <fstream>

using namespace std;

const int MOD = 666013;

void copyMatrix(int dest[2][2], int src[2][2]) {
    for (int i = 0; i <= 1; ++ i)
        for (int j = 0; j <= 1; ++ j)
            dest[i][j] = src[i][j];
}

void multMatrix(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i <= 1; ++ i)
        for (int j = 0; j <= 1; ++ j) {
            C[i][j] = 0;
            for (int k = 0; k <= 1; ++ k)
                C[i][j] = (C[i][j] + 1ULL * A[i][k] * B[k][j]) % MOD;
        }
}

void lgpow(int M[2][2], int pw) {
    if (pw > 1) {
        int temp[2][2];
        copyMatrix(temp, M);
        multMatrix(temp, temp, M);
        lgpow(M, pw / 2);
        if (pw % 2) {
            int aux[2][2];
            copyMatrix(aux, M);
            multMatrix(aux, temp, M);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int A[2][2];
    A[0][0] = 0;
    A[0][1] = A[1][0] = A[1][1] = 1;
    
    lgpow(A, n - 1);
    cout << A[1][1] << "\n";

    return 0;
}
