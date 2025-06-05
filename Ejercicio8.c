#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Hijo (PID: %d) en bucle infinito...\n", getpid());
        while(1) {
            sleep(1);
        }
    } else if (pid > 0) {
        printf("Padre (PID: %d) esperando 5 segundos...\n", getpid());
        sleep(5);
        printf("Enviando SIGTERM al hijo (PID: %d)\n", pid);
        kill(pid, SIGTERM);
        wait(NULL);
        printf("Hijo terminado\n");
    } else {
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}
