#include "Queue.h"


void QueueInit(Queue* pq) {
	assert(pq);

	pq->phead = pq->ptail = NULL;
}


void QueueDestroy(Queue* pq) {
	assert(pq);

	QueueNode* pcur = pq->phead;
	QueueNode* next = NULL;
	while (pcur) {
		next = pcur->next;
		free(pcur);
		pcur = next;
	}

	pq->phead = pq->ptail = NULL;
}

void QueuePush(Queue* pq, QDatatype x) {
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL) {
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->phead == NULL) {
		pq->phead = pq->ptail = newnode;
	}
	else {
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	
}

void QueuePop(Queue* pq) {
	assert(pq && pq->phead);

	if (pq->phead->next == NULL) {
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else {
		QueueNode* del = pq->phead;
		pq->phead = pq->phead->next;
		free(del);
		del = NULL;
	}
	
}

QDatatype QueueFront(Queue* pq) {
	assert(pq && pq->phead);

	return pq->phead->data;
}


int QueueSize(Queue* pq) {
	assert(pq);

	int count = 0;
	QueueNode* pcur = pq->phead;
	while (pcur) {
		count++;
		pcur = pcur->next;
	}

	return count;
}
