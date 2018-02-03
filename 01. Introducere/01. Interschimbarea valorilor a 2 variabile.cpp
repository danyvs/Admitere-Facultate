void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/* Functia swap poate interschimba valorile si a altor tipuri de date. Singura conditie este ca atribuirea pentru acel tip sa se poate
face cu =. De exemplu, toate tipurile numerice se pot interschimba dupa modelul de mai sus. Insa, sirurile de caractere nu se poate 
interschimba, deoarece copierea se face cu ajutorul functiilor specifice. */
