#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static void handler_parent() { printf("%d: Parent received signal\n", getpid()); }
static void handler_child() { printf("%d: Child received signal\n", getpid()); }
int main(int argc, char* argv[]) {
	pid_t pid;
	int count = 0;
	if (signal(SIGUSR1, handler_parent) == SIG_ERR)
		{ /* signal error */}
	if (signal(SIGUSR2, handler_child) == SIG_ERR)
		{ /* signal error */}
	if ((pid = fork()) < 0)
		{ /* fork error */}
	else if (pid > 0) {
		kill(pid, SIGUSR2);
		while(pause()){
			if(signal(SIGUSR1, handler_parent)!=SIG_ERR){
				printf("HEY A SIGNAL\n");
				count++;
			}
			
			else{printf("Uh Oh, there was a signal error ://\n");}
			
		}
		
	} else {
		/* child’s code */
		kill(getppid(), SIGUSR1);
		//pause();
		kill(getppid(), SIGUSR1);
		//pause();
		kill(getppid(), SIGUSR1);
		pause();
	}
	
	printf("Received a total of %d signals from child\n", count);
	return EXIT_SUCCESS;
}
