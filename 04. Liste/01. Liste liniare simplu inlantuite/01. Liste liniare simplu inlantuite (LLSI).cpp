/*  O LISTA LINIARE SIMPLU INLANTUITA (LLSI) permite memorearea mai multor valori. Aceasta este formata dintr-o succesiune de noduri, 
fiecare nod memorand o informatie utila si adresa nodului urmator. */
  
  struct node {
      int info;
      node* next;
  }
  
// Pentru a accesa toate valorile dintr-o LLSI este suficient sa se cunoasca doar adresa primului nod.
  
// CREAREA UNEI LLSI CU n NODURI
  node* createSLL() {
      int n, temp;
      cin >> n;
      // creare lista cu un singur nod
      cin >> temp;
      node* head = new node;
      head->info = temp;
      head->next = NULL;
      node* tail = head;
      // se adauga urmatoarele n - 1 noduri
      for (int i = 2; i <= n; ++ i) {
          cin >> temp;
          node* p = new node;
          p->info = temp;
          p->next = NULL;
          tail->next = p;
          tail = p;
      }
      return head;
  }
  

// PARCURGEREA UNEI LLSI
  void traverseSLL(node* head) {
      for (node* p = head; p; p = p->next)
          // prelucrare p->info
  }
