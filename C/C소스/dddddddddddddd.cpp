#include <stdio.h>

int main(void)
{

   int ch = 0;
	
	
		printf("값을 입력받습니다:");
		ch = getchar();
  	 if (ch >= 65 && ch <= 90)
  	 {
  	    ch += 32;
  	    putchar(ch);
 	  }
  	 else if (ch >= 97 && ch <= 122)
  	 {
  	    ch -= 32;
 	     putchar(ch);
 	  }
  	 else
  	    printf("알파벳이 아닙니다.");
	
	
	
   
      
   return 0;
}
