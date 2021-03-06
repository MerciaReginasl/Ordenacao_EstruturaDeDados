#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);

void remover(int dado);

struct sNODE *buscar(int dado);

int obter(struct sNODE *node);

int tamanho();

//Ordenação Selection Sort
void selectionSort(struct sNODE *l, int tam);

//Auxiliar da função Selection Sort
struct sNODE *indexMin(struct sNODE *aux);


void imprimir();


void inserir(int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if (!ini)
	    ini = fim = novo;
    else{
	    fim->prox = novo;
	    fim = novo;
    }
}

struct sNODE *buscar(int dado){
  struct sNODE *aux = ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(int dado){
  struct sNODE *aux = ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	    if (aux == ini)
    	        ini = ini->prox;
  	    else if(aux == fim){
    	        ant->prox = NULL;
    	        fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

void apagar(){
  struct sNODE *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int obter(struct sNODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(){
  struct sNODE *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

//Função Auxiliar Selection Sort
struct sNODE *indexMin(struct sNODE *aux){
	struct sNODE *aux2 = aux, *menor = aux;
	
	while(aux2){
		if(aux2->dado < menor->dado){
			menor = aux2;
		}
		aux2 = aux2->prox;
	}
    return menor;
}
//Ordenação Selection Sort
void selectionSort(struct sNODE *l, int tam){
	struct sNODE *aux = l, *eleito;

	for (int i = 0 ; i < tam - 1 ; i++) {
		eleito = aux;
		struct sNODE *im = indexMin(aux->prox);
  		if (im->dado < eleito->dado){
			int value = im->dado;
			im->dado = eleito->dado;
			eleito->dado = value;
		  }
		aux = aux->prox;
 	}
}

void imprimir(){
  struct sNODE *aux = ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}


int main(){
   
    inserir(9);
    inserir(65);
    inserir(111);
    inserir(15);
    inserir(70);
    inserir(57);
    inserir(26);
    inserir(81);
    inserir(2);
    inserir(10);

    int tam = tamanho();

	printf("Elementos sem ordenacao:\n");
    imprimir();

	selectionSort(ini, tam);
	printf("\n");

	
	printf("Elementos com ordenacao:\n");
	imprimir();

  return 0;
}


