//3.2 2차원 배열을 이용한 선형 리스트 구현
#include <stdio.h>
int main()
{
	int i, n = 0, * ptr;
	int sale[2][4] = { { 63, 84, 140, 130 },// 3 차원배열의초기화
	{ 157, 209, 251, 312 } };
	ptr = &sale[0][0];
	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}
	getchar();
}

//ptr의 자료형이 int이기 때문에 ptr의 값이 ++될 때 마다 address의 주소가 4씩 증가함을 확
//인 할 수 있다.그리고 I가 증가 할 때 마다 63(= sale[0][0]), 84(= sale[0][1])..의 값들이 순차
//적으로 출력되는 것으로 보아 ‘행 우선 순서 방법‘으로 2차원 배열을 저장함을 확인했다.