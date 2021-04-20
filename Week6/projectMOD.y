%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);
	int yylineno;
	int success = 1;
	int current_data_type;
	int expn_type=-1;
	int expn_type_temp=-1;
	int is_modulus = 0;
	int isValue = 1;
	int is_Array;
	int temp;
	int dims;
	int array_dim[5];
	int ptr_depth;
	struct symbol_table{char var_name[30]; int type; int dim; int pointerDepth; int dim_bounds[5];}var_list[20];
	int var_count=-1;
	struct symbol_table get_column(char var[30]);
	extern int lookup_in_table(char var[30]);
	extern void insert_to_table(char var[30], int type);
	extern int get_array_dimensions(char var[30]);
	void check_EXPNtype_rhs(char var[30]);
	void check_EXPNtype_lhs(char var[30]);
%}

%union{
int data_type;
char var_name[30];
int integer_val;
struct 
	{
		int  data_depth;
		int type;
		int isValue;
	}EXPN_type;
}
%token HASH INCLUDE HEADER_FILE MAIN LB RB LCB RCB LSQRB RSQRB SC COLON QMARK COMA IF ELSE FOR DO WHILE ET EQ GT LT GTE LTE NE AMPER OR NOT DQUOTE PLUS MINUS MUL DIV MOD EXP UPLUS UMINUS

%left PLUS MINUS
%left MUL DIV MOD
%left UMINUS
%left UPLUS
%right EXP
%right AMPER
%token<data_type>INT
%token<data_type>CHAR
%token<data_type>FLOAT
%token<data_type>DOUBLE
%token<var_name>VAR
%token<integer_val>NUMBER
%type<data_type>DATA_TYPE
%type<var_name>VAR_ARRAY_ACCESS_LHS
%type<var_name>VAR_ARRAY_ACCESS_RHS
%type<EXPN_type>A_EXPN
%type<EXPN_type>POINTER_STATEMENTS_LHS

%start prm

%%
prm	: HEADERS MAIN_TYPE MAIN LB RB LCB BODY RCB {
							printf("\n parsing successful\n");
						   }
HEADERS : HEADER HEADERS | HEADER
HEADER	: HASH INCLUDE LT HEADER_FILE GT | HASH INCLUDE DQUOTE HEADER2 HEADER_FILE DQUOTE
HEADER2 :  HEADER2 VAR DIV {/*printf("<HEADER2 VAR DIV>");*/} | DIV {/*printf("<DIV>");*/} | /*Epsilon*/ {/*printf("<HEADER2->Epsilon>");*/}
BODY	: DECLARATION_STATEMENTS BODY2
BODY2	: /*Epsilon*/ | DECLARATION_STATEMENTS BODY2 | PROGRAM_STATEMENTS BODY2

DECLARATION_STATEMENTS: DATA_TYPE VAR_LIST SC {}
VAR_LIST : VAR COMA VAR_LIST {
				insert_to_table($1,current_data_type);
			    }
	| ARRAY_DECLARATION COMA VAR_LIST {
		//printf("<ARRAY_DECLARATION COMA VAR_LIST>");
	}
	| PTR_VAR COMA VAR_LIST
	| VAR {
		insert_to_table($1,current_data_type);
	      }
	| ARRAY_DECLARATION {
		//printf("<ARRAY_DECLARATION>");
	}
	| PTR_VAR
PTR_VAR :	PTR_DEPTH VAR {
				//printf("<PTR_DEPTH VAR>");
				insert_to_table($2,current_data_type);
				ptr_depth = 0;
			}
PTR_DEPTH :	MUL PTR_DEPTH {
				//printf("<MUL PTR_DEPTH>");
				ptr_depth++;

			} 
			| MUL {				
				//printf("<MUL>");
				ptr_depth = 0;
				ptr_depth++;
			}
ARRAY_DECLARATION: VAR ARRAY_SIZE {
		is_Array = 1;
		insert_to_table($1,current_data_type);
	}
ARRAY_SIZE : ARRAY_SIZE LSQRB NUMBER RSQRB {
				dims++;
				array_dim[dims] = $3;
				//printf("<ARRAY_SIZE LSQRB %d RSQRB>", $3);
			}
			| LSQRB NUMBER RSQRB {
				dims = 0;
				array_dim[dims] = $2;
				//printf("<LSQRB %d RSQRB>", $2);
			}
MAIN_TYPE : INT
DATA_TYPE : INT {
			$$=$1;
			current_data_type=$1;
		} 
	| CHAR  {
			$$=$1;
			current_data_type=$1;
		}
	| FLOAT {
			$$=$1;
			current_data_type=$1;
		}
	| DOUBLE {
			$$=$1;
			current_data_type=$1;
		}
 
