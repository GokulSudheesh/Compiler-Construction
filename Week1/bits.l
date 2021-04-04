%{
#include <stdio.h>
%}

year [2][0-9]{3}
stream [A]([A]|[0-9]{1})	
TSPS [PT]{1}[S]
id_no [0-9]{4}
full_id {year}{stream}{TSPS}{id_no}[U]

%%
{year} { printf("Year"); }
{stream} { printf("Stream"); }
{TSPS} { printf("TS/PS"); }
{id_no} { printf("id_no"); }
{full_id} { details(); }
. { printf("Not valid."); }
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