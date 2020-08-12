#include <stdio.h>
#include <stdlib.h>
 
char color[5]; //색깔 입력받을 배열 
int num[5]; //숫자 입력받을 배열
int line_num[4][2]={0};
 
int flush_check(void);		//플러쉬 확인 함수  
int straight_check(void);	//스트레이트 확인 함수  
void count(void);
void pr(void);

int main(void)
{
    int i, col, li;
 
    for(i=0; i<5; i++)
        scanf(" %c %d", &color[i], &num[i]);
 
    col=flush_check();
    li=straight_check();
 
    if(col==5 && li==5) //1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때 
        printf("%d", num[4]+900);
 
    else if(col==5) //4. 카드 5장이 모두 같은 색일 때 
        printf("%d", num[4]+600);
 
    else if(li==5) //5. 카드 5장의 숫자가 연속적일 때 
        printf("%d", num[4]+500);
 
    else
    {
        count();
 
        if(line_num[0][1]==4) //2. 카드 4장의 숫자가 같을 때 
            printf("%d", line_num[0][0]+800);
 
        else if(line_num[0][1]==3)
        {
            if(line_num[1][1]==2) //3. 카드 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 
                printf("%d", (line_num[0][0]*10)+line_num[1][0]+700);
 
            else //6. 카드 3장의 숫자가 같을 때 
                printf("%d", line_num[0][0]+400);
        }
 
        else if(line_num[0][1]==2)
        {
            if(line_num[1][1]==2) //7. 카드 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 
                printf("%d", (line_num[1][0]*10)+line_num[0][0]+300);
 
            else //8. 카드 2장의 숫자가 같을 때 
                printf("%d", line_num[0][0]+200);
        }
        else //어떤 경우도 해당하지 않을 때 
            printf("%d", num[4]+100);
 
    }
 
 
 
    return 0;
}
 
int flush_check(void) //플러시의 유무 확인 
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
 
    for(i=0; i<4; i++) //버블정렬 
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
 
    for(i=0; i<4; i++) //숫자가 연속적인가? 
    {
        if(num[i]+1!=num[i+1])
            break;
        c++;
    }
 
    return c;
}
 
void count(void) //같은 숫자의 개수 
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
