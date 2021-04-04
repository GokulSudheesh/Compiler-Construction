%{
#include<stdio.h>
int characters = 0;
int words = 0;
int lines = 0;
%}
%%
[a-zA-Z]+ { lencheck(); }
\n { characters++; lines++; }
. { characters++; }
%%
lencheck(){
	int len = strlen(yytext);
	if(len >= 6){
		words++; 
		characters += strlen(yytext);
	}
}
main(int argc, char **argv)
{
	yylex();
	printf(" Number of lines=%d\n Number of words=%d\n Number of characters=%d\n",lines, words, characters);
}
