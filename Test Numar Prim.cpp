// Pentru a verifica daca un numar este prim, se cunosc mai multi algoritmi.

// 1. Ineficient: se verifica daca numarul este divizibil cu orice numar din intervavlul [2; x / 2]
bool prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= x / 2; ++ i)
        if (x % i == 0)
            return false;
    return true;
}

// 2. Mai eficienta: se verifica daca numarul este divizibil cu orice numar din intervavlul [2; sqrt(x)]
bool prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; ++ i)
        if (x % i == 0)
            return false;
    return true;
}

// 3. Eficient: se trateaza separat cazul x = 2 si apoi se verifica daca x este divizibil cu orice numar impar din intervalul [2; sqrt(x)]
bool prime(int x) {
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

/* Observatii:
1. O metoda mult mai eficienta pentru testarea proprietatii de numar prim pentru mai multe numere este cu ajutorul Ciurului lui Eratostene.
*/
