#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "time.h"
#include "stdlib.h"
int err = 0;
// ���� ���� ���� �׸��� ���� ����
typedef struct {
    char name[20]; //������ ��
    char code[13]; //�����ȣ
    int rsv_d; //���� ��¥
    char rsv_t[20]; //���� �ð���
    char pay; //���� ���� Ȯ��
}element;
// ���� ���� ���� ���� Ʈ���� ��� ���� ����
typedef struct treeNode {
    element key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;
// ������ p�� ����Ű�� ���� ���Ͽ� �׸� key�� �����ϴ� ����
treeNode* insertKey(treeNode* p, element key)
{
    treeNode* newNode;
    int compare;
    // ������ �ڸ��� �� ��带 �����Ͽ� ����
    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // ���� Ʈ������ ������ �ڸ� Ž��
    else {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
            p->left = insertKey(p->left, key);
        else if (compare > 0)
            p->right = insertKey(p->right, key);
        else
            printf("\n �̸��� �ߺ� �˴ϴ�. \n");
        return p; // ������ �ڸ� ��ȯ
    }
}
void insert(treeNode** root, element key)
{
    *root = insertKey(*root, key);
}
// root ������ Ž���Ͽ� key�� ���� ��带 ã�� �����ϴ� ����
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
    // ������ ��尡 ���� ���
    if (p == NULL) {
        printf("\n ����� �����ڰ� �����ϴ�.");
        return;
    }
    // ������ ��尡 �ܸ� ����� ���
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
    // ������ ��尡 �ڽ� ��带 �� �� ���� ���
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
    // ������ ��尡 �ڽ� ��带 �� �� ���� ���
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
// ���� Ž�� Ʈ������ Ű���� key�� ��� ��ġ�� Ž���ϴ� ����
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
// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
void displayInorder(treeNode* root)
{
    if (root) {
        displayInorder(root->left);
        printf("\n�����ڸ� : %s ��\n", root->key.name);
        printf("�����ȣ : %s \n", root->key.code);
        printf("���� ��¥ : %d \n", root->key.rsv_d);
        printf("���� �Ⱓ : %s \n", root->key.rsv_t);
        printf("���� ���� : %c \n", root->key.pay);
        displayInorder(root->right);
    }
}
// ���� ���� ���� �޴�
void menu()
{
    printf("\n*-------<����1�� ���� ���� ����>-------*");
    printf("\n\t1 : ��ü ���� ���");
    printf("\n\t2 : ���� ���� �Է�");
    printf("\n\t3 : ���� ���");
    printf("\n\t4 : ���� ����");
    printf("\n\t5 : ����");
    printf("\n*------------------------------------------*\n ");
}
int main()
{
    system("title PARKGEUNWOO");
    element e;
    treeNode* root = NULL, * temp = NULL;
    int choice;
    //����ð�
    time_t current_time = time(NULL);
    struct tm struct_time = *localtime(&current_time);
    int year, month, day;
    int count = 0; //���� ������ ��Ÿ���� ����
    year = struct_time.tm_year + 1900; //���� �⵵
    month = struct_time.tm_mon + 1; //���� ��
    day = struct_time.tm_mday; //���� ��
    // [5 :����] �޴��� ������ ������ �޴��� ���� �� ���� ���� ���� �ݺ�
    do {
        menu(); //���� ���� ���� �޴� ����
        scanf("%d", &choice); //���� �׸� �� ����
        switch (choice)
        {
        case 1: //��ü ���� ���
            system("cls");
            printf("\t[��ü ���� ���]");
            displayInorder(root);
            printf("\n\t[���� ��� ��]\n\n");
            break;
        case 2: //���� ���� �Է�
            system("cls");
            while (1)
                //�̸��� �ߺ��Ǵ��� Ȯ���ϴ� ����
            {
                printf("\n[���� ����] ������ �̸� �Է� : ");
                scanf("%s", &e.name);
                if (searchBST(root, e) != 0) /*��ȯ���� 0�� �ƴϸ� �ߺ���.*/
                {
                    printf("\n�̸��� �ߺ� �˴ϴ�.\n");
                    continue;
                }
                else //��ȯ���� 0�̸� ���� Ż��
                {
                    break;
                }
            }
            system("cls");
            while (1)
                //������ ��¥�� �Է��ϴ� ����
            {
                printf("\n[���� ����] ������ ��¥�� �����ϼ���. ex)20200605 (1���� ���� �ʼ�) : ");
                scanf("%d", &e.rsv_d);
                if (e.rsv_d > (day + month * 100 + year * 10000)) //���� ��¥�� ���� ��¥���� ũ�� ���� Ż��
                    break;
                else
                {
                    printf("\n������ ��¥�� �ùٸ��� �ʽ��ϴ�.\n");
                    continue;
                }
            }
            system("cls");
            while (1) //������ �ð��븦 �Է��ϴ� ����
            {
                int num;
                printf("\n[���� ����] ������ �ð���(09:00~22:00)�� �����ϼ���. (�� : 17�Է½� 17 : 00~17 : 59 ����) : ");
                scanf("%s", &e.rsv_t);
                num = atoi(e.rsv_t);
                if (num >= 9 && num <= 22) /*������ �ð��� 9�ú�
                �� ũ�ų� ���� 22�ú��� �۰ų� ������ ����Ż��*/
                    break;
                else
                {
                    printf("\n������ �ð��밡 �ùٸ��� �ʽ��ϴ�.\n");
                        continue;
                }
            }
            system("cls");
            if (MessageBox(NULL, L"�����Ͻðڽ��ϱ�?", L"���� ����", MB_OKCANCEL) == IDOK) /*���� ���θ� Ȯ���ϴ� �޼��� �ڽ�
                ���*/
                e.pay = 'Y'; //Ȯ���� ������ ��������� Y ����
            else
                e.pay = 'N'; //��Ҹ� ������ ��������� N ����
            sprintf(e.code, "%.4d%.2d%.2d%.4d", year, month, day, ++count);
            //���� ��ȣ�� ��������� ���ڿ��� ����
            insert(&root, e); //Ʈ���� ����
            break;
        case 3: //���� ���
            system("cls");
            printf("\n[���� ���] �����ڸ� �Է� : ");
            scanf("%s", &e.name);
            deleteNode(root, e);
            if (err == 1)
            {
                root = NULL;
            }
            printf("\n������ ��ҵǾ����ϴ�.\n");
            break;
        case 4: //���� ����
            system("cls");
            printf("\n[���� ����] �����ڸ� �Է� : ");
            scanf("%s", &e.name);
            temp = searchBST(root, e);
            //���� ������ �������� �ּҸ� temp�� ����
            if (temp != NULL) //�����ڰ� �����Ҷ� ���� ����
            {
                printf("\n�����ڸ� : %s ��\n", temp->key.name);
                printf("�����ȣ : %s \n", temp->key.code);
                printf("���� ��¥ : %d \n", temp->key.rsv_d);
                printf("���� �Ⱓ : %d \n", temp->key.rsv_t);
                printf("���� ���� : %c \n\n\n", temp->key.pay);
                while (1) //���� ������ ��¥�� �Է��ϴ� ����
                {
                    printf("\n[���� ����] ���� ������ ��¥�� �����ϼ���.ex)20200605 (1���� ���� �ʼ�) : ");
                    scanf("%d", &temp->key.rsv_d);
                    if (temp->key.rsv_d > (day + month * 100 +
                        year * 10000)) /*���� ������ ��¥�� ���� ��
                        ¥���� ũ�ٸ� ���� Ż��*/
                        break;
                    else
                    {
                        printf("\n���� ������ ��¥�� �ùٸ��� �ʽ��ϴ�.\n");
                            continue;
                    }
                }
                system("cls");
                while (1) //���� ������ �ð��븦 �Է��ϴ� ����
                {
                    int num;
                    printf("\n[���� ����] ���� ������ �ð��� (09:00~22 : 00)�� �����ϼ���. (�� : 17�Է½� 17 : 00~17 : 59 ����) : ");
                    scanf("%s", &temp->key.rsv_t);
                    num = atoi(temp->key.rsv_t); /*�Է¹��� ��
                    ������ ���ڿ����� ���ڸ� ����*/
                    if (num >= 9 && num <= 22)
                        /*���ڷ� ����� �ð��밡 9~22�̶�� ���� Ż
                        ��*/
                        break;
                    else
                    {
                        printf("\n���� ������ �ð��밡 �ùٸ��� �ʽ��ϴ�.\n");
                        continue;
                    }
                }
                system("cls");
                if (MessageBox(NULL, L"�����Ͻðڽ��ϱ�?", L"���� ����", MB_OKCANCEL) == IDOK) /*���� ���θ� Ȯ���ϴ� �޼��� �ڽ� ��� */
                    temp->key.pay = 'Y';
                //Ȯ���� ������ ��������� Y ����
                else
                    temp->key.pay = 'N';
                //��Ҹ� ������ ��������� N ����
            }
            else
                    printf("\n�Էµ� ������ �����ϴ�.");
            break;
        }
        while (getchar() != '\n');
    } while (choice != 5);

    return 0;
}