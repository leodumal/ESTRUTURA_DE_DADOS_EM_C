struct NoPILHA{
    int item;
    struct NoPILHA *prox;
};
typedef struct NoPILHA nopilha;
int vazia(nopilha *PILHA){
    if(PILHA -> prox == NULL){
        return 1;
    }else{
        return 0;
    }
}
nopilha* Empilhar(nopilha *PILHA, int tam){
    nopilha *novo=(nopilha*) malloc(sizeof(nopilha));
    novo->prox = NULL;
    printf("Novo Item: ");
    scanf("%d", &novo->item);
    if(vazia(PILHA))
        PILHA -> prox = novo;
    else{
        nopilha* tmp = PILHA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
    return novo;
}
void DESEMPILHAR(nopilha *PILHA, int tam){
    if(PILHA->prox ==NULL){
        printf("PILHA ja vazia\n\n");
        return;
    }else{
         nopilha *ultimo = PILHA->prox;
        nopilha *penultimo = NULL;
        while (ultimo->prox != NULL) {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        tam--;
    } 
     printf("\n Desempilhado com Sucesso!\n");
    }
void IMPRIMIR(nopilha *PILHA, int tam){
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
    return;
    }
    nopilha *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA:");
    while(tmp != NULL){
        printf("%3d", tmp->item);
        tmp = tmp-> prox;
        tam++;
        }
    printf("\nQtde itens PILHA: %d", tam);
    printf("\n");
}

void LimparPilha(nopilha *PILHA) {
    if (vazia(PILHA)) {
        printf("PILHA já está vazia!\n\n");
        return;
    }
    nopilha *tmp = PILHA->prox;
    while (tmp != NULL) {
        nopilha *proximo = tmp->prox;
        free(tmp);
        tmp = proximo;
    }
    PILHA->prox = NULL;
    printf("PILHA limpa com sucesso!\n");
}
void imprimirTopo(nopilha *PILHA) {
    if (vazia(PILHA)) {
        printf("PILHA vazia!\n");
        return;
    }
    nopilha *tmp = PILHA->prox;
    while (tmp->prox != NULL) {
        tmp = tmp->prox;
    }
    printf("O Topo da PILHA: %d\n", tmp->item);
}
