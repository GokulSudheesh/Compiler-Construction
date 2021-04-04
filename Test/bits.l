%{
#include <stdio.h>
%}

year [2][0-9]{3}
stream [A]([A]|[0-9]{1})	
TSPS [P,T]{1}[S]
id_no [0-9]{4}
full_id {year}{stream}{TSPS}{id_no}[U]
not_id {^full_id}
%%
{year}  {printf(" Year: %s", yytext);}
{stream} { printf(" Stream: %s", yytext);}
{TSPS} { printf(" PS/TS: %s", yytext); }
{id_no} { printf(" Id_no: %s", yytext); }
{full_id} { details(); }
{not_id} { printf(" Not valid."); }
%%

details(){
	char *buff = yytext;//2018A7PS0067U
	printf("Year: %.*s", 4, buff+0); //4-->bytes, buff+0 --> 0th index
	printf(" Stream: %.*s", 2, buff+4);
	printf(" PS/TS: %.*s", 2, buff+6);
	printf(" Id_no: %.*s", 4, buff+8);
}

main(){
	yylex();
}