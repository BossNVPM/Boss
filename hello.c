#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	char c[256];
	printf("(^_^): Hello Bro.\n");
	while (c!= NULL){
		printf("(^_^): ");
		scanf("%s",c);
		pid_t pid=fork();
		if (!pid){
			int rv=execlp(c,c, NULL);
			if (rv==-1){
				perror("(=_=)");
				return EXIT_FAILURE;
			}
		}	
		pid=wait(NULL);
		if (pid==-1){
			perror("(0_0)");
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}