/* lex program to implement a simple calculator
*/
%{
    int op, i;
    float a,b;
%}

dig [0-9]+|([0-9]*)"."([0-9]+)
add "+"
sub "-"
mul "*"
div "/"
pow "^"
ln \n
%%
{dig} {digi();}
{add} {op=1;}
{sub} {op=2;}
{mul} {op=3;}
{div} {op=4;}
{pow} {op=5;}
{ln} {printf("\n The Answer :%f\n\n",a);}
. {printf("Invalid Input"); exit(0);}
%%
digi()
{ if(op==0)
  //op defines the operation to be performed
  a = atof(yytext); //atof convert string to float
  
  else
  {
    b = atof(yytext);
	i = a;

    switch(op)
    {
      case 1: a = a+b;
      break;
      case 2: a = a-b;
      break;
      case 3: a = a*b;
      break;
      case 4: a = a/b;
      break;
      case 5: for(int j = 1; j < b; j++) 
      a = a*i;
	  break;
	}
	op = 0;
  }
}
int main(int argc, char **argv){
  yylex();
}