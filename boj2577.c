#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  

int main()
{
	int A, B, C, Result;
	int arr[10] = {0,};//0-9���� ��� ������
	int ans;//�� �ڸ����� �ӽ�����
	int num = 0;//���ڸ��� ����Ȯ��
	int temp;//num�� �ӽ�����

	scanf("%d %d %d", &A, &B, &C);

	Result = A * B * C;
	temp = Result;

	while (Result > 0)
	{
		num++;
		Result /= 10;
	}
	Result = temp;
	for (int i = 0;i < num;i++)
	{
		ans = Result % 10;
		arr[ans] += 1;
		Result /= 10;
	}	
	
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);

	
	return 0;
}