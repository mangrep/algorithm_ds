#include<stdio.h>
#include<string.h>

struct infix {
	char target[MAX];
	char stack[MAX];
	char *s, *t;
	int top, l;

};

typedef struct infix Infix;

void convert(Infix *);

Int main(){

return 0;
}

//convert infix to prefix
void convert(Infix * infixexpr){
	char opr;
	while(*(infixexpr->s)){
		if (*(infixexpr->s) == '' || *(infixexpr->s) == '\t'){
			infixexpr->s++;
			continue;
		}		
			
		if( isdigit(*(infixexpr->s)) || isalpha(*(infixexpr->s)) ){
			while(isdigit(*(infixexpr->s))){
				*(infixexpr->t) = *(infixexpr->	
			}
		}	
	}
}
