#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
  int num;
  struct no* dir;
  struct no* esq;
} tNo;



/* Função que cria uma árvore */
tNo* criaArvore()
{

  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int arvoreVazia(tNo* t)
{

  return t == NULL;

}

/* Função que mostra a informação da árvore */
void mostraArvore(tNo* t){

  if(!arvoreVazia(t)){ /* se a árvore não for vazia */
    /* Mostra os elementos in-ordem */

    mostraArvore(t->esq); /* mostra a sae (subárvore à esquerda) */
    printf("%d ", t->num); /* mostra a raiz */
    mostraArvore(t->dir); /* mostra a sad (subárvore à direita) */
  }
}

/* Função que insere um dado na árvore */
void insereArvore(tNo** t, int num){

  if(*t == NULL)
  {
    *t = (tNo*)malloc(sizeof(tNo)); /* Aloca memória para a estrutura */
    (*t)->esq = NULL; /* Subárvore à esquerda é NULL */
    (*t)->dir = NULL; /* Subárvore à direita é NULL */
    (*t)->num = num; /* Armazena a informação */
  } else {
    if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      insereArvore(&(*t)->esq, num);
    }
    if(num > (*t)->num) /* Se o número for maior então vai pra direita */
    {

      insereArvore(&(*t)->dir, num);
    }
  }
}

/* Função de busca*/
int busca(tNo* t, int dado) {

    if(arvoreVazia(t)) { /* Se a árvore estiver vazia, então retorna 0 */
        return 0;
  }
    if(t->num == dado){
        return t;
    }
        busca(t->esq, dado);
    if(t->esq == NULL){
        busca(t->dir, dado);
        return t;
    }


  return t;
}

int main()
{
    tNo* t = criaArvore(); /* cria uma árvore */

    insereArvore(&t, 12);
    insereArvore(&t, 15);
    insereArvore(&t, 10);
    insereArvore(&t, 13);

    mostraArvore(t);

    if(busca(t,15)){
        printf("O numero 15 esta na arvore");
    }else{
        printf("O numero 15 nao esta na arvore");
    }



  free(t);

  return 0;
}
