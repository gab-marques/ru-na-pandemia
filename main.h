
struct Pessoa{
        int ticket; 
        int vacinado; /*0 - nao, 1 - sim*/
        int mascara; /*0 - nao, 1 - sim*/
        float dinheiro;

    };
    typedef struct Pessoa Pessoa;

struct contabilidade{
    float dinheiro_total;
    float dinheiro_refeicao;
    float dinheiro_mascara;
    int ticket;
    char razao;
}; 
typedef struct contabilidade contabilidade;