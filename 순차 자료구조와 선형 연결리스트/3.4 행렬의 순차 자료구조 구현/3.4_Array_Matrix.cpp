//3.4 ����� ���� �ڷᱸ�� ���� <��� ��� �����>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row; // ���� ��Ÿ���� ����
    int col; // ���� ��Ÿ���� ����
    int value; // ��� ���� ���� ��Ÿ���� ����
} SprsMtrx; //��� ����� ��Ÿ���� ����ü
SprsMtrx* smCreate(int A[][7], int row, int col, int* cnt) /*�Լ� ȣ�� �迭A, ���� ũ
��, ���� ũ��, cnt�� ũ�⸦ �Ű������� ����.*/
{
    int i, j;
    SprsMtrx* S; //����ü ��ü ����
    for (j = 0; j < row; j++) //���� ũ�⸸ŭ for�� ����
    {
        for (i = 0; i < col; i++) // ���� ũ�⸸ŭ for�� ����
        {
            if (A[j][i]) /*A[0][0]~A[row-1][col-1]���� �����Կ� ���� cnt�� ��
             �Ұ� ��Ÿ���� �� ����*/
                (*cnt)++;
        }
    }
    S = (SprsMtrx*)malloc(sizeof(SprsMtrx) * ((*cnt) + 1)); /*���� �Ҵ����� �� ��
    ������ �� ĭ �� ����*/
    S[0].row = row; // S[0].row �����A�����ʱ�ȭ
    S[0].col = col; // S[0].col ���࿭A�ǿ��ʱ�ȭ
    S[0].value = *cnt; //S[0].value ���࿭A������value ���ǰ����ʱ�ȭ
    * cnt = 1; //S[1]~S[2]��������������cnt���ּҰ�����Ű�°���1���ʱ�ȭ
    for (j = 0; j < row; j++)
    {
        for (i = 0; i < col; i++)
        {
            if (A[j][i])
            {
                S[*cnt].row = j; //���������� �� ��ȣ ����
                S[*cnt].col = i; //���������� �� ��ȣ ����
                S[(*cnt)++].value = A[j][i]; /* ���S��value ���� ����
                �����Ƿ� cnt ���� ������Ű�� �ݺ�*/
            }
        }
    }
    return S; // ��Ĺ�ȯ
}
int main()
{
    int i, j, cnt = 0;
    int A[][7] = { {0,0,2,0,0,0,12}, // ����� ��Ÿ��
    {0,0,0,0,7,0,0},
    {23,0,0,0,0,0,0},
    {0,0,0,31,0,0,0},
    {0,14,0,0,0,25,0},
    {0,0,0,0,0,0,6},
    {52,0,0,0,0,0,0},
     {0,0,0,0,11,0,0} };
    for (j = 0; j < 8; j++)
    {
        for (i = 0; i < 7; i++)
        {
            printf("%d", A[j][i]);
        }
        printf("\n");
    }
    SprsMtrx* S = smCreate(A, sizeof(A) / (sizeof(int) * 7), 7, &cnt); /*�Լ� ȣ��
    �迭A, ���� ũ��, ���� ũ��, cnt�� ũ�⸦ �Ű������� ����.*/
    printf("======���������==========\n");/*S[i].row��S[i].col���� ��value ���
    �ϴ� ���*/
    for (i = 0; i < cnt; i++)
    {
        printf("%d %d %d\n", S[i].row, S[i].col, S[i].value);
    }
    return 0;
}