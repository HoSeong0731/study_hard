#include <stdio.h>
int cal(int *ch1)
{
	while(1)
	{
		if (*ch1 >= 65 && *ch1 <= 90)
 	  {
 	     *ch1 += 32;
 	     putchar(*ch1);
 	     break;
  	 }
  	 else if (*ch1 >= 97 && *ch1 <= 122)
  	 {
  	    *ch1 -= 32;
  	    putchar(*ch1);
  	    break;
  	 }
  	 else
  	    printf("알파벳이 아닙니다.");	
   	   return 1; 
   	   break;
		}

}
int main(void)
{
   int ch = 0;
   back:
   printf("값을 입력받습니다:");
   ch = getchar();
	cal(&ch);   
	if(ch = 1) 
	{
		goto back;
	}

      
   return 0;
}
