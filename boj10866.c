#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int Data;
	struct Node	* next;
	struct Node * before;
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

void AddBack(Queue * pqueue, int Data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = Data;
	
	if(IsEmpty(pqueue))
	{
		pqueue->front = newNode;
		(pqueue->sizeOfData)++;
	}
	else
	{
		pqueue->back->next = newNode;
		newNode->before = pqueue->back;
		(pqueue->sizeOfData)++;
	}
		newNode->next = NULL;
		pqueue->back = newNode;
}

void AddFront(Queue * pqueue, int Data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = Data;
	
	if(IsEmpty(pqueue))
	{
		pqueue->back = newNode;
		(pqueue->sizeOfData)++;
	}
	else
	{
		pqueue->front->before = newNode;
		newNode->next = pqueue->front;
		(pqueue->sizeOfData)++;
	}
	
		newNode->before = NULL;
		pqueue->front = newNode;
}

int RemoveFront(Queue * pqueue)
{
	Node * rnode = pqueue->front;
	int rdata = pqueue->front->Data;
	
	pqueue->front = pqueue->front->next;
		
	(pqueue->sizeOfData)--;
	free(rnode);
	
	if(pqueue->front == NULL)
		pqueue->back = NULL;
	else
		pqueue->front->before = NULL;
	
	return rdata;
}

int RemoveBack(Queue * pqueue)
{

	Node * rnode = pqueue->back;
	int rdata = pqueue->back->Data;
	
	pqueue->back = pqueue->back->before;	
	
	(pqueue->sizeOfData)--;
	free(rnode);
	
	if(pqueue->back == NULL)
		pqueue->front = NULL;
	else
		pqueue->back->next = NULL;
	
	return rdata;
}

int IsEmpty(Queue * pqueue)//ºô¶§ 1 ²ËÂû¶§ 0
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



void orderFind(Queue * pqueue,char * order)//¸í·É ½ÇÇà
{
	if(strncmp("push_front",order,10) == 0)
	{	
		char str[7];
		for(int i =0;i < 7 ;i++)
		{
			str[i] = order[10+i];
		}
		AddFront(pqueue, atoi(str));
	}
	else if(strncmp("push_back",order,9) == 0)
	{	
		char str[7];
		for(int i =0;i < 7 ;i++)
		{
			str[i] = order[9+i];
		}
		AddBack(pqueue, atoi(str));
	}
	else if(strncmp("pop_front",order,9) == 0)
	{
		if(IsEmpty(pqueue))
		{
			printf("-1");
			printf("\n");
			return;
		}
		printf("%d", RemoveFront(pqueue));		
		printf("\n");
	}
	else if(strncmp("pop_back",order,8) == 0)
	{
		if(IsEmpty(pqueue))
		{
			printf("-1");
			printf("\n");
			return;
		}
		printf("%d", RemoveBack(pqueue));		
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