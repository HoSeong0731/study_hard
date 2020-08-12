//스페이드 하트 클로버 다이아 S H C D 같은 족보일때 문양 따지는 거 포기 
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

void choice(int *select,int *game_number);		//UI선택함수 
void mapping(char *c[11]);						//10, J, Q, K, A로 변환함수 
void sort(char *shape, int *number);			//숫자 기준 오름차순 정렬함수 
int high_shape(char shape[5]);					//가장 높은 카드의 문양  
int straight_check(int num[]);					//스트레이트 유무 함수 
int flush_check(char color[]);					//플러쉬 유무 함수 
int calculation(int col, int li, char card[10]);//계산함수  
void count(char card[11], int *num, int *num2, int *plus);	//계산함수 중 페어에 따라   
void final_print(int result, int num);			//최종 출력  

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
	        printf("계산해쓰 \n");
			}while(select == 1);
		}
	    else{//3번 넣을 칸  
	    	
		}
	printf("넘어 왔으 \n");
	}
   
}

void choice (int *select, int *game_number){
   printf("--------------------------------------------------------------\n");
   printf("1.   Print all Game result\n");
   printf("2.   Print Game(number)\n");
   printf("3.   Delete Game(number)\n");
   printf("4.   Exit");
   printf("(스페이스바로 공백처리 해서 입력해 주세요!)\n");
   printf("--------------------------------------------------------------\n");
   printf("입력:");
   scanf("%d", select);
   if (*select != 1 && *select != 4)
      scanf("%d",game_number);
   if (*select != 1 && *select != 2 && *select != 3 && *select != 4) {
      printf("다시 입력해주세요 \n");
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
	for(i=0; i<4; i++) //버블정렬 숫자에 맞게 
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
    for(i=0; i<4; i++) //숫자가 연속적인가? 
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
	if(col==5 && li==5) //1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때 
        if (card[8] == 14){
        	return 1000 + card[8];
		}else{
			return 900 + card[8];
		} 
    else if(col==5) //4. 카드 5장이 모두 같은 색일 때 
        return 600 + card[8];
 
    else if(li==5) //5. 카드 5장의 숫자가 연속적일 때 
        return 500 + card[8];
 
    else
    {
    	int num = 1;
		int num2 = 1;
		int plus = 0; 
		count(card[11], &num, &num2, &plus);
 
        if(num==4) //2. 카드 4장의 숫자가 같을 때 
            return 800 + plus;
 
        else if(num==3)
        {
            if(num2==2) //3. 카드 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 
                return 700 + plus;
 
            else //6. 카드 3장의 숫자가 같을 때 
                return 400 + plus;
        }
 
        else if(num==2)
        {
            if(num2==2) //7. 카드 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 
                return 300 + plus;
 
            else //8. 카드 2장의 숫자가 같을 때 
                return 200 + plus;
        }
        else //어떤 경우도 해당하지 않을 때 
            return 100 + plus;
 
    }
}

void count(char card[11], int *num, int *num2, int *plus) //같은 숫자의 개수 
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
		if (card[2] == card[6]){	//포카드  
			num = 4;
		}else{
			num = 3;			//풀 하우스  
			num2 = 2;
		}
	}else if(count == 3){		
		if (card[0] == card[2] && card[0] == card[4]){//트리플  
			num = 3;
			num2= 1;
		}else if (card[2] == card[4] && card[2] == card[6]){//트리플  
			num = 3;
			num2= 1;
		}else if (card[4] == card[6] && card[4] == card[8]){//트리플  
			num = 3;
			num2= 1;
		}else{//투페어  
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
			printf("로얄 스트레이트 플러쉬로 A가 이겼습니다.");
		}else if (num/100 == 9){
			printf("스트레이트 플러쉬로 A가 이겼습니다.");
		}else if (num/100 == 8){
			printf("포카드로 A가 이겼습니다.");
		}else if (num/100 == 7){
			printf("풀하우스로 A가 이겼습니다.");
		}else if (num/100 == 6){
			printf("플러쉬로 A가 이겼습니다.");
		}else if (num/100 == 5){
			printf("스트레이트로 A가 이겼습니다.");
		}else if (num/100 == 4){
			printf("트리플로 A가 이겼습니다.");
		}else if (num/100 == 3){
			printf("투페어로 A가 이겼습니다.");
		}else if (num/100 == 2){
			printf("원페어로 A가 이겼습니다.");
		}else{
			printf("탑으로 A가 이겼습니다.");
		}
	}else{
		if (num/100 == 10){
			printf("로얄 스트레이트 플러쉬로 B가 이겼습니다.");
		}else if (num/100 == 9){
			printf("스트레이트 플러쉬로 B가 이겼습니다.");
		}else if (num/100 == 8){
			printf("포카드로 B가 이겼습니다.");
		}else if (num/100 == 7){
			printf("풀하우스로 B가 이겼습니다.");
		}else if (num/100 == 6){
			printf("플러쉬로 B가 이겼습니다.");
		}else if (num/100 == 5){
			printf("스트레이트로 B가 이겼습니다.");
		}else if (num/100 == 4){
			printf("트리플로 B가 이겼습니다.");
		}else if (num/100 == 3){
			printf("투페어로 B가 이겼습니다.");
		}else if (num/100 == 2){
			printf("원페어로 B가 이겼습니다.");
		}else{
			printf("탑으로 B가 이겼습니다.");
		}
	}
}

