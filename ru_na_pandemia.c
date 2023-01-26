#include "lista.c"
#include "fila.c"
#include "pilha.c"
#include "main.h"
#include<time.h>

int aleat(int num, int num2){
    int a;
    a = num + ( rand() % num2 );
    return a;
}
float  sorteia_dinheiro(float dinheiro){
    /*isso deve ter proporção de 60/100*/
    int dinheiros;
    dinheiros = (rand() % 2); 
    if(dinheiros == 0)
        dinheiro = 1.30; 
    else
        dinheiro = 3.80; 

    return dinheiro;
}

Pessoa* inicializar_pessoa(){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));  
    p->ticket =  0;
    p->vacinado = rand() % 2; 
    p->mascara = rand() % 1;
    p->dinheiro = 0;
    return p;
}

contabilidade* inicializar_contabilidade(){
    contabilidade *c = (contabilidade*)malloc(sizeof(contabilidade));
    c->dinheiro_total = 0;
    c->dinheiro_refeicao = 0;
    c->dinheiro_mascara = 0;
    c->ticket = 0;
    c->razao = ' ';
    return c;
}

int criar_pessoas(int num_pessoas, Pessoa *pessoas){
    int i;
    srand(time(NULL));
    for(i = 0; i < num_pessoas; i++){
        pessoas[i] = *inicializar_pessoa();
        pessoas[i].ticket = aleat(1, 1000);
        pessoas[i].dinheiro = sorteia_dinheiro(pessoas[i].dinheiro);
    }
    return 0;
}

int criar_contabilidade(int num_pessoas, contabilidade* contabilidade){
    int i;
    srand(time(NULL));
    for(i = 0; i < num_pessoas; i++){
        contabilidade[i] = *inicializar_contabilidade();
    }
    return 0;
}
int mostrar_pessoas(Pessoa *pessoas, int num_pessoas){
    int i;
    for(i = 0; i < num_pessoas; i++){
        printf("\nPessoa %d\n", i);
        printf("Ticket: %d\n", pessoas[i].ticket);
        printf("Vacinado: %d\n", pessoas[i].vacinado);
        printf("Mascara: %d\n", pessoas[i].mascara);
        printf("Dinheiro: %.2f\n", pessoas[i].dinheiro);
    }
    return 0;
}

float saldo_total(int num_pessoas, contabilidade *c){
    c->dinheiro_total = c->dinheiro_refeicao + c->dinheiro_mascara + c->dinheiro_total;
    return c->dinheiro_total;
}

float saldo_mascara(int num_pessoas, contabilidade *c){
    int i;
    for(i = 0; i < num_pessoas; i++){
    c->dinheiro_mascara =  c->dinheiro_mascara + c[i].dinheiro_mascara;
     
}
    return c->dinheiro_mascara;
}

float saldo_refeicao(int num_pessoas, contabilidade *c){
    int i;
    for(i = 0; i < num_pessoas; i++){
    c->dinheiro_refeicao = c->dinheiro_refeicao + c[i].dinheiro_refeicao;
     
}
    return c->dinheiro_refeicao;
}

int encher_refeicoes(pilha_t *refeicoes, int tamanho_refeicoes){
    int i;
    for(i = 0; i < tamanho_refeicoes; i++){
        push(refeicoes, 1);
    }
    return 0;
}

int encher_mascara(pilha_t *mascara, int tamanho_mascara){
    int i;
    for(i = 0; i < tamanho_mascara; i++){
        push(mascara, 1);
    }
    return 0;
}

