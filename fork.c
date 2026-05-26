#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
 pid_t pid;
 pid=fork();
 if(pid<0){
     perror("fork failed!");
     return 1;

}
    else if(pid==0){
        printf("child process:\n");
        printf("child pid:%d\n",getpid());
        printf("parent pid:%d\n", getppid());

    }
    else{
        printf("Parent process:\n");
        printf("child pid:%d\n",pid);
        printf("parent pid:%d\n",getpid());
    }
    sleep(300);
    return 0;

}

/*Basic fork
 * run cheyyande: gcc fork.c -o fork
 * ./fork
 * then next terminal pstree -p parentpid
