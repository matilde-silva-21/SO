#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int nfiles = 0;
	while (nfiles!=(argc-1)){
		nfiles++;
		FILE* ptr = fopen(argv[nfiles], "r");
		if(ptr==NULL) {printf("File can't be opened\n");}
		else {
			char one;
			do {
				one = fgetc(ptr);
				printf("%c", one);
			}
			while(one!=EOF);
		}
		printf("\n");
	}
	
	return 0;
}
