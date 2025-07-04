#define tree_h

typedef struct Nodo {
    int chave;
    int height;
    struct Nodo *esq;
    struct Nodo *dir;
    struct Nodo *pai;
} Nodo;

int alturaTree(Nodo *n);
int max(int a, int b);
Nodo* Cria_Nodo(int chave);
int balanco(Nodo *n);
Nodo* dirRotate(Nodo *y);
Nodo* esqRotate(Nodo *x);
Nodo* insereAVL(Nodo* node, int chave);
Nodo* minValueNodo(Nodo* node);
Nodo* deleteNodo(Nodo* root, int chave);
Nodo* search(Nodo* root, int chave);
void inOrder(Nodo* root);
void freeTree(Nodo* root);
void visualTree(Nodo* root);
