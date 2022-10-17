#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _heap 
{
	int (*comp)(int, int);//비교함수
	int numOfData;
	int heapArr[1000001];
}Heap;

void HeapInit(Heap * ph, int pc(int d1, int d2))
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int GetHiPriChildIdx(Heap * ph, int idx)
{
	if(idx*2 > ph->numOfData)
	{
		return 0;
	}
	else if(idx*2 == ph->numOfData)
	{
		return idx*2;
	}
	else
	{
		if(ph->comp(ph->heapArr[idx*2],ph->heapArr[idx*2+1]) > 0)
		{
			return idx*2;
		}
		else
		{
			return idx*2 + 1;
		}
	}
}

void HInsert(Heap * ph, int data)
{
	int idx = ph->numOfData+1;
	
	while(idx != 1)
	{
		if(ph->comp(data, ph->heapArr[idx/2]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[idx/2];
			idx = idx/2;
		}
		else 
		{
			break;
		}
	}
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

int HDelete(Heap * ph)
{
	int retData = ph->heapArr[1];
	int lastElem = ph->heapArr[ph->numOfData];
	
	int parentIdx = 1;
	int childIdx;
	
	while(childIdx = GetHiPriChildIdx(ph, parentIdx))
	{
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -=1;
	return retData;
}

int DataPriorityComp(int n1, int n2)
{
	return n1 - n2;
}

int main()
{
	int num, ans;
	int index = 0;
	int arr[11] = {0,};
	Heap heap;
	
	HeapInit(&heap, DataPriorityComp);
	
	scanf("%d", &num);
	
	while(num!=0)
	{
		arr[index] = num%10;
		index++;
		num/=10;
	}
	
	for(int i =0;i<index;i++)
	{
		HInsert(&heap, arr[i]);
	}
	
	for(int i =0;i<index;i++)
	{
		ans = HDelete(&heap);
		printf("%d",ans);
	}
	
	
	return 0;
} 