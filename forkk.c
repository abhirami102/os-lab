//to create multiple child process under a same parent.

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Main Parent PID: %d\n\n", getpid());

    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            // Inside the child process
            printf("Child %d [PID: %d] -> Parent [PID: %d]\n", i + 1, getpid(), getppid());
            return 0;
        }
    }

    return 0;
}
