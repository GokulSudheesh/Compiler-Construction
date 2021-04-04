%{
/*
1.Request input of an even and an odd number
2.indicate input characteristic : Even/Odd
3.check for input's correctness and print result
*/
 
#include <stdlib.h>
#include <stdio.h>
 
int number_1;
int number_2;
 
%}
 
binary_sequence [0-1]* 
number_sequence [0-9]*
 
%%
[0]*[1][0]* { 
              int num = BinarytoInt(yytext);
              printf("Even binary number (%d) of length %d", num, yyleng);
              printf(" Power of two.");
              return num;
            } 

{binary_sequence}[0] {
                        int num = BinarytoInt(yytext);
                        printf("Even binary number (%d) of length %d", num, yyleng);
                        printf(" Not power of two.");
                        return num;
                      }

{binary_sequence}[1] {
                        int num = BinarytoInt(yytext);
                        printf("Odd binary number (%d) of length %d", num, yyleng);
                        printf(" Not power of two.");
                        return num;
                      }

{number_sequence}[0|2|4|6|8] {	
                                int num = atoi(yytext);
                                printf("Even number of length %d",yyleng);
                                if (poweroftwo(num))
									                printf(" Power of two.");
								                else
									                printf(" Not power of two.");
								                return num;
                             }
 
{number_sequence}[1|3|5|7|9] {
                                printf("Odd number of length %d",yyleng);
								                printf(" Not power of two.");
                                return atoi(yytext);
                              }
%%
 
int poweroftwo(int num){
    if (num == 0)
        return 0;
    while(num != 1){
        if(num%2 != 0)
            return 0;
        num /= 2;
    }
    return 1;
}

int BinarytoInt(const char *s) {
  return (int) strtol(s, NULL, 2); //long int strtol(const char *str, char **endptr, int base)
}

int main()
{
  printf("\nInput an even number and an odd number\n");
  number_1 = yylex();
  number_2 = yylex();
  int diff = number_1 - number_2;
  if(diff%2!=0)
    printf("\nYour inputs were checked for correctness, \nResult : Correct\n");
  else
    printf("\nYour inputs were checked for correctness, \nResult : Incorrect\n");
  return 1;
}
