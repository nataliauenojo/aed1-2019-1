typedef int T;

typedef struct no{
  T dado;
  struct no* ant;
  struct no* prox;
} No;

typedef struct{
  No* sentinela;
  int qtde;
}Lista;

Lista* lista_cria(){
  Lista*l=(Lista*)malloc(sizeof(Lista));
  l->qtde=0;
}

void lista_desaloca(Lista* l){
  No*aux;
  while(l->sentinela!=NULL){
    aux=l->sentinela;
    l->sentinela=l->sentinela->prox;
    free(aux);
  }
  free(l);
}

void lista_insere(Lista* l, T elemento, int posicao){
  No*aux;
  aux=l->sentinela;
  int count=0;
  while(l->sentinela!=NULL){
    if(posicao==count){
      aux->dado=elemento;
    }
    aux=aux->prox;
    count++;
    l->qtde++;
  }
}

void lista_insere_fim(Lista* l, T elemento){
  No*aux;
  aux=l->sentinela;
  while(aux!=NULL){
    aux=aux->prox;
  }
  aux->qtde++;
  aux->dado=elemento;
}

T* lista_remove1(Lista* l, int posicao){
  if(l->sentinela==NULL)return NULL;
  T*endereço=(T*)malloc(sizeof(T));
  lista_remove2(l,posicao,endereco);
  return endereço;
}

int lista_remove2(Lista* l, int posicao, T* endereco){
  if(l->sentinela==NULL)return 0;
  No*aux;
  int count=0;
  aux=l->sentinela;
  while(aux!=NULL){
    if(posicao==count){
      aux->dado=0;
      aux->qtde--;
      return 1;
    }
    aux=aux->prox;
    count++
  }
}

T* lista_remove_elemento(Lista* l, T elemento, int (*compara)(void*,void*));

T* lista_busca1(Lista* l, int posicao){

}

int lista_busca2(Lista* l, int posicao, T* endereco){
  if(l->sentinela==NULL)return 0;
  No*aux;
  int count=0;
  aux=l->sentinela;
  while(aux!=NULL){
    if(pos==count){
      printf("A lista contem o dado buscado\n");
      *endereco=aux->dado;
      return 1;
    }
    aux=aux->prox;
    count++;
  }
}

int lista_contem(Lista* l, T elemento, int (*compara)(void*,void*));
int lista_posicao(Lista* l, T elemento, int (*compara)(void*,void*));

void lista_imprime(Lista* l){
  No*aux;
  aux=l->sentinela;
  while(aux!=NULL){
    printf("%d\n",aux->dado);
    aux=aux->prox;
  }
}

int lista_tamanho(Lista* l){
  if(l->sentinela==NULL)return 0;
  No*aux;
  int tam=0;
  aux=l->sentinela;
  while(aux!=NULL){
    aux=aux->prox;
    tam++;
  }
  return 1;
}