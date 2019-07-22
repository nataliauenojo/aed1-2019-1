typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tamVetor;
    int qtde; //topo
}Pilha;

Pilha* pilha_criar(){

    Pilha*p=(Pilha*)malloc(sizeof(Pilha));
    p->tamVetor = 10;
    p->vetor=(Tipo*)calloc(10,sizeof(Tipo));
    p->qtde=0;
    return p;
}

void pilha_desalocar(Pilha* p){
    if(p->vetor==NULL)return NULL;
    free(p->vetor);
}

int pilha_push(Pilha* p, Tipo elemento){
    Tipo* aux;
    if (p->vetor==NULL){
       p->vetor=elemento;
       p->tamVetor++; 
    }
    else{
        for(int i=0;i<p->tamVetor;i++){
            aux=p->vetor;
        }
        p->tamVetor++;
        if(aux==p->vetor){
            p->vetor=aux;
        }
        else{
            p->vetor=elemento;
        }
    }
    return p;
}

Tipo* pilha_pop1(Pilha* p){
    if(p->vetor==NULL)return NULL;
    Tipo*endereco=(Tipo*)malloc(sizeof(Tipo));
    pilha_pop2(p,endereco);
    return endereco;

}

int pilha_pop2(Pilha* p, Tipo* endereco){
    if(p->vetor==NULL)return 0;
    No*aux;
    for(int i=0;i<p->tamVetor;i++){
        aux=p->vetor;
        if(i==0){
            *endereco=aux->vetor;
        }
    }
    for(int i=0;i<p->tamVetor;i++){
        p->vetor=aux+1;
    }
    free(aux);
    p->tamVetor--;
    return 1;
}

int pilha_topo(Pilha* p, Tipo* endereco){
    Tipo* endereco=(Tipo*)malloc(sizeof(Tipo));
    for(int j=0;j<p->tamVetor;j++){
        if(j==0){
            *endereco=p->vetor;
        }
    return endereco;
}

int pilha_tamanho(Pilha* p){
    int tam=0;
    for(int j=0;j<p->tamVetor;j++){
        tam++;
    }
    return tam;
}

void pilha_imprimir1(Pilha* p){
for(int j=0;j<p->tamVetor;j++){
    printf("%d",p->vetor);
}

void pilha_imprimir2(Pilha* p, void (*printElemento)(void*));