//1. �ܼ� ���� ����Ʈ ���α׷� �����.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode  //ListNode�� ���� ����ü ����
{
    char data[4];  // �����͸� ������ ���
    struct ListNode* link; //���� ����� �ּҸ� ������ ������
}listNode;

typedef struct //����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
{
    listNode* head;
}linkedList_h;

linkedList_h* creatLinkedList_h(void)  //���� ���Ḯ��Ʈ�� �����ϴ� ����
{
    linkedList_h* L; // ���� ����� �ּҸ� ������ ������
    L = (linkedList_h*)malloc(sizeof(linkedList_h)); //�������� �ּҸ޸��Ҵ�
    L->head = NULL; // ���� �ּҷ� head�� ����Ű�� NULL�� �����Ѵ�.
        return L; // NULL�� L ���� ����
}
void freeLinkedList_h(linkedList_h* L) // ���Ḯ��Ʈ�� ��ü �޸𸮸� �����ϴ� ����
{
    listNode* p;  // ���� ����� �ּҸ� ������ ������
    while (L->head != NULL) /* ���� ����Ʈ�� ��ȸ��Ű�� ����. free()�� �ش��常 �޸𸮸� ��ü��Ű�Ƿ� ��ũ�� ���󰡸� ������ �����Ѵ�. */
    {
        p = L->head;  // ���� �ּҴ� head�� ��.
        L->head = L->head->link;
        free(p); //P�� ����Ű�� �ּ��� ���� �޸𸮸� ������Ų��.
        p = NULL; //P�� NULL���� �����Ѵ�.
    }
}
void printList(linkedList_h* L)
{
    listNode* p; // ���� �ּҸ� ��Ÿ���� ������
    printf("L=(");
    p = L->head;//������ ������� p�� ���س��L�� ����Ű�� ���۳��
    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL)
            printf(",");
    }
    printf(")\n");
}
void insertFirstNode(linkedList_h* L, char *x) // ù ��° ���� ���Խ�Ű�� �Լ�
{
    listNode* newNode; //������ �� ��� ����
    newNode = (listNode*)malloc(sizeof(listNode));  //�� ����� �޸� �Ҵ�
    strcpy(newNode->data, x);// �� ����� ������ �ʵ忡 x ����
    newNode->link = L->head; // �� ����� ���� ��忡 ���س���� ���� ��带 ����
    L->head = newNode;  /*���� ����� ���� ��带 ���۳��� �����ϰ� �� ���� �� 				��尡 ��.*/
}
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x)  /*�߰� ���� �����ϴ� ���� */
{
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(ListNode)); // �� �޸� �Ҵ�
    strcpy(newNode->data, x); //�� �޸𸮿� ���ڿ� ����.
    if (L == NULL)  // ���� ����Ʈ�� ���
    {
        newNode->link = NULL;  // �� ��带 ù ��°���� ������ ���� ����
        L->head = newNode;
    }
    else if (pre == NULL)   // ������ġ�� �����ϴ� ������ pre�� NULL�� ���
    {
        L->head = newNode;  // �� ��带 ù ��° ���� ����
    }
    else
    {
        newNode->link = pre->link;  //������ pre�� ��� �ڿ� �� ��� ����.
        pre->link = newNode;
    }
}
void insertLastNode(linkedList_h* L, char* x) //������ ���� �����ϴ� ����.
{
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (L->head == NULL)   // ���� ����Ʈ�� ������ ���
    {
        L->head = newNode;  //�� ��带 ����Ʈ�� ���� ���� ����
        return;
    }
    // ���� ����Ʈ�� ������ �ƴ� ���
    temp = L->head;
    while (temp->link != NULL)
    {
        temp = temp->link;  // ���� ����Ʈ�� ������ ��带 ã��.
    }
    temp->link = newNode; // �� ��带 ������ ����� ���� ���� ����
}
int main()
{
    linkedList_h* L; //����� �������� ��Ÿ���� ����ü ����.
    L = creatLinkedList_h(); // creatLinkedList_h�� ���� �� NULL���� L�� �����Ѵ�.
    printf("(1) ���鸮��Ʈ�����ϱ�!\n");
    printList(L); //printList()�Լ�ȣ�� /*���� L�� ���� NULL�̱� ������ �Լ� ���� �ݺ�				       �� ���� ���� L=() ��� */
    getchar();

    printf("(2) ����Ʈ��[��] �������ϱ�!\n");
    insertFirstNode(L,"��"); //"��"�� ù ��° ��忡 ����.
    printList(L);
    getchar();

    printf("(3) ����Ʈ��[��] �������ϱ�!\n");
    insertLastNode(L,"��"); // "��"�� ������ ��忡 ����
    printList(L);
    getchar();

    printf("(4) ����Ʈ��[��] �������ϱ�!\n");
    insertFirstNode(L,"��"); // "��"�� ù ��° ��忡 ����
    printList(L);
    getchar();

    printf("(5) ����Ʈ������ �����Ͽ� ���� ����Ʈ�� �����!\n");
    freeLinkedList_h(L);
    printList(L);

    getchar();

    return 0;
}