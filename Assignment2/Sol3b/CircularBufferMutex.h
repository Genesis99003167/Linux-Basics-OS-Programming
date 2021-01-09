#ifndef __CIRCULARBUFFERMUTEX_H
#define __CIRCULARBUFFERMUTEX_H

#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

void* producer(void* p);
void* consumer(void* c);

#endif
