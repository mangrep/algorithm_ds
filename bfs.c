#include<stdio.h>
#include<malloc.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

struct node{
	int data;
	struct node *next;
};

void bfs(int vertex, struct node **grap_list){
	struct node *temp;
	visited[ vertex -1 ] = TRUE;
	printf("%d \t",vertex);
	addqueue(vertex);

	while ( isempty() == FALSE ){
		vertex = deletequeue();
	}

	
}










