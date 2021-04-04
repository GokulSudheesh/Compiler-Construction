%{
//this doesnt work dumbass
#include <stdio.h>
char year[5], stream[3], T_P[3], idno[5];
%}

year [2][0-9]{3}
stream [A]([A]|[0-9]{1})	
TSPS [PT]{1}[S]
id_no [0-9]{4}
full_id {year}{stream}{TSPS}{id_no}[U]

%%
{year} { printf("Year"); return(atoi(yytext));}
{stream} { printf("Stream"); return(yytext);}
{TSPS} { printf("TS/PS"); return(yytext);}
{id_no} { printf("id_no"); return(yytext);}
{full_id} { details(); }
. { printf("Not valid."); }
%%

details(){
	/*
	char *buff = yytext;//2018A7PS0067U
	printf("Year: %.*s", 4, buff+0); //4-->bytes, buff+0 --> 0th index
	printf(" Stream: %.*s", 2, buff+4);
	printf(" PS/TS: %.*s", 2, buff+6);
	printf(" Id_no: %.*s", 4, buff+8);
	*/
	printf("Year: %.*s", year);
	printf(" Stream: %.*s", stream);
	printf(" PS/TS: %.*s", T_P);
	printf(" Id_no: %.*s", idno);
}

main(){
	
	strcpy(year, yylex());
	strcpy(stream, yylex());
	strcpy(T_P, yylex());
	strcpy(idno, yylex());
}