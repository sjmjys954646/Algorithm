int main(void)
{
	int N;
	int i;
	int j;
	int ans=100000;
	int A=100000;
	int B=100000;
	int MAX;
	int k=0;
	
	scanf("%d", &N);
	
	if (N % 3 == 0)
	{
		A = N / 3;
		k++;
	}
	
	if (N % 5 == 0)
	{
		B = N / 5;
		k++;
	}
	
	for (i = 0;i <= 1000;i++)
	{
		for (j = 0;j <= 1667;j++)
		{
			if (N == i * 5 + j * 3)
			{
				ans = i + j;
				k++;
			}
		}
	}
	
	MAX = A;
	if (A <= B)
	{
		if (A <= ans)
		{
			MAX = A;
		}
		else if (A >= ans)
		{
			MAX = ans;
		}
	}
	else if (B <= A)
	{
		if (B <= ans)
		{
			MAX = B;
		}
		else if (B >= ans)
		{
			MAX = ans;
		}
	}
	
	if (k == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d", MAX);
	}

	return 0;
}