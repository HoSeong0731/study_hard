#include <stdio.h>

int main(void)
{

   int ch = 0;
	
	
		printf("���� �Է¹޽��ϴ�:");
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
  	    printf("���ĺ��� �ƴմϴ�.");
	
	
	
   
      
   return 0;
}
