%{
#include <stdio.h>
%}

words [\w]

%%
{words} { printf("Word"); }
%%

main(){
	yylex();
}