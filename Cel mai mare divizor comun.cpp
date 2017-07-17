/* Cel mai mare divizor comun a 2 numere naturale (cmmdc sau gcd) se poate determina foarte usor cu Algoritmul lui Euclid. Acesta prezinta
2 variante: prin scaderi repetate (ineficienta) si prin impartiri repetate (eficienta), cea din urma avand si o scriere recursiva foarte 
usoara. */

// 1. Cel mai mare divizor comun prin scaderi repetate - Varianta ineficienta
int gcd(int a, int b) {
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
} 

// 2. Cel mai mare divizor comun prin impartiri repetate - Iterativ - Varianta eficienta
int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 3. Cel mai mare divizor comun prin impartiri repetate - Recursiv - Varianta Eficienta
int gcd(int a, int b) {
    return (!b) ? a : gcd(b, a % b);
}

/* Observatii
1. Varianta rpin impartiri repetate executa un numar de pasi mult mai mici decat cea prin scaderi repetate.
2. Se prefera varianta 3 de scriere a functiei datorita usurintei de scriere si a dimensiunii reduse.
3. Varianta 3 se poate scrie si fara folosirea operatorului tertiar (?), prin inlocuirea acestuia cu un if.
!!! 4. Cel mai mic multiplu comun a 2 numere se calculeaza dupa urmatoarea formula: cmmmc(a, b) = (a * b) / cmmdc(a, b).
!!! 5. Pentru a verifica daca 2 numere sunt prime intre ele, se calculeaza valoarea cmmdc-ului: daca aceasta este 1, atunci numerele sunt
prime intre ele; daca valoarea este diferita de 1, atunci numerele NU sunt prime intre ele.
*/
