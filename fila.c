#include <stdlib.h>
#include <stdio.h>
#include "libfila.h"

fila_t* fila_cria (){
    fila_t *p = (fila_t*)malloc(sizeof(fila_t));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}
fila_t* fila_destroi(fila_t* f){
    nodo_f_t *p = f->ini;
    nodo_f_t *q;
    while(p != NULL){
        q = p->prox;
        free(p);
        p = q;
    }
    free(f);
    return NULL;
}

int fila_vazia (fila_t* f){
    if (f->ini == NULL)
        return 1;
    return 0;
}

int fila_tamanho (fila_t* f){
    return f->tamanho;
}

int queue (fila_t* f, int elemento){
    nodo_f_t *fila = malloc(sizeof(nodo_f_t));
    /*se a fila for diferente de null*/
    if(fila){
        /*sifnifica que tá vazia*/
        fila->chave = elemento;
        fila->prox = NULL;

        if(f->ini == NULL){
            f->ini = fila;
            f->fim = fila;
        }
        else{
            f->fim->prox = fila;
            f->fim = fila;
        }
        f->tamanho++;
        
    }
    else{

        printf("erro alocação de memoria");

    }
    return 1;
}

int dequeue (fila_t* f, int *elemento){
        nodo_f_t *p = f->ini;
        if(p == NULL){
            printf("Fila vazia");
            return 0;
        }
        else{
            *elemento = p->chave;
            f->ini = p->prox;
            free(p);
            f->tamanho--;
            return 1;
        }
}

int retira_elemento_fila (fila_t* f, int elemento){
    nodo_f_t *p = f->ini;
    nodo_f_t *q;
    if(p == NULL){
        /*printf("Fila vazia");*/
        return 0;
    }
    else{
        while(p != NULL){
            if(p->chave == elemento){
                if(p == f->ini){
                    f->ini = p->prox;
                    free(p);
                    f->tamanho--;
                    return 1;
                }
                else{
                    q->prox = p->prox;
                    free(p);
                    f->tamanho--;
                    return 1;
                }
            }
            q = p;
            p = p->prox;
        }
        return 0;
    }
}


void fila_imprime (fila_t* f){
    nodo_f_t *inicio = f->ini;
    printf("[");
    while(inicio != NULL){
        printf("%d ", inicio->chave);
        inicio = inicio->prox;
    }
    printf("]\n");
    
}

