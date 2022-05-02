#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

/*falta ler a diretoria direito mas depois é so usar struct stat e dar output as informacoes pretendidas*/
int main (int argc, char** argv) {
	int n = 1;
	struct dirent *p;
	DIR *q;
	while(n!=argc){
		q = opendir (argv[n]);
		if (q == NULL) {
			fprintf (stderr, "%s: Cannot open directory ’%s’\n",
			argv[0], argv[n]);
			return EXIT_FAILURE;
		}
		printf ("%s/\n", argv[n]);
		p = readdir(q);
		while (p != NULL) {
			printf ("\t%s\n", p->d_name);
			p = readdir(q);
		}
		closedir (q);
		n++;
	}
	
	return EXIT_SUCCESS;
}
