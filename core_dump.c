//#include<sys/types.h>
#include<unistd.h>
void dump_core_and_terminate(void)
{
    /*
     * Alternative:
     *   char *p = NULL; *p = 0;
     */
  //  abort();
	while(1);
}
 
void dump_core_and_continue(void)
{
    pid_t child = fork();
    if (child < 0) {
        /*Parent: error*/
    }
    else if (child == 0) {
        dump_core_and_terminate(); /*Child*/
    }
    else {
        /*Parent: continue*/
    }
}

int main(){

dump_core_and_continue();
}
