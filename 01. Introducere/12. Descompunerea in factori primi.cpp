// Descompunerea unui numar in factori primi, in mod eficient: x = a1 ^ p1 + a2 ^ p2 + ... + ak ^ pk

void primeFactors(int x) {
    int d, cnt;
    cnt = 0;
    while (x % 2 == 0) {
        ++ cnt;
        x /= 2;
    }
    if (cnt) {
        // prelucrare 2 la puterea cnt
    } 
    d = 3;
    while (d * d <= x) {
        cnt = 0;
        while (x % d == 0) {
            ++ cnt;
            x /= d;
        }
        if (cnt) {
            // prelucrare d la puterea cnt
        } 
        d += 2;
    }
    if (x != 1) {
        // prelucrare x la puterea 1
    }
}

/* Observatii:
1. Pe baza descompunerii in factori primi se poate determina numarul divizorilor duma urmatoarea formula: NUMARUL DIVIZORILOR = 
(p1 + 1) * (p2 + 1) * ... * (pk + 1)
2. Pe baza descompunerii in factori primi se poate determina suma divizorilor dupa urmatoarea formula : SUMA DIVIZORILOR = 
((a1 ^ (p1 + 1) - 1) / (a1 - 1)) * ((a2 ^ (p2 + 1) - 1) / (a2 - 1)) * ... * ((ak ^ (pk + 1) - 1) / ak - 1).
*/
