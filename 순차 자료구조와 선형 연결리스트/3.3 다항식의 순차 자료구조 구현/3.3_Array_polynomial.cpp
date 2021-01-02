//3.3 ���׽��� ���� �ڷ� ���� ���� <���׽��� ���� �˰��� : A(x) + B(x) = C(x)>
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define MAX(a, b) ((a>b) ? a : b) // a>b�̸�a ��� �׷��� �ʴٸ� b ���
#define MAX_DEGREE 50

typedef struct { // ���׽��� ��Ÿ�� ����ü
	int degree; // ������ ��Ÿ���� ���� ����
	float coef[MAX_DEGREE]; // ������ ����� ��Ÿ���� ���� ����
} polynomial;
polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree); /*A�� degree ��(A�� �ְ� ����), B��
	degree ��(B�� �ְ� ����) ��*/
	while (A_index <= A.degree && B_index <= B.degree) { /*A,B degree �� ���
	-1 �� �� ���� while�� ����*/
		if (A_degree > B_degree) { /* A��������B����������ũ��
		C.coef[C_index]�� A.coef[A_index] ���� ��, ������ index ��++ (���׽� A�� ������ ���
		�� �״�� �Է�) */
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--; //A_degree ��-- (���� -1)
		}
		else if (A_degree == B_degree) { /* A, B�� ������ ���ٸ�
		C.coef[C_index]�� A.coef[A_index] + B.coef[B_index] �� ���� ��, ������ index ��++ */
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else { /* B�� ������ A�� ���� ���� ũ��C.coef[C_index]��
		B.coef[B_index] ���� ��, ������ index ��++ (���׽� B�� ������ ��� �� �״�� �Է�) */
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}
void printPoly(polynomial P) // �Լ� ȣ�� �� �� ���� ���������� P= A, B �Է¹���
{
	int i, degree; // �Լ� printPoly ������ ��� �� ���� ����
	degree = P.degree; // ����degree��polynomial ��� ���� �� ����.
	for (i = 0; i <= P.degree; i++) { //������ ��Ÿ���� P.degree ����ŭ for �� ����
		printf("%3.0fx^%d", P.coef[i], degree--); /*������������ x�� ����� ��
		�� ��� */
		if (i < P.degree)
			printf("+"); // i=P.degree�� �Ǵ� ��츦 �����ϰ�'+'�� ���
	}
	printf("\n");
}

int main()
{
	polynomial A = { 3,{ 4,3,5,0 } }; /*��� ���� degree,coef[]�� ���� �־��� �� ��
	��ȭ*/
	polynomial B = { 4,{ 3,1,0,2,1 } }; /* ��� ���� degree,coef[]�� ���� �־��� ��
	�ʱ�ȭ*/
	polynomial C;
	C = addPoly(A, B);
	printf("\n A(x) = "); printPoly(A);
	printf("\n B(x) = "); printPoly(B);
	printf("\n C(x) = "); printPoly(C);
	getchar();
}