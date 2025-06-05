#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            printf("Hijo %d: PID = %d\n", i, getpid());
            _exit(0);
        } else if (pid < 0) {
            perror("Error en fork");
            return 1;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }
    
    printf("Todos los hijos han terminado\n");
    return 0;
}
