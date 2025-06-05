#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void mostrar_identidad(const char* quien) {
    printf("%s: PID = %d, PPID = %d\n", quien, getpid(), getppid());
}

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        mostrar_identidad("Hijo");
        _exit(0);
    } else if (pid > 0) {
        mostrar_identidad("Padre");
        wait(NULL);
    } else {
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}
