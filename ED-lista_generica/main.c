#include <stdio.h>

#define tam 10

int quant = 0;

int menu();
void inserir(int *);
void inicializar(int *);
void remover(int *);
void compactar(int *);
void mostrar(int *);

int main(void)
{
	int lista[tam];
	do{
		int op = menu();
		switch (op) {
		case 1:
			inserir(lista);
			break;
		case 2:
			remover(lista);
			break;
		case 3:
			mostrar(lista);
			break;
		case 4:
			break;
		default:
			printf("Opcao invalida! \nEscolha outra.");
			break;
		}
	}while(op < 5);
	printf("FIM!\n");
	return 0;
}

int menu(){
	int op;
	printf("***** MENU *****\n");
	printf("1........INSERIR\n");
	printf("2........REMOVER\n");
	printf("3........MOSTRAR\n");
	printf("4...........SAIR\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &op);
//	printf("\n");
	return(op);
}

void inicializar(int *v){
	int i;
	for(i=0; i<tam; i++)
		v[i] = -1;
}

void inserir(int *v){
	//
}

void compactar(int *){
	//
}

void remover(int *v){
	if(quant == 0)
		printf("lista vazia!");
	else{
		int val;
		printf("Informe o valor para remover: \n");
		scanf("%d", &val);
		int i = 0;
		while((i<tam) || (v[i] != val)){
			i++;
		}
		if(i == tam)
			printf("Valor nao encontrado na lista!");
		else{
			v[i] = -1;
			quant--;
		}
	}
}


void mostrar(int *v){
	if(quant == 0)
		printf("lista vazia!");
	else{
		int i = 0;
		while(i < tam){
			if(v[i] != -1)
				printf("lista[%i]: %i \n", i, v[i]);
			i++;
		}
	}
}

