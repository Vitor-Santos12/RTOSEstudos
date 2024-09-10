#ifndef SEMAPHOREMODULE_H
#define SEMAPHOREMODULE_H

#include "FreeRTOS.h"
#include "semphr.h"

class SemaphoreModule {
private:
    SemaphoreHandle_t semaphore;
public:
    SemaphoreModule();
    void createTasks();
    static void task1(void* pvParameters);
    static void task2(void* pvParameters);
};

#endif