int mostrar_razao(contabilidade *c, int num_pessoas){
    int i, V, D;
    for(i = 0; i < num_pessoas; i++){
        if(c[i].razao == 'V'){
            V++;
        }
        else if(c[i].razao == 'D'){
            D++;
        }
        
    }
    printf("\nRazao V: %d\n", V);
    printf("Razao D: %d\n", D);
    return 0;
}

     
int main(){
    Pessoa *pessoas_fila;
    contabilidade *contabilidade_dia;
    pilha_t *mascara;
    pilha_t *refeicoes;
    fila_t *atendimento;
    lista_t * lista_ticket;
    int tamanho_mascara, tamanho_refeicoes, num_pessoas, pessoas, i;
    num_pessoas = 1000;
    tamanho_mascara = aleat(1, 100);
    mascara = pilha_cria(tamanho_mascara);
    encher_mascara(mascara, tamanho_mascara);
    tamanho_refeicoes = aleat(500, 1000);
    refeicoes = pilha_cria(tamanho_refeicoes);
    encher_refeicoes(refeicoes, tamanho_refeicoes);
    atendimento = fila_cria();
    lista_ticket = lista_cria();
    pessoas_fila = inicializar_pessoa();
    criar_pessoas(num_pessoas, pessoas_fila);
    contabilidade_dia = inicializar_contabilidade();
    criar_contabilidade(num_pessoas, contabilidade_dia);
    /*mostrar_pessoas(pessoas_fila, num_pessoas);*/
    for(pessoas = 0; pessoas <num_pessoas ; pessoas++){
        queue(atendimento, pessoas_fila[pessoas].ticket);
     }; 
    while( fila_vazia(atendimento) != 1 ){
        for(i = 0; i < num_pessoas; i++){
            if( pessoas_fila[i].vacinado == 0){
                /*printf("Pessoa não vacinada %d \n", pessoas_fila[i].ticket);*/
                retira_elemento_fila (atendimento, pessoas_fila[i].ticket);
                lista_insere_inicio(lista_ticket, pessoas_fila[i].ticket);
                contabilidade_dia[i].razao = 'V';
                contabilidade_dia[i].ticket = pessoas_fila[i].ticket;
            }
            else if(pessoas_fila[i].vacinado == 1){
                if(pessoas_fila[i].mascara == 0){
                    if(pessoas_fila[i].dinheiro > 2.50){
                        pessoas_fila[i].dinheiro = pessoas_fila[i].dinheiro - 2.50;
                       /* printf("Comprou mascara %d\n", pessoas_fila[i].ticket);*/
                        pessoas_fila[i].mascara = 1;
                        pop(mascara);
                        contabilidade_dia[i].dinheiro_mascara = contabilidade_dia[i].dinheiro_mascara + 2.50;
                        retira_elemento_fila (atendimento, pessoas_fila[i].ticket);
                        queue(atendimento, pessoas_fila[i].ticket);
                    
                    }
                    else{
                        /*printf("Não tem dinheiro suficiente %d\n", pessoas_fila[i].ticket);*/
                        contabilidade_dia[i].razao = 'D';
                        contabilidade_dia[i].ticket = pessoas_fila[i].ticket;
                        retira_elemento_fila (atendimento, pessoas_fila[i].ticket);
                        lista_insere_inicio(lista_ticket, pessoas_fila[i].ticket);
                    }
                }
            else{
                    /*printf("Pessoa ja possui mascara %d \n", pessoas_fila[i].ticket);*/
                    pop(refeicoes);
                    retira_elemento_fila (atendimento, pessoas_fila[i].ticket);
                    pessoas_fila[i].dinheiro = pessoas_fila[i].dinheiro - 1.30;
                    /*printf("Pessoa conseguiu se alimentar%d \n", pessoas_fila[i].ticket);*/
                    contabilidade_dia[i].dinheiro_refeicao = contabilidade_dia[i].dinheiro_refeicao + 1.30;
                   

                }
            }
                 
        }
    }
   
    /*printf("A ultima fila Final é: \n");*/
    /*fila_imprime(atendimento);*/
    /*printf("A ultima lista de ticket não utilizado é: \n");*/
    /*lista_imprime(lista_ticket);*/
    printf("o dinheiro total de venda de mascara foi: %.2f \n",saldo_mascara(num_pessoas, contabilidade_dia));
    printf("o dinheiro total de venda de refeicao foi: %.2f \n",saldo_refeicao(num_pessoas, contabilidade_dia));
    printf("O dinheiro total eh: %.2f \n",saldo_total(num_pessoas, contabilidade_dia));
    printf("as pessoas que não foram atendidas sao: V - Vacina D - Dinheiro");
    mostrar_razao(contabilidade_dia, num_pessoas);
   
    fila_destroi(atendimento);
    pilha_destroi(mascara);
    pilha_destroi(refeicoes);
    lista_destroi(lista_ticket);
    
    return 0;
}