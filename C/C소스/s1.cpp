#include <stdio.h>

int main(void)
{
   int a, s, d;// 새우깡700, 크림빵500, 콜라400
   int m = 0;

   printf("소유하고 있는 금액: 3500 \n");

      for (a = 1; a < 5; a++)
      {
         for (s = 1; s < 5; s++)
         {
            m = 3500 - (700 * a) - (500 * s); 
            if (m > 0 && (m % 400 == 0))//콜라가 400원이여서 최소 400원이 있어야 하며 돈이 음수이면 안된다
            {
               d = m / 400; //나머지로 산 콜라
               break; //s for문을 탈출하기 위해 
            }
         }
         if (s < 5)
            printf("새우깡 %d개, 크림빵 %d개, 콜라 %d개 \n", a, s, d);
      }

   printf("어떻게 구입하시겠습니까?");
   return 0;
}
