#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Queue.h"


typedef char BNTDataType;
typedef struct BinaryTreeNode {
	BNTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


typedef struct BinaryTreeNode* QDatatype;
typedef struct QueueNode {
	QDatatype data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode* phead;
	QueueNode* ptail;
}Queue;



BTNode* BinaryTreeCreate();

void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

int BinaryTreeSize(BTNode* root);

int BinaryTreeLeafSize(BTNode* root);

int BinaryTreeLevelSize(BTNode* root, int k);

int BinaryTreeDepth(BTNode* root);

BTNode* BinaryTreeFind(BTNode* root, BNTDataType x);

void BinaryTreeDestroy1(BTNode** root);
void BinaryTreeDestroy2(BTNode* root);

void LevelOrder(BTNode* root);

