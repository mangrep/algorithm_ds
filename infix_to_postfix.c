#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
   int top;
   int capacity;
   int* array;
};

struct stack* createStack(int capacity){
   struct stack* root = (struct stack*)malloc(sizeof(struct stack));
   if(root == NULL){
        return NULL;
   }
   root->top = -1;
   root->capacity = capacity;
   root->array = (int *)malloc(sizeof(int) * capacity);
   return root;
}
void push(struct stack* stack , char ipChar){
     if(stack->top > stack->capacity){
        printf("Stackoverflow");
        return;
     }
     //printf("stack->top %d and (stack->top)++ is %d  \n",stack->top, (stack->top)++);
     stack->top = stack->top + 1;
     stack->array[stack->top] = ipChar;
}

char pop(struct stack* stack){
     if(stack == NULL){
       printf("Stackunderflow");
     }
     stack->top = stack->top - 1;
     return stack->array[stack->top];
}

int prefrence(char ch){
    switch(ch){
      case '+':
      case '-':
	return 1;
      case '*':
      case '/':
        return 2;
      case '^':
        return 3;
      default:
        return -1;
    }
}
void infixToPostfix(char infix[]){
    struct stack* stack = createStack(strlen(infix));
    int i = 0, k = 0;
    char postfix[50] ;
    while(infix[i] != '\0'){
     if(isalnum(infix[i])){
       postfix[k++] = infix[i];
     }else if(infix[i] == '('){
       push(stack, infix[i]);
     }else if(infix[i] == ')'){
       while(infix[i] != ')'){
         postfix[k++] = pop(stack);
       }
     }else{
        while(prefrence(infix[i]) < prefrence(stack->array[stack->top])){
          postfix[k++] = pop(stack);
        }
	push(stack, infix[i]);
     }
     i++;
    }
   while(stack->top > -1 ){
     postfix[k++] = pop(stack);
   }
   postfix[k] = '\0';
   printf("Postfix is %s.\n", postfix);
}

int main(){
    char infix[50] ;
    printf("Enter expression:");
    scanf("%s",infix);
    infixToPostfix(infix);
    return 0;
}
