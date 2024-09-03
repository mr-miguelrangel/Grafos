#include <stdio.h>
#include <stdlib.h>

typedef node *lista;

typedef struct node {
    int value;
    lista prox;
    lista ant;
} node;

void inicializa_grafo (lista *grafo, int n_vertices); // Aloca um vetor com n_vertices posições do tipo "lista"
void insere_aresta (lista *grafo, int origem, int destino); // Cria a aresta origem->destino no grafo
void insere_ordenado (lista l, int info);

int main (void) {
    int vertice_inicial, n_vertices, n_arestas, i, origem, destino;
    lista *grafo;

    scanf ("%d", &vertice_inicial);
    scanf ("%d", &n_vertices);
    scanf ("%d", &n_arestas);

    inicializa_grafo (grafo, n_vertices);

    for (i = 0; i < n_arestas; i++) {
        scanf ("%d", &origem);
        scanf ("%d", &destino);
        insere_aresta (grafo, origem, destino);
    }

    return 0;
}

void inicializa_grafo (lista *grafo, int n_vertices) {
    grafo = malloc (n_vertices * sizeof(lista));
}

void insere_aresta (lista *grafo, int origem, int destino) {
    insere_ordenado (grafo[origem], destino); // INSERE ORDENADO
}

void insere_ordenado (lista l, int info) {
    lista novo, aux; 
    
    novo = malloc (sizeof(node));
    novo->prox = novo->ant = NULL;
    novo->value = info;

    if (l == NULL)
        novo->ant = l;
    else {
        aux = l;
        
        while (aux != NULL) {
            if (aux->value < info)
                aux = aux->prox;
            else {
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
            }

            break;
        }
    }
}