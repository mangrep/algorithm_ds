/*Problem Statement: Find any two elements in BST such that sum of those two nodes = k. */
/* Author:Manish Kumar Choudhary
	  please report any error or suggestion to manishchoudhrary55@gmail.com
*/

#include<stdio.h>
#include<malloc.h>
#define MAXNODE 5
struct node {
	struct node *left;
	int data;
	struct node *right;
};

typedef struct node node;
void insert(node **, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);

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

void insert(node **root, int data){
	
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
void inorder( node *root ){

	if ( root != NULL ) {
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}else{	
		return;
	}
}	
//left-right-data
void postorder( node *root ){

	if ( root != NULL ){
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->data);
	}else{
		return;
	}
}
//Data-left-right
void preorder(node *root){

	if( root != NULL){
		printf(" %d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}else{
		return;
	}
}
