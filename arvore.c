#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
  int num;
  struct no* dir;
  struct no* esq;
} tNo;



/* Fun��o que cria uma �rvore */
tNo* criaArvore()
{

  return NULL;
}

/* Fun��o que verifica se uma �rvore � vazia */
int arvoreVazia(tNo* t)
{

  return t == NULL;

}

/* Fun��o que mostra a informa��o da �rvore */
void mostraArvore(tNo* t){

  if(!arvoreVazia(t)){ /* se a �rvore n�o for vazia */
    /* Mostra os elementos in-ordem */

    mostraArvore(t->esq); /* mostra a sae (sub�rvore � esquerda) */
    printf("%d ", t->num); /* mostra a raiz */
    mostraArvore(t->dir); /* mostra a sad (sub�rvore � direita) */
  }
}

/* Fun��o que insere um dado na �rvore */
void insereArvore(tNo** t, int num){

  if(*t == NULL)
  {
    *t = (tNo*)malloc(sizeof(tNo)); /* Aloca mem�ria para a estrutura */
    (*t)->esq = NULL; /* Sub�rvore � esquerda � NULL */
    (*t)->dir = NULL; /* Sub�rvore � direita � NULL */
    (*t)->num = num; /* Armazena a informa��o */
  } else {
    if(num < (*t)->num) /* Se o n�mero for menor ent�o vai pra esquerda */
    {
      /* Percorre pela sub�rvore � esquerda */
      insereArvore(&(*t)->esq, num);
    }
    if(num > (*t)->num) /* Se o n�mero for maior ent�o vai pra direita */
    {

      insereArvore(&(*t)->dir, num);
    }
  }
}

/* Fun��o de busca*/
int busca(tNo* t, int dado) {

    if(arvoreVazia(t)) { /* Se a �rvore estiver vazia, ent�o retorna 0 */
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
    tNo* t = criaArvore(); /* cria uma �rvore */

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
