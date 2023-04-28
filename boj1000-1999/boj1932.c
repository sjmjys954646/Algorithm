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
	// 동적으로 배열 선언

	for (int i = 1; i <= n; i++) //1층~N층까지 층수만큼 반복 한다
	{
		for (int j = 0; j < i; j++) //각 층수마다 index 0 부터 층수 - 1 까지 반복 (각층의 가로에 해당)
		{
			scanf("%d", &tmparr[j]); 

			if (j == 0) //해당 층의 가장 왼쪽은 바로 위에서 밖에 선택받지 못한다.
			{
				tmparr[j] = arr[j] + tmparr[j];
			}
			else if (j == i - 1) //해당 층의 가장 오른쪽은 한칸 옆 위에서 밖에 선택받지 못한다.
			{
				tmparr[j] = arr[j - 1] + tmparr[j];
			}
			else // 나머지중에서는 두 수중 더 큰 값으로 선택받는다.
			{
				tmparr[j] = max(arr[j] + tmparr[j], arr[j - 1] + tmparr[j]);
			}

			if (i == n) // 마지막층에 도달했을때 최고값을 갱신하면서 찾는다.
			{
				ans = max(tmparr[j], ans);
			}
		}
		for (int k = 0; k < n; k++) //다음 층에 대한 내용을 현재층으로 갱신시키낟.
			arr[k] = tmparr[k];
	}

	printf("%d", ans);

	free(arr);
	free(tmparr);

	return 0;
}