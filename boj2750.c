#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void Swap(int arr[],int aIdx, int bIdx)
{
	int temp = arr[aIdx];
	arr[aIdx] = arr[bIdx];
	arr[bIdx] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left +1;
	int high = right;
	
	while(low<=high)
	{
		while(pivot > arr[low])
		{
			low++;
		}
		
		while(pivot < arr[high])
		{
			high--;
		}
		
		if(low<=high)
			Swap(arr,low,high);
	}
	Swap(arr,left,high);
	return high;
}

void QuickSort(int arr[],int left,int right)
{
	if(left<=right)
	{
		int pivot = Partition(arr,left,right);
		QuickSort(arr,left,pivot -1);
		QuickSort(arr,pivot+1,right);
	}
}

int main()
{
	int arr[1000001];
	int T;
	
	scanf("%d", &T);
	for(int i =0;i<T;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	QuickSort(arr,0,T-1);
	
	for(int i =0;i<T;i++)
	{
		printf("%d\n",arr[i]);
	}
	
	return 0;
}