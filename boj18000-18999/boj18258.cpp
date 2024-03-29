#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int Data;
	struct Node	* next;
}Node;

typedef struct Linkedlist
{
	Node * front;
	Node * back;
	int sizeOfData;
}Queue;

void Init(Queue * pqueue)	
{
	pqueue->front = NULL;
	pqueue->back = NULL;
	pqueue->sizeOfData = 0;
}

int IsEmpty(Queue * pqueue)//���� 1 ������ 0
{
	if(pqueue->front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Enqueue(Queue * pqueue, int Data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = Data;
	newNode->next = NULL;
	
	if(IsEmpty(pqueue))
	{
		pqueue->front = newNode;
		pqueue->back = newNode;
		(pqueue->sizeOfData)++;
	}
	else
	{
		pqueue->back->next = newNode;
		pqueue->back = newNode;
		(pqueue->sizeOfData)++;
	}
}

int Dequeue(Queue * pqueue)
{
	Node * rnode = pqueue->front;
	int rdata = pqueue->front->Data;
	
	pqueue->front = pqueue->front->next;
	
	(pqueue->sizeOfData)--;
	free(rnode);
	return rdata;
}



void orderFind(Queue * pqueue,char * order)//���� ����
{
	if(strncmp("push",order,4) == 0)
	{	
		char str[7];
		for(int i =0;i < 7 ;i++)
		{
			str[i] = order[4+i];
		}
		Enqueue(pqueue, atoi(str));
	}
	else if(strncmp("pop",order,3) == 0)
	{
		if(IsEmpty(pqueue))
		{
			printf("-1");
			printf("\n");
			return;
		}
		printf("%d", Dequeue(pqueue));		
		printf("\n");
	}
	else if(strncmp("size",order,4) == 0)
	{
		printf("%d",pqueue->sizeOfData);		
		printf("\n");
	}
	else if(strncmp("empty",order,5) == 0)
	{
		if(IsEmpty(pqueue))
		{
			printf("1");
			printf("\n");
		}
		else
		{
			printf("0");
			printf("\n");
		}
	}
	else if(strncmp("front",order,5) == 0)
	{
		if(IsEmpty(pqueue))
		{
			printf("-1");
			printf("\n");
			return;
		}
		printf("%d", pqueue->front->Data);	
		printf("\n");
	}
	else if(strncmp("back",order,4) == 0)
	{
		if(IsEmpty(pqueue))
		{
			printf("-1");
			printf("\n");
			return;
		}	
		printf("%d", pqueue->back->Data);
		printf("\n");
	}
}


int main()
{
	Queue queue;
	int orderNum;
	char order[10000];
	
	Init(&queue);
	
	scanf("%d",&orderNum);
	
	for(int i = 0; i < orderNum;i++)
	{
		scanf(" %[^\n]",order);
		orderFind(&queue,order);
	}
	return 0;
}