//3.1 �迭 �ȿ� �ִ� ��Ҹ� 90�� �̵���Ű��
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
	printf("======= 90 ��1 ��°=======\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("======= 90 ��2 ��°=======\n");
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