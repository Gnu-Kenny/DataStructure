//1. 단순 연결 리스트 프로그램 만들기.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode  //ListNode에 대한 구조체 정의
{
    char data[4];  // 데이터를 저장할 멤버
    struct ListNode* link; //다음 노드의 주소를 저장할 포인터
}listNode;

typedef struct //리스트 시작을 나타내는 head 노드를 구조체로 정의
{
    listNode* head;
}linkedList_h;

linkedList_h* creatLinkedList_h(void)  //공백 연결리스트를 생성하는 연산
{
    linkedList_h* L; // 다음 노드의 주소를 저장할 포인터
    L = (linkedList_h*)malloc(sizeof(linkedList_h)); //포인터의 주소메모리할당
    L->head = NULL; // 다음 주소로 head를 가리키고 NULL을 저장한다.
        return L; // NULL인 L 값을 리턴
}
void freeLinkedList_h(linkedList_h* L) // 연결리스트의 전체 메모리를 해제하는 연산
{
    listNode* p;  // 다음 노드의 주소를 저장할 포인터
    while (L->head != NULL) /* 연결 리스트를 순회시키는 역할. free()는 해당노드만 메모리를 해체시키므로 링크를 따라가며 일일이 해제한다. */
    {
        p = L->head;  // 다음 주소는 head가 됨.
        L->head = L->head->link;
        free(p); //P가 가리키는 주소의 값의 메모리를 해제시킨다.
        p = NULL; //P에 NULL값을 저장한다.
    }
}
void printList(linkedList_h* L)
{
    listNode* p; // 다음 주소를 나타내는 포인터
    printf("L=(");
    p = L->head;//포인터 멤버변수 p에 기준노드L이 가리키는 시작노드
    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL)
            printf(",");
    }
    printf(")\n");
}
void insertFirstNode(linkedList_h* L, char *x) // 첫 번째 노드로 삽입시키는 함수
{
    listNode* newNode; //삽입할 새 노드 생성
    newNode = (listNode*)malloc(sizeof(listNode));  //새 노드의 메모리 할당
    strcpy(newNode->data, x);// 새 노드의 데이터 필드에 x 저장
    newNode->link = L->head; // 새 노드의 다음 노드에 기준노드의 다음 노드를 지정
    L->head = newNode;  /*기준 노드의 다음 노드를 시작노드로 지정하고 그 노드는 새 				노드가 됨.*/
}
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x)  /*중간 노드로 삽입하는 연산 */
{
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(ListNode)); // 새 메모리 할당
    strcpy(newNode->data, x); //새 메모리에 문자열 저장.
    if (L == NULL)  // 공백 리스트인 경우
    {
        newNode->link = NULL;  // 새 노드를 첫 번째이자 마지막 노드로 연결
        L->head = newNode;
    }
    else if (pre == NULL)   // 삽입위치를 지정하는 포인터 pre가 NULL인 경우
    {
        L->head = newNode;  // 새 노드를 첫 번째 노드로 삽입
    }
    else
    {
        newNode->link = pre->link;  //포인터 pre의 노드 뒤에 새 노드 연결.
        pre->link = newNode;
    }
}
void insertLastNode(linkedList_h* L, char* x) //마지막 노드로 삽입하는 연산.
{
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (L->head == NULL)   // 현재 리스트가 공백인 경우
    {
        L->head = newNode;  //새 노드를 리스트의 시작 노드로 연결
        return;
    }
    // 현재 리스트가 공백이 아닌 경우
    temp = L->head;
    while (temp->link != NULL)
    {
        temp = temp->link;  // 현재 리스트의 마지막 노드를 찾음.
    }
    temp->link = newNode; // 새 노드를 마지막 노드의 다음 노드로 연결
}
int main()
{
    linkedList_h* L; //노드의 시작점을 나타내는 구조체 생성.
    L = creatLinkedList_h(); // creatLinkedList_h의 리턴 값 NULL값을 L에 저장한다.
    printf("(1) 공백리스트생성하기!\n");
    printList(L); //printList()함수호출 /*현재 L의 값이 NULL이기 때문에 함수 내의 반복				       문 실행 없이 L=() 출력 */
    getchar();

    printf("(2) 리스트에[수] 노드삽입하기!\n");
    insertFirstNode(L,"수"); //"수"를 첫 번째 노드에 삽입.
    printList(L);
    getchar();

    printf("(3) 리스트에[금] 노드삽입하기!\n");
    insertLastNode(L,"금"); // "금"를 마지막 노드에 삽입
    printList(L);
    getchar();

    printf("(4) 리스트에[월] 노드삽입하기!\n");
    insertFirstNode(L,"월"); // "월"를 첫 번째 노드에 삽입
    printList(L);
    getchar();

    printf("(5) 리스트공백을 해제하여 공백 리스트로 만들기!\n");
    freeLinkedList_h(L);
    printList(L);

    getchar();

    return 0;
}