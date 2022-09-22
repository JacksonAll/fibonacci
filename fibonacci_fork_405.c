#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fibonacci(int a){
    if (a == 0){
            return 0;
    }
    else if(a == 1) 
        
        return 1; 
        
    else{
            return ( fibonacci(a-1) + fibonacci(a-2) );
}
}



int main()
{
	pid_t  pid;
    int input;

	/* fork another process */
	pid = fork();
	if (pid < 0) {
		/* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) {
		/* child process */
		//execlp("/bin/ls", "ls", NULL);
        printf("enter your integer for fibonacci!!\n");
        scanf("%d", &input);
        
        for(int i = 1; i <= input; i++){
            
           printf("%d \n",fibonacci(i));
           
            }
        
     //printf("%d", fibonacci(input));

	}
	else {
		/* parent process */
		/* parent will wait for the child to complete */

		wait (NULL);
		printf ("\n Child Complete \n");
		exit(0);
	}
}

