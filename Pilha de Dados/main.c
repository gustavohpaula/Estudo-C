#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define tamanho 5
struct tLivros{
	char autor[30], livro[30];
};
struct tpilha{
	struct tLivros livros[tamanho];
	int inicio, fim;	
};
struct tpilha pilha;
int op;

void pilhaEntrar(){
	if(pilha.fim == tamanho){
		printf("\n A plilha ja está cheia");
		system("pause");
	}else{
		printf("\nDigite o nome do autor");
		scanf("%s", pilha.livros[pilha.fim].autor);
		printf("\nDigite o nome do livro");
		scanf("%s", pilha.livros[pilha.fim].livro);
		pilha.fim++;
	}
}
void pilhaSair(){
	if(pilha.inicio == pilha.fim){
		printf("\nPilha está vazia");
		system("pause");
	}else{
		strcpy(pilha.livros[pilha.fim-1].livro, "");
		strcpy(pilha.livros[pilha.fim-1].autor, "");
		pilha.fim--;
	}
}
void mostrarConteudoPilha(){
	int i;
	for(i=0; i< tamanho; i++){
		printf("\nAutor: %s", pilha.livros[i].autor);
		printf("\nLivro: %s", pilha.livros[i].livro);
	}
}

void mostrarMenu(){

	printf("\nEscolha uma opção");
	printf("\n1 - Empilhar");
	printf("\n2 - Desempilhar");
	printf("\n0 - Sair");
	
}
int main() {
	setlocale(LC_ALL, "Portuguese");
	op =1;
	pilha.inicio = 0;
	pilha.fim=0;
	while(op != 0){
		system("cls");
		mostrarConteudoPilha();
		mostrarMenu();
		scanf("%d", &op);
		switch(op){
			case 1:
				pilhaEntrar();
				break;
			case 2:
				pilhaSair();
				break;
		}
	}
	
	
	return(0);
}
