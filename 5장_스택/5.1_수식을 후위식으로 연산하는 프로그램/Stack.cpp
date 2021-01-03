//수식을 후위식으로 연산하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//스택 원소(의 자료형을 int 로 정의
typedef char element;
//스택의 노드를 구조체로 정의
typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;
//스택의 top 노드를 지정하기 위해 포인터 top 선언
stackNode* top;
//스택의 top 에 원소를 삽입하는 연산
void push(element item)
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;// 삽입 노드를 top 의 위에 연결
	top = temp; // top 위치를 삽입 노드로 이동
}
//스택의 top 에서 원소를 삭제하는 연산
element pop()
{
	element item;
	stackNode* temp = top;
	if (top == NULL)// 스택이 공백 리스트인 경우
	{
		printf("\n Stack is empty !\n");
		return 0;
	}
	else // 스택이 공백 리스트가 아닌 경우
	{
		item = temp->data;
		top = temp->link;// top 위치를 삭제 노드 아래로 이동
		free(temp); // 삭제된 노드의 메모리 반환
		return item; // 삭제된 원소 반환
	}
}
//중의 표기식을 후위 표기식으로 변환
//1.왼쪽괄호를 만나면 무시하고 다음 문자를 읽는다. //2. 피연산자를 만나면 출력한다. //3. 연산자를 만ㄴ나면 스택에 push한다. //4. 오른쪽 괄호를 만나면 스택을 pop하여 출력한다. //5. 수식이 끝나면 스택이 공백이 될 때까지 pop하여 출력
//후위 표기법 수식을 계산하는 연산
element evalPostfix(char* exp)
{
	int i = 0;
	// char 형 포인터 매개변수로 받은 수식 exp 의 길이를 계산하여
	// length 변수에 저장
	int length = strlen(exp);
	char symbol;
	top = NULL;
	for (i = 0; i < length; i++)
	{
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol !=
			'/' && symbol != '(' && symbol != ')')
		{
			printf("%c", symbol);
		}
		else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		{
			push(symbol);
		}
		else if (symbol == ')')
		{
			printf("%c", pop());
		}
	}
	//수식 exp 에 대한 처리를 마친 후 스택에 남아 있는 결과값을 pop 하여 반환
	return pop();
}
int main()
{
	int result;
	char express[100] = "((A*B)-(C/D))";
	printf("중위 표기식 : %s\n", express);
	printf("후위 표기식 : ");
	result = evalPostfix(express);
	getchar();
	return 0;
}