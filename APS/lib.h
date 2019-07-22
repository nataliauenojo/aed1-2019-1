/**********************************
Algoritmos e Estrutura de Dados 1
Prof. Rafael Liberato
-----------------------------------
Exercício: APS.
Alunos:Juliano Kendyi Shinohara
Natália Namie Uenojo
Data: 11/07/2019
***********************************/
#ifndef MATRIZESPARSA_H_INCLUDED
#define MATRIZESPARSA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int linha;
	int coluna;
	int valor;
	struct node *direita;
	struct node *baixo;
} Node;

typedef struct
{
	Node **linhas;  //ponteiro para o vetor cujas células são ponteiros de nós
	Node **colunas; //ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;  //Quantidade de linhas da matriz
	int numColunas; //Quantidade de colunas da matriz
} MatrizEsparsa;

//Funções auxiliares

Node *criarNode(int linha, int coluna, int valor)
{											 //função para criar um no
	Node *no = (Node *)malloc(sizeof(Node)); //alocar espaço na memoria
	no->linha = linha;						 // atribuindo os valores passado por parametro
	no->coluna = coluna;
	no->valor = valor;
	no->direita = NULL; //ponteiros vazios
	no->baixo = NULL;
}

Node *getEnderecoNode(MatrizEsparsa *m, int linha, int coluna)
{ //buscar o endereco do elemento buscado

	if (m == NULL)
		return NULL; //se a matriz esta vazia
	if (linha > m->numLinhas)
		return NULL; //se o número de linhas é maior que tem na linhas de matriz
	if (coluna > m->numColunas)
		return NULL; //se o número de colunas é maior que tem na colunas de matriz
	if (linha < 0)
		return NULL; // verificar se são numeros negativos
	if (coluna < 0)
		return NULL;

	int i = 0;					  //contador
	Node *aux = m->linhas[linha]; // auxiliar para não peder os dados da matriz e acessa-la
	if(aux==NULL) return NULL;
	while (aux->direita != NULL && i < coluna)
	{ //enquanto o ponteiro nao estiver vazio e for menor coluna
		if (aux->direita->coluna <= coluna)
		{						// quando chegar na posiçao desejada
			aux = aux->direita; //auxiliar receber a proxima posicao
		}
		i++;
	}
	return aux; //retornar o endereço
}

// Protóticos

MatrizEsparsa *criarMatriz(int qtdeLinhas, int qtdeColunas);
void inserir(MatrizEsparsa *m, int linha, int coluna, int valor);
void remover(MatrizEsparsa *m, int linha, int coluna);
int acessar(MatrizEsparsa *m, int linha, int coluna);
void imprimir(MatrizEsparsa *m);
void desalocar_matriz(MatrizEsparsa *m);

// Implementação

MatrizEsparsa *criarMatriz(int qtdeLinhas, int qtdeColunas)
{
	MatrizEsparsa *m = (MatrizEsparsa *)malloc(sizeof(MatrizEsparsa)); //alocando espaço para matriz na linha
	m->linhas = (Node **)calloc(qtdeLinhas, sizeof(Node *));		   // alocando espaço para as linha da matriz
	m->colunas = (Node **)calloc(qtdeColunas, sizeof(Node *));		   //aloca espaço para as colunas da matriz
	for (int i = 0; i < qtdeLinhas; i++)
	{ //criando matriz vazia
		m->linhas[i] = NULL;
	}
	for (int j = 0; j < qtdeColunas; j++)
	{
		m->colunas[j] = NULL;
	}
	m->numLinhas = qtdeLinhas; // atribuido o valores para quantidades de linhas e colunas
	m->numColunas = qtdeColunas;
	return m;
}

