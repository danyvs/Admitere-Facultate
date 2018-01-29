  Parcurgerea nodurilor unui graf reprezinta vizitarea nodurilor dupa o anumita regula.
  
  1) BFS (Breadth-first Search) - parcurgerea in latime
    - Se incepe parcurgerea un nod de start
    - Se viziteaza vecinii nevizitati, apoi vecinii vecinilor etc.
    
    Utilizare:
      - determinarea unui lant de lungime minima de la nodul x la nodul y
      - determinarea conexitatii grafului si a componentelor conexe
      
    Se da graful:
      7 10
      1 2
      1 3
      2 4
      2 6
      3 4
      3 7
      4 5
      5 6
      5 7
      6 7
        
    BFS(1): 1 2 3 4 6 7 5
    BFS(2): 2 1 4 6 3 5 7
      
    Implementare:
      - O(n ^ 2) - graful este reprezentat cu matrice de adiacenta
      - O(n + m) - graful este reprezentat cu liste de adiacenta
      
      void bfs(node* G[NMAX], int startNode) {
        bool seen[NMAX] = {false}; // vector de memorare a nodurilor vizitate
        int q[NMAX], idx = 0, dim = 0; // coada
        q[++ dim] = startNode;
        seen[startNode] = true;
        idx = 1;
        // prelucrare nod start
        while (idx <= dim) {
          int currNode = q[idx ++];
          for (node* p = G[currNode]; p; p = p->next) 
            if (!seen[p->info]) {
              q[++ dim] = p->info;
              seen[p->info] = true;
              // prelucrare p->info
            }
          }
        }
        
        
  2) DFS (Depth-first Search)
    - Se incepe parcurgerea dintr-un node de start
    - Seviziteaza primul vecin nevizitat, apoi primul vecin nevizitat al acestuia etc
    - Daca un nod nu mai are vecini nevizitati, se intoarce si viziteaza urmatorul vecin nevizitat al nodurilor din care acesta a fost 
  vizitat etc
    
    Utilizare:
      - determinarea conexitatii grafului si a componentelor conexe
      - determinarea ciclicitatii grafului (daca contine cel putin un ciclu)
      
    Se da graful:
      8 9
      1 2
      1 4
      1 6
      2 3
      3 6
      4 5
      4 7
      4 8
      5 8
      
    DFS(1): 1 2 3 6 4 5 8 7
    DFS(4): 4 1 2 3 6 5 8 7
    DFS(8): 8 4 1 2 3 6 5 7
    
    Implementare:
      void dfs(node* G[NMAX], int currNode, bool seen[]) {
        // prelucrare currNode
        seen[currNode] = true;
        for (node* p = G[currNode]; p; p = p->next)
          if (!seen[p->info])
            dfs(p->info);
      }
  
