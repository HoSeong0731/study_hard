#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dhfb_1;
int dhfb_2;
int dhfb_3;
int dhfb_4;

int main()
{
   char * mos;
   char * text;
   char * a;
   int re,len,up=0;
   char abc;
   mos = (char*)malloc(sizeof(char));
   text = (char*)malloc(sizeof(char));
   a = (char*)malloc(sizeof(char)*strlen(text));
   
   
   printf("in:");
   gets(mos);
   len = strlen(mos);
   printf("Out:");
   
   for (re = 0; re < len + 1; re++)
   {
      if (mos[re] == 'a')
         printf(".- ");
      else if (mos[re] == 'b')
         printf("-... ");
      else if (mos[re] == 'c')
         printf("-.-. ");
      else if (mos[re] == 'd')
         printf("-.. ");
      else if (mos[re] == 'e')
         printf(". ");
      else if (mos[re] == 'f')
         printf("..-. ");
      else if (mos[re] == 'g')
         printf("--. ");
      else if (mos[re] == 'h')
         printf(".... ");
      else if (mos[re] == 'i')
         printf(".. ");
      else if (mos[re] == 'j')
         printf(".--- ");
      else if (mos[re] == 'k')
         printf("-.- ");
      else if (mos[re] == 'l')
         printf(".-.. ");
      else if (mos[re] == 'm')
         printf("-- ");
      else if (mos[re] == 'n')
         printf("-. ");
      else if (mos[re] == 'o')
         printf("--- ");
      else if (mos[re] == 'p')
         printf(".--. ");
      else if (mos[re] == 'q')
         printf("--.- ");
      else if (mos[re] == 'r')
         printf(".-. ");
      else if (mos[re] == 's')
         printf("... ");
      else if (mos[re] == 't')
         printf("- ");
      else if (mos[re] == 'u')
         printf("..- ");
      else if (mos[re] == 'v')
         printf("...- ");
      else if (mos[re] == 'w')
         printf(".-- ");
      else if (mos[re] == 'x')
         printf("-..- ");
      else if (mos[re] == 'y')
         printf("-.-- ");
      else if (mos[re] == 'z')
         printf("--.. ");
      else if (mos[re] == ' ')
         printf(" ");
   }
   printf("\n");
   printf("out:");
   gets(text);

   len = strlen(text);
   printf("In:");
   
   while(scanf_s("%c",&abc)!='\n')
   {
      if (abc == '.-')
         printf("A");
         else if (text[re] == '-...')
            a[up] = "B";
         else if (text[re] == '-.-.')
            a[up] = "C";
         else if (text[re] == '-..')
            a[up] = "D";
         else if (text[re] == '.')
            a[up] = "E";
         else if (text[re] == '..-.')
            a[up] = "F";
         else if (text[re] == '--.')
            a[up] = "G";
         else if (text[re] == '....')
            a[up] = "H";
         else if (text[re] == '..')
            a[up] = "I";
         else if (text[re] == '.---')
            a[up] = "J";
         else if (text[re] == '-.-')
            a[up] = "K";
         else if (text[re] == '.-..')
            a[up] = "L";
         else if (text[re] == '--')
            a[up] = "M";
         else if (text[re] == '-.')
            a[up] = "N";
         else if (text[re] == '---')
            a[up] = "O";
         else if (text[re] == '.--.')
            a[up] = "P";
         else if (text[re] == '--.-')
            a[up] = "Q";
         else if (text[re] == '.-.')
            a[up] = "R";
         else if (text[re] == '...')
            a[up] = "S";
         else if (text[re] == '-')
            a[up] = "T";
         else if (text[re] == '..-')
            a[up] = "U";
         else if (text[re] == '...-')
            a[up] = "V";
         else if (text[re] == '.--')
            a[up] = "W";
         else if (text[re] == '-..-')
            a[up] = "X";
         else if (text[re] == '-.--')
            a[up] = "Y";
         else if (text[re] == '--..')
            a[up] = "Z";
         else if (text[re] == ' ')
            a[up] = " ";
         up++;
      
   }
   return 0;

}
