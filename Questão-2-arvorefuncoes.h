typedef struct Arvore {
    int chave;
    struct Arvore *esquerda;
    struct Arvore *direita;
} Arvore;
typedef struct {
    struct Arvore *raiz;
    int tam;
} ArVB;
Arvore* inserir(Arvore *raiz, int valor) {
    if (raiz == NULL) {
        Arvore *novo = (Arvore*) malloc(sizeof(Arvore));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if (valor < raiz->chave)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        else if (valor > raiz->chave)
            raiz->direita = inserir(raiz->direita, valor);
        return raiz;
    }
}
void imprime(Arvore *raiz) {
    if (raiz != NULL) {
        imprime(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprime(raiz->direita);
    }
}
Arvore* remover(Arvore *raiz, int item) {
    if (raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if (raiz->chave == item) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            } else {
                if (raiz->esquerda == NULL || raiz->direita == NULL) {
                    Arvore *aux;
                    if (raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                } else {
                    Arvore *aux = raiz->esquerda;
                    while (aux->direita != NULL)
                        aux = aux->direita;
                    raiz->chave = aux->chave;
                    aux->chave = item;
                    raiz->esquerda = remover(raiz->esquerda, item);
                    return raiz;
                }
            }
        } else {
            if (item < raiz->chave)
                raiz->esquerda = remover(raiz->esquerda, item);
            else
                raiz->direita = remover(raiz->direita, item);
            return raiz;
        }
    }
}
void imprimeDaDireita(Arvore *raiz) {
    if (raiz != NULL) {
        imprimeDaDireita(raiz->direita);
        printf("%d ", raiz->chave);
        imprimeDaDireita(raiz->esquerda);
    }
}
int encontrarMaiorElemento(Arvore *raiz) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return 0;
    } else {
        int maiorValor = raiz->chave;

        while (raiz->direita != NULL) {
            raiz = raiz->direita;
            if (raiz->chave > maiorValor)
                maiorValor = raiz->chave;
        }
        printf("Maior valor da árvore: %d\n", maiorValor);
        return maiorValor;
    }
}
void buscar(Arvore* raiz) {
    int valorDesejado;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorDesejado);
    if (raiz == NULL) {
        printf("Valor não encontrado na árvore.\n");
    } else if (valorDesejado == raiz->chave) {
        printf("Valor encontrado na árvore.\n");
    } else if (valorDesejado < raiz->chave) {
        buscar(raiz->esquerda);
    } else {
        buscar(raiz->direita);
    }
}
