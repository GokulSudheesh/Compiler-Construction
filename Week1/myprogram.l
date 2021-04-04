%{
#include <stdio.h>
%}
digit [0-9]
letter [A-Z a-z]
ident {letter}({letter}|{digit})*
%%
if {printf("Keyword 'if'\n");}
while {printf("Keyword 'while'\n");}
{digit} {printf("Digit\n");}
{letter} {printf("Letter\n");}
{ident} {printf("Identifier\n");}
. ECHO;
%%
