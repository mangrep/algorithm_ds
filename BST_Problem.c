/*Problem Statement: Find any two elements in BST such that sum of those two nodes = k. */
/* Author:Manish Kumar Choudhary
	  please report any error or suggestion to manishchoudhrary55@gmail.com
*/

#include<stdio.h>
#include<malloc.h>

#define MAXNODE 5
#define SUCCESS 1
#define FAIL 0

//Node for BST
struct BST_node {
	struct BST_node *left;
	int data;
	struct BST_node *right;
};
typedef struct BST_node node;

//Node for Stack
struct stack_node {
    struct stack_node *link;
    int data;
};

//Function dec for BST
void insert(node **, int);
void inorder(node *, struct stack_node *);
void preorder(node *,struct stack_node *);
void postorder(node *,struct stack_node *);

//Func dec for stack
int push(struct stack_node **, int );
int pop(struct stack_node**);
void display(struct stack_node *);

int main(){

	int i,num;
	node  *bt = NULL;
	for( i = 0; i < MAXNODE; i++){
		printf("Enter data:");
		scanf("%d",&num);
	//	printf("\n");
		insert(&bt, num);
	}
	printf("Inorder\n");
	inorder(bt);
	printf("\nPreorder\n");
	preorder(bt);
	printf("\nPostorder\n");
	postorder(bt);
	return;

}
//Insert in bst
void
insert(node **root, int data){
	
	if ( *root == NULL ){
		*root = (node *) malloc(sizeof(node));
		(*root)->left = NULL;
		(*root)->data = data;
		(*root)->right= NULL;
		return;
	}
	
	//search the location of new node
	if( data < (*root)->data )	
		insert( &(*root)->left, data );
	else
		insert(&(*root)->right, data );

	return;
}
//left-data-right
void
inorder( node *root, struct stack_node *top ){

	if ( root != NULL ) {
		inorder(root->left);
		push();
		inorder(root->right);
	}else{	
		return;
	}
}	
//left-right-data
void
postorder( node *root, struct stack_node *top ){

	if ( root != NULL ){
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->data);
	}else{
		return;
	}
}
//Data-left-right
void
preorder(node *root, struct stack_node *top){

	if( root != NULL){
		printf(" %d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}else{
		return;
	}
}

int
push(struct stack_node **top, int data){
    
    struct stack_node *temp = (struct stack_node *) malloc(sizeof(struct node));

    if ( temp == NULL ){
        printf("Stack overflow");
        return FAIL;
    }

    temp->data = data;
    temp->link = *top;
    *top = temp;
    return SUCCESS;
}

void
display(struct stack_node *top){

    while (top != NULL){
        printf(" %d ",top->data);
        top = top->link;
    }
}

int
pop(struct stack_node **top){

	if ( *top == NULL ){
		printf("Underflow\n");
		return FAIL;
	}
	int poped = (*top)->data;
	*top = (*top)->link;
	return poped;
}
