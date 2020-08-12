//�����̵� ��Ʈ Ŭ�ι� ���̾� S H C D ���� �����϶� ���� ������ �� ���� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 100000

struct card{
   char player[11];
   int number[5];
   char shape[5];
   int straight, flush, result, high_shape;
};

void choice(int *select,int *game_number);		//UI�����Լ� 
void mapping(char *c[11]);						//10, J, Q, K, A�� ��ȯ�Լ� 
void sort(char *shape, int *number);			//���� ���� �������� �����Լ� 
int high_shape(char shape[5]);					//���� ���� ī���� ����  
int straight_check(int num[]);					//��Ʈ����Ʈ ���� �Լ� 
int flush_check(char color[]);					//�÷��� ���� �Լ� 
int calculation(int col, int li, char card[10]);//����Լ�  
void count(char card[11], int *num, int *num2, int *plus);	//����Լ� �� �� ����   
void final_print(int result, int num);			//���� ���  

int main()
{   
	while(1){
		struct card teamA;
   		struct card teamB;
   		int select = 0;
   		int game_number = 0;
   		int result = 0;
   
   		choice(&select, &game_number);

   		scanf("%s",teamA.player);
   		scanf("%s",teamB.player);
   		if (select != 3){
	   	do{
	        int i, j=0;
	     
	        for(i=0;i<10;i=i+2) {
	            teamA.shape[j] = teamA.player[i+1];
	            teamA.number[j] = teamA.player[i];
	            j++;
	        }
	        mapping(teamA.player);
	        sort(&teamA.shape, &teamA.number);
	        teamA.straight=straight_check(&teamA.number);
	        teamA.flush=flush_check(&teamA.shape);
	        teamA.result = calculation(teamA.flush, teamA.straight, teamA.player);
	        teamA.high_shape = high_shape(teamA.shape);
			   
	        j = 0;
	        for(i=0;i<10;i=i+2) {
	        	teamB.shape[j] = teamB.player[i+1];
	       		teamB.number[j] = teamB.player[i];
	            j++;
	        }
	        sort(&teamB.shape, &teamB.number);
	        teamB.straight=straight_check(&teamB.number);
	        teamB.flush=flush_check(&teamB.shape);
	        teamB.result=calculation(teamB.flush, teamB.straight, teamB.player);
	        teamB.high_shape = high_shape(teamB.shape);  
	        
	        if(teamA.result>teamB.result){
	        	result = 1;
				final_print(result, teamA.result);	        	
			}else if(teamA.result>teamB.result){
				result = 2;
				final_print(result, teamB.result);
			}else{
				if(teamA.high_shape > teamB.high_shape){
					result = 1;
					final_print(result, teamA.result);
				}else{
					result = 2;
					final_print(result, teamB.result);	
				}
			}
	        printf("����ؾ� \n");
			}while(select == 1);
		}
	    else{//3�� ���� ĭ  
	    	
		}
	printf("�Ѿ� ���� \n");
	}
   
}

void choice (int *select, int *game_number){
   printf("--------------------------------------------------------------\n");
   printf("1.   Print all Game result\n");
   printf("2.   Print Game(number)\n");
   printf("3.   Delete Game(number)\n");
   printf("4.   Exit");
   printf("(�����̽��ٷ� ����ó�� �ؼ� �Է��� �ּ���!)\n");
   printf("--------------------------------------------------------------\n");
   printf("�Է�:");
   scanf("%d", select);
   if (*select != 1 && *select != 4)
      scanf("%d",game_number);
   if (*select != 1 && *select != 2 && *select != 3 && *select != 4) {
      printf("�ٽ� �Է����ּ��� \n");
      choice(select, game_number);
   }
	
}

void mapping(char *c[11]) {
    int i = 0;
	for(i=0; i<5; i++){
		if(c[2*i]=='A') c[2*i] = 14;
    	else if(c[2*i]=='K') c[2*i] = 13;
    	else if(c[2*i]=='Q') c[2*i] = 12;
    	else if(c[2*i]=='J') c[2*i] = 11;
    	else if(c[2*i]=='0') c[2*i] = 10;
    	else;
	}
}

void sort (char *shape, int *number){
	int aa, i, j;
	char bb;
	for(i=0; i<4; i++) //�������� ���ڿ� �°� 
    {
        for(j=i+1; j<5; j++)
        {
            if(number[i]>number[j])
            {
                aa=number[i];
                number[i]=number[j];
                number[j]=aa;
 
                bb=shape[i];
                shape[i]=shape[j];
                shape[j]=bb;
            }
        }
    }
}
void re_sort(char card[11]){

}

int high_shape(char shape[5]){
	if (shape[5] = 'S'){
		return 4;
	}else if (shape = 'H'){
		return 3;
	}else if (shape = 'C'){
		return 2;
	}else{
		return 1;
	}
		
}

int straight_check(int num[]){
	int i;
	int c = 1;
    for(i=0; i<4; i++) //���ڰ� �������ΰ�? 
    {
        if(num[i]+1!=num[i+1])
        	if(num[i+1]==14 && num[i]==5)
        		c++;
        	else
            	break;
        c++;
    }
}

int flush_check(char color[]){
	int i, c=1;
 
    for(i=1; i<5; i++)
    {
        if(color[0]!=color[i])
            break;
        c++;
    }
 
    return c;
}

int calculation(int col, int li, char card[11]){
	if(col==5 && li==5) //1. ī�� 5���� ��� ���� ���̸鼭 ���ڰ� �������� �� 
        if (card[8] == 14){
        	return 1000 + card[8];
		}else{
			return 900 + card[8];
		} 
    else if(col==5) //4. ī�� 5���� ��� ���� ���� �� 
        return 600 + card[8];
 
    else if(li==5) //5. ī�� 5���� ���ڰ� �������� �� 
        return 500 + card[8];
 
    else
    {
    	int num = 1;
		int num2 = 1;
		int plus = 0; 
		count(card[11], &num, &num2, &plus);
 
        if(num==4) //2. ī�� 4���� ���ڰ� ���� �� 
            return 800 + plus;
 
        else if(num==3)
        {
            if(num2==2) //3. ī�� 3���� ���ڰ� ���� ������ 2�嵵 ���ڰ� ���� �� 
                return 700 + plus;
 
            else //6. ī�� 3���� ���ڰ� ���� �� 
                return 400 + plus;
        }
 
        else if(num==2)
        {
            if(num2==2) //7. ī�� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� �� 
                return 300 + plus;
 
            else //8. ī�� 2���� ���ڰ� ���� �� 
                return 200 + plus;
        }
        else //� ��쵵 �ش����� ���� �� 
            return 100 + plus;
 
    }
}

void count(char card[11], int *num, int *num2, int *plus) //���� ������ ���� 
{
	int count = 1;
	int i, j;
    for(i=0;i<4;i++){
    	for(j=0;j<4-i;j++){
    		if(card[2*i] == card[2+(2*j)+(2*i)]){
				count++;
				plus = card[2+(2*j)+(2*i)];
			}	
		}
	}
	if (count == 4){
		if (card[2] == card[6]){	//��ī��  
			num = 4;
		}else{
			num = 3;			//Ǯ �Ͽ콺  
			num2 = 2;
		}
	}else if(count == 3){		
		if (card[0] == card[2] && card[0] == card[4]){//Ʈ����  
			num = 3;
			num2= 1;
		}else if (card[2] == card[4] && card[2] == card[6]){//Ʈ����  
			num = 3;
			num2= 1;
		}else if (card[4] == card[6] && card[4] == card[8]){//Ʈ����  
			num = 3;
			num2= 1;
		}else{//�����  
			num = 2;
			num2 = 2;
		}
	}else if(count == 2){
		num = 2;
		num2 = 1;
	}else{
		num = 1;
		plus = card[8];
	}
}
void final_print(int result, int num){
	if (result == 1){
		if (num/100 == 10){
			printf("�ξ� ��Ʈ����Ʈ �÷����� A�� �̰���ϴ�.");
		}else if (num/100 == 9){
			printf("��Ʈ����Ʈ �÷����� A�� �̰���ϴ�.");
		}else if (num/100 == 8){
			printf("��ī��� A�� �̰���ϴ�.");
		}else if (num/100 == 7){
			printf("Ǯ�Ͽ콺�� A�� �̰���ϴ�.");
		}else if (num/100 == 6){
			printf("�÷����� A�� �̰���ϴ�.");
		}else if (num/100 == 5){
			printf("��Ʈ����Ʈ�� A�� �̰���ϴ�.");
		}else if (num/100 == 4){
			printf("Ʈ���÷� A�� �̰���ϴ�.");
		}else if (num/100 == 3){
			printf("������ A�� �̰���ϴ�.");
		}else if (num/100 == 2){
			printf("������ A�� �̰���ϴ�.");
		}else{
			printf("ž���� A�� �̰���ϴ�.");
		}
	}else{
		if (num/100 == 10){
			printf("�ξ� ��Ʈ����Ʈ �÷����� B�� �̰���ϴ�.");
		}else if (num/100 == 9){
			printf("��Ʈ����Ʈ �÷����� B�� �̰���ϴ�.");
		}else if (num/100 == 8){
			printf("��ī��� B�� �̰���ϴ�.");
		}else if (num/100 == 7){
			printf("Ǯ�Ͽ콺�� B�� �̰���ϴ�.");
		}else if (num/100 == 6){
			printf("�÷����� B�� �̰���ϴ�.");
		}else if (num/100 == 5){
			printf("��Ʈ����Ʈ�� B�� �̰���ϴ�.");
		}else if (num/100 == 4){
			printf("Ʈ���÷� B�� �̰���ϴ�.");
		}else if (num/100 == 3){
			printf("������ B�� �̰���ϴ�.");
		}else if (num/100 == 2){
			printf("������ B�� �̰���ϴ�.");
		}else{
			printf("ž���� B�� �̰���ϴ�.");
		}
	}
}

