#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  

int main(void) 
{
	int n;//�Է¹�����
	int k;
	int i;//���° ���� �ΰ�
	int j;//���� �ȿ��� ���°�ΰ�

	scanf("%d", &n);
	
	for ( i = 1;;i++)
	{
		if (n >  i*(i - 1)/2  && n <= i * (i + 1) / 2)
		{
			break;
		}
	}

	k = (i*(i + 1)) / 2 - n;
	j = i - k;

	if (n == 1)
	{
		printf("1/1");
	}
	else if (i % 2 == 0)
	{
		printf("%d/%d", j, i - j+1);
	}
	else
	{
		printf("%d/%d", i-j+1, j);
	}



	return 0;
}