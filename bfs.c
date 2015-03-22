#include<stdio.h>
#include<malloc.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

struct node{
	int data;
	struct node *next;
};

int visited[MAX]; //Initialize all to 0

void dfs(int start_node, struct node **graph_list){

	struct node *temp;
	visited[start_node-1] = TRUE;

	printf("%d\t",start_node);

	temp = *(graph_list + start_node - 1);
	while( temp != NULL ){
		if( visited[temp->data-1] == FALSE ){
			dfs(temp->data, graph_lis);
		}else{
			temp = temp->next;
		}
	}

}
