#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h> 
int main(int argc, char* argv[]) {
printf("%d\n",getpid());
/* fork a child process */
fork();
/* fork another child process */
fork();
/* and fork another */
fork();
printf("%d\n", getpid());
return EXIT_SUCCESS;
}

//sempre que chamo fork divide o processo original em dois tipo uma binary tree
