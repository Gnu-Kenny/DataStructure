//2. �ܼ� ���� ����Ʈ ���� ���α׷� �����. (��ȭ ���� ���� / ���)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

typedef struct ListNode // �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
{
    char data[SIZE]; //�����͸� ������ �������
    int year;
    struct ListNode* link; //���� ����� �ּҸ� ������ ������
}listNode;

typedef struct  //����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
{
    listNode* head;
}linkedList_h;

linkedList_h* creatLinkedList_h(void) // ���� ���� ����Ʈ�� �����ϴ� ����
{
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h)); //�������� �ּ� �޸� �Ҵ�
    L->head = NULL; // ���� ���� ���� ��带 ����Ű�� NULL�� �����Ѵ�.
    return L; // NULL�� L ���� ����.
}
void freeLinkedList_h(linkedList_h* L) // ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
{
    listNode* p;
    while (L->head != NULL) /*���Ḯ��Ʈ�� ��ȸ��Ű�� ����. free()�� �ش� ��常 �޸𸮸� ��ü��Ű�Ƿ� ��ũ�� ���󰡸� ������ �����Ѵ�.*/
    {
        p = L->head; // �����ּҴ�head����.
        L->head = L->head->link;
        free(p); //P�� ����Ű�� �ּ��� ���� �޸𸮸� ������Ų��.
        p = NULL;
    }
}

void printList(linkedList_h* L)
{
    int Num = 0;
    listNode* p;   // =NULL
    p = L->head;
    while (p != NULL)
    {
        Num++;
        printf(" %d ����: %s\t", Num, p->data);
        printf(" �⵵: %d\n", p->year);
        p = p->link;
    }
}

void insertNode(linkedList_h* L, char* s, int y)
{
    ListNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));   // �� �޸��Ҵ�
    strcpy(newNode->data, s);
    newNode->year = y; //�� ����� ������ �κп� year ������ �ְ� y���� �����Ѵ�.

        // ���� ����Ʈ�� ���
        // �� ��带 ù ��°���� ������ ���� ����
        if (L->head == NULL)
        {
            newNode->link = NULL;
            L->head = newNode;
        }
    // ���� ��尡 ������ �� ���� ��忡 ���Եǰ� �Ѵ�.
        else if (newNode == NULL)
        {
            newNode->link = L->head;  // �� ��带 ù ��° ���� ����
            L->head = newNode;
        }
    // ����Ʈ �߰��� ���Եǰ� �Ѵ�.
        else
        {
            newNode->link = L->head->link; // 
            L->head->link = newNode;
        }
}

int menu()
{
    int men = 0;
    printf("----------------------\n");
    printf(" 1. ��ȭ�����߰�\n");
    printf(" 2. ��ȭ�������\n");
    printf(" 3. ����\n");
    printf("----------------------\n");
    printf(" ��ȣ�������ϼ���: ");
    scanf("%d", &men);
    return men;
}
int main()
{
    int cho = 0, y;
    char s[40];
    linkedList_h* L;
    L = creatLinkedList_h();

    while ((cho = menu()) != 3) //cho = 3(����)�� �ƴ϶�� �ݺ� ����
    {
        getchar();
        if (cho == 1)
        {
            printf(" ��ȭ���������Է��ϼ���: ");
            scanf("%s", &s);
            printf(" ��ȭ�ǰ����������Է��ϼ���: ");
            scanf("%d", &y);
            insertNode(L, s, y);
        }
        else if (cho == 2)
        {
            printList(L);
            getchar();
        }
        else
        {
            freeLinkedList_h(L);
            break;
        }
        system("cls");
    }
    return 0;
}