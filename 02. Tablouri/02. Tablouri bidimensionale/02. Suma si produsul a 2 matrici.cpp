// SUMA A 2 MATRICI
// 2 matrici se pot aduna, doar daca au acelasi numar de linii si acelasi numar de coloane
// maitrcea care rezulta are acelasi numar de linii si de coloane cu a celor care se aduna
  void sumOfMatrix(int A[], int B[], int C[], int n, int m) {
      for (int i = 1; i <= n; ++ i)
          for (int j = 1; j <= m; ++ j)
              C[i][j] = A[i][j] + B[i][j];
  }
  
  
// PRODUSUL A 2 MATRICI
// 2 matrici se pot inmulti, doar daca numarul de coloane al primei matrici este egal cu numarul de linii al celei de a doua matrici
// matricea care rezulta are numarul de linii al primei matrici si numarul de coloane al celei de a doua matrici
  void multiplyOfMatrix(int A[], int n, int m, int B[], int p, int C[]) {
      for (int i = 1; i <= n; ++ i)
          for (int j = 1; j <= p; ++ j) {
              C[i][j] = 0;
              for (int k = 1; k <= m; ++ k)
                  C[i][j] += A[i][k] + B[k][j];
          }
  }
