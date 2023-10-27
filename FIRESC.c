#include <stdio.h>
#include <stdlib.h>
int qtd_global[10001];
int k=0;

typedef struct vertice
{
    int visitado;
    struct lista *lista_adj;
} vertice;

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;
int carrega_grafo(vertice *vertices, char *nome_do_arquivo)
{
    FILE *arq;
    arq = fopen(nome_do_arquivo, "r");
    int a, b, c;
    int qtd_vertices=0;

    int i;

    for(i=0;i<10001;i++)
    {
        qtd_global[i] =0;
    }

    if (arq == NULL)
    {
        printf("\n Arquivo nao localizado");
        return 0;
    }
    if(fscanf(arq, "%d", &c) != fscanf(arq, "%d;%d\n", &a, &b) )
    {
        k = c;
    }

    while (fscanf(arq, "%d;%d\n", &a, &b) != EOF)
    {
        printf("\n A: %d B: %d", a, b);

        if (qtd_global[a]==0)
            qtd_vertices++;
            qtd_global[a] = 1;

        if (qtd_global[b]==0)
            qtd_vertices++;
            qtd_global[b] = 1;

        push(&vertices[a], b);
        push(&vertices[b], a);
    }

    return qtd_vertices;
}
