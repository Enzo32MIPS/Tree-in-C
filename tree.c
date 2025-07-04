#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int alturaTree(Nodo *n) {
    if (n){
        return n->height;
    } else {
        return 0;
    }
}

int max(int a, int b) {
    if (a > b){
        return a;
    } else {
        return b;
    }
}

Nodo* Cria_Nodo(int chave) {
    Nodo* node = (Nodo*)malloc(sizeof(Nodo));
    node->chave = chave;
    node->height = 1;
    node->esq = node->dir = NULL;
    return node;
}

int balanco(Nodo *n) {
    if (n){
        return alturaTree(n->esq) - alturaTree(n->dir);
    } else {
        return 0;
    }
}

Nodo* dirRotate(Nodo *y) {
    Nodo *x = y->esq;
    Nodo *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->height = max(alturaTree(y->esq), alturaTree(y->dir)) + 1;
    x->height = max(alturaTree(x->esq), alturaTree(x->dir)) + 1;

    return x;
}

Nodo* esqRotate(Nodo *x) {
    Nodo *y = x->dir;
    Nodo *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->height = max(alturaTree(x->esq), alturaTree(x->dir)) + 1;
    y->height = max(alturaTree(y->esq), alturaTree(y->dir)) + 1;

    return y;
}

Nodo* insereAVL(Nodo* node, int chave) {
    if (!node) return Cria_Nodo(chave);

    if (chave < node->chave)
        node->esq = insereAVL(node->esq, chave);
    else if (chave > node->chave)
        node->dir = insereAVL(node->dir, chave);
    else
        return node;

    node->height = 1 + max(alturaTree(node->esq), alturaTree(node->dir));
    if (node->height > 1){
        node->pai =
    }
    int balance = balanco(node);

    if (balance > 1 && chave < node->esq->chave)
        return dirRotate(node);
    if (balance < -1 && chave > node->dir->chave)
        return esqRotate(node);
    if (balance > 1 && chave > node->esq->chave) {
        node->esq = esqRotate(node->esq);
        return dirRotate(node);
    }
    if (balance < -1 && chave < node->dir->chave) {
        node->dir = dirRotate(node->dir);
        return esqRotate(node);
    }

    return node;
}

Nodo* minValueNodo(Nodo* node) {
    Nodo* current = node;
    while (current->esq)
        current = current->esq;
    return current;
}

Nodo* deleteNodo(Nodo* root, int chave) {
    if (!root) {
        return root;
    }

    if (chave < root->chave){
        root->esq = deleteNodo(root->esq, chave);
    } else
    if (chave > root->chave) {
        root->dir = deleteNodo(root->dir, chave);
    } else {
        if (!root->esq || !root->dir) {
            Nodo *temp = root->esq ? root->esq : root->dir;
            if (!temp) {
                free(root);
                return NULL;
            } else {
                Nodo *old = root;
                root = temp;
                free(old);
            }
        } else {
            Nodo *temp = minValueNodo(root->dir);
            root->chave = temp->chave;
            root->dir = deleteNodo(root->dir, temp->chave);
        }
    }

    root->height = 1 + max(alturaTree(root->esq), alturaTree(root->dir));
    int balance = balanco(root);

    if (balance > 1 && balanco(root->esq) >= 0)
        return dirRotate(root);
    if (balance > 1 && balanco(root->esq) < 0) {
        root->esq = esqRotate(root->esq);
        return dirRotate(root);
    }
    if (balance < -1 && balanco(root->dir) <= 0)
        return esqRotate(root);
    if (balance < -1 && balanco(root->dir) > 0) {
        root->dir = dirRotate(root->dir);
        return esqRotate(root);
    }

    return root;
}

Nodo* search(Nodo* root, int chave) {
    if (!root || root->chave == chave) {
        return root;
    }
    if (chave < root->chave) {
        return search(root->esq, chave);
    } else {
        return search(root->dir, chave);
    }
}

void inOrder(Nodo* root) {
    if (root) {
        inOrder(root->esq);
        printf("%d ", root->chave);
        inOrder(root->dir);
    }
}

void freeTree(Nodo* root) {
    if (!root) {
        return;
    }
    freeTree(root->esq);
    freeTree(root->dir);
    free(root);
}

void visualTree(Nodo* root){
    if (!root){
        return;
    }
    Nodo* aux = root;
    while (aux){
        printf("\t%i\n",aux->chave);
        aux = aux->esq;
    }
}
