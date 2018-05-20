# Boss
Тут програмки
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	int i =0;
	char c[10];
	while (c != NULL) {
		printf("(^_^):");
		scanf("%s\n",c);
		pid_t pid = fork();
		if (!pid){ //caild branch
			int rv=execlp(c,c, NULL);
			if (rv==-1){
				perror("(=_=)");
				return EXIT_FAILURE;
				exit(1);
			}
			exit(1);
		}
		// parent branch
		pid = wait(NULL);
		if (pid == -1){
			perror ("(0_0)");
			return EXIT_FAILURE;
			exit(1);
		}
	}
	return EXIT_SUCCESS;
}
