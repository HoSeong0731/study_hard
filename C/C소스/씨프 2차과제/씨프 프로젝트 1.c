#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char benglish[26] = {
   'A','B','C','D','E',
   'F','G','H','I','J',
   'K','L','M','N','O',
   'P','Q','R','S','T',
   'U','V','W','X','Y',
   'Z' };//����� ���� ����
char senglish[26] = {
   'a','b','c','d','e',
   'f','g','h','i','j',
   'k','l','m','n','o',
   'p','q','r','s','t',
   'u','v','w','x','y',
   'z' };//�Է¹ޱ� ���� ����
char * mos[26] = {
   ".-","-...","-.-.","-..",".",
   "..-.","--.","....","..",".---",
   "-.-",".-..","--","-.","---",
   ".--.","--.-",".-.","...","-",
   "..-","...-",".--","-..-","-.--",
   "--.." };//�𽺺�ȣ

int error1(char input, int num) //ù���� �Է� �� �����̽��� �Ǵ� ���͸� �Է��Ͽ���.
{
   if ((input == ' ' || input == '\n') && num == 0)
      return 1;
}
int error2(char input,int mos,int english)//�𽺺�ȣ�� �ԷµǴ� ����� ���Ͽ���.(�ݴ��� ������) 
{
   if ( mos == 1 && english==1)
      return 1;

}
int error3(char input) //�ٸ� ���ڰ� ��� �� ���
{
   if (input == 45 || input == 46)
      return 0;
   else if (input == 10 || input == 32)
      return 0;
   else if ((input > 96 && input < 123) || (input > 64 && input < 91))
      return 0;
   else
      return 1;
}



int main()
{

   char input, getin[1][10] = { 0 }, mos_jump[2];
   //input �Է� ���� ��
   //getin input�� ���� getin�� ����
   //mos_jump �����̽���(10)�� �ι� �ԷµǸ� �𽺺�ȣ�� ���⸦ ���� ���� ����
   int i, k, num1=0, up=0, exit=0, mos_use=0, english_use=0, jump=0;// i �ݺ����� ����
   int Error1 = 0, Error2 = 0, Error3 = 0;
   char * English = (char*)calloc(30,sizeof(char));	//30ĭ¥�� �����Ҵ� 
   char * Mos = (char*)calloc(30, sizeof(char));	//30ĭ¥�� �����Ҵ�  
   int text, print=0;
   

   while (1)
   {  
      printf("In:");
      do {	//�ѱ��ھ� ��ȯ�Ǵ� �� �ݺ��Ǵ� dowhile��  
         
         input = getchar();	//����ڿ��� ���� �Է¹���  
         
         Error1 = error1(input, num1);					//����Ȯ��1 (num1�� 0�� ������ ���� ����) 
         Error2 = error2(input, mos_use, english_use);	//����Ȯ��2 
         Error3 = error3(input);						//����Ȯ��3 
         num1 = 1;//45= "-",46=".", 32=" ", 10="\n"
         if (Error1 == 1)
         {
            exit = 1;
            printf("�����Դϴ�. ���α׷��� �����մϴ�.");
            break; 	//dowhile�� Ż��  
         }
         if (Error2 == 1)
         {
            exit = 1;
            printf("\n�ڵ带 �ؼ��ϴ� �� �ٸ� �� ���Խ��ϴ�. ���α׷��� �����մϴ�.");
            break; 	//dowhile�� Ż��   
         }
         if (Error3 == 1)
         {
            exit = 1;
            printf("\n��� �𽺺�ȣ�� �ƴ� �ٸ� ���� �Է��߽��ϴ�. ���α׷��� �����մϴ�.");
            break; 	//dowhile�� Ż��   
         }
        
         if (print == 0)	//ó������ out�� ����ϱ� ����. ù��° ���� ���������� print = 1�� �ٲ���. 
            printf("Out:");

         if ((input == '\n' && mos_use == 1) || (input == 32 && mos_use == 1))
         {
            for (i = 0; i < 26; i++)//�𽺺�ȣ�� �Է� �޾��� ��
            {

               if (!strcmp(getin[0], mos[i]))	//mos[i]���� 0�� �ƴϸ� ���� 
               {
                  printf("%c", benglish[i]);	//�빮�� ���  
                  mos_jump[0] = 0;				
                  mos_jump[1] = 0;
                  for (k = 0; k < 10; k++)		//�𽺺�ȣ�� �������� ����� �ѱ��ھ� �̹Ƿ�  
                     getin[0][k] = 0;
                  break;		//��� �Է� �޾��� ���� �Ѿ�� �ʱ� ���� �ʿ�.  
               }
            }
         }
         
         do{
         	for (i = 0; i < 26; i++)//��� �Է� �޾��� ��
            {
               if (input == senglish[i] || input == benglish[i])//��ġ �� ������ �ϳ��� ���� �޴´�.
               {
                  printf("%s ", mos[i]);	//�����ͷ� �Ҵ��� ����ü �������� ����  
               }
            }
		 }while(0);	//ó���� ������ ���� �ȹ޴� ������ �ذ��ϱ� ����(ó�� do while���� ������ english_use���� ������ 0��.) 
         if(english_use==1)
         {
            
            if (input == 32)	//�ƽ�Ű�ڵ� ������ �����̽��ٰ� 32��.  
            {
               printf(" ");
            }
         }
         if (input == 32&&mos_use==1)
         {
            up = 0;					//�Ѱ��� �Էµǰ� ���� -���� ���� ���� �غ� �Ѵ�.
            mos_jump[jump] = input;	//�� ��ȣ�� ����� �˸���.
            jump++;					//���� ���� �ʱ�ȭ���ش�.
         }
         else if ((input > 96 && input < 123) || (input > 64 && input < 91))//a=97, z=122, A=65, Z=90
            english_use=1;
      
         else if (input == 45 || input == 46)
         {
            getin[0][up] = input;	//input�� �Է°��� �迭�� �ϳ��ϳ� �����Ѵ�.
            up++;			//�Ѱ��� �Էµǰ� ���� -���� ���� ���� �غ� �Ѵ�.
            mos_use = 1;	//�� ��ȣ�� ����� �˸���.
            jump = 0;		//���� ���� �ʱ�ȭ���ش�.
         }
         if (mos_jump[0] == 32 && mos_jump[1] == 32)
            printf(" ");	//���
         print = 1;			//out�� ����� ���ϱ� ���� ������Ų��.
      } while (input != '\n');	//input���� \n�� �ö����� �ݺ��Ѵ�.  
      
      
      if (exit == 1)	//������ �ɸ��� ���ѹݺ� Ż��  
         break;
      else if (exit == 0)	
         break;			//���������� dowhile���� ����Ǿ Ż��  
   }

   return 0;			//main�Լ� ����  
}
