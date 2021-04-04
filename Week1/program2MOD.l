/*A program that counts the number of characters, words and lines in a file*/
/*Modify program2.l so that it counts only those words which are of length at least 6.*/
%{
#include<stdio.h>
int chars = 0;
int words = 0;
int lines = 0;
%}
%%
[a-zA-Z]+ { check_length(); }
\n { chars++; lines++; }
. { chars++; }
%%
check_length(){
	int len = strlen(yytext);
	if(len >= 6){
		words++; 
		chars += strlen(yytext);
	}
}
main(int argc, char **argv)
{
	yylex();
	printf(" Number of lines=%d\n Number of words=%d\n Number of characters=%d\n",lines, words, chars);
}
