#ifndef TASKMODULE_H
#define TASKMODULE_H

class TaskModule {
public:
    TaskModule();
    void createTasks();
    static void task1(void* pvParameters);
    static void task2(void* pvParameters);
};

#endif
