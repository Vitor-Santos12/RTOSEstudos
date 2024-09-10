#include "../include/TaskModule.h"
#include "../include/QueueModule.h"
#include "../include/SemaphoreModule.h"
#include "FreeRTOS.h"
#include "task.h"

TaskModule taskModule;
QueueModule queueModule;
SemaphoreModule semaphoreModule;

int main() {
    // Exemplo de uso de tarefas básicas
    taskModule.createTasks();

    // Exemplo de comunicação entre tarefas com filas
    // queueModule.createTasks();

    // Exemplo de sincronização entre tarefas com semáforo
    // semaphoreModule.createTasks();

    // Inicia o scheduler do FreeRTOS
    vTaskStartScheduler();

    // O loop principal não será utilizado
    for(;;) {}
    
    return 0;
}
