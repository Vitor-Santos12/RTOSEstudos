#include <stdio.h>
#include "TaskModule.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

TaskModule::TaskModule() {}

void TaskModule::createTasks() {
    xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
    xTaskCreate(task2, "Task 2", 1000, NULL, 1, NULL);
}

void TaskModule::task1(void* pvParameters) {
    for(;;) {
        printf("Task 1 is running\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void TaskModule::task2(void* pvParameters) {
    for(;;) {
        printf("Task 2 is running\n");
        vTaskDelay(1500 / portTICK_PERIOD_MS);
    }
}
