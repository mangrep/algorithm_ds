#include<stdio.h>
#include<string.h>

int xstrlen(char *);
//void xstrcpy(char *, char *);


int main(){

	char fname[] = "manish";
	char lname[] = "kumar";

	int len = xstrlen(fname);
	printf("length of %s is %d\n",fname, len);

}

int xstrlen(char *input){
	 
	int len = 0;
	while (*input){
		len++;
		input++;
	}
	return len;
}
