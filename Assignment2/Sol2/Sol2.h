#ifndef __SOL2_H
#define __SOL2_H

#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

void* producer(void* p);
void* consumer(void* c);


#endif
