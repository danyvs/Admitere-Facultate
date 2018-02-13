// INSERAREA UNUI NOUD NOD LA INCEPUTUL UNEI LLSI
  void addFirst(node* &head, int x) {
      node* p = new node;
      p->info = x;
      p->next = head;
      head = p;
  }
  
// INSERAREA UNUI NOD LA SFARSITUL UNEI LLSI
  void addLast(node* head, int x) {
      node* p = new node;
      p->info = x;
      p->next = NULL;
      if (head == NULL)
          head = p;
      else {
          node* q = head;
          while (q->next)
              q = q->next;
          q->next = p;
      }
  }
  
// INSERAREA UNUI NOU NOD DUPA NODUL DE ADRESA adr
  void addAfter(node* head, int x, node* adr) {
      node* p = new node;
      p->info = x;
      p->next = adr;
      p->urm = q->urm;
      adr->urm = p;
  }
  
// INSERAREA UNUI NOU NOD INAINTEA NODULUI DE ADRESA adr
  void addBefore(node* &head, int x, node* adr) {
      node* p = new node;
      p->info = x;
      p->next = adr;
      if (p == head)
          head = p;
      else {
          node* q = head;
          while (q->next != p)
              q = q->next;
          q->next = p;
      }
  }
