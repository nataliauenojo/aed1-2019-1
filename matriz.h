#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int linha;
	int coluna;
	int valor;
	struct no* direita;
	struct no* baixo;	
}No;

typedef struct{
	No** linhas;	//ponteiro para o vetor cujas células são ponteiros de nós
	No** colunas;	//ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;	//Quantidade de linhas da matriz
	int numColunas;	//Quantidade de colunas da matriz
}Matriz;

// Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);

// Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_inserir(Matriz* m, int linha, int coluna, int valor);

// Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.
int matriz_acessar(Matriz* m, int linha, int coluna);

// Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void matriz_imprimir(Matriz* m);

// Libera toda memória alocada dinamicamente para a matriz.
void desalocar_matriz(Matriz* m);

void ler(char* arquivo, Matriz* m);

No* getEnderecoNos(Matriz* m, int linha, int coluna);

No* criarNode(int linha, int coluna, int valor);

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){

	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	m->linhas = (No**) calloc(qtdeLinhas,sizeof(No*));
	for(int i=0; i<qtdeLinhas; i++){
		m->linhas[i] = NULL;
	}
	//m->linhas = NULL;
	m->colunas = (No**) calloc(qtdeColunas,sizeof(No*));
	for(int j=0; j<qtdeColunas; j++){
		m->colunas[j] = NULL;
	}
	//m->colunas = NULL;
	/*for(int i=0; i<qtdeLinhas; i++){
		m->linhas[i] = (No*) malloc(qtdeColunas,sizeof(No));
		m->linhas[i] = NULL;
	}
	for(int j=0; j<qtdeColunas; j++){
		m->colunas[j] = (No*) malloc(sizeof(No));
		m->colunas[j] = NULL;
	}*/
	m->numLinhas = qtdeLinhas;
	m->numColunas = qtdeColunas;
	return(m);
}

No* criarNode(int linha, int coluna, int valor){
	No* n = (No*) malloc(sizeof(No));
	n->linha = linha;
	n->coluna = coluna;
	n->valor = valor;
	n->direita = NULL;
	n->baixo = NULL;
}

No* getEnderecoNo(Matriz* m, int linha, int coluna){
	
    if(m == NULL) return NULL;
    if(linha > m->numLinhas-1) return NULL;
	if(coluna > m->numColunas-1) return NULL;
    if(linha < 0) return NULL;
	if(coluna < 0) return NULL;
    
    int i = 0;
    No* aux = m->linhas[linha];
    while(aux->direita != NULL && i < coluna){
        if(aux->direita->coluna <= coluna ){
			aux = aux->direita;
				
		}
		i++;
    }
	
    return aux;
}


int matriz_inserir(Matriz* m, int linha, int coluna, int valor){

	No* novo = criarNode(linha, coluna, valor);
	
	if(m->linhas[linha] == NULL){
		m->linhas[linha] = novo;
		
		
	}
	else{
		
		
		No* aux = getEnderecoNo(m, linha, coluna);
		No* aux2 = getEnderecoNo(m, linha, aux->coluna-1);
		if(aux->coluna == coluna){
			aux->valor = novo->valor;
		}
		else{
			if(aux->coluna > coluna){
				novo->direita = aux;
				m->linhas[linha] = novo;
			}
			else{
				
				novo->direita = aux->direita;
				aux->direita = novo;
			}
			
		}
		
	}
	if(m->colunas[coluna] == NULL){
		m->colunas[coluna] = novo;
	}
	else{
		No* aux = getEnderecoNo(m, linha, coluna);
		No* aux2 = getEnderecoNo(m, aux->linha-1, coluna);
		if(aux->linha == linha){
			aux->valor = novo->valor;
		}
		else{
			if(aux->linha > linha){
				novo->baixo = m->colunas[coluna];
				m->colunas[coluna] = novo;
			}
			else{
				
				
				novo->baixo = aux->baixo;
				aux->baixo = novo;
			}
		
		}

	
		
	}
	
	
	return 1;
		
}

int matriz_acessar(Matriz* m, int linha, int coluna){
	No* aux = getEnderecoNo(m, linha, coluna);
	if(aux->coluna == coluna){
		printf("%d\n", aux->valor);
		return(aux->valor);
	}
	else{
		printf("0");
		return 0;
	}
}

void desalocar_matriz(Matriz* m){
	
	int l,c=0,i;
	for(l=0; l < m->numLinhas; l++){
		
		for(i = 0; i < m->numColunas; i++){
			// printf("%d",i);
			No* aux = m->linhas[l];
			No* aux2;
			while(aux->direita != NULL){
				
				printf("%d",l);

				printf("%d\n",i);
				printf("%d\n",c);
				printf("%d\n",aux->valor);
				aux2 = aux;
				aux = aux->direita;
				c++;
			}
			aux2->direita = NULL;
			printf("valor:%d\n",aux->valor);
			free(aux);
			// for(c = 0; c < m->numColunas; c++){	
			// 	// printf("%d\n",c);	
			// 	if(aux != NULL){
			// 		aux2 = aux;
			// 		if(aux->direita == NULL){
			// 			aux2->direita = NULL;
			// 			printf("%d",l);
			// 			printf("%d",i);
			// 			printf("%d\n",c);
			// 			free(aux2);
			// 			aux = NULL;
			// 		}
			// 		// aux2 = aux;
			// 		aux = aux->direita;
			// 	}
			// 	// else
			// 		// m->linhas[l]=NULL;
				
			// }
			
		}
			
	}
	// free(m->linhas);
	// free(m->colunas);
	// free(m);
	
	// for(int i=0; i<m->numLinhas; i++){
	// 	No* aux = m->linhas[i];
	// 	No* aux2 = aux;
	// 	while(aux2 != NULL){
	// 		while(aux2->direita != NULL){
	// 			aux2 = aux2->direita;
	// 		}
	// 		free(aux2);
	// 		aux2 = aux;
	// 	}
	// }	
}

void matriz_imprimir(Matriz* m){ 
	No* aux;
	int l,c;
	for(l=0; l < m->numLinhas; l++){
		aux = m->linhas[l];
		for(c = 0; c < m->numColunas; c++){
		//	aux = m->colunas[c];
		//	 if(aux != NULL){
		//	 	if(c == aux->coluna){
		//	 		printf("%d ", aux->valor);				
		//	 		aux = aux->baixo;
		//	 	}else{
		//	 		printf("%d ", 0);
		//	 	}
		//	 }else{
		//	 	printf("%d ", 0);
		//	 }

			
				if(aux != NULL && c == aux->coluna){
					printf("%d ", aux->valor);				
					aux = aux->direita;
				}
				else{
					printf("%d ", 0);
				}
				

		}
		printf("\n ", 0);
	}
}