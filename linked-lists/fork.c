#include <stdio.h>
#include <unistd.h>   // for fork()

int main() {
    int x = 2;   // you need to define x, set as example (change as needed)

    fork();

    for (int i = 0; i < x; i++) {
        if (fork() && !fork()) {
            printf("OS Mid Semester\n");
            fork();
        }
    }

    fork();
    printf("2024\n");

    return 0;
}
