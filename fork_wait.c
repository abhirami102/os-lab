#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("fork failed");
        return 1;
    }
    else if(pid==0){
        printf("child:\n");
        printf("course code\n");
    }
    else{
        wait(NULL);
        printf("parent:\n");
        printf("os lab\n");
    }
    return 0;
}
