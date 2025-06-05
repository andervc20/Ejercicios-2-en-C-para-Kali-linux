#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t hijos[3];
    
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            printf("Hijo %d: PID = %d\n", i+1, getpid());
            sleep(3 - i); // Cada hijo duerme un tiempo diferente
            _exit(0);
        } else if (pid > 0) {
            hijos[i] = pid;
        } else {
            perror("Error en fork");
            return 1;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        int status;
        pid_t terminado = waitpid(hijos[i], &status, 0);
        printf("Hijo terminado: PID = %d\n", terminado);
    }
    
    return 0;
}