PROGRAM_STATEMENTS :	VAR_EXPN1 SC
				| SC
				| VAR_EXPN2 SC
				| POINTER_STATEMENTS SC
				| LB LOGICAL_EXPN RB QMARK LCB BODY2 RCB COLON LCB BODY2 RCB 
				| IF LB LOGICAL_EXPN RB LCB BODY2 RCB
				| IF LB LOGICAL_EXPN RB LCB BODY2 RCB ELSE LCB BODY2 RCB
				| WHILE LB LOGICAL_EXPN RB LCB BODY2 RCB
				| DO LCB BODY2 RCB WHILE LB LOGICAL_EXPN RB SC
				| FOR LB VAR_EXPN1 SC LOGICAL_EXPN SC VAR_EXPN2 RB LCB BODY2 RCB

POINTER_STATEMENTS : POINTER_STATEMENTS_LHS EQ A_EXPN{
						if($1.type!=$3.type)
						{
							yyerror("\ntype mismatch in the expression\n");
							exit(0);
						}else if($1.data_depth!=$3.data_depth)
						{
							printf("\n Line number: %d Warning : Incompatible pointer type in assignment",yylineno);
						}
						else if($1.isValue==1)
						{
							yyerror("lvalue required as left operand of the assignment operator");
							exit(0);
						}
						if (is_modulus){
							if(expn_type!=0){
								yyerror("Modulus operator reserved for integers."); exit(0);
							}	
							is_modulus = 0;
						}
						expn_type = -1;
					}
POINTER_STATEMENTS_LHS	: MUL A_EXPN {
							if($2.data_depth==0)
							{
								yyerror("Invalid operand to unary \'*\' operator");
								exit(0);
							}
							if(isValue){
								yyerror("lvalue required as left operand of the assignment operator");
								exit(0);
							}
							else
							{
								$$.type=$2.type;
								$$.data_depth=$2.data_depth-1;
								$$.isValue=0;
							}
							expn_type = -1;
						}
LOGICAL_EXPN	: NOT LB LOGICAL_EXPN1 RB | LOGICAL_EXPN1
LOGICAL_EXPN1	: LOGICAL_EXPN1 LOGICAL_OPERATOR LOGICAL_EXPN1 | LOGICAL_EXPN2 | NOT LB LOGICAL_EXPN1 RB 
				| LB LOGICAL_EXPN1 RB
LOGICAL_EXPN2	: LOGICAL_EXPN2_ARTH COMP_OPERATOR LOGICAL_EXPN2_ARTH
LOGICAL_EXPN2_ARTH	: A_EXPN {
						if (is_modulus){
							if(expn_type!=0){
								yyerror("Modulus operator reserved for integers."); exit(0);
							}
							is_modulus = 0;
						}
						expn_type = -1;
					} 
COMP_OPERATOR	: ET | GT | LT | GTE | LTE | NE
LOGICAL_OPERATOR	: AMPER AMPER | OR

VAR_EXPN1	: VAR EQ A_EXPN {	
					check_EXPNtype_lhs($1);
			}
			| VAR_ARRAY_ACCESS_LHS EQ A_EXPN {
					//printf("<VAR_ARRAY_ACCESS_LHS EQ A_EXPN SC>");
					check_EXPNtype_lhs($1);					
			}

VAR_EXPN2	: VAR ARRAY_ACCESS UNARY_OPERATORS {
				if(lookup_in_table($1)==-1){
					printf("\n variable \"%s\" undeclared\n",$1);exit(0);
				}
				if(dims!=get_array_dimensions($1)){
					printf("\n Error: Indexing error in array: %s\n", $1);
					exit(0);
				}				
			} 
			| VAR UNARY_OPERATORS {
				if(lookup_in_table($1)==-1){
					printf("\n variable \"%s\" undeclared\n",$1);exit(0);
				}
			}

VAR_ARRAY_ACCESS_LHS	: VAR ARRAY_ACCESS {
					strcpy($$,$1);
					if(get_array_dimensions($1)==0){
						yyerror("Subscripted value neither array nor pointer");
						exit(0);
					}
					if(dims!=get_array_dimensions($1)){
						printf("\n Error: Indexing error in array: %s\n", $1);
						exit(0);
					}					
				}
VAR_ARRAY_ACCESS_RHS	: VAR ARRAY_ACCESS {
						check_EXPNtype_rhs($1);
						strcpy($$,$1);
						if(get_array_dimensions($1)==0){
							yyerror("Subscripted value neither array nor pointer");
							exit(0);
						}
						if(dims!=get_array_dimensions($1)){
							printf("\n Error: Indexing error in array: %s\n", $1);
							exit(0);
						}						
				}
ARRAY_ACCESS	: ARRAY_ACCESS LSQRB {expn_type_temp = expn_type; expn_type = -1;} A_EXPN RSQRB {
					dims++;
					//printf("<ARRAY_ACCESS LSQRB %s RSQRB>");
					if (is_modulus){
						if(expn_type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if($4.data_depth!=0 || $4.type!=0){
						yyerror("\nError: Arrays must be indexed by int values."); exit(0);
					}
					expn_type = expn_type_temp;
				}
				| LSQRB {expn_type_temp = expn_type; expn_type = -1;} A_EXPN RSQRB {
					dims=0;
					dims++;
					//printf("<LSQRB %s RSQRB>");
					if (is_modulus){
						if(expn_type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if($3.data_depth!=0 || $3.type!=0){
						yyerror("\nError: Arrays must be indexed by int values."); exit(0);
					}
					expn_type = expn_type_temp;
				}

A_EXPN	: A_EXPN PLUS A_EXPN{
			$$.isValue=1;
			isValue=1;
			if($1.data_depth==$3.data_depth)
			{
				$$.data_depth=$1.data_depth;
				$$.type=$1.type;
			}
			else if($1.data_depth==0)
			{	
				if($1.type==0)
				{	$$.data_depth=$3.data_depth;
					$$.type=$3.type;
				}
			}
			else if($3.data_depth==0)
			{	
				if($3.type==0)
				{	$$.data_depth=$1.data_depth;
					$$.type=$1.type;
				}
			}
			else
			{
				yyerror("Type mismatch in dereferencing operands");
				exit(0);						
			}
		}
		| A_EXPN MINUS A_EXPN{
			$$.isValue=1;
			isValue=1;
			if($1.data_depth==$3.data_depth)
			{
				$$.data_depth=$1.data_depth;
				$$.type=$1.type;
			}
			else if($1.data_depth==0)
			{	
				if($1.type==0)
				{	$$.data_depth=$3.data_depth;
					$$.type=$3.type;
				}
			}
			else if($3.data_depth==0)
			{	
				if($3.type==0)
				{	$$.data_depth=$1.data_depth;
					$$.type=$1.type;
				}
			}
			else
			{
				yyerror("Type mismatch in dereferencing operands");
				exit(0);						
			}
		}
		| A_EXPN MUL A_EXPN{
			if($1.data_depth!=0 || $3.data_depth!=0)
			{
				yyerror("Invalid operands to binary operator *");exit(0);	
			}	
			$$.isValue = 1;
			isValue=1;
			$$.data_depth = 0;
			$$.type = $1.type;
		}
		| A_EXPN DIV A_EXPN{
			if($1.data_depth!=0 || $3.data_depth!=0)
			{
				yyerror("Invalid operands to binary operator /");exit(0);	
			}	
			$$.isValue = 1;
			isValue=1;
			$$.data_depth = 0;
			$$.type = $1.type;
		} 
		| A_EXPN MOD A_EXPN {
			is_modulus = 1;
			if($1.data_depth!=0 || $3.data_depth!=0)
			{
				yyerror("Invalid operands to binary operator %");exit(0);	
			}	
			$$.isValue = 1;
			isValue=1;
			$$.data_depth = 0;
			$$.type = $1.type;
		}
		| A_EXPN EXP A_EXPN {
			if($1.data_depth!=0 || $3.data_depth!=0)
			{
				yyerror("Invalid operands to binary operator ^");exit(0);	
			}	
			$$.isValue = 1;
			isValue=1;
			$$.data_depth = 0;
			$$.type = $1.type;
		}
		| LB A_EXPN RB {
			isValue = 0;//only for pointers
			$$.isValue = $2.isValue;
			$$.data_depth = $2.data_depth;
			$$.type = $2.type;
		}
		| NUMBER {
			expn_type = 0;
			$$.type = 0;
			$$.data_depth = 0;	
			$$.isValue = 1;
		}
		| A_EXPN UNARY_OPERATORS {
			if($$.isValue==1)
			{
				yyerror("lvalue required");exit(0);
			}else
			{
				$$.type=$1.type;
				$$.data_depth=$1.data_depth;	
				$$.isValue=1;
				isValue=1;
			}
		}
		| VAR {		
			isValue = 0;//only for pointers	
			struct symbol_table column = get_column($1);
			$$.type = column.type;
			$$.data_depth = column.pointerDepth;
			$$.isValue = 0;
			if (column.pointerDepth==0){
				check_EXPNtype_rhs($1);
			}
		}
		| MUL A_EXPN {
			if($2.data_depth==0)
			{
				yyerror("Invalid operand to unary \'*\' operator");
				exit(0);
			}
			else
			{
				$$.type=$2.type;
				$$.data_depth=$2.data_depth-1;
				$$.isValue=0;
			}	
		}
		| VAR_ARRAY_ACCESS_RHS {
			struct symbol_table column = get_column($1);
			$$.type = column.type;
			$$.data_depth = column.pointerDepth-dims;
			$$.isValue = 0;
		}
		| AMPER A_EXPN {
			if($2.isValue){
				yyerror("lvalue required for unary operator &");exit(0);
			}
			$$.type=$2.type;
			$$.data_depth=$2.data_depth+1;
			$$.isValue=1;
		}

UNARY_OPERATORS: UPLUS | UMINUS

%%

void check_EXPNtype_lhs(char var[30])
{
	if((temp=lookup_in_table(var))!=-1)
	{
		if (is_modulus){
			if(expn_type!=0 && temp!=0){
				yyerror("Modulus operator reserved for integers."); exit(0);
			}
			is_modulus = 0;
		}
		if(expn_type==-1)
		{
			expn_type=temp;
		}else if(expn_type!=temp)
		{
			yyerror("\ntype mismatch in the expression\n");
			exit(0);
		}
	}else
	{
		printf("\n variable \"%s\" undeclared\n",var);exit(0);
	}
	expn_type=-1;
}

void check_EXPNtype_rhs(char var[30])
{
	if((temp=lookup_in_table(var))!=-1)
	{		
		if(expn_type==-1)
		{
			expn_type=temp;
		}else if(expn_type!=temp)
		{
			yyerror("\ntype mismatch in the expression\n");
			exit(0);
		}
	}else
	{
		printf("\n variable \"%s\" undeclared\n",var);exit(0);
	}	
}

struct symbol_table get_column(char var[30]){
    if(lookup_in_table(var)!=-1){
		for(int i=0; i<=var_count; i++)
		{
			if(strcmp(var_list[i].var_name, var)==0)
			{
				return var_list[i];
			}
		}
	}
	else{
		printf("\n variable \"%s\" undeclared\n",var);exit(0);
	}
	return var_list[0];  
}

int lookup_in_table(char var[30])
{
	for(int i=0; i<=var_count; i++)
	{
		if(strcmp(var_list[i].var_name, var)==0)
		{
			return var_list[i].type;
		}
	}
	return -1;
}
void insert_to_table(char var[30], int type)
{
	if (lookup_in_table(var) == -1)
	{
		var_count++;
		strcpy(var_list[var_count].var_name, var);
    	var_list[var_count].type = type;
		if (is_Array){
			var_list[var_count].dim = dims+1;
			var_list[var_count].pointerDepth = dims+1;
			for(int i = 0; i <= dims; i++){
				var_list[var_count].dim_bounds[i] = array_dim[i];
				//printf("\n%d\n",var_list[var_count].dim_bounds[i]);
			}
			is_Array=0;
		}
		else{
			var_list[var_count].dim = 0;
			for(int i = 0; i < 5; i++){
				var_list[var_count].dim_bounds[i] = -1;
			}
		}
		if(ptr_depth > 0){
			var_list[var_count].pointerDepth = ptr_depth;
		}
    }
    else
    {
		char error_message[50];
		strcpy(error_message, "multiple declaration of variable: ");
    	yyerror(strcat(error_message, var));
    	exit(0);
    }
}
int get_array_dimensions(char var[30])
{
	if (lookup_in_table(var)!=-1){
		for(int i=0; i<=var_count; i++)
		{
			if(strcmp(var_list[i].var_name, var)==0)
			{
				return var_list[i].dim;
			}
		}
	}
	printf("\n variable \"%s\" undeclared\n",var);exit(0);
}
void display_symbol_table(){
	printf("\nSYMBOL TABLE\n");
	printf("Var name\tType\tPtrDepth\tDim\tDim Bounds\n");
	for(int i=0; i<=var_count; i++)
	{
		printf("%s\t\t%d\t%d\t\t%d\t{", var_list[i].var_name, var_list[i].type, var_list[i].pointerDepth, var_list[i].dim);
		for(int j=0; j<5; j++){
			printf("%d ",var_list[i].dim_bounds[j]);
		}
		printf("}\n");
	}
}
int main()
{
    yyparse();
/*    if(success)
    	printf("Parsing Successful\n");*/
	display_symbol_table();
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	return 0;
}