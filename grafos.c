#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BRANCO 0;
#define AMARELO 1;
#define VERMELHO 2;

typedef struct adj{

    int vertice;
    int peso;
    struct adj *prox;

}Adjacencia;

typedef struct ver{
    int id;
    int cor;
    Adjacencia *cab;

}Vertice;

typedef struct grafo{
    int vertices, arestas;
    Vertice *adj;
}Grafo;

Grafo* CriaGrafo(int v){

    Grafo* g = malloc(sizeof(Grafo));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (Vertice*) malloc(v*sizeof(Vertice));
    int i;
    for(i=0;i<v;i++){
        g->adj[i].cab = NULL;
        g->adj[i].id = i;
    }
    return g;    

};

Adjacencia* CriaAdj(int v,int peso){
    Adjacencia* temp = (Adjacencia*) malloc(sizeof(Adjacencia));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
};

int Cria_Aresta(Grafo* gr, int vi, int vf, int peso){

    if(!gr) return 1;

    if((vf < 0) || (vf >= gr->vertices)) return 1;

    if((vi < 0) || (vi >= gr->vertices)) return 1;    


    Adjacencia* novo = CriaAdj(vf,peso);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;

    return 0;

};


void DFS(Vertice* vi, int target, int* found){

        vi->cor = AMARELO;
      
        if(vi->id == target){
            *found = 1;
            return;

        }
        Vertice* p = vi.cab;

        while(!p){
            DFS(p,target,found);
            if(!found) p = NULL;
            p = p->prox;
        }

        vi->cor = VERMELHO;
        
}


void imprime(Grafo* gr){

    printf("O grafo contém %d arestas e %d vértices.\n",gr->arestas,gr->vertices);

    int i;

    for(i=0; i<gr->vertices;i++){

        if(gr->adj[i].cab)
        printf("Vértice nº%d: \n",i);

        Adjacencia* adj = gr->adj[i].cab;
        while(adj){
            printf("Ligado ao vértice %d com peso %d.\n",adj->vertice,adj->peso);
            adj = adj->prox;
        }
    }

};

int main(){

    int vert = 6;

    Grafo* gr = CriaGrafo(vert);

    Cria_Aresta(gr,0,2,3);
    Cria_Aresta(gr,1,4,2);
    Cria_Aresta(gr,1,3,1);
    Cria_Aresta(gr,5,1,2);
    Cria_Aresta(gr,4,0,2);

    imprime(gr);

    return 0;
}