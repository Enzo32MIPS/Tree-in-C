#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main(){

	char opt = '5';
	DESC_AVL* AVL = NULL;
	pNodoA* root = NULL;
	TipoInfo* nodo = NULL;
	int key = 0;

	system("clear");

	while (opt != '0'){

	printf("=====MENU=====\n");
	printf("1. Inserir na arvere\n");
	printf("2. Imprimir arvere\n");
	printf("3. Deletar da arvere\n");
	printf("0. Sair\n");
	printf(":");
	scanf(" %c",&opt);

		switch (opt){

		case '0':
		exit(1);
		break;

		case '1':
		printf("\nInsira o numero que vc deseja inserir:\n");
		scanf(" %i",&key);
		nodo = Cria_nodo(key);
		root = InsereAVL(root, nodo, &AVL->tamanho);
		break;

		default:
		printf("Erro!\n");
		break;
		}
	}
}
