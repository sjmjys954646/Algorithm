#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int C;
	int N;
	int Narr[1000];
	double avg = 0;
	double Nans[1000];
	int count = 0;
	double ans = 0;
	
	scanf("%d", &C);

	for (int j = 0;j < C;j++)
	{
		scanf("%d", &N);

		count = 0;
		avg = 0;
		for (int i = 0;i < N;i++)
		{
			Narr[i] = 0;
		}

		for (int i = 0;i < N;i++)
		{
			scanf("%d", &Narr[i]);
		}

		for (int i = 0;i < N;i++)
		{
			avg += Narr[i];
		}
		avg = (double)avg / (double)N;

		for (int i = 0;i < N;i++)
		{
			if (Narr[i] > avg)
			{
				count += 1;
			}
		}

		ans = (double)count / (double)N * (double)100;
		
		Nans[j] = ans;
	}

	for (int i = 0;i < C;i++)
	{
		printf("%.3lf%%", Nans[i]);
		printf("\n");
	}


	return 0;
}