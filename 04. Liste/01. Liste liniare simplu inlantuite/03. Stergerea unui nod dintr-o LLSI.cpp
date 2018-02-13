// STERGERA PRIMULUI NOD
  void deleteFirst(node* &head) {
      if (head != NULL) {
          node* p = head;
          head = head->next;
          delete p;
      }
  }
  
// STERGEREA ULTIMULUI NOD
  void deleteLast(node* &head) {
      if (head != NULL) {
          if (head->next == NULL) {
              delete head;
              head = NULL;
          }
          else {
              node* p = head;
              while (p->next->next)
                  p = p->next;
              node* q = p->next;
              q->next = NULL;
              delete p;
          }
      }
  }
