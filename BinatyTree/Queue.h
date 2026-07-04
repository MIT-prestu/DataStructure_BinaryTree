#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int QDatatype;
typedef struct QueueNode {
	QDatatype data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode* phead;
	QueueNode* ptail;
}Queue;


void QueueInit(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDatatype x);

void QueuePop(Queue* pq);

QDatatype QueueFront(Queue* pq);

int QueueSize(Queue* pq);

