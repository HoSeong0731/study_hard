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
        printf("입력(종료: -1): ");
        scanf("%d", &num);

        if (num == -1)
            break;

        pNew = (Node*)malloc(sizeof(Node)); // 노드 생성
        pNew->num = num;    //생성된 노드의 num설정
        pNew->pNext = NULL;  //생성된 노드의 pNext 초기화

        /* 초기 노드 생성시 pHead, pWork 설정 */
        if (pHead == NULL)
        {
            pHead = pNew;
            pWork = pNew;
        }

        /* 링크드 리스트에 노드 연결 */
        else
        {
            pWork->pNext = pNew; //링크드 리스트에 생성된 노드 연결
            pWork = pNew; //pWork = 링크드 리스트의 마지막 노드
        }
    }
    pWork = pHead; //첫번째 노드 주소

    /* 링크드 리스트 출력 */
    while (1)
    {
        if (pWork == NULL)break;

        printf("%d->", pWork->num);

        if (pWork->pNext == NULL)
            break;

        pWork = pWork->pNext; //다음 노드를 가리킴
    }
    printf("NULL\n");

    /* 링크드 리스트 삭제 */
    if (pWork == NULL)return 0;
    free_linkedlist(pHead);

    return 0;
}

void free_linkedlist(Node* pNode)
{
    Node* pTemp = NULL;

    while (pNode->pNext)
    {
        pTemp = pNode; //pNode를 pTemp에 저장
        pNode = pNode->pNext; //pNode가 다음 노드를 가리키게 함.
        free(pTemp);
    }
}