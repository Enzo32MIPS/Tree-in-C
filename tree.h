#define tree_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	struct nodo *pai;
	int chave;
	struct nodo *esq;
	struct nodo *dir;
	int fator;
	int balanco;
};
typedef struct nodo TipoInfo;

struct desc_avl{
	struct nodo *raiz;
	int* tamanho;
};
typedef struct desc_avl DESC_AVL;

struct TNodoA{
	TipoInfo* info;
	int FB;
	DESC_AVL* tree;
	struct TNodoA *esq;
	struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA* rotacao_direita(pNodoA* pt);
pNodoA* rotacao_esquerda(pNodoA *pt);
pNodoA* rotacao_dupla_direita (pNodoA* pt);
pNodoA* rotacao_dupla_esquerda (pNodoA *pt);
pNodoA* InsereAVL (pNodoA *a, TipoInfo* x, int* ok);
pNodoA* Caso1 (pNodoA *a , int *ok);
pNodoA* Caso2 (pNodoA *a , int *ok);
TipoInfo* Cria_nodo(int key);
void TreeBCheck(pNodoA* root);
void NodoFBCheck(TipoInfo* nodo);
