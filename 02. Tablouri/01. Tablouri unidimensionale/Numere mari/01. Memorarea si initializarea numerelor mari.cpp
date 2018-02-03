/* Numerele mari sunt numere care nu se pot reprezenta pe tipurile de date simple standard. Ele se vor memora cu ajutorul tablourilor 
unidimensionale. */

// MEMORAREA UNUI NUMAR MARE
/* Vom reprezenta un număr natural mare ca un vector care să conțină pe prima poziție (A[0]) lungimea numărului mare (numărul de cifre) 
şi apoi cifrele sale în ordine inversă, începând cu unităţile. */
  typedef int bigInt[NMAX];
  
  
// INITIALIZAREA UNUI NUMAR MARE
// 1. cu un numar mic (scalar)
  void atribIntToBigInt(bigInt A, int x) {
      // lui A i se atribuie valoarea lui x
      A[0] = 0;
      while (x) {
          A[++ A[0]] = x % 10;
          x /= 10;
      }
  }

// 2. cu un alt numar mare
void atribBigIntToBigInt(bigInt A, bigInt B) {
    // lui A is se atribuie valoarea lui B
    for (int i = 0; i <= B[0]; ++ i)
        A[i] = B[i];
}
