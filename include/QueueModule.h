#ifndef QUEUEMODULE_H
#define QUEUEMODULE_H

#include "FreeRTOS.h"
#include "queue.h"

class QueueModule {
private:
    QueueHandle_t queue;
public:
    QueueModule();
    void createTasks();
    static void senderTask(void* pvParameters);
    static void receiverTask(void* pvParameters);
};

#endif
