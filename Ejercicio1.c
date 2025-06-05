#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Hijo: PID = %d\n", getpid());
    } else if (pid > 0) {
        printf("Padre: PID = %d\n", getpid());
    } else {
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}
