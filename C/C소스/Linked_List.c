#pragma warning (disable:4996)
#include <stdio.h>

typedef struct node
{
    int num;
    struct node* pNext;
}Node;

void free_linkedlist(Node* pNode);

int main(void)
{
    Node* pHead = NULL;
    Node* pWork = NULL;
    Node* pNew = NULL;
    int num = 0;

    while (1)
    {
        printf("�Է�(����: -1): ");
        scanf("%d", &num);

        if (num == -1)
            break;

        pNew = (Node*)malloc(sizeof(Node)); // ��� ����
        pNew->num = num;    //������ ����� num����
        pNew->pNext = NULL;  //������ ����� pNext �ʱ�ȭ

        /* �ʱ� ��� ������ pHead, pWork ���� */
        if (pHead == NULL)
        {
            pHead = pNew;
            pWork = pNew;
        }

        /* ��ũ�� ����Ʈ�� ��� ���� */
        else
        {
            pWork->pNext = pNew; //��ũ�� ����Ʈ�� ������ ��� ����
            pWork = pNew; //pWork = ��ũ�� ����Ʈ�� ������ ���
        }
    }
    pWork = pHead; //ù��° ��� �ּ�

    /* ��ũ�� ����Ʈ ��� */
    while (1)
    {
        if (pWork == NULL)break;

        printf("%d->", pWork->num);

        if (pWork->pNext == NULL)
            break;

        pWork = pWork->pNext; //���� ��带 ����Ŵ
    }
    printf("NULL\n");

    /* ��ũ�� ����Ʈ ���� */
    if (pWork == NULL)return 0;
    free_linkedlist(pHead);

    return 0;
}

void free_linkedlist(Node* pNode)
{
    Node* pTemp = NULL;

    while (pNode->pNext)
    {
        pTemp = pNode; //pNode�� pTemp�� ����
        pNode = pNode->pNext; //pNode�� ���� ��带 ����Ű�� ��.
        free(pTemp);
    }
}