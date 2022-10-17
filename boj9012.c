#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char Data;
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

void Push(Stack * pstack, char pdata)//Çª½¬
{	
	Node * newNode = (Node *)malloc(sizeof(Node));
	
	newNode->Data = pdata;
	newNode->next = pstack->cur;
	
	pstack->cur = newNode;
	(pstack->sizeOfData)++;
}

void Pop(Stack * pstack)//ÆË
{
	char rdata;
	Node * rNode = pstack->cur;
	
	pstack->cur = pstack->cur->next;
	
	free(rNode);
	(pstack->sizeOfData)--;
}

int Top(Stack * pstack)
{
	return pstack->cur->Data;
}

int Empty(Stack * pstack)
{
	if(pstack->cur == NULL)
		return 1;
	else
		return 0;
}

int VPS(Stack * pstack, char * sentence)
{	
	Init(pstack);
	
	int fin = 0;
	int len =0;
	len = strlen(sentence);
	
	for(int i =0;i<len;i++)
	{
		if(sentence[i] == '(')
		{
			Push(pstack, '(');
			fin++;
		}
		else if(sentence[i] == ')')
		{
			if(pstack->sizeOfData == 0)
				return 0;
			Pop(pstack);
			fin --;
		}
	}
	
	if(fin == 0)
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}

int main()
{
	Stack stack;
	int orderNum;
	char order[50];
	
	Init(&stack);
	
	scanf("%d",&orderNum);
	
	for(int i = 0; i < orderNum;i++)
	{
		scanf(" %[^\n]",order);
		if(VPS(&stack, order))
		{
			printf("YES");
		}
		else
		{
			printf("NO");
		}
		printf("\n");
	}
	return 0;
}