typedef int T;

typedef struct no{
    T* dado;
    struct no* prox;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Fila;

Fila* fila_criar(){
    Fila* f=(Fila*)malloc(sizeof(Fila));
    f->qtde=0;
    return f;
}

void fila_desalocar(Fila* f){
    No* aux;
    if(f->primeiro!=NULL){
        aux=f->primeiro;
        f->primeiro=aux->prox;
        free(aux);
    }
    free(f);
}

int fila_inserir(Fila* f, T elemento){
    No*aux;//para não perder os dados da fila original
    No*novo=(No*)malloc(sizeof(No));//armazenar o elemento
    novo->dado=elemento;
    if(f->ultimo==NULL){
        f->ultimo=novo;
        f->qtde++;
    }else{
        aux=f->ultimo;//armazenar o valor do ultimo elemento da fila
        f->ultimo=novo;
        aux->prox=f->ultimo;
        f->qtde++;
    }
}

T* fila_remover1(Fila* f){
    if(f->primeiro==NULL)return NULL;
    T*endereco=(T*)malloc(sizeof(T));
    fila_remover2(f,endereco);
    return endereco;
}

int fila_remover2(Fila* f, T* endereco){
    if(f->primeiro==NULL)return 0;
    No* aux;
    aux=p->ultimo;
    p->ultimo=(p->ultimo)-1;
    *endereco=aux->dado;
    free(aux);
    p->qtde--;
    return 1;
}

T* fila_primeiro(Fila* f){
    if(f->primeiro==NULL)return NULL;
    T*endereco=(T*)malloc(sizeof(T));
    No*aux;
    aux=f->primeiro;
    *endereco=aux->dado;
    return endereco;
}

int fila_tamanho(Fila* f){
    if(f->primeiro==NULL)return 0;
    No*aux;
    int tam=0;
    while(f->primeiro!=NULL){
        aux=f->primeiro;
        f->primeiro=f->primeiro->prox;
        tam++;
    }
    return 1;
}

int fila_contem(Fila* f, T* elemento){
    if(f->primeiro==NULL)return 0;
    No* aux;
    while (f->primeiro!=NULL){
        aux=f->primeiro;
        if (aux->dado==(*elemento)){
            return 1;
        }
        else{
            p->primeiro=p->primeiro->prox;
        }
    }
}

void fila_imprimir1(Fila* p){
    if(f->primeiro==NULL)return 0;
    No*aux;
    while(f->primeiro!=NULL){
        aux=f->primeiro;
        printf("%d",aux->dado);
        f->primeiro=f->primeiro->prox;
    }
}

void fila_imprimir2(Fila* p, void (*printElemento)(void*));