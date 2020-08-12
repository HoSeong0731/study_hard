#include <stdio.h>
#include <stdlib.h>
 
char color[5]; //���� �Է¹��� �迭 
int num[5]; //���� �Է¹��� �迭
int line_num[4][2]={0};
 
int flush_check(void);		//�÷��� Ȯ�� �Լ�  
int straight_check(void);	//��Ʈ����Ʈ Ȯ�� �Լ�  
void count(void);
void pr(void);

int main(void)
{
    int i, col, li;
 
    for(i=0; i<5; i++)
        scanf(" %c %d", &color[i], &num[i]);
 
    col=flush_check();
    li=straight_check();
 
    if(col==5 && li==5) //1. ī�� 5���� ��� ���� ���̸鼭 ���ڰ� �������� �� 
        printf("%d", num[4]+900);
 
    else if(col==5) //4. ī�� 5���� ��� ���� ���� �� 
        printf("%d", num[4]+600);
 
    else if(li==5) //5. ī�� 5���� ���ڰ� �������� �� 
        printf("%d", num[4]+500);
 
    else
    {
        count();
 
        if(line_num[0][1]==4) //2. ī�� 4���� ���ڰ� ���� �� 
            printf("%d", line_num[0][0]+800);
 
        else if(line_num[0][1]==3)
        {
            if(line_num[1][1]==2) //3. ī�� 3���� ���ڰ� ���� ������ 2�嵵 ���ڰ� ���� �� 
                printf("%d", (line_num[0][0]*10)+line_num[1][0]+700);
 
            else //6. ī�� 3���� ���ڰ� ���� �� 
                printf("%d", line_num[0][0]+400);
        }
 
        else if(line_num[0][1]==2)
        {
            if(line_num[1][1]==2) //7. ī�� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� �� 
                printf("%d", (line_num[1][0]*10)+line_num[0][0]+300);
 
            else //8. ī�� 2���� ���ڰ� ���� �� 
                printf("%d", line_num[0][0]+200);
        }
        else //� ��쵵 �ش����� ���� �� 
            printf("%d", num[4]+100);
 
    }
 
 
 
    return 0;
}
 
int flush_check(void) //�÷����� ���� Ȯ�� 
{
    int i, c=1;
 
    for(i=1; i<5; i++)
    {
        if(color[0]!=color[i])
            break;
        c++;
    }
 
    return c;
}
 
int straight_check(void)
{
    int i, j, aa, c=1;
    char bb;
 
    for(i=0; i<4; i++) //�������� 
    {
        for(j=i+1; j<5; j++)
        {
            if(num[i]>num[j])
            {
                aa=num[i];
                num[i]=num[j];
                num[j]=aa;
 
                bb=color[i];
                color[i]=color[j];
                color[j]=bb;
            }
        }
    }
 
    for(i=0; i<4; i++) //���ڰ� �������ΰ�? 
    {
        if(num[i]+1!=num[i+1])
            break;
        c++;
    }
 
    return c;
}
 
void count(void) //���� ������ ���� 
{
    int i, j, a=0, aa;
    //printf("start \n");
    //pr();
    for(i=0; i<5;)
    {
    //  printf("for i= %d\n", i);
        line_num[a][0]=num[i];
        line_num[a][1]=1;
 
        for(j=i+1; j<5; j++)
        {
            if(num[i]==num[j])
                line_num[a][1]++;
 
            else
            {
                i=j;
                a++;
                break;
            }
 
        }
      printf("j= %d \n", j);
      printf("for \n");
      pr();
      system("pause");
 
        if(a>3 || j>4)
            break;
    }
 
    for(i=0; i<3; i++)
    {
        for(j=i+1; j<4; j++)
        {
            if(line_num[i][1]<line_num[j][1])
            {
                aa=line_num[i][0];
                line_num[i][0]=line_num[j][0];
                line_num[j][0]=aa;
 
                aa=line_num[i][1];
                line_num[i][1]=line_num[j][1];
                line_num[j][1]=aa;
            }
        }
    }
  printf("finish \n");
  pr();
 
}
void pr(void)
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("[%d] - %d %d \n", i, line_num[i][0], line_num[i][1]);
    }
    printf("\n\n");
}
