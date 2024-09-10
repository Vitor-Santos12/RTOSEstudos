#include <stdio.h>
#include "SemaphoreModule.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

SemaphoreModule::SemaphoreModule() {
    semaphore = xSemaphoreCreateBinary();
}

void SemaphoreModule::createTasks() {
    xTaskCreate(task1, "Semaphore Task 1", 1000, this, 1, NULL);
    xTaskCreate(task2, "Semaphore Task 2", 1000, this, 1, NULL);
    xSemaphoreGive(semaphore); // Inicializa o semáforo
}

void SemaphoreModule::task1(void* pvParameters) {
    SemaphoreModule* module = (SemaphoreModule*) pvParameters;
    for(;;) {
        if (xSemaphoreTake(module->semaphore, portMAX_DELAY)) {
            printf("Task 1 got the semaphore\n");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            xSemaphoreGive(module->semaphore); // Libera o semáforo para a próxima tarefa
        }
    }
}

void SemaphoreModule::task2(void* pvParameters) {
    SemaphoreModule* module = (SemaphoreModule*) pvParameters;
    for(;;) {
        if (xSemaphoreTake(module->semaphore, portMAX_DELAY)) {
            printf("Task 2 got the semaphore\n");
            vTaskDelay(1500 / portTICK_PERIOD_MS);
            xSemaphoreGive(module->semaphore); // Libera o semáforo para a próxima tarefa
        }
    }
}
