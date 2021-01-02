//3.3 다항식의 순차 자료 구조 구현 <다항식의 덧셈 알고리즘 : A(x) + B(x) = C(x)>
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define MAX(a, b) ((a>b) ? a : b) // a>b이면a 출력 그렇지 않다면 b 출력
#define MAX_DEGREE 50

typedef struct { // 다항식을 나타낸 구조체
	int degree; // 차수를 나타내는 변수 선언
	float coef[MAX_DEGREE]; // 각항의 계수를 나타내는 변수 선언
} polynomial;
polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree); /*A의 degree 값(A의 최고 차수), B의
	degree 값(B의 최고 차수) 비교*/
	while (A_index <= A.degree && B_index <= B.degree) { /*A,B degree 값 모두
	-1 될 때 까지 while문 실행*/
		if (A_degree > B_degree) { /* A의차수가B의차수보다크면
		C.coef[C_index]에 A.coef[A_index] 저장 후, 각각의 index 값++ (다항식 A의 차수의 계수
		값 그대로 입력) */
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--; //A_degree 값-- (차수 -1)
		}
		else if (A_degree == B_degree) { /* A, B의 차수가 같다면
		C.coef[C_index]에 A.coef[A_index] + B.coef[B_index] 값 저장 후, 각각의 index 값++ */
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else { /* B의 차수가 A의 차수 보다 크면C.coef[C_index]에
		B.coef[B_index] 저장 후, 각각의 index 값++ (다항식 B의 차수의 계수 값 그대로 입력) */
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}
void printPoly(polynomial P) // 함수 호출 될 때 마다 순차적으로 P= A, B 입력받음
{
	int i, degree; // 함수 printPoly 내에서 사용 될 변수 선언
	degree = P.degree; // 변수degree에polynomial 멤버 변수 값 저장.
	for (i = 0; i <= P.degree; i++) { //차수를 나타내는 P.degree 값만큼 for 문 실행
		printf("%3.0fx^%d", P.coef[i], degree--); /*내림차순으로 x의 계수와 차
		수 출력 */
		if (i < P.degree)
			printf("+"); // i=P.degree가 되는 경우를 제외하고'+'를 출력
	}
	printf("\n");
}

int main()
{
	polynomial A = { 3,{ 4,3,5,0 } }; /*멤버 변수 degree,coef[]에 각각 주어진 값 초
	기화*/
	polynomial B = { 4,{ 3,1,0,2,1 } }; /* 멤버 변수 degree,coef[]에 각각 주어진 값
	초기화*/
	polynomial C;
	C = addPoly(A, B);
	printf("\n A(x) = "); printPoly(A);
	printf("\n B(x) = "); printPoly(B);
	printf("\n C(x) = "); printPoly(C);
	getchar();
}