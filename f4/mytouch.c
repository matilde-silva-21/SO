#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]){
	FILE* ptr = fopen(argv[1], "a+");
	if(ptr==NULL){
		mode_t newperms = (mode_t)0;
		newperms |= S_IRUSR | S_IWUSR;
		newperms |= S_IRGRP; 
		newperms |= S_IROTH;
		if (chmod(argv[1], newperms) == -1) {
			(void)fprintf(stderr, "%s: cannot chmod %s\n", argv[0], argv[2]);
			return EXIT_FAILURE;
		}	
	}
	
	else{ 
		//como mudar o tempo da ultima modificacao?
		auto ftime = std::filesystem::last_write_time(argv[1]);
		std::filesystem::last_write_time(p, NULL);
	}
	
	fclose(ptr);
	return EXIT_SUCCESS;
}
