%{
 
#include <stdlib.h>
#include <stdio.h>
 
int number_1;
int number_2;
 
%}
 
 
number_sequence [0-9]*
binary_sequence [0-1]*
 
%%
{binary_sequence} {printf("Binary.");}
{number_sequence}[0|2|4|6|8] {	int num = atoi(yytext);
                                printf("Even number of length %d",yyleng);
                                if (power_of_two(num))
									printf(" It is a power of two.");
								else
									printf(" It is not a power of two.");
								return num;
                             }
 
{number_sequence}[1|3|5|7|9] {
                                printf("Odd number of length %d",yyleng);
								printf(" It is not power of two.");
                                return atoi(yytext);
                              }
%%
 
int power_of_two(int num){
    if (num == 0)
        return 0;
    while(num != 1){
        if(num%2 != 0)
            return 0;
        num /= 2;
    }
    return 1;
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
