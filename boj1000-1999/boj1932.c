#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x, y) (x) > (y) ? (x) : (y)


int main()
{
	int n;
	int* arr;
	int* tmparr;
	int ans = -1;
	scanf("%d", &n);

	arr = malloc(sizeof(int) * n);
	tmparr = malloc(sizeof(int) * n);
	// �������� �迭 ����

	for (int i = 1; i <= n; i++) //1��~N������ ������ŭ �ݺ� �Ѵ�
	{
		for (int j = 0; j < i; j++) //�� �������� index 0 ���� ���� - 1 ���� �ݺ� (������ ���ο� �ش�)
		{
			scanf("%d", &tmparr[j]); 

			if (j == 0) //�ش� ���� ���� ������ �ٷ� ������ �ۿ� ���ù��� ���Ѵ�.
			{
				tmparr[j] = arr[j] + tmparr[j];
			}
			else if (j == i - 1) //�ش� ���� ���� �������� ��ĭ �� ������ �ۿ� ���ù��� ���Ѵ�.
			{
				tmparr[j] = arr[j - 1] + tmparr[j];
			}
			else // �������߿����� �� ���� �� ū ������ ���ù޴´�.
			{
				tmparr[j] = max(arr[j] + tmparr[j], arr[j - 1] + tmparr[j]);
			}

			if (i == n) // ���������� ���������� �ְ��� �����ϸ鼭 ã�´�.
			{
				ans = max(tmparr[j], ans);
			}
		}
		for (int k = 0; k < n; k++) //���� ���� ���� ������ ���������� ���Ž�Ű��.
			arr[k] = tmparr[k];
	}

	printf("%d", ans);

	free(arr);
	free(tmparr);

	return 0;
}