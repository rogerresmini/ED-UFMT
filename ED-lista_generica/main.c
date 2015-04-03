#include <stdio.h>

#define tam 10

int quant = 0;

int menu();
void inserir(int *);
void inicializar(int *, int);
void remover(int *);
void compactar(int *);
void mostrar(int *);
void mostrar2(int *);

int main(void)
{
    int lista[tam], op;
    inicializar(lista, -1);
	do{
        op = menu();
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
        case 0:
            compactar(lista);
            break;
        case -1:
            mostrar2(lista);
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

void inicializar(int *v, int val){
	int i;
	for(i=0; i<tam; i++)
        v[i] = val;
}

void inserir(int *v){
    if(quant == tam)
        printf("Lista cheia!");
    else{
        int val;
        printf("Informe um valor acima de -1: ");
        scanf("%d", &val);
        if(quant == 0){
            v[quant] = val;
            quant++;
        }else{
            int i = 0;
            while(i<tam){
                printf("i: %d\n", i);
                if(v[i] > val)
                    break;
                i++;
            }
            if(i==tam){ // inserir no fim
                compactar(v);
                v[quant] = val;
                quant++;
            }else
                if(v[i] == -1){ // inserir no meio com buraco
                    v[i] = val;
                    quant++;
                }else
                    if(i == 0){ // inserir no início ou inserir no meio sem buraco
                        compactar(v);
                        int j;
                        for(j=quant; j<i; j--)
                            v[j] = v[j-1];
                        v[j] = val;
                        quant++;
                    }
        }
    }
}

void compactar(int *v){
    if(quant == tam)
        printf("Lista cheia!");
    else{
        int i;
        for(i=0; i<tam-1; i++){
            if(v[i] == -1){
                v[i] = v[i+1];
                v[i+1] = -1;
            }
        }
    }
}

void remover(int *v){
	if(quant == 0)
		printf("lista vazia!");
	else{
		int val;
		printf("Informe o valor para remover: \n");
		scanf("%d", &val);
		int i = 0;
        while((i<tam) && (v[i] != val)){
			i++;
		}
        printf("\n(remover) i: %d \n", i);
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
        int i;
        for(i=0; i<tam; i++){
			if(v[i] != -1)
				printf("lista[%i]: %i \n", i, v[i]);
		}
	}
}

void mostrar2(int *v){
    int i;
    for(i=0; i<tam; i++)
        printf("lista[%i]: %i \n", i, v[i]);
}

