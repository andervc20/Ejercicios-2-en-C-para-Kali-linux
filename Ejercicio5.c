#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Padre: PID = %d\n", getpid());
    
    pid_t hijo_pid = fork();
    
    if (hijo_pid == 0) {
        printf("Hijo: PID = %d, PPID = %d\n", getpid(), getppid());
        
        pid_t nieto_pid = fork();
        
        if (nieto_pid == 0) {
            printf("Nieto: PID = %d, PPID = %d\n", getpid(), getppid());
            _exit(0);
        } else if (nieto_pid > 0) {
            wait(NULL);
            _exit(0);
        } else {
            perror("Error en fork nieto");
            return 1;
        }
    } else if (hijo_pid > 0) {
        wait(NULL);
    } else {
        perror("Error en fork hijo");
        return 1;
    }
    
    return 0;
}
