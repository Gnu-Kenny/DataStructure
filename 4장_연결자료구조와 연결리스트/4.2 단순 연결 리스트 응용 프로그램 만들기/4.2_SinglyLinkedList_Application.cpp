//2. 단순 연결 리스트 응용 프로그램 만들기. (영화 정보 삽입 / 출력)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

typedef struct ListNode // 단순 연결 리스트의 노드 구조를 구조체로 정의
{
    char data[SIZE]; //데이터를 저장할 멤버변수
    int year;
    struct ListNode* link; //다음 노드의 주소를 저장할 포인터
}listNode;

typedef struct  //리스트 시작을 나타내는 head 노드를 구조체로 정의
{
    listNode* head;
}linkedList_h;

linkedList_h* creatLinkedList_h(void) // 공백 연결 리스트를 생성하는 연산
{
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h)); //포인터의 주소 메모리 할당
    L->head = NULL; // 다음 노드로 시작 노드를 가리키고 NULL을 저장한다.
    return L; // NULL인 L 값을 리턴.
}
void freeLinkedList_h(linkedList_h* L) // 연결 리스트의 전체 메모리를 해제하는 연산
{
    listNode* p;
    while (L->head != NULL) /*연결리스트를 순회시키는 역할. free()는 해당 노드만 메모리를 해체시키므로 링크를 따라가며 일일이 해제한다.*/
    {
        p = L->head; // 다음주소는head가됨.
        L->head = L->head->link;
        free(p); //P가 가리키는 주소의 값의 메모리를 해제시킨다.
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
        printf(" %d 제목: %s\t", Num, p->data);
        printf(" 년도: %d\n", p->year);
        p = p->link;
    }
}

void insertNode(linkedList_h* L, char* s, int y)
{
    ListNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));   // 새 메모리할당
    strcpy(newNode->data, s);
    newNode->year = y; //새 노드의 데이터 부분에 year 변수를 넣고 y값을 저장한다.

        // 공백 리스트인 경우
        // 새 노드를 첫 번째이자 마지막 노드로 연결
        if (L->head == NULL)
        {
            newNode->link = NULL;
            L->head = newNode;
        }
    // 선행 노드가 있으면 그 다음 노드에 삽입되게 한다.
        else if (newNode == NULL)
        {
            newNode->link = L->head;  // 새 노드를 첫 번째 노드로 삽입
            L->head = newNode;
        }
    // 리스트 중간에 삽입되게 한다.
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
    printf(" 1. 영화정보추가\n");
    printf(" 2. 영화정보출력\n");
    printf(" 3. 종료\n");
    printf("----------------------\n");
    printf(" 번호를선택하세요: ");
    scanf("%d", &men);
    return men;
}
int main()
{
    int cho = 0, y;
    char s[40];
    linkedList_h* L;
    L = creatLinkedList_h();

    while ((cho = menu()) != 3) //cho = 3(종료)이 아니라면 반복 실행
    {
        getchar();
        if (cho == 1)
        {
            printf(" 영화의제목을입력하세요: ");
            scanf("%s", &s);
            printf(" 영화의개봉연도를입력하세요: ");
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