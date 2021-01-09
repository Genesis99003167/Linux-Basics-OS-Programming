#ifndef __STACKMUTEX_H
#define __STACKMUTEX_H


#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

void* producer(void* p);
void* consumer(void* c);

#endif
