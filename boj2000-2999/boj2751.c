#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int aIdx = left;
	int bIdx = mid +1;
	int i;
	
	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int Idx = left;
	
	while(aIdx <= mid && bIdx <= right)
	{
		if(arr[aIdx] <= arr[bIdx])
			sortArr[Idx] = arr[aIdx++];
		else
			sortArr[Idx] = arr[bIdx++];
		
		Idx++;
	}
	
	if(aIdx > mid)
	{
		for(i = bIdx;i<=right;Idx++,i++)
		{
			sortArr[Idx] = arr[i];
		}
	}
	else
	{
		for(i = aIdx;i<=mid;Idx++,i++)
		{
			sortArr[Idx] = arr[i];
		}
	}
	
	for(i=left;i<=right;i++)
	{
		arr[i] = sortArr[i];
	}
	
	free(sortArr);
}

//병합정렬 구현하기
void MergeSort(int arr[],int left,int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;
	
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);

		MergeTwoArea(arr, left, mid, right);
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
	
	MergeSort(arr,0,T-1);
	
	for(int i =0;i<T;i++)
	{
		printf("%d\n",arr[i]);
	}
	
	return 0;
}