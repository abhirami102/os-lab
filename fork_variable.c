/*fork() does not share variables
It copies memory
Each process modifies its own copy
due to separate address spaces

After fork(), the parent and child run as two separate processes.
Each process gets its own copy of memory.

So the variable x is copied:

Parent has its own x
Child has its own x

When the child changes x, it changes only its copy.
When the parent changes x, it changes only its copy.

That is why the outputs are different.

One-line answer:
fork() creates separate processes with separate memory, so the same variable is copied and modified independently.*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int x;   // common variable
printf("Enter the value for x:");
scanf("%d",&x);
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        x = x + 5;
        printf("Child Process (x+5): x = %d\n", x);
    }
    else {
        // Parent process
        x = x - 5;
        printf("Parent Process (x-5): x = %d\n", x);
    }

    return 0;
}
