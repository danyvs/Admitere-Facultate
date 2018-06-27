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

/* Daca este necesara verificarea proprietatii de numar prim pentru un numar mare de numere, este recomandat sa se foloseasca 
Ciurul lui Eratostene */
