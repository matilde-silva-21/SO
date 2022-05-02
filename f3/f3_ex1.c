#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64
int main(int argc, char* argv[]) {

//exemplo

/*char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
int result = strcmp(argv[1], argv[2]);
if (result == 0)
printf("the strings are the same\n");
else if (result < 0)
printf("%s < %s\n", argv[1], argv[2]);
else
printf("%s > %s\n", argv[1], argv[2]);
strcpy(p1, argv[1]);
strcpy(p2, argv[2]);
printf("p1 holds:%s\n", p1);
printf("p2 holds:%s\n", p2);
strcat(p1,p2);
printf("p1 holds:%s\n", p1);
strcat(p2,p1);
printf("p2 holds:%s\n", p2);
*/

//parte 1

/*
char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
strcpy(p1, argv[1]);

for(int i=0; p1[i]!='\0' ; ++i){
	if(isupper(p1[i])) {p1[i] = tolower(p1[i]);}
	else {p1[i] = toupper(p1[i]);}
}
printf("%s", p1);*/

//parte 2

/*char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
strcpy(p1, argv[1]);
char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
strcpy(p2, argv[2]);

char* found = strstr(p2, p1);

if(found) printf("String 1 is in string 2\n");
else printf("String 1 is not in string 2\n");*/

//parte 3

char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
strcpy(p1, argv[1]);
char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
strcpy(p2, argv[2]);

int count=0;

const char *tmp = p1;
while((tmp = strstr(tmp, p2)))
{
   count++;
   tmp++;
}

printf("Number of occurences: %i\n", count);


return EXIT_SUCCESS;
}
