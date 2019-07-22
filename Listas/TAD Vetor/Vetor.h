#include <stdlib.h>
#include <string.h>

typedef struct vetor{
  int* array;
  int qtde;
  int tam;
}Vetor;


// Criar um vetor sem a necessidade de definir um tamanho
Vetor* vetor_criar(){
  Vetor*novo = (Vetor*) malloc(sizeof(Vetor));
  novo->array = (int*) calloc(5, sizeof(int));
  novo->qtde = 0;
  novo->tam = 5;
  return novo;
}

void verificaCapacidade(Vetor* v){
  if(v->qtde < v->tam) return;

  int novoTamanho = v->tam *2; //v->tam + 10
  int* tmp = (int*) calloc(novoTamanho, sizeof(int));

  int qtdeBytes = v->qtde * sizeof(int);
  memcpy(tmp, v->array, qtdeBytes);

  free(v->array);
  v->array = tmp;
  v->tam = novoTamanho;
}

// Destruir (desalocar) um vetor
void vetor_desalocar(Vetor* v){
  for(int i=0;i<v->tam;i++){
    free(v->array);
  }
  free(v);
}

// Inserir No fim
int vetor_inserirNoFim(Vetor* v, int elemento){
  
  verificaCapacidade(v);

  v->array[v->qtde++] = elemento;
  return 1;
}

// Inserir Em uma posição específica
int vetor_inserir(Vetor* v, int elemento, int pos){
  for(int i=0;i<v->tam;i++){
    if(v->tam==pos){
      v->array==elemento;
      return 1;
    }
  }
  return 0;
}

// Remover Por posição
int vetor_removerPosicao(Vetor* v, int pos){
  for (int i = 0; i < v->tam; i++){
    if(v->tam==pos){
      v->array=0;
      return 1;
    }
  }
  return 0;
}

// Remover Por elemento
int vetor_removerElemento(Vetor* v, int elemento){
  for(int i=0;i<v->tam;i++){
    if(v->array==elemento){
      v->array=0;
    }
  }
}

// Encontrar a posição de um elemento no vetor
int vetor_posicaoElemento(Vetor* v, int elemento){
  int pos=0;
  for(int i=0;i<v->tam;i++){
    if(v->array=elemento){
       pos=v->tam;
       return 1;
    }
  }
  return 0;
}
// Buscar um elemento dado o indice no vetor
int* vetor_getElemento(Vetor* v, int pos){
  int elem=0;
  for(int i=0;i<v->tam;i++){
    if(v->tam==pos){
      elem=v->array;
    }
  }
  return elem;
}

// Consultar quantos elementos existem no vetor
int vetor_quantidade(Vetor* v){
  int qtde=0;
  while(v->array!=NULL){
    qtde++; 
  }
}

// Imprimir o vetor no formato "[1,2,3]"
void vetor_imprimir(Vetor* v){
  int i;
  printf("[");
  for(i=0; i < v->qtde; i++){
    printf("%d",v->array[i]);
    if(i != v->qtde-1) printf(",");
  }
  printf("]\n");
}

int qtdDigitos(int n){
  int cont = 0;
  while(n > 0){
    cont++;
    n/=10;
  }
  return cont;
}

// Devolver uma string com uma representação textual do vetor ("[1,2,3]")
char* vetor_toString(Vetor* v){

  int tamanhoString = 2 + v->qtde-1 + 1;
  int i;
  for(i=0; i < v->qtde; i++){
    int elemento = v->array[i];
    tamanhoString += qtdDigitos(elemento);
  }

  char* string = (char*) calloc(tamanhoString, sizeof(char));
  
  int pos = 0;
  string[pos++] = '[';
   for(i=0; i < v->qtde; i++){
     sprintf(string + pos, "%d",v->array[i]);
     pos+= qtdDigitos(v->array[i]);
     if (i != v->qtde-1) string[pos++] = ',';
   }
   string[pos++] = ']';
   string[pos] = '\0';
  return string;





}
