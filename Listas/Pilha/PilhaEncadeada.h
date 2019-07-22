typedef int Tipo;

typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

typedef struct{
    No* topo;
    int qtde;
}Pilha;
 

Pilha* pilha_criar(){
    Pilha*p=(Pilha*)malloc(sizeof(Pilha));//criar pilha
    p->qtde=0;//zerar a quantidade
    return p;
}

void pilha_desalocar(Pilha* p){
    No*aux;//criar uma auxiliar
    while(p->topo!=NULL){
        aux=p->topo;//auxiliar recebe topo
        p->topo=aux->prox;// topo recebe a proxima posiçao
        free(aux);//limpar o no
    }
    free(p);//limpar a pilha
}

    int pilha_push(Pilha* p, Tipo elemento){
        No*aux;
        No*novo=(No*)malloc(sizeof(No));
        novo->dado=elemento;
        if(p->topo==NULL){
            p->topo=novo;
            p->qtde++;
        }
        else{
            aux=p->topo;
            p->topo=novo;
            novo->prox=aux;
            p->qtde++;
        }
    }

Tipo* pilha_pop1(Pilha* p){
    if(p->topo==NULL)return NULL;
    Tipo*endereco=(Tipo*)malloc(sizeof(Tipo));
    pilha_pop2(p,endereco);
    return endereco;
}
int pilha_pop2(Pilha* p, Tipo* endereco){
    if(p->topo==NULL)return 0;
    No*aux;
    aux=p->topo;
    p->topo=p->topo->prox;
    *endereco=aux->dado;
    free(aux);
    p->qtde--;
    return 1;
}

int pilha_topo(Pilha* p, Tipo* endereco){
    if (p->topo==NULL)return 0;
    No*aux;
    aux=p->topo;
    *endereco=aux->dado;
    return 1;
}

int pilha_tamanho(Pilha* p){
    if(p->topo==NULL)return 0;
    No*aux;
    int tam=0;
    aux=p->topo;
    p->topo=p->topo->prox;
    tam++;
    return tam;
}

void pilha_imprimir1(Pilha* p){
    No* aux;
    while(p->topo!=NULL){
        aux=p->topo;
        printf("%d",aux->dado);
        p->topo=p->topo->prox;
    }
}

//ponteiro de funçao
//(void*)->paramêtro
void pilha_imprimir2(Pilha* p, void (*printElemento)(void*));