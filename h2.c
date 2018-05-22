#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/unistd.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
int main()
{
	printf("(^_^): Hello Bro.\n"); 
	//начало работы        
	while (TRUE){					 	
		//переменные
		char c[256], c1[256], c2[256];
		char a;		  
		int i,k,n, idsim,n1,n2,idsim1;
		char *name1 = NULL; 
		char *name2= NULL;
		i=0;
		idsim=0;
		idsim=0;
		//считывание вызова
		printf("(^_^): ");
 		while ((a=getchar()) != 10){
 			c[i]=a;
 			++i;
 		} 		
 		//создание дочернего процесса
		pid_t pid=fork();
		if (!pid){
			k=i;
      		n=0;
      		//вызов echo
			if (c[0]=='e' && c[1]=='c'){
        		for (i=0; i<k; ++i){
            		if (c[i]=='>'){
              			idsim=i;
               			break;
            		}
         		}
        		 //если есть >
         		if (idsim != 0){
           			for(i=5; i<(idsim); ++i){
                		c1[n]=c[i];
               			++n;
           			}
            		n2=n;
            		n=0;
            		for(i=(idsim+1); i<k; ++i){
                		c2[n]=c[i];
                		++n;
            		}
            		name1=c2;
            		int f1=open( name1, O_WRONLY | O_CREAT | O_TRUNC, 0666);
            		write(f1, &c1, n2);
            		close(f1);
            		printf("(^_^): Fail creat/added\n");
         		}
         		//если нет >   
         		else {
               		for(i=5; i<k; ++i){
                  		c1[n]=c[i];
                  		++n;
               		}
               		printf("%s\n", c1);
         		}    
      		}
			else if (c[0]=='c' && c[1]=='a' && c[2]=='t')
			{
				for (i=0; i<k; ++i){
         if (c[i]=='<'){
            idsim=i;
            break;
         }
      }
      for (i=0; i<k; ++i){
         if (c[i]=='>'){
            idsim1=i;
            break;
         }
      }
      if (idsim != 0 && idsim1 !=0){
                  n=0;
                  for(i=(idsim+1); i<idsim1; ++i){
                     c1[n]=c[i];
                     ++n;
                  }
                  name1=c1;
                  n=0;
                  for(i=(idsim1+1); i<k; ++i){
                     c2[n]=c[i];
                     ++n;
                  }
                  name2=c2;
                  int f1=open( name1, O_RDONLY, 0666);
                  int f2=open( name2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                  while ((n1=read(f1,c,256))>0){
                        write(f2,c,n1);
                  printf("(^_^): Copying was successful\n");
                  }
               }
      else{ //и другое...
         for(i=4; i<k; ++i){
         c2[n]=c[i];
         ++n;
      }
      name1=c2;
      int f1=open( name1, O_RDONLY, 0666);
      while ((n1=read(f1,c1,256))>0){
         write(0,c1,n1);
      }
      printf("\n");
      }
			}  //другие вызовы				
			else{
					int rv=execlp(c,c, NULL); 
				}   
			n=0;
		}
		pid=wait(NULL);
		memset(c,0,256);
		memset(c1,0,256);
		memset(c2,0,256);				
	}
	return EXIT_SUCCESS;
}