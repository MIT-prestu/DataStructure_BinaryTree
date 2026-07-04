#include "Tree.h"



BTNode* BuyNode(BNTDataType x) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL) {
		perror("malloc fail");
		exit(-1);
	}

	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}


BTNode* BinaryTreeCreate() {
	BTNode* NodeA = BuyNode('A');
	BTNode* NodeB = BuyNode('B');
	BTNode* NodeC = BuyNode('C');
	BTNode* NodeD = BuyNode('D');
	BTNode* NodeE = BuyNode('E');
	BTNode* NodeF = BuyNode('F');


	NodeA->left = NodeB;
	NodeA->right = NodeC;
	NodeB->left = NodeD;
	NodeC->left = NodeE;
	NodeC->right = NodeF;

	return NodeA;
}


void PreOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}


	
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}


void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}


int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

int BinaryTreeLeafSize(BTNode* root){
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


int BinaryTreeLevelSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
		return 1;
	}

	return BinaryTreeLevelSize(root->left, k - 1) + BinaryTreeLevelSize(root->right, k - 1);
	
}


int BinaryTreeDepth(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	int LeftDepth = BinaryTreeDepth(root->left);
	int RightDepth = BinaryTreeDepth(root->right);

	return 1 + (LeftDepth > RightDepth ? LeftDepth : RightDepth);
}


BTNode* BinaryTreeFind(BTNode* root, BNTDataType x) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == x) {
		return root;
	}

	BTNode* leftnode = BinaryTreeFind(root->left, x);
	if (leftnode) {
		return leftnode;
	}
	BTNode* rightnode = BinaryTreeFind(root->right, x);
	if (rightnode) {
		return rightnode;
	}

	return NULL;
}



void BinaryTreeDestroy1(BTNode** root) {
	assert(root);

	BinaryTreeDestroy(&(*root)->left);
	BinaryTreeDestroy(&(*root)->right);
	free(*root);
	*root = NULL;
}

void BinaryTreeDestroy2(BTNode* root) {
	
	BinaryTreeDestroy2(root->left);
	BinaryTreeDestroy2(root->right);
	free(root);
}


void LevelOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}


	Queue q;

	QueueInit(&q);
	QueuePush(&q, root);

	while (!(IsQueueEmpty(&q))) {
		BTNode* node = QueueFront(&q);
		printf("%c ", node->data);
		QueuePop(&q);

		if (node->left) {
			QueuePush(&q, node->left);
		}
		if (root->right) {
			QueuePush(&q, node->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);
}



int main() {

	return 0;
}