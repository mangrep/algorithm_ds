#include<stdio.h>
#include<malloc.h>

struct AdjNode{
	int vertexId;
	struct Adjnode* next; 

};

struct AdjList{
	struct AdjNode *head;//pointer to head of each node	
};

struct graph{
	int size;
	struct AdjList* array; // assume as column containing vertex
};

//creating graph
struct graph *createGraph(int numVertex){

	struct graph * g = (struct graph*)malloc(sizeof(struct graph));
	g->size = numVertex;
	g->array = (struct AdjList*)malloc(numVertex *  sizeof(struct AdjList));
	int i;
	for(i = 0; i < numVertex; i++){
		g->array[i].head = NULL;
	}
	return g; //return scalaton
}

void addEdge(struct graph *g, int src, int dest){
	
	struct AdjNode * newNode = (struct AdjNode *)malloc(sizeof(struct AdjNode));
	newNode->vertexId = src;
	newNode->next = g->array[src].head;
	g->array[src].head = newNode;
	
	struct AdjNode * newNode2 = (struct AdjNode *)malloc(sizeof(struct AdjNode));
	newNode2->vertexId = dest;
	newNode2->next = g->array[dest].head;
	g->array[dest].head = newNode2;
}

void printGraph(struct graph* g)
{
    int v;
    for (v = 0; v < g->size; ++v)
    {
        struct AdjNode* pCrawl = g->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->vertexId);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(){

    struct graph * graph1 = createGraph(10);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 0, 4);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 1, 3);
    addEdge(graph1, 1, 4);
    addEdge(graph1, 2, 3);
    addEdge(graph1, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph1);
 
    return 0;

}
