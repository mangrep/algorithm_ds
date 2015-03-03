#include<stdio.h>
#include<malloc.h>
	//Node
	struct node {
		int data;
		struct node *next;
	};

	typedef struct node Node;

	//fun declaration
	void * pop(Node **);
	void push(Node **, int );
	void display(Node *);
	void del(Node *);

int main(){

	Node *top = NULL;
	push(&top,210);
	pop(&top);		
	display(top);
	del(top);
}

	void * pop(Node **t){
		if( *t == NULL){
			printf("StackUnderflow");
			return NULL;
		}

		Node *temp = *t;
		*t = temp->next;
		printf("Poped element is %d:",temp->data);
		free(temp);
		 
		
	}

	void push(Node **t, int data){
		Node * top = *t;
		Node * temp = (Node *)malloc(sizeof(Node));
			
		if(!temp){
			printf("Memory Error: Unable to create node\n");
			return ;
		}

		temp->data = data;
		temp->next = *t;
		*t = temp;  
	} 


	void display(Node *top){
		Node *temp = top;

		while( temp != NULL){
			printf(": %d :",temp->data );
			temp = temp->next;
		}

	}

	void del(Node *top){
		Node * temp =top;
		
		if( top == NULL)
			return;
		while( temp->next != NULL){
			temp = top;
			top = top->next;
			free(temp);
		}
	}
