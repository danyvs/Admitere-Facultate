/* Pentru ca o problema sa poate fi rezolvata cu ajutorul metodei backtracking:
  1. solutia trebuie sa poata fi reprezentata cu ajutorul unui vector
    X = (x1, x2, ... xn)
  2. fiecare element al vectorului trebuie sa ia valori intr-o multime ordonata si fininta
    ∀ k ∈ 1, n => xk ∈ [ak; bk] 
  Solutia problemei se contruieste pas cu pas, la fiecare pas verificandu-se daca solutia partiala este valida.
  Metoda backtracking genereaza, de fapt, toate elementele produsului cartezian al unei multimi, renuntand din timp la toate combinatiile
care nu pot fi solutii finale.
*/

// 1. Schema generala
void bkt(int k, int X[], int a, int b) {
    for (int i = a; i <= b; ++ i) {
        X[k] = i;
        if (valid(k)) {
            if (finalSolution(k))
                print(k);
            else
                bkt(k + 1, X, a, b);
        }
    }
}
