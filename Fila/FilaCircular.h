typedef int T;

typedef struct{
    T* vetor;
    int primeiro;
    int ultimo;
    int tamanhoVet;
}Fila;

Fila* fila_criar(){
    Fila*f=(Fila*)malloc(sizeof(Fila));
    f->tamanhoVet=0;
    return f;
}

void fila_desalocar(Fila* f){
    if(p->vetor==NULL)return NULL;
    free(f->vetor);
}

int fila_inserir(Fila* f, T elemento){
    T*aux;
    T*novo=(T*)malloc(sizeof(T));
    novo->dado=elemento;
    if(f->ultimo==NULL){
        f->ultimo=novo;
        f->tamanhoVet++;
    }else{
        for(int i=0;i<p->tamanhoVet;i++){
            aux=f->vetor;
        }
        f->tamanhoVet++;
        for(int i=0;i<f->tamanhoVet;i++){
            if(i<f->tamanhoVetor){
                f->vetor=aux;
            }
            else{
                f->vetor=novo->dado;
                novo->dado=f->ultimo;
            }
        }
    }
    free(aux);
    return 1;
}

T* fila_remover1(Fila* f){
    if(f->primeiro==NULL)return NULL;
    T*endereco=(T*)malloc(sizeof(T));
    fila_remover2(f,endereco);
    return endereco;
}

int fila_remover2(Fila* f, T* endereco){
    if(f->vetor==NULL)return 0;
    T* aux;
    for(int i=0;i<tamanhoVetor;i++){
        aux=f->vetor;
        if(i=(tamanhoVetor-1)){
            *endereco=aux;
        }
    }
    f->tamanhoVet--;
    for (int j = 0; j < tamanhoVetor; j++){
        f->vetor=aux; 
    }
    return 1;
}

T* fila_primeiro(Fila* f){
    if(f->primeiro==NULL)return NULL;
    T*endereco=(T*)malloc(sizeof(T));
    *endereco=f->primeiro;
    return endereco;
}

int fila_tamanho(Fila* f){
    if(f->primeiro==NULL)return 0;
    T*aux;
    int tam=0;
    for(int i=0;i<tamanhoVetor;i++){
        tam++;
    }
    return 1;
}

int fila_contem(Fila* f, T elemento){
    if(f->vetor==NULL)return 0;
    for (int i=0; i<f->tamanhoVet;i++){
        if (f->vetor==elemento){
            return 1;
        }
    }
}

void fila_imprimir1(Fila* p){
    if(f->vetor==NULL)return 0;
    for (int i=0; i<f->tamanhoVet;i++){
        printf("%d ",f->vetor);
    }
}

void fila_imprimir2(Fila* p, void (*printElemento)(void*));