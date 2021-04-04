%{
#include <stdio.h>
%}

year [2][0-9]{3}
disc [A]([A]|[0-9]{1})	
T_P [PT]{1}[S]
idnum [0-9]{4}
full_id {year}{disc}{T_P}{idnum}[U]

%%
{year} { printf("Year"); }
{disc} { printf("Disc"); }
{T_P} { printf("PS or TS"); }
{idnum} { printf("id no."); }
{full_id} { print_fullid(); }
. { printf("Not a valid character."); }
%%

print_fullid(){
	char *sub = yytext;
	printf("Year: %.*s", 4, sub+0);
	printf(" Disc: %.*s", 2, sub+4);
	printf(" PS or Thesis: %.*s", 2, sub+6);
	printf(" idnum: %.*s", 4, sub+8);
}

main(){
	yylex();
}