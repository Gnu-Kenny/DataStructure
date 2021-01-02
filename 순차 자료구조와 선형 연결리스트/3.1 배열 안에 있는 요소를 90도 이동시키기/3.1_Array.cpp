//3.1 배열 안에 있는 요소를 90도 이동시키기
#include <stdio.h>
int main()
{
	int A[5][5], B[5][5], C[5][5];
	int i, j, h, r;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			A[i][j] = (j + 1) * 2 + (i * 10);
		}
	}
	for (r = 1; r < 3; r++)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (r == 1)
				{
					h = 4 - j;
					B[i][j] = A[h][i];
				}
				else
				{
					h = 4 - j;
					A[i][j] = B[h][i];
				}
			}
		}
	}
	printf("======= 90 도1 번째=======\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("======= 90 도2 번째=======\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}