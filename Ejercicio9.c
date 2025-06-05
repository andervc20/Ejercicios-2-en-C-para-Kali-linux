#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Recibida señal %d. Adiós mundo cruel...\n", sig);
    exit(0);
}

int main() {
    signal(SIGTERM, handler);
    
    printf("Proceso (PID: %d) esperando señal...\n", getpid());
    
    while(1) {
        sleep(1);
    }
    
    return 0;
}
