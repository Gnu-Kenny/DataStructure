//������ ���������� �����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//���� ����(�� �ڷ����� int �� ����
typedef char element;
//������ ��带 ����ü�� ����
typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;
//������ top ��带 �����ϱ� ���� ������ top ����
stackNode* top;
//������ top �� ���Ҹ� �����ϴ� ����
void push(element item)
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;// ���� ��带 top �� ���� ����
	top = temp; // top ��ġ�� ���� ���� �̵�
}
//������ top ���� ���Ҹ� �����ϴ� ����
element pop()
{
	element item;
	stackNode* temp = top;
	if (top == NULL)// ������ ���� ����Ʈ�� ���
	{
		printf("\n Stack is empty !\n");
		return 0;
	}
	else // ������ ���� ����Ʈ�� �ƴ� ���
	{
		item = temp->data;
		top = temp->link;// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp); // ������ ����� �޸� ��ȯ
		return item; // ������ ���� ��ȯ
	}
}
//���� ǥ����� ���� ǥ������� ��ȯ
//1.���ʰ�ȣ�� ������ �����ϰ� ���� ���ڸ� �д´�. //2. �ǿ����ڸ� ������ ����Ѵ�. //3. �����ڸ� �������� ���ÿ� push�Ѵ�. //4. ������ ��ȣ�� ������ ������ pop�Ͽ� ����Ѵ�. //5. ������ ������ ������ ������ �� ������ pop�Ͽ� ���
//���� ǥ��� ������ ����ϴ� ����
element evalPostfix(char* exp)
{
	int i = 0;
	// char �� ������ �Ű������� ���� ���� exp �� ���̸� ����Ͽ�
	// length ������ ����
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
	//���� exp �� ���� ó���� ��ģ �� ���ÿ� ���� �ִ� ������� pop �Ͽ� ��ȯ
	return pop();
}
int main()
{
	int result;
	char express[100] = "((A*B)-(C/D))";
	printf("���� ǥ��� : %s\n", express);
	printf("���� ǥ��� : ");
	result = evalPostfix(express);
	getchar();
	return 0;
}