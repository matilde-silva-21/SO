#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
	char path[256];
	
	if(getcwd(path, sizeof(path)) != NULL) {printf("%s\n", path); return EXIT_SUCCESS;}
	
	return EXIT_FAILURE;
	
}
