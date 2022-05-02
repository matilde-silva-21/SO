#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 

int main(int argc, char* argv[]){
	
	FILE* ptr1 = fopen(argv[1], "r");
	FILE* ptr2 = fopen(argv[2], "w+");
	char ch;
	if(ptr1!=NULL && ptr2!=NULL){
	while(ch!=EOF){
		ch = fgetc(ptr1);
		if(ch==EOF) break;
		fputc(ch, ptr2);
	}
	}
	
	else{printf("File couldn't be open\n");}
	fclose(ptr1);
	fclose(ptr2);
	
	return 0;
}
