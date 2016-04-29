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
void inorder(node *, struct stack_node **);
void preorder(node *,struct stack_node **);
void postorder(node *,struct stack_node **);
int rev_inorder(node *, struct stack_node **);

//Func dec for stack
int push(struct stack_node **, int );
int pop(struct stack_node**);
void display_stack(struct stack_node *);

int main(){

	int i,num,sum;
	struct stack_node *stack1 = NULL;
	struct stack_node *stack2 = NULL;
	node  *bt = NULL;
	for( i = 0; i < MAXNODE; i++){
		printf("Enter data:");
		scanf("%d",&num);
	//	printf("\n");
		insert(&bt, num);
	}
	printf("Enter the required sum value to be checked:");
	scanf("%d",&sum);
	printf("Inorder\n");
	inorder(bt,&stack1);
	printf("\nrev_inorder\n");
	rev_inorder(bt,&stack2);
	int a,b;
	for(i = 0; i < MAXNODE; i++){
		a = pop(&stack1);
		b = pop(&stack2);
		printf(" a = %d, b = %d",a,b);
		if( (a+b) == sum ) {
			printf("Sum Exists\n");
			return 0;
		}
	}
	printf("Sum does not exist");
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
inorder( node *root, struct stack_node **s1){

	if ( root != NULL ) {
		inorder(root->left, s1);
		push(s1, root->data);
		inorder(root->right, s1);
	}else{	
		return;
	}
}	
//left-right-data
void
postorder( node *root, struct stack_node **s1 ){

	if ( root != NULL ){
		postorder(root->left, s1);
		postorder(root->right, s1);
		printf(" %d ",root->data);
		push(s1,root->data);
	}else{
		return;
	}
}
//Data-left-right
void
preorder(node *root, struct stack_node **s1){

	if( root != NULL){
		printf(" %d ",root->data);
		push(s1,root->data);
		preorder(root->left, s1);
		preorder(root->right, s1);
	}else{
		return;
	}
}
//Right-data-Left
int 
rev_inorder(node *root, struct stack_node **s1){

	if ( root != NULL ) {
                rev_inorder(root->right, s1);
                push(s1,root->data);
                rev_inorder(root->left, s1);
        }else{
                return;
        }

}

int
push(struct stack_node **top, int data){
    
    struct stack_node *temp = (struct stack_node *) malloc(sizeof(struct stack_node));

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
display_stack(struct stack_node *top){

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
