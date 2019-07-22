#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h"

void testeInsercao(){
  Pilha* p = pilha_criar();
  pilha_push(p, 10);
  pilha_push(p, 20);
  pilha_push(p, 30);
  pilha_push(p, 40);
  pilha_push(p, 50);
  pilha_imprimir1(p);
  // impressao da base para o topo
  // [50, 40, 30, 20, 10]
}

void testeRemocao1(){
  Pilha* p = pilha_criar();
  pilha_push(p, 10);
  pilha_push(p, 20);
  pilha_push(p, 30);
  int elemento = 0;  
  printf("Retorno: %d Elemento: %d \n ", pilha_pop2(p, &elemento), elemento);  
  printf("Retorno: %d Elemento: %d \n ", pilha_pop2(p, &elemento), elemento);  
  printf("Retorno: %d Elemento: %d \n ", pilha_pop2(p, &elemento), elemento);  
  if(pilha_pop2(p, &elemento) == 0) printf("Pilha vazia\n");  
  // RESULTADO ESPERADO
  // Retorno: 1 Elemento: 30 
  // Retorno: 1 Elemento: 20 
  // Retorno: 1 Elemento: 10 
  // Pilha vazia
}

void testeRemocao2(){
  Pilha* p = pilha_criar();
  pilha_push(p, 10);
  pilha_push(p, 20);
  pilha_push(p, 30);
  
  int* retorno;
  
  retorno = pilha_pop1(p);
  printf("Retorno: %p Elemento: %d \n", retorno, *retorno);
  free(retorno);

  retorno = pilha_pop1(p);
  printf("Retorno: %p Elemento: %d \n", retorno, *retorno);
  free(retorno);

  retorno = pilha_pop1(p);
  printf("Retorno: %p Elemento: %d \n", retorno, *retorno);
  free(retorno);

  retorno = pilha_pop1(p);
  if (retorno == NULL) printf("Pilha Vazia\n");

  // RESULTADO ESPERADO
  // Retorno: [ENDERECO] Elemento: 30 
  // Retorno: [ENDERECO] Elemento: 20 
  // Retorno: [ENDERECO] Elemento: 10 
  // Pilha vazia
  
}

int main(void) {
  testeInsercao();
  testeRemocao1();
  testeRemocao2();
  return 0;
}