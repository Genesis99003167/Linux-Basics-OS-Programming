#ifndef __SEMAPHORESTACK_H
#define __SEMAPHORESTACK_H


#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>


void* producer(void* pro);
void* consumer(void* con);

#endif
