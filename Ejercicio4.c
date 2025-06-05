#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void realizar_tarea(int num_hijo) {
    switch(num_hijo) {
        case 1:
            printf("Hijo %d: Imprimiendo...\n", num_hijo);
            sleep(2);
            break;
        case 2:
            printf("Hijo %d: Copiando archivos...\n", num_hijo);
            sleep(3);
            break;
        case 3:
            printf("Hijo %d: Descargando datos...\n", num_hijo);
            sleep(4);
            break;
        case 4:
            printf("Hijo %d: Procesando información...\n", num_hijo);
            sleep(1);
            break;
        case 5:
            printf("Hijo %d: Guardando resultados...\n", num_hijo);
            sleep(2);
            break;
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            printf("Iniciando tarea %d (PID: %d)\n", i, getpid());
            realizar_tarea(i);
            printf("Tarea %d completada\n", i);
            _exit(0);
        } else if (pid < 0) {
            perror("Error en fork");
            return 1;
        }
    }
    
    printf("Esperando que terminen las tareas...\n");
    
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }
    
    printf("Todas las tareas completadas\n");
    return 0;
}
