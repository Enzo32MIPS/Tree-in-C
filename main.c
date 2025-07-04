#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Nodo* root = NULL;
    int chave;
	char opt = '5';

    do {
        printf("\n==== SELECIONE ====\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Imprimir arvere (in-order)\n");
        printf("5. Visualizar como arvere\n");
        printf("0. Sair\n");
        printf(": ");
        scanf(" %c", &opt);

        switch (opt) {
            case '1':

                printf("Digite o valor a inserir: ");
                scanf("%d", &chave);
                root = insereAVL(root, chave);
                break;

            case '2':

                printf("Digite o valor a remover: ");
                scanf("%d", &chave);
                root = deleteNodo(root, chave);
                break;

            case '3':

                printf("Digite o valor a buscar: ");
                scanf("%d", &chave);
                Nodo* found = search(root, chave);
                if (found)
                    printf("\nElemento %d encontrado na arvere.\n", chave);
                else
                    printf("\nElemento %d NAO encontrado.\n", chave);
                break;

            case '4':

                printf("\nSua arvere: ");
                inOrder(root);
                printf("\n");
                break;

            case '5':

                printf("\nSua arvere:");
                visualTree(root);
                printf("\n");
                break;

            case '0':

                printf("Lembre-se, Jesus é o jardineiro, e as arveres somos nozes\n");
				printf("Ate mais!\n");
                freeTree(root);
                break;

            default:

                printf("Opcao invalida!\n");
                break;
        }
    } while (opt != '0');

    return 0;
}
