//
// Created by 11751 on 2023/11/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_POOL_SIZE 5
#define TASK_QUEUE_SIZE 10

typedef struct {
    void (*task)(void *);
    void *arg;
} Task;

typedef struct {
    Task taskQueue[TASK_QUEUE_SIZE];
    int queueSize;
    int head;
    int tail;
    pthread_mutex_t lock;
    pthread_cond_t notEmpty;
    pthread_cond_t notFull;
} ThreadPool;

void *worker(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    while (1) {
        pthread_mutex_lock(&pool->lock);
        while (pool->queueSize == 0) {
            pthread_cond_wait(&pool->notEmpty, &pool->lock);
        }
        Task task = pool->taskQueue[pool->head];
        pool->head = (pool->head + 1) % TASK_QUEUE_SIZE;
        pool->queueSize--;
        pthread_cond_signal(&pool->notFull);
        pthread_mutex_unlock(&pool->lock);
        task.task(task.arg);
    }
}

void ThreadPoolInit(ThreadPool *pool) {
    pool->queueSize = 0;
    pool->head = 0;
    pool->tail = 0;
    pthread_mutex_init(&pool->lock, NULL);
    pthread_cond_init(&pool->notEmpty, NULL);
    pthread_cond_init(&pool->notFull, NULL);
    for (int i = 0; i < THREAD_POOL_SIZE; ++i) {
        pthread_t tid;
        pthread_create(&tid, NULL, worker, pool);
    }
}

void ThreadPoolAddTask(ThreadPool *pool, Task task) {
    pthread_mutex_lock(&pool->lock);
    while (pool->queueSize == TASK_QUEUE_SIZE) {
        pthread_cond_wait(&pool->notFull, &pool->lock);
    }
    pool->taskQueue[pool->tail] = task;
    pool->tail = (pool->tail + 1) % TASK_QUEUE_SIZE;//循环队列
    pool->queueSize++;
    pthread_cond_signal(&pool->notEmpty);
    pthread_mutex_unlock(&pool->lock);
}

void myTask(void *arg) {
    int *num = (int *)arg;
    printf("Processing task with argument: %d\n", *num);
}

/*
int main() {
    ThreadPool pool;
    ThreadPoolInit(&pool);
    for (int i = 0; i < 20; ++i) {
        Task task = {myTask, &i};
        ThreadPoolAddTask(&pool, task);
    }
    // 等待所有任务完成
    // ...
    return 0;
}*/