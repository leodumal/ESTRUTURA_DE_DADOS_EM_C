struct NodeF {
    int conteudo;
    struct NodeF *prox;
};
typedef struct NodeF nodeF;
int EMPTY(nodeF *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}
nodeF* ENQUEUE(nodeF *FILA, int tam) {
    nodeF *novo = (nodeF*) malloc(sizeof(nodeF));
    novo->prox = NULL;
    printf("Novo Item da fila: ");
    scanf("%d", &novo->conteudo);

     if (EMPTY(FILA)) {
        FILA->prox = novo;
    } else {
        nodeF *tmp = FILA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
    return novo;
}
void DEQUEUE(nodeF *FILA, int tam) {
    if (FILA->prox == NULL) {
        printf("Fila está vazia\n");
        return;
    } else {
        nodeF *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
    printf("\nDesenfileira com Sucesso!\n");
}
void IMPRIME(nodeF *FILA, int tam) {
    nodeF *tmp = FILA->prox;
    printf("Fila: ");
    while (tmp != NULL) {
        printf("%d ", tmp->conteudo);
        tmp = tmp->prox;
        tam++;
    }
    printf("\nTamanho da fila é de : %d",tam);
    printf("\n\n");
}
void LimparFila(nodeF *FILA) {
    if (EMPTY(FILA)) {
        printf("Fila já está vazia!\n\n");
        return;
    }
    nodeF *tmp = FILA->prox;
    while (tmp != NULL) {
        nodeF *proximo = tmp->prox;
        free(tmp);
        tmp = proximo;
    }
    FILA->prox = NULL;
    printf("Fila limpa com sucesso!\n");
}
void imprimirMaiorElemento(nodeF *FILA) {
    if (EMPTY(FILA)) {
        printf("Fila vazia!\n");
        return;
    }
    int maior = FILA->prox->conteudo;  
    nodeF *tmp = FILA->prox;
    
    while (tmp != NULL) {
        if (tmp->conteudo > maior) {
            maior = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("Maior elemento da fila: %d\n", maior);
}
void imprimirMenorElemento(nodeF *FILA) {
    if (EMPTY(FILA)) {
        printf("Fila vazia!\n");
        return;
    }
    int menor = FILA->prox->conteudo;  
    nodeF *tmp = FILA->prox;
    while (tmp != NULL) {
        if (tmp->conteudo < menor) {
            menor = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("Menor elemento da fila: %d\n", menor);
}
