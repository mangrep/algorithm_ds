#include<stdio.h>

struct node {
	int value;
	struct node *next;
};

//adding node in stack
struct node * add(struct node *head, int data){

	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->next = head;
	temp->value = data;
	return temp;
}

void depth_first_search(struct node *list[], int parent[], int vertex, int status[] ){
	
	if (parent[vertex] != -1){  //Un-Visited node
		struct node *temp = parent[vertex];
		status[vertex] = 1; // mark visited
		
		while(temp != NULL){
			if( parent[temp->value] == -1){
				parent[temp->next] = vertex;
				depth_first_search(list, parent, temp->value, status);
			}else{
				if(status[temp->val] == 1)
					printf("\n%d ---> %d is a Backward Edge\n", vertex, temp->val);
			}
			temp = temp->next;		
		}

		status[vertex] = 0;
	}
}
