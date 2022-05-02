#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char* argv[]){

	char* mod = argv[1];
	if(!strcmp(mod,"-u")){
		FILE* ptr = fopen(argv[2],"r");
		if(ptr==NULL) {printf("File can't be opened\n");}
		else {
			char one;
			do {
				one = fgetc(ptr);
				printf("%c",toupper(one));
			}
			while(one!=EOF);
		}
		
	}
	
	else if(!strcmp(mod,"-l")){
		FILE* ptr = fopen(argv[2],"r");
		if(ptr==NULL) {printf("File can't be opened\n");}
		else {
			char one;
			do {
				one = fgetc(ptr);
				printf("%c",tolower(one));
			}
			while(one!=EOF);
		}
	}
	
	else {
		FILE* ptr = fopen(argv[1],"r");
		if(ptr==NULL) {printf("File can't be opened\n");}
		else {
			char one;
			do {
				one = fgetc(ptr);
				printf("%c",one);
			}
			while(one!=EOF);
		}
	}
	
	return 0;
}
