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
	Node * cur;
	int sizeOfData;
}Stack;

void Init(Stack * pstack)//ÃÊ±âÈ­
{
	pstack->cur = NULL;
	pstack->sizeOfData = 0;
}

void Push(Stack * pstack, int pdata)//Çª½¬
{	
	Node * newNode = (Node *)malloc(sizeof(Node));
	
	newNode->Data = pdata;
	newNode->next = pstack->cur;
	
	pstack->cur = newNode;
	(pstack->sizeOfData)++;
}

int Pop(Stack * pstack)//ÆË
{
	if(pstack->sizeOfData==0)
	{
		return -1;
	}
	
	int rdata;
	Node * rNode = pstack->cur;
	
	rdata = pstack->cur->Data;
	pstack->cur = pstack->cur->next;
	
	free(rNode);
	if(pstack->sizeOfData>0)
		(pstack->sizeOfData)--;
	
	return rdata;
}

int Top(Stack * pstack)
{
	return pstack->cur->Data;
}

void orderFind(Stack * pstack,char * order)//¸í·É ½ÇÇà
{
	if(strncmp("push",order,4) == 0)
	{	
		char str[7];
		for(int i =0;i < 7 ;i++)
		{
			str[i] = order[4+i];
		}
		Push(pstack, atoi(str));
	}
	else if(strncmp("pop",order,3) == 0)
	{
		printf("%d", Pop(pstack));		
		printf("\n");
	}
	else if(strncmp("size",order,4) == 0)
	{
		printf("%d",pstack->sizeOfData);		
		printf("\n");
	}
	else if(strncmp("empty",order,5) == 0)
	{
		if(pstack->sizeOfData==0)
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
	else if(strncmp("top",order,3) == 0)
	{
		if(pstack->sizeOfData==0)
		{
			printf("-1");
			printf("\n");
		}
		else
		{	
			printf("%d",Top(pstack));
			printf("\n");
		}
	}
}

int main()
{
	Stack stack;
	int orderNum;
	char order[10000];
	
	Init(&stack);
	
	scanf("%d",&orderNum);
	
	for(int i = 0; i < orderNum;i++)
	{
		scanf(" %[^\n]",order);
		orderFind(&stack,order);
	}
	return 0;
}