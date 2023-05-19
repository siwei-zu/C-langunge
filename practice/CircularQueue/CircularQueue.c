#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>

typedef struct {
    int front;
    int rear;
    int* a;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->rear == obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->front = obj->rear = 0;
    obj->k = k;
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!myCircularQueueIsFull(obj))
    {
        obj->a[obj->rear] = value;
        obj->rear = (obj->rear + 1) % (obj->k + 1);
        return true;
    }
    else
        return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!myCircularQueueIsEmpty(obj))
    {
        obj->front = (obj->front + 1) % (obj->k + 1);
        return true;
    }
    else
        return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (!myCircularQueueIsEmpty(obj))
    {
        return obj->a[obj->front];
    }
    else
        return -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (!myCircularQueueIsEmpty(obj))
    {
        if (obj->rear == 0)
            return obj->a[obj->k];
        else
            return obj->a[obj->rear - 1];
    }
    else
        return -1;
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    obj->front = obj->k = obj->rear = 0;
    free(obj);
}