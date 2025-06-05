#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void tarea_leer() {
    printf("(PID: %d) Leyendo archivo...\n", getpid());
    sleep(3);
    printf("(PID: %d) Lectura completada\n", getpid());
}

void tarea_procesar() {
    printf("(PID: %d) Procesando datos...\n", getpid());
    sleep(4);
    printf("(PID: %d) Procesamiento completado\n", getpid());
}

void tarea_guardar() {
    printf("(PID: %d) Guardando resultados...\n", getpid());
    sleep(2);
    printf("(PID: %d) Guardado completado\n", getpid());
}

int main() {
    printf("Sistema multitarea iniciado\n");
    
    pid_t hijos[3];
    char* tareas[] = {"leer", "procesar", "guardar"};
    void (*funciones[])() = {tarea_leer, tarea_procesar, tarea_guardar};
    
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            printf("Iniciando tarea '%s' (PID: %d)\n", tareas[i], getpid());
            funciones[i]();
            _exit(0);
        } else if (pid > 0) {
            hijos[i] = pid;
        } else {
            perror("Error en fork");
            return 1;
        }
    }
    
    printf("Esperando que terminen las tareas...\n");
    
    for (int i = 0; i < 3; i++) {
        waitpid(hijos[i], NULL, 0);
        printf("Tarea '%s' (PID: %d) terminada\n", tareas[i], hijos[i]);
    }
    
    printf("Todas las tareas completadas\n");
    return 0;
}
