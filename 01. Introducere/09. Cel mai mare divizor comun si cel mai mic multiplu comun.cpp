// Cel mai mare divizor comun
// 1. prin scaderi repetate
int gcd(int a, int b) {
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}


// 2. prin impartiri repetate
int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


// 3. recursiv (forma condensata)
int gcd(int a, int b) {
    return (!b) ? a : gcd(b, a % b);
}


// Cel mai mic multiplu comun
CMMMC(a, b) = a * b / CMMDC(a, b)
