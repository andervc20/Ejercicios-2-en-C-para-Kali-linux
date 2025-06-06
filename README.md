# Ejercicios-2-en-C-para-Kali-linux

10 ejercicios prácticos sobre gestión de procesos en C, desarrollados en Kali Linux. Cada ejercicio aborda conceptos fundamentales de sistemas operativos como fork(), señales, jerarquía de procesos y más.

## Lista de Ejercicios

1. **Hola desde padre e hijo**  
   Crear un programa que use fork() donde ambos procesos (padre e hijo) impriman su PID y su rol.

2. **Crear múltiples hijos**  
   El proceso padre debe crear 5 hijos en un bucle, donde cada hijo imprime su número de orden y PID. El padre espera a que todos terminen.

3. **Tiempos de ejecución**  
   Modificar el ejercicio anterior para que cada hijo espere un tiempo aleatorio (1-5 segundos) antes de terminar, observando el orden de finalización.

4. **Simulación de tareas**  
   Cada proceso hijo debe simular una tarea diferente (imprimir, copiar, descargar) mientras el padre monitorea el inicio y fin de cada una.

5. **Jerarquía de procesos**  
   Implementar una estructura padre → hijo → nieto, mostrando los PID de cada proceso en la jerarquía.

6. **Uso de getppid()**  
   Cada proceso debe identificar a su padre usando getppid(), mostrando la información con una función especializada.

7. **Esperar hijos en orden**  
   El padre crea 3 hijos y los espera individualmente usando waitpid(), mostrando el PID de cada hijo al terminar.

8. **Enviar señal de finalización**  
   Crear un hijo en bucle infinito que reciba una señal SIGTERM del padre después de 5 segundos.

9. **Manejo de señales**  
   Implementar un manejador de señales (signal handler) que capture SIGTERM y muestre un mensaje de despedida.

10. **Simulación completa**  
    Sistema multitarea con 3 hijos que simulan: lectura de archivo, procesamiento de datos y guardado de resultados, mientras el padre monitorea el progreso.