void inserir(MatrizEsparsa *m, int linha, int coluna, int valor)
{
	Node *novo;
	novo = criarNode(linha, coluna, valor); //criar um no auxiliar
	if (m->linhas[linha] == NULL)
	{ //caso esteja vazio
		m->linhas[linha] = novo;
	}
	else
	{
		Node *aux = getEnderecoNode(m, linha, coluna); //auxiliares
		if (aux->coluna == coluna)
		{ //caso a coluna for igual atribui o novo elemento
			aux->valor = novo->valor;
		}
		else
		{
			if (aux->coluna > coluna)
			{						 //caso a coluna ainda for maior
				novo->direita = aux; //auxiliar recebe a proxima posiçao
				m->linhas[linha] = novo;
			}
			else
			{
				novo->direita = aux->direita; //auxiliar recebe posiçao anterior
				aux->direita = novo;
			}
		}
	}
	if (m->colunas[coluna] == NULL)
	{ //caso esteja vazio
		m->colunas[coluna] = novo;
	}
	else
	{
		Node *aux = getEnderecoNode(m, linha, coluna); //auxiliares
		if (aux->linha == linha)
		{ //caso linha for igual para atribui o novo elemento
			aux->valor = novo->valor;
		}
		else
		{
			if (aux->linha > linha)
			{									  //caso a linha ainda for maior
				novo->baixo = m->colunas[coluna]; //auxiliar recebe a proxima posiçao
				m->colunas[coluna] = novo;
			}
			else
			{
				novo->baixo = aux->baixo; //auxiliar recebe posiçao anterior
				aux->baixo = novo;
			}
		}
	}
}

void remover(MatrizEsparsa *m, int linha, int coluna)
{

	Node *aux = getEnderecoNode(m, linha, coluna); //auxiliares
	Node *aux1;
	int x = 0;
	if(aux==NULL){
		printf("Posicao Invalida.\n");		
		return;
	}
	if (m->linhas[linha]->coluna > coluna) //
	{
		printf("Posicao Invalida.\n");
		return;
	}
	else if (m->linhas[linha]->coluna < coluna)
	{
		aux1 = m->linhas[linha];
		while (x == 0)
		{
			if (aux1->direita->coluna == coluna)
			{
				aux1->direita = aux1->direita->direita;
				x = 1;
			}
			else
			{
				aux1 = aux1->direita;
			}
		}
	}
	else if (m->linhas[linha]->coluna == coluna)
	{
		m->linhas[linha] = m->linhas[linha]->direita;
	}

	x = 0;

	if (m->colunas[coluna]->linha > linha)
	{
		printf("Posicao Invalida.\n");
		return;
	}
	else if (m->colunas[coluna]->linha < linha)
	{
		aux1 = m->colunas[coluna];
		while (x == 0)
		{
			if (aux1->baixo->linha == linha)
			{
				aux1->baixo = aux1->baixo->baixo;
				x = 1;
			}
			else
			{
				aux1 = aux1->baixo;
			}
		}
	}
	else if (m->colunas[coluna]->linha == linha)
	{
		m->colunas[coluna] = m->colunas[coluna]->baixo;
	}
	free(aux);
}

int acessar(MatrizEsparsa *m, int linha, int coluna)
{
	Node *aux = getEnderecoNode(m, linha, coluna); //auxiliar
	if (aux->coluna == coluna)
	{ //buscar a posicao desejada
		return aux->valor;
	}
	else
	{
		return 0;
	}
}

void imprimir(MatrizEsparsa *m)
{
	Node *aux;
	for (int i = 0; i < m->numLinhas; i++)
	{						//acessar as linhas
		aux = m->linhas[i]; //armazenar os dados
		for (int j = 0; j < m->numColunas; j++)
		{ //acessar as colunas;
			if (aux != NULL && j == aux->coluna)
			{							   //se caso tiver elemento estiver na coluna
				printf("%d ", aux->valor); // imprime
				aux = aux->direita;		   // auxiliar vai para proxima posicao
			}
			else
			{
				printf("%d ", 0); //imprime o zero
			}
		}
		printf("\n");
	}
}

void desalocar_matriz(MatrizEsparsa *m)
{
	for (int i = 0; i < m->numLinhas; i++)
	{
		for (int j = 0; j < m->numColunas; j++)
		{
			Node *aux = m->linhas[i]; //auxiliar para armazenar os dados da matriz
			Node *aux1;				  //auxilia para armazenar a posicao anterior
			while (aux->direita != NULL)
			{						//se a proxima posicao nao for nula
				aux1 = aux;			//auxiliar 1 recebe os dados da variavel
				aux = aux->direita; //auxiliar vai para proxima posiçao
			}
			aux1->direita = NULL; //auxiliar 1 tambem vai para proxima posicao
			free(aux);			  // limpara a auxiliar
		}
	}
	free(m);
}

#endif // MATRIZESPARSA_H_INCLUDED
