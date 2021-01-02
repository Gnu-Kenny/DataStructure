//3.4 행렬의 순차 자료구조 구현 <희소 행렬 만들기>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row; // 행을 나타내는 변수
    int col; // 열을 나타내는 변수
    int value; // 행렬 들어가는 값을 나타내는 변수
} SprsMtrx; //희소 행렬을 나타내는 구조체
SprsMtrx* smCreate(int A[][7], int row, int col, int* cnt) /*함수 호출 배열A, 행의 크
기, 열의 크기, cnt의 크기를 매개변수에 저장.*/
{
    int i, j;
    SprsMtrx* S; //구조체 객체 생성
    for (j = 0; j < row; j++) //행의 크기만큼 for문 실행
    {
        for (i = 0; i < col; i++) // 열의 크기만큼 for문 실행
        {
            if (A[j][i]) /*A[0][0]~A[row-1][col-1]까지 증가함에 따라 cnt의 주
             소가 나타내는 값 증가*/
                (*cnt)++;
        }
    }
    S = (SprsMtrx*)malloc(sizeof(SprsMtrx) * ((*cnt) + 1)); /*동적 할당으로 행 개
    수보다 한 칸 더 생성*/
    S[0].row = row; // S[0].row 에행렬A의행초기화
    S[0].col = col; // S[0].col 에행열A의열초기화
    S[0].value = *cnt; //S[0].value 에행열A가가진value 값의개수초기화
    * cnt = 1; //S[1]~S[2]에값대입을위해cnt의주소가가리키는값을1로초기화
    for (j = 0; j < row; j++)
    {
        for (i = 0; i < col; i++)
        {
            if (A[j][i])
            {
                S[*cnt].row = j; //순차적으로 행 번호 저장
                S[*cnt].col = i; //순차적으로 열 번호 저장
                S[(*cnt)++].value = A[j][i]; /* 행렬S에value 값을 저장
                했으므로 cnt 값을 증가시키며 반복*/
            }
        }
    }
    return S; // 행렬반환
}
int main()
{
    int i, j, cnt = 0;
    int A[][7] = { {0,0,2,0,0,0,12}, // 행렬을 나타냄
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
    SprsMtrx* S = smCreate(A, sizeof(A) / (sizeof(int) * 7), 7, &cnt); /*함수 호출
    배열A, 행의 크기, 열의 크기, cnt의 크기를 매개변수에 저장.*/
    printf("======희소행렬출력==========\n");/*S[i].row행S[i].col열의 값value 출력
    하는 행렬*/
    for (i = 0; i < cnt; i++)
    {
        printf("%d %d %d\n", S[i].row, S[i].col, S[i].value);
    }
    return 0;
}