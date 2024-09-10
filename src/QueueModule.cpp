#include <stdio.h>
#include "QueueModule.h"
#include "queue.h"
#include "FreeRTOS.h"
#include "task.h"
#include <portmacro.h>

QueueModule::QueueModule() {
    queue = xQueueCreate(5, sizeof(int));
}

void QueueModule::createTasks() {
    xTaskCreate(senderTask, "Sender Task", 1000, this, 1, NULL);
    xTaskCreate(receiverTask, "Receiver Task", 1000, this, 1, NULL);
}

void QueueModule::senderTask(void* pvParameters) {
    QueueModule* module = (QueueModule*) pvParameters;
    int count = 0;
    for(;;) {
        xQueueSend(module->queue, &count, portMAX_DELAY);
        printf("Sent: %d\n", count);
        count++;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void QueueModule::receiverTask(void* pvParameters) {
    QueueModule* module = (QueueModule*) pvParameters;
    int receivedValue;
    for(;;) {
        if (xQueueReceive(module->queue, &receivedValue, portMAX_DELAY)) {
            printf("Received: %d\n", receivedValue);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
