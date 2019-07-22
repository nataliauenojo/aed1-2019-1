#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct no{
  T dado;
  struct no* ant;
  struct no* prox;
} No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int tam;
}Lista;

Lista* lista_cria() {
  Lista*l=(Lista*)malloc(sizeof(Lista));
  l->tam=0;
}

void lista_desaloca(Lista* l){
  No*aux;
  while(l->primeiro!=NULL){
    aux=l->primeiro;
    l->primeiro=l->primeiro->prox;
    free(aux);
  }
  free(l);
}

void lista_insere(Lista* l, T elemento, int posicao){
  No*aux;
  aux=l->primeiro;
  int count=0;
  while(aux!=NULL){
    if(posicao==count){
      aux->dado=elemento;
    }
    aux=aux->prox;
    count++;
  }
}

void lista_insere_fim(Lista* l, T elemento){
  No*aux;
  aux=l->primeiro;
  int count=0;
  while(aux!=NULL){
    if(ultimo==count){
      aux->dado=elemento;
    }
    aux=aux->prox;
    count++;
  }
}

T* lista_remove1(Lista* l, int posicao){
  if(l->primeiro==NULL)return NULL;
  T* endereco=(T*)malloc(sizeof(T));
  lista_remove2(l,posicao,endereco);
  return endereco;
}

int lista_remove2(Lista* l, int posicao, T* endereco){
  if(l->primeiro==NULL)return 0;
  No* aux;
  aux=l->primeiro;
  int count=0;
  while(aux!=NULL){
  if(count==posicao){
    *endereco=aux->dado;
    free(aux);
    return 1;
  }
  aux=aux->prox;
  count++;
  }
}

T* lista_remove_elemento(Lista* l, T elemento, int (*compara)(void*,void*));


T* lista_busca1(Lista* l, int posicao){
  if(l->primeiro==NULL)return 0;
  T*endereco=(T*)malloc(sizeof(T));
  lista_busca2(l,posicao,endereco);
  return 1;
}

int lista_busca2(Lista* l, int posicao, T* endereco){
  if(l->primeiro==NULL)return 0;
  No* aux;
  aux=l->primeiro;
  int count=0;
  while(aux!=NULL){
    if(count==posicao){
      printf("A lista contem a posição\n");
      return endereco;
    }
  }
  aux=aux->prox;
  count++;
}

}
int lista_contem(Lista* l, T elemento, int (*compara)(void*,void*));

int lista_posicao(Lista* l, T elemento, int (*compara)(void*,void*));

void lista_imprime(Lista* l){ 
  if(l->primeiro==NULL)return 0;
  No* aux;
  aux=l->primeiro;
  while(aux!=NULL){
    printf("%d\n",aux->dado);
    aux=aux->prox;
  }
}

int lista_tamanho(Lista* l){
  if(l->primeiro==NULL)return NULL;
  int tam=0;
  No* aux;
  aux=l->primeiro;
  while(aux!=NULL){
    aux=aux->prox;
    tam++;
  }
  return tam;
}



No* criarNo(T elemento){
  No* no = (No*)malloc(sizeof(No));
  no->dado = elemento;
  no->prox = no->ant = NULL;
  return no;
}

void lista_insere(Lista* l, T elemento, int posicao){
  if (l == NULL) return;
  if(posicao < 0) posicao = 0;
  if(posicao > l->qtde) posicao = l->qtde;  
  
  No* novo = criarNo(elemento);
    
  if(l->primeiro == NULL){ //LISTA VAZIA
    l->primeiro = l->ultimo = novo;    
  }else if(posicao == 0){
    novo->prox = l->primeiro;
    novo->ant = NULL;
    l->primeiro->ant = novo;
    l->primeiro = novo;
    
  }else if(posicao == l->qtde){
    // novo->prox = NULL;
    // novo->ant = l->ultimo;
    // l->ultimo->prox = novo;
    // l->ultimo = novo;
    // l->qtde++-;

    lista_insere_fim(l, elemento);
    return; //
  }else{

    No* aux = getEndereco(l, posicao-1);
    inserirDireita(aux, novo);
    // No* aux = getEndereco(l, posicao);
    // inserirEsquerda(aux, novo);
  }
  l->qtde++;
}

No* getEndereco(Lista* l, int pos){
  int i;
  No* aux = l->primeiro;
  for(i=0 ; i < pos; i++) aux = aux->prox;
  
  return aux;
}

void inserirDireita(No* referencia, No* novo){
  novo->ant = referencia;
  novo->prox = referencia->prox;

  referencia->prox->ant = novo; //novo->prox->ant = novo;
  referencia->prox = novo;

}

void inserirEsquerda(No* referencia, No* novo){
  novo->prox = referencia;
  novo->ant = referencia->ant;

  referencia->ant->prox = novo; 
  referencia->ant = novo;

}