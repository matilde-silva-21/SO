#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// variable extended specifys if we want to print the lines or not

int phrases(bool extended, char *filename)
{   
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL)
    {
        printf("File not found!\n");
        return -1;
    }

    int size_sentence=1024, char_count = 0, line_count=0;
    char *sentence = malloc(size_sentence), c;
    bool end = false;

    if(sentence == NULL){
        fprintf(stderr, "out of memory\n");
        return -1;
    }


    while((c = fgetc(ptr)) != EOF){
        
        if(end && (c==' ' || c=='\n')) {end=false; continue;}
        
        if(char_count >= size_sentence-1){
            size_sentence += 256;
            sentence = realloc(sentence, size_sentence);
            if(sentence == NULL){

                fprintf(stderr, "out of memory\n");
                return -1;
            }
        }

        sentence[char_count++] = c;

        if(c=='!' || c=='.' || c=='?'){
            sentence[char_count++] = '\0';
            //reset the sentence array
            char_count = 0;
            end=true;
            line_count++;
            if(extended){
                printf("[%d] %s\n", line_count, sentence);
            }
        }
        
    }
    if(extended && char_count!=0) {printf("[%d] %s\n", ++line_count, sentence);}
    else {printf("%d\n", ++line_count);}
    return 0;
    
}

int main(int argc, char *argv[])
{
    if(argv[1]=="-l") {phrases(true, argv[2]);}
    else{phrases(false, argv[1]);}
    return 0;
}