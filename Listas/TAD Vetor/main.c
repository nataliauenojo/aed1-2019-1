#include <stdio.h>
#include "Vetor.h"

void testeInsercao1(){
  Vetor* v = vetor_criar();
  vetor_inserirNoFim(v, 10);
  vetor_inserirNoFim(v, 20);
  vetor_inserirNoFim(v, 30);
  vetor_inserirNoFim(v, 40);
  vetor_inserirNoFim(v, 40);
  vetor_inserirNoFim(v, 40);
  vetor_inserirNoFim(v, 40);
  
  
  vetor_imprimir(v);  // [10,20,30]
  printf("tam: %d - qtde: %d \n", v->tam, 
  v->qtde);
printf("%s \n", vetor_toString(v));
printf(" %d \n", qtdDigitos(7));

  // char* str = vetor_toString(v);
  // printf("%s \n", str); // [10,20,30] 
  // free(str); 
}

// void testeInsercao2(){
//   Vetor* v = vetor_criar();

//   vetor_inserir(v, 10, 0);
//   vetor_inserir(v, 20, 1);
//   vetor_inserir(v, 30, 2);
//   vetor_inserir(v, 5, 0);
//   vetor_inserir(v, 15, 2);
//   vetor_inserir(v, 25, 4);
  
//   vetor_imprimir(v);
//   // [5,10,15,20,25,30]
// }

// void testeRemocao1(){
//   Vetor* v = vetor_criar();
//   vetor_inserirNoFim(v, 10);
//   vetor_inserirNoFim(v, 20);
//   vetor_inserirNoFim(v, 30);
//   vetor_inserirNoFim(v, 40);
//   vetor_inserirNoFim(v, 50);

//   vetor_removerPosicao(v, 0); 
//   vetor_imprimir(v); // [20,30,40,50]
//   vetor_removerPosicao(v, 3); 
//   vetor_imprimir(v); // [20,30,40]
//   vetor_removerPosicao(v, 1); 
//   vetor_imprimir(v); // [20,40]
//   vetor_removerPosicao(v, 0); 
//   vetor_removerPosicao(v, 0); 
//   vetor_imprimir(v); // []
// }

// void testeRemocao2(){
//   Vetor* v = vetor_criar();
//   vetor_inserirNoFim(v, 10);
//   vetor_inserirNoFim(v, 20);
//   vetor_inserirNoFim(v, 30);
//   vetor_inserirNoFim(v, 40);
//   vetor_inserirNoFim(v, 50);
//   vetor_removerElemento(v, 10); 
//   vetor_imprimir(v); // [20,30,40,50]
//   vetor_removerElemento(v, 50); 
//   vetor_imprimir(v); // [20,30,40]
//   vetor_removerElemento(v, 30); 
//   vetor_imprimir(v); // [20,40]
//   vetor_removerPosicao(v, 20); 
//   vetor_removerPosicao(v, 40); 
//   vetor_imprimir(v); // []
// }



// void testePosicaoElemento(){
//   Vetor* v = vetor_criar();
//   vetor_inserirNoFim(v, 10);
//   vetor_inserirNoFim(v, 20);
//   vetor_inserirNoFim(v, 30);
  
//   printf("%d \n", vetor_posicaoElemento(v, 10)); // 0
//   printf("%d \n", vetor_getElemento(v, 0)); // 10
  
//   printf("%d \n", vetor_posicaoElemento(v, 20)); // 1
//   printf("%d \n", vetor_getElemento(v, 1)); // 20

//   printf("%d \n", vetor_posicaoElemento(v, 30)); // 2
//   printf("%d \n", vetor_getElemento(v, 2)); // 30

//   printf("%d \n", vetor_posicaoElemento(v, 100)); // -1
//   printf("%d \n", vetor_posicaoElemento(v, 50)); // -1

// int elemento =  vetor_getElemento(v, 100); //?

// }

int main(void) {
  testeInsercao1();
  // testeInsercao2();
  // testeRemocao1();
  // testeRemocao2();
  // testePosicaoElemento();


  return 0;
}