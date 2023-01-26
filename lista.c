#include <stdlib.h>
#include <stdio.h>
#include "liblista.h"

lista_t * lista_cria()
{
	lista_t * p = (lista_t*)malloc(sizeof(lista_t));
	p->ini = NULL;
	p->tamanho = 0;
	return p;	
}

int lista_vazia (lista_t *l){
	if(l->ini == NULL)
		return 1;
	else
		return 0;

}

lista_t * lista_destroi (lista_t *l){
	nodo_l_t *p = l->ini;
	nodo_l_t *q;
	while(p != NULL){
		q = p->prox;
		free(p);
		p = q;
	}
	free(l);
	return NULL;
}

int lista_tamanho (lista_t *l){
	return l->tamanho;
}

int lista_insere_inicio (lista_t *l, int elemento){
	nodo_l_t * novo = (nodo_l_t*)malloc(sizeof(nodo_l_t));
	novo->elemento = elemento;
	novo->prox = l->ini;
	l->ini = novo;
	l->tamanho++;
	
	return 1;
	
}
int lista_insere_fim (lista_t* l, int elemento){
    nodo_l_t *no,*novo = (nodo_l_t*)malloc(sizeof(nodo_l_t));
	novo->elemento = elemento;
	novo->prox = NULL;

	if(l->ini == NULL){
		l = lista_cria();
	}
	else{
		no = l->ini;
		while(no->prox != NULL){
			no = no->prox;
		}
		no->prox = novo;
		l->tamanho++;
	}
	return 1;
}

int lista_insere_ordenado (lista_t* l, int elemento){
    nodo_l_t *aux, *novo = malloc(sizeof(nodo_l_t));
	if(novo){
		novo->elemento = elemento;
		if(l->ini == NULL){
			return 0;
			novo->prox = NULL;
			l->ini = novo;
		}		
		else if((novo->elemento) < (l->ini->elemento)){
			novo->prox = l->ini;
			l->ini = novo;
		}
		else{
			aux = l->ini;
			while((aux->prox != NULL) && (novo->elemento > aux->prox->elemento))
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
		}
		l->tamanho++;
		return 1;
	}

	else
		return 0;
		
}

int lista_retira_elemento (lista_t* l, int *elemento){
	nodo_l_t *aux, *anterior;
	if(l->ini == NULL){
		return 0;
	}
	else{
		aux = l->ini;
		anterior = NULL;
		while(aux->elemento != *elemento){
			anterior = aux;
			aux = aux->prox;
		}
		if(anterior == NULL){
			l->ini = aux->prox;
		}
		else{
			anterior->prox = aux->prox;
		}
		free(aux);
		l->tamanho--;
		return 1;
	}
}



int lista_retira_inicio(lista_t *l, int *elemento){
	nodo_l_t *aux;
	if(l->ini == NULL){
		return 0;
	}
	else{
		aux = l->ini;
		*elemento = aux->elemento;
		l->ini = aux->prox;
		free(aux);
		l->tamanho--;
		return 1;
	}
}

int lista_retira_fim (lista_t* l, int* elemento){
	nodo_l_t *aux, *noa;
	if(l->ini == NULL){
		return 0;
	}
	else{
		noa = l->ini;
		while(noa->prox != NULL){
			noa = noa->prox;
		}
		aux = noa;
		*elemento = aux->elemento;
		noa = noa->prox;
		free(aux);
		l->tamanho--;
		return 1;
	}
}




int lista_pertence (lista_t* l, int elemento){
    nodo_l_t *inicio= malloc(sizeof(nodo_l_t));
	for(inicio = l->ini; inicio != NULL; inicio = inicio->prox){
		 if(inicio->elemento == elemento)
		 	return inicio->elemento;
	 }
	 
	return 1;
}

void lista_imprime (lista_t* l){
    nodo_l_t *inicio = l->ini;
	printf("[");
	while(inicio != NULL){
		printf(" %d", inicio->elemento);
		inicio = inicio->prox;
	}
	printf("]\n");
	
}
