// rasturnatul unui numar
int inverse(int x) {
    int newNumber = 0;
    while (x) {
        newNumber = newNumber * 10 + x % 10; // adaugarea unei cifre la sfarsitul unui numar
        x /= 10;
    }
    return newNumber;
}


// numarul in aceeasi ordine
int modifyNumber(int x) {
    int newNumber = 0, pw = 1;
    while (x) {
        newNumber = (x % 10) * pw + newNumber; // adaugarea unei cifre la inceputul unui numar
        pw *= 10;
        x /= 10;
    }
    return newNumber;
}
