#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <cstring>

#define tamanho 5
struct tcliente{
	char nome[30], horario[5];
};
struct tFila{
	struct tcliente clientes[tamanho];
	int inicio, fim;	
};
struct tFila fila;
int op;

void pilhaEntrar(){
	if(fila.fim == tamanho){
		printf("\n A fila ja esta cheia\n");
		system("pause");
	}else{
		printf("\nDigite o nome do cliente\n");
		scanf("%s", fila.clientes[fila.fim].nome);
		printf("\nDigite o horario de chegada\n");
		scanf("%s", fila.clientes[fila.fim].horario);
		fila.fim++;
	}
}
void pilhaSair(){
	if(fila.inicio == fila.fim){
		printf("\nFila esta vazia");
		system("pause");
	}else{
		int i;
		for(i=0; i < tamanho; i++){
			strcpy(fila.clientes[i].nome, fila.clientes[i+1].nome);
			strcpy(fila.clientes[i].horario, fila.clientes[i+1].horario);
		}
		strcpy(fila.clientes[fila.fim].nome, "");
		strcpy(fila.clientes[fila.fim].horario, "");
		fila.fim--;
	}
}
void mostrarConteudoPilha(){
	int i;
	for(i=0; i< tamanho; i++){
		printf("\nCliente: %s", fila.clientes[i].nome);
		printf("\nHorario: %s", fila.clientes[i].horario);
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
	fila.inicio = 0;
	fila.fim=0;
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

