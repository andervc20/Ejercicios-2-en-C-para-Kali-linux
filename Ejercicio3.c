#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    srand(time(NULL));
    
    for (int i = 1; i <= 5; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            int sleep_time = 1 + rand() % 5;
            printf("Hijo %d: PID = %d, durmiendo %d segundos\n", i, getpid(), sleep_time);
            sleep(sleep_time);
            printf("Hijo %d terminado\n", i);
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
