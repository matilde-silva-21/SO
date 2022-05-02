#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	int marker = 1;
	struct stat info;
	while(marker!=argc){
		if (lstat(argv[marker], &info) == -1) {
			fprintf(stderr, "fsize: Can’t stat %s\n", argv[marker]);
			return EXIT_FAILURE;
		}
		printf("%s size: %d bytes, disk_blocks: %d\n",
		argv[marker], (int)info.st_size, (int)info.st_blocks);
		//como dar output da data corretamente?
		printf("%s last modification timestamp is %lli and the id of the user that owns the file is %d.\n\n", argv[marker], (long long int)info.st_mtime, (int)info.st_uid);
		marker++;
	}
	
	return EXIT_SUCCESS;

}
