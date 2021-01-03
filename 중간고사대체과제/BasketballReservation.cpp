#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "time.h"
#include "stdlib.h"
int err = 0;
// 농구장 예약 서비스 항목의 구조 정의
typedef struct {
    char name[20]; //예약자 명
    char code[13]; //예약번호
    int rsv_d; //예약 날짜
    char rsv_t[20]; //예약 시간대
    char pay; //결제 여부 확인
}element;
// 농구장 예약 서비스 이진 트리의 노드 구조 정의
typedef struct treeNode {
    element key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;
// 포인터 p가 가리키는 노드와 비교하여 항목 key를 삽입하는 연산
treeNode* insertKey(treeNode* p, element key)
{
    treeNode* newNode;
    int compare;
    // 삽입할 자리에 새 노드를 구성하여 연결
    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // 이진 트리에서 삽입할 자리 탐색
    else {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
            p->left = insertKey(p->left, key);
        else if (compare > 0)
            p->right = insertKey(p->right, key);
        else
            printf("\n 이름이 중복 됩니다. \n");
        return p; // 삽입한 자리 반환
    }
}
void insert(treeNode** root, element key)
{
    *root = insertKey(*root, key);
}
// root 노드부터 탐색하여 key와 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode* root, element key)
{
    treeNode* parent, * p, * succ, * succ_parent;
    treeNode* child;
    parent = NULL;
    p = root;
    while ((p != NULL) && (strcmp(p->key.name, key.name) != 0))
    {
        parent = p;
        if (strcmp(key.name, p->key.name) < 0)
            p = p->left;
        else
            p = p->right;
    }
    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("\n 취소할 예약자가 없습니다.");
        return;
    }
    // 삭제할 노드가 단말 노드인 경우
    if ((p->left == NULL) && (p->right == NULL)) {
        if (parent != NULL) {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
        {
            err = 1;
            root = NULL;
        }
    }
    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p->left == NULL) || (p->right == NULL)) {
        if (p->left != NULL)
            child = p->left;
        else
            child = p->right;
        if (parent != NULL) {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
    }
    // 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        succ_parent = p;
        succ = p->right;
        while (succ->left != NULL)
        {
            succ_parent = succ;
            succ = succ->left;
        }
        if (succ_parent->left == succ)
            succ_parent->left = succ->right;
        else
            succ_parent->right = succ->right;
        p->key = succ->key;
        p = succ;
    }
    free(p);
}
// 이진 탐색 트리에서 키값이 key인 노드 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, element key)
{
    treeNode* p;
    int compare;
    p = root;
    while (p != NULL)
    {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
            p = p->left;
        else if (compare > 0)
            p = p->right;
        else {
            return p;
        }
    }
    return p;
}
// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* root)
{
    if (root) {
        displayInorder(root->left);
        printf("\n예약자명 : %s 님\n", root->key.name);
        printf("예약번호 : %s \n", root->key.code);
        printf("예약 날짜 : %d \n", root->key.rsv_d);
        printf("예약 기간 : %s \n", root->key.rsv_t);
        printf("결제 정보 : %c \n", root->key.pay);
        displayInorder(root->right);
    }
}
// 농구장 예약 서비스 메뉴
void menu()
{
    printf("\n*-------<정왕1동 농구장 예약 서비스>-------*");
    printf("\n\t1 : 전체 정보 출력");
    printf("\n\t2 : 예약 정보 입력");
    printf("\n\t3 : 예약 취소");
    printf("\n\t4 : 예약 변경");
    printf("\n\t5 : 종료");
    printf("\n*------------------------------------------*\n ");
}
int main()
{
    system("title PARKGEUNWOO");
    element e;
    treeNode* root = NULL, * temp = NULL;
    int choice;
    //현재시간
    time_t current_time = time(NULL);
    struct tm struct_time = *localtime(&current_time);
    int year, month, day;
    int count = 0; //예약 순서를 나타내는 변수
    year = struct_time.tm_year + 1900; //현재 년도
    month = struct_time.tm_mon + 1; //현재 월
    day = struct_time.tm_mday; //현재 일
    // [5 :종료] 메뉴를 선택할 때까지 메뉴에 대한 농구 예약 서비스 동작 반복
    do {
        menu(); //농구장 예약 서비스 메뉴 실행
        scanf("%d", &choice); //서비스 항목 중 선택
        switch (choice)
        {
        case 1: //전체 정보 출력
            system("cls");
            printf("\t[전체 정보 출력]");
            displayInorder(root);
            printf("\n\t[정보 출력 끝]\n\n");
            break;
        case 2: //예약 정보 입력
            system("cls");
            while (1)
                //이름이 중복되는지 확인하는 루프
            {
                printf("\n[예약 정보] 예약자 이름 입력 : ");
                scanf("%s", &e.name);
                if (searchBST(root, e) != 0) /*반환값이 0이 아니면 중복됨.*/
                {
                    printf("\n이름이 중복 됩니다.\n");
                    continue;
                }
                else //반환값이 0이면 루프 탈출
                {
                    break;
                }
            }
            system("cls");
            while (1)
                //예약할 날짜를 입력하는 루프
            {
                printf("\n[예약 정보] 예약할 날짜를 선택하세요. ex)20200605 (1일전 예약 필수) : ");
                scanf("%d", &e.rsv_d);
                if (e.rsv_d > (day + month * 100 + year * 10000)) //예약 날짜가 현재 날짜보다 크면 루프 탈출
                    break;
                else
                {
                    printf("\n예약할 날짜가 올바르지 않습니다.\n");
                    continue;
                }
            }
            system("cls");
            while (1) //예약할 시간대를 입력하는 루프
            {
                int num;
                printf("\n[예약 정보] 예약할 시간대(09:00~22:00)를 선택하세요. (예 : 17입력시 17 : 00~17 : 59 예약) : ");
                scanf("%s", &e.rsv_t);
                num = atoi(e.rsv_t);
                if (num >= 9 && num <= 22) /*예약할 시간이 9시보
                다 크거나 같고 22시보다 작거나 같으면 루프탈출*/
                    break;
                else
                {
                    printf("\n예약할 시간대가 올바르지 않습니다.\n");
                        continue;
                }
            }
            system("cls");
            if (MessageBox(NULL, L"결제하시겠습니까?", L"결제 정보", MB_OKCANCEL) == IDOK) /*결제 여부를 확인하는 메세지 박스
                출력*/
                e.pay = 'Y'; //확인을 누를시 멤버변수에 Y 저장
            else
                e.pay = 'N'; //취소를 누를시 멤버변수에 N 저장
            sprintf(e.code, "%.4d%.2d%.2d%.4d", year, month, day, ++count);
            //예약 번호를 멤버변수에 문자열로 저장
            insert(&root, e); //트리에 저장
            break;
        case 3: //예약 취소
            system("cls");
            printf("\n[예약 취소] 예약자명 입력 : ");
            scanf("%s", &e.name);
            deleteNode(root, e);
            if (err == 1)
            {
                root = NULL;
            }
            printf("\n예약이 취소되었습니다.\n");
            break;
        case 4: //예약 변경
            system("cls");
            printf("\n[예약 변경] 예약자명 입력 : ");
            scanf("%s", &e.name);
            temp = searchBST(root, e);
            //예약 변경할 예약자의 주소를 temp에 저장
            if (temp != NULL) //예약자가 존재할때 예약 변경
            {
                printf("\n예약자명 : %s 님\n", temp->key.name);
                printf("예약번호 : %s \n", temp->key.code);
                printf("예약 날짜 : %d \n", temp->key.rsv_d);
                printf("예약 기간 : %d \n", temp->key.rsv_t);
                printf("결제 정보 : %c \n\n\n", temp->key.pay);
                while (1) //예약 변경할 날짜를 입력하는 루프
                {
                    printf("\n[예약 변경] 예약 변경할 날짜를 선택하세요.ex)20200605 (1일전 예약 필수) : ");
                    scanf("%d", &temp->key.rsv_d);
                    if (temp->key.rsv_d > (day + month * 100 +
                        year * 10000)) /*예약 변경할 날짜가 현재 날
                        짜보다 크다면 루프 탈출*/
                        break;
                    else
                    {
                        printf("\n예약 변경할 날짜가 올바르지 않습니다.\n");
                            continue;
                    }
                }
                system("cls");
                while (1) //예약 변경할 시간대를 입력하는 루프
                {
                    int num;
                    printf("\n[예약 변경] 예약 변경할 시간대 (09:00~22 : 00)를 선택하세요. (예 : 17입력시 17 : 00~17 : 59 예약) : ");
                    scanf("%s", &temp->key.rsv_t);
                    num = atoi(temp->key.rsv_t); /*입력받은 시
                    간대의 문자열에서 숫자를 추출*/
                    if (num >= 9 && num <= 22)
                        /*숫자로 추출된 시간대가 9~22이라면 루프 탈
                        출*/
                        break;
                    else
                    {
                        printf("\n예약 변경할 시간대가 올바르지 않습니다.\n");
                        continue;
                    }
                }
                system("cls");
                if (MessageBox(NULL, L"결제하시겠습니까?", L"결제 정보", MB_OKCANCEL) == IDOK) /*결제 여부를 확인하는 메세지 박스 출력 */
                    temp->key.pay = 'Y';
                //확인을 누를시 멤버변수에 Y 저장
                else
                    temp->key.pay = 'N';
                //취소를 누를시 멤버변수에 N 저장
            }
            else
                    printf("\n입력된 정보가 없습니다.");
            break;
        }
        while (getchar() != '\n');
    } while (choice != 5);

    return 0;
}