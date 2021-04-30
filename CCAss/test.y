%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);
	int yylineno;
	struct Variables{char var_name[30];int is_Array;int dims;int array_dim[5];int ptr_depth;int LHS_type;}var_list[20];
	int var_list_ind = 0;
	int success = 0;
	int current_data_type;
	int is_modulus = 0;
	int array_format_spec[20];
	int format_spec_counter=0;
	int RWmode; // 1 -> read mode, 2 -> write mode
	int dims;
	char temp_string[100];
	char *temp_char;

	struct symbol_table{char var_name[30]; int type; int dim; int pointerDepth; int dim_bounds[5];};
	struct symbol_table_stack{
    	struct symbol_table var_list[100];
    	int var_count;
		int ind_level;
    	struct symbol_table_stack * prev;
    	struct symbol_table_stack * next;
	};
	struct symbol_table_stack * pointer = NULL;

	struct functions{char func_name[30]; struct fun_type{int type;int data_depth;int isValue;}func_type; int paras; struct paras_table{int type; int data_depth;} para_sym[10];}func_list[100];
	int func_count = -1; 
	struct functions func_column;
	int args;

	extern void push_table(int mode);//mode==1 -> prints "{\n" else nope
	extern void pop_table();
	struct symbol_table get_column(char var[30]);
	extern int lookup_in_table(char var[30], int mode);
	extern void insert_to_table(char var[30], int type, int is_Array, int dims, int ptr_depth, int array_dim[5]);
	extern int get_array_dimensions(char var[30]);
	extern void display_symbol_table();
	extern void display_function_table();
	extern void format_string(char str[200]);
	extern void check_ind(int current_ind);
	struct functions func_lookup(char var[30]);
	void check_func(char str[30]);
	extern void print_tabs(int mode);//0 -> prev ind level | 1 -> current ind level
%}

%union{
	int line_ind;	
	int data_type;
	struct 
		{
			int type;char code[100];
		}DATA_type;
	char var_name[30];
	char code[100];
	struct{
		int integer_val;
		float float_val;
		char code[100];
	}Number;
	char q_string[200];
	struct 
		{
			char var_name[30];
			int type;
			int  data_depth;
			int isValue;
			char code[100];
		}EXPN_type;
}
%token HASH IMPORT AT SET VOID RETURN TAB LB RB LCB RCB LSQRB RSQRB SC COLON QMARK COMA IF ELSE_IF ELSE FOR DO 
%token WHILE IN PRINT PRINTLN SCANF ET EQ IS GT LT GTE LTE NE ISNOT AMPER AND OR NOT DQUOTE PLUS MINUS MUL DIV 
%token MOD EXP UPLUS UMINUS

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
%token<Number>INT_NUMBER
%token<Number>FLOAT_NUMBER
%token<q_string>Q_STRING
%token<var_name>HEADER_FILE
%type<line_ind>INDENTATION
%type<DATA_type>DATA_TYPE
%type<EXPN_type>A_EXPN
%type<EXPN_type>ARRAY_ACCESS
%type<EXPN_type>INCR_DCR_EXPN
%type<EXPN_type>FUNC_DEC
%type<EXPN_type>FUNC_DEPTH
%type<data_type>FUNC_BODY
%type<code>DECLARATION_STATEMENTS
%type<code>VAR_LIST
%type<code>UNARY_OPERATORS
%type<code>OPR_PREC1
%type<code>OPR_PREC2
%type<code>FUNC_CALL
%type<code>FUNC_ARG
%type<code>ARRAY_DECLARATION
%type<code>ARRAY_SIZE
%type<code>PTR_VAR
%type<code>PTR_DEPTH
%type<code>VAR_LIST2
%type<code>ASSIGNMENT_STATEMENT
%type<code>LOGICAL_EXPN
%type<code>LOGICAL_EXPN1
%type<code>LOGICAL_EXPN2
%type<code>COMP_OPERATOR
%type<code>LOGICAL_OPERATOR
%type<code>VAR_LIST_OP
%type<code>VAR_LIST_IP

%start prm

%%
prm	: HEADERS FUNCTIONS {
		if(strcmp(func_list[func_count].func_name, "main")!=0){
			yyerror("Main function must be declared at the end.");exit(0);
		}
		success=1;
	}
HEADERS : HEADER HEADERS | HEADER
HEADER	: IMPORT HEADER_FILE {printf("#include <%s>\n",$2);}| IMPORT Q_STRING {format_string($2);printf("#include %s\n",$2);}

FUNCTIONS : FUNCTION_BODY | FUNCTION_BODY FUNCTIONS {/*Epsilon*/}
FUNCTION_BODY : DATA_TYPE AT {printf("%s ",$1.code);} FUNC_DEPTH VAR {check_func($5);func_count++; strcpy(func_list[func_count].func_name, $5); func_list[func_count].func_type.type = $1.type; func_list[func_count].func_type.data_depth = $4.data_depth;printf("%s",$5);}
			FUNC_PARAM FUNC_BODY {
				if(func_list[func_count].func_type.type != $8 && strcmp(func_list[func_count].func_name, "main") != 0){
					yyerror("Syntax Error: Function has no return statement.");exit(0);
				}
				pop_table();
				pointer = NULL;
			}
FUNC_DEPTH : MUL FUNC_DEPTH {$$.data_depth++;printf("*");} | MUL {$$.data_depth++;printf("*");} | /*Epsilon*/ {$$.data_depth=0;}

FUNC_PARAM : LB {push_table(0);printf("(");} FUNC_PARAS {/*display_function_table();*/} RB COLON {printf("){\n");}
FUNC_BODY : BODY2 RETURN A_EXPN {
				if($3.type != func_list[func_count].func_type.type || $3.data_depth != func_list[func_count].func_type.data_depth){
					yyerror("Return type does not match function type.");exit(0);
				}
				$$ = $3.type;
				func_list[func_count].func_type.isValue = $3.isValue;
				printf("return %s;\n",$3.code);
			} 
			| BODY2 {$$ = -1;}
FUNC_PARAS : FUNC_PARAS2 COMA {printf(",");} FUNC_PARAS | FUNC_PARAS2 
FUNC_PARAS2 : FUNC_DEC COLON COLON DATA_TYPE {
				func_list[func_count].para_sym[func_list[func_count].paras].type = $4.type;
				func_list[func_count].para_sym[func_list[func_count].paras].data_depth = $1.data_depth;
				func_list[func_count].paras++;
				insert_to_table(var_list[var_list_ind-1].var_name, current_data_type, var_list[var_list_ind-1].is_Array, var_list[var_list_ind-1].dims, var_list[var_list_ind-1].ptr_depth, var_list[var_list_ind-1].array_dim);
				var_list_ind = 0;
				for(int i = 0; i< 20; i++){
					var_list[i].LHS_type = 0;
					if (var_list[i].is_Array){
						var_list[i].is_Array = 0;
						var_list[i].dims = 0;
					}
					if (var_list[i].ptr_depth > 0){
						var_list[i].ptr_depth = 0;
					}
				}
				printf("%s %s",$4.code, $1.code);
			}
			| {/*Epsilon*/}
FUNC_DEC : VAR {
			$$.data_depth = 0;
			strcpy(var_list[var_list_ind].var_name,$1);
			var_list_ind++;
			strcpy($$.code,$1);
		}
		| ARRAY_DECLARATION {
			$$.data_depth = var_list[var_list_ind-1].dims+1;
			strcpy($$.code,$1);
		}
		| PTR_VAR {
			$$.data_depth = var_list[var_list_ind-1].ptr_depth;
			strcpy($$.code,$1);
		}
//MAIN_FUNC_BODY : DATA_TYPE AT MAIN LB RB COLON {push_table(1);} BODY {pop_table();}

//BODY	: INDENTATION {/*printf("Level %d\n", $1);*/check_ind($1);} DECLARATION_STATEMENTS {printf("%s;\n",$3);} BODY2
BODY2	: /*Epsilon*/ | INDENTATION {/*printf("Level %d\n", $1);*/check_ind($1);} DECLARATION_STATEMENTS {printf("%s;\n",$3);} BODY2 | INDENTATION {/*printf("Level %d\n", $1);*/check_ind($1);} PROGRAM_STATEMENTS BODY2

DECLARATION_STATEMENTS: SET VAR_LIST COLON COLON DATA_TYPE{
						
						for(int i = 0; i < var_list_ind; i++){
							if(var_list[i].LHS_type > 0){
								if (!((current_data_type == 2 && var_list[i].LHS_type == 1) || (current_data_type == 3 && var_list[i].LHS_type == 1)
								|| (current_data_type == 3 && var_list[i].LHS_type == 3))){
									if (current_data_type+1 != var_list[i].LHS_type){
										yyerror("Incompatible types.");
										exit(0);
									}
								}
							}
							insert_to_table(var_list[i].var_name, current_data_type, var_list[i].is_Array, var_list[i].dims, var_list[i].ptr_depth, var_list[i].array_dim);
						}
						var_list_ind = 0;
						for(int i = 0; i< 20; i++){
							var_list[i].LHS_type = 0;
							if (var_list[i].is_Array){
								var_list[i].is_Array = 0;
								var_list[i].dims = 0;
							}
							if (var_list[i].ptr_depth > 0){
								var_list[i].ptr_depth = 0;
							}
						}
						strcpy(temp_string,$5.code);
						strcat(temp_string," ");
						strcat(temp_string,$2);
						strcpy($$, temp_string);
						strcpy(temp_string, "");
					} 
VAR_LIST : VAR COMA VAR_LIST {
				strcpy(var_list[var_list_ind].var_name,$1);
				var_list_ind++;
				strcpy(temp_string,$1);strcat(temp_string,",");
				strcat(temp_string,$3);strcpy($$,temp_string);
				strcpy(temp_string,"");
				//insert_to_table($1,current_data_type);
			    }
	| ARRAY_DECLARATION COMA VAR_LIST {
		//printf("<ARRAY_DECLARATION COMA VAR_LIST>");
		strcpy(temp_string,$1);strcat(temp_string,",");
		strcat(temp_string,$3);strcpy($$,temp_string);
		strcpy(temp_string,"");
	}
	| PTR_VAR COMA VAR_LIST {
		strcpy(temp_string,$1);strcat(temp_string,",");
		strcat(temp_string,$3);strcpy($$,temp_string);
		strcpy(temp_string,"");
	}
	| VAR_LIST2 COMA VAR_LIST {
		strcpy(temp_string,$1);strcat(temp_string,",");
		strcat(temp_string,$3);strcpy($$,temp_string);
		strcpy(temp_string,"");
	}
	| VAR {
			strcpy(var_list[var_list_ind].var_name,$1);
			var_list_ind++;
			strcpy($$, $1);
			//insert_to_table($1,current_data_type);
	      }
	| ARRAY_DECLARATION {strcpy($$,$1);}
	| PTR_VAR {strcpy($$,$1);}
	| VAR_LIST2 {strcpy($$,$1);}
VAR_LIST2 : VAR EQ A_EXPN {
				if ($3.data_depth!=0){
					yyerror("Incompatible pointer type in assignment");
					exit(0);
				}
				
				strcpy(var_list[var_list_ind].var_name,$1);
				var_list[var_list_ind].LHS_type = $3.type+1;
				var_list_ind++;
				strcpy(temp_string,$1);
				strcat(temp_string,"=");
				strcat(temp_string,$3.code);
				strcpy($$,temp_string);
				strcpy(temp_string,"");
			}
PTR_VAR :	PTR_DEPTH VAR {
				//printf("<PTR_DEPTH VAR>");
				//insert_to_table($2,current_data_type);
				strcpy(var_list[var_list_ind].var_name,$2);
				var_list_ind++;
				//var_list[var_list_ind].ptr_depth = 0;
				strcpy(temp_string, $1);
				strcat(temp_string, $2);
				strcpy($$, temp_string);
				strcpy(temp_string,"");
			}
PTR_DEPTH :	MUL PTR_DEPTH {
				//printf("<MUL PTR_DEPTH>");
				var_list[var_list_ind].ptr_depth++;
				strcpy(temp_string,"*");strcat(temp_string,$2);
				strcpy($$,temp_string);strcpy(temp_string,"");
			} 
			| MUL {				
				//printf("<MUL>");
				var_list[var_list_ind].ptr_depth = 0;
				var_list[var_list_ind].ptr_depth++;
				strcpy($$,"*");
			}
ARRAY_DECLARATION: VAR ARRAY_SIZE {
		var_list[var_list_ind].is_Array = 1;
		strcpy(var_list[var_list_ind].var_name,$1);
		var_list_ind++;
		//insert_to_table($1,current_data_type);
		strcpy(temp_string,$1);
		strcat(temp_string,$2);
		strcpy($$,temp_string);
		strcpy(temp_string,"");
	}
ARRAY_SIZE : ARRAY_SIZE LSQRB INT_NUMBER RSQRB {
				var_list[var_list_ind].dims++;
				var_list[var_list_ind].array_dim[var_list[var_list_ind].dims] = $3.integer_val;
				//printf("<ARRAY_SIZE LSQRB %d RSQRB>", $3);
				strcpy(temp_string, $1);
				strcat(temp_string,"[");
				strcat(temp_string,$3.code);
				strcat(temp_string,"]");
				strcpy($$,temp_string);
				strcpy(temp_string,"");
			}
			| LSQRB INT_NUMBER RSQRB {
				var_list[var_list_ind].dims = 0;
				var_list[var_list_ind].array_dim[var_list[var_list_ind].dims] = $2.integer_val;
				//printf("<LSQRB %d RSQRB>", $2);
				strcpy(temp_string,"[");
				strcat(temp_string,$2.code);
				strcat(temp_string,"]");
				strcpy($$,temp_string);
				strcpy(temp_string,"");
			}

DATA_TYPE : INT {
			$$.type=$1;
			strcpy($$.code,"int");
			current_data_type=$1;
		} 
	| CHAR  {
			$$.type=$1;
			strcpy($$.code,"char");
			current_data_type=$1;
		}
	| FLOAT {
			$$.type=$1;
			strcpy($$.code,"float");
			current_data_type=$1;
		}
	| DOUBLE {
			$$.type=$1;
			strcpy($$.code,"double");
			current_data_type=$1;
		}
	| VOID {
		$$.type=-1;
		strcpy($$.code,"void");
		current_data_type=-1;
	}
 
PROGRAM_STATEMENTS :	ASSIGNMENT_STATEMENT {printf("%s;\n",$1);}
				| READ_STATEMENT
				| WRITE_STATEMENT
				| INCR_DCR_EXPN {printf("%s;\n",$1.code);}
				| FUNC_CALL {printf("%s;\n",$1);}
				| CONDITIONAL_STATEMENTS
				| WHILE LB LOGICAL_EXPN RB COLON {printf("while(%s)",$3);push_table(1);} BODY2 //RCB {pop_table();}
				| DO LB LOGICAL_EXPN RB COLON BODY2
				| FOR VAR {push_table(0);insert_to_table($2, 0, var_list[0].is_Array, var_list[0].dims, var_list[0].ptr_depth, var_list[0].array_dim);} IN A_EXPN COLON {
					if($5.type!=0 || $5.data_depth!=1){
						yyerror("Integer array of 1 dimension required for the iterator.");exit(0);
					}
					print_tabs(0);
					printf("for(int i = 0; i < sizeof(%s)/sizeof(%s[0]); i++){\n",$5.code,$5.code);
					print_tabs(1);
					printf("int %s = %s[i];\n",$2,$5.code);
				} BODY2 
				| FOR LB ASSIGNMENT_STATEMENT SC LOGICAL_EXPN SC INCR_DCR_EXPN RB COLON {printf("for(%s; %s; %s)",$3,$5,$7.code);push_table(1);} BODY2 //RCB {pop_table();}
				| FOR LB DECLARATION_STATEMENTS SC LOGICAL_EXPN SC INCR_DCR_EXPN RB COLON {printf("for(%s; %s; %s)",$3,$5,$7.code);push_table(1);} BODY2
				| {/*Epsilon*/}

FUNC_CALL : VAR LB {func_column = func_lookup($1);} FUNC_ARG RB {
				if(args!=-1){
					printf("\nError: Too few arguments to function ‘%s’\n",$1);exit(0);
				}
				strcpy(temp_string, $1);
				strcat(temp_string, "(");
				strcat(temp_string, $4);
				strcat(temp_string, ")");
				strcpy($$, temp_string);
				strcpy(temp_string, "");
			}
FUNC_ARG : A_EXPN COMA FUNC_ARG {
			if($1.type != func_column.para_sym[args].type || func_column.para_sym[args].data_depth != $1.data_depth){
				yyerror("Type mismatch in function arguments.");exit(0);
			}
			args--;
			strcpy(temp_string, $1.code);
			strcat(temp_string, ", ");
			strcat(temp_string, $3);
			strcpy($$, temp_string);
			strcpy(temp_string, "");		
		}
		| A_EXPN {
			args = func_column.paras-1;
			if($1.type != func_column.para_sym[args].type || func_column.para_sym[args].data_depth != $1.data_depth){
				yyerror("Type mismatch in function arguments.");exit(0);
			}
			args--;
			strcpy($$,$1.code);
		}
		| {/*Epsilon*/strcpy($$,"");}

WRITE_STATEMENT : PRINTF LB Q_STRING {RWmode = 2; format_string($3);} RB{
					RWmode = 0;
					if(format_spec_counter!=0){
						yyerror("More arguments expected to printf function."); exit(0);
					}
					temp_char = $3+1;
					printf("%s);\n",temp_char);
				} 
				| PRINTF LB Q_STRING {RWmode = 2; format_string($3);} COMA VAR_LIST_OP RB{
					//printf("%d",format_spec_counter);
					RWmode = 0;
					if(format_spec_counter != 0){
						yyerror("more arguments required.");
						//printf("Parsing Failed\nLine Number %d: more arguments required.\n", yylineno);
						exit(0);
					}
					temp_char = $3+1;
					printf("%s,%s);\n",temp_char,$6);
				}
				| PRINTF LB RB {printf("\");\n");}
PRINTF : PRINT {printf("printf(\"");} | PRINTLN {printf("printf(\"\\n");} 
VAR_LIST_OP : A_EXPN COMA VAR_LIST_OP {
				//printf("<A_EXPN COMA VAR_LIST_OP>");
				if(array_format_spec[--format_spec_counter] == 4){
					if($1.data_depth != 1 || $1.type != 1){
						yyerror("Format '%s' expects argument of type 'char *'"); exit(0);
					}
				}
				else if (array_format_spec[format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}	
				strcpy(temp_string,$1.code);
				strcat(temp_string,",");
				strcat(temp_string,$3);
				strcpy($$,temp_string);
				strcpy(temp_string,"");		
			}
			| A_EXPN {
				//printf("<A_EXPN>");
				if(array_format_spec[--format_spec_counter] == 4){
					if($1.data_depth != 1 || $1.type != 1){
						yyerror("Format '%s' expects argument of type 'char *'"); exit(0);
					}
				}
				else if (array_format_spec[format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				strcpy($$,$1.code);		
			}

READ_STATEMENT : SCANF LB Q_STRING {RWmode = 1; format_string($3);} COMA VAR_LIST_IP RB{printf("scanf(%s,%s);\n",$3,$6);RWmode = 0;}
VAR_LIST_IP : A_EXPN COMA VAR_LIST_IP {
				//printf("<A_EXPN COMA VAR_LIST_IP>");
				if (array_format_spec[--format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				else if ($1.data_depth != 1){
					yyerror("Error in reference depth."); exit(0);
				}	
				strcpy(temp_string,$1.code);strcat(temp_string,",");
				strcat(temp_string,$3);strcpy($$,temp_string);
				strcpy(temp_string,"");	
			}
			| A_EXPN {
				//printf("<A_EXPN>");
				if (array_format_spec[--format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				else if ($1.data_depth != 1){
					yyerror("Error in reference depth."); exit(0);
				}
				strcpy($$,$1.code);				
			}

CONDITIONAL_STATEMENTS : IF_STATEMENT | IF_STATEMENT ELSE_STATEMENT | IF_STATEMENT ELSE_IF_STATEMENT | IF_STATEMENT ELSE_IF_STATEMENT ELSE_STATEMENT
IF_STATEMENT : IF LB LOGICAL_EXPN RB COLON {printf("if(%s)",$3);push_table(1);} BODY2 //RCB {pop_table();}
ELSE_IF_STATEMENT : ELSE_IF LB LOGICAL_EXPN RB COLON {printf("else if(%s)",$3);push_table(1);} BODY2 /*RCB {pop_table();}*/ | ELSE_IF_STATEMENT ELSE_IF LB LOGICAL_EXPN RB COLON {printf("else if(%s)",$4);push_table(1);} BODY2 //RCB {pop_table();}
ELSE_STATEMENT : ELSE COLON {printf("else");push_table(1);} BODY2 //RCB {pop_table();}

ASSIGNMENT_STATEMENT : A_EXPN EQ A_EXPN
				{
					if($1.type!=$3.type)
					{
						yyerror("Incompatible type in assignment");
						exit(0);
					}else if($1.data_depth!=$3.data_depth)
					{
						yyerror("Incompatible pointer type in assignment");
						exit(0);
						//printf("\n Line number: %d Warning : Incompatible pointer type in assignment",yylineno);
					}
					else if($1.isValue==1)
					{
						yyerror("lvalue required as left operand of the assignment operator");
						exit(0);
					}
					strcpy(temp_string,$1.code);
					strcat(temp_string," = ");
					strcat(temp_string,$3.code);
					strcpy($$, temp_string);
					strcpy(temp_string,"");
				}

LOGICAL_EXPN	: NOT LB LOGICAL_EXPN1 RB {strcpy(temp_string,"!");strcat(temp_string,"(");strcat(temp_string,$3);strcat(temp_string,")");strcpy($$,temp_string);strcpy(temp_string,"");}
				| LOGICAL_EXPN1 {strcpy($$,$1);}
LOGICAL_EXPN1	: LOGICAL_EXPN1 LOGICAL_OPERATOR LOGICAL_EXPN1{
					strcpy(temp_string,$1);
					strcat(temp_string,$2);
					strcat(temp_string,$3);
					strcpy($$,temp_string);
					strcpy(temp_string,"");
				}
				| LB LOGICAL_EXPN1 RB {
					strcpy(temp_string,"(");
					strcat(temp_string,$2);
					strcat(temp_string,")");
					strcpy($$,temp_string);
					strcpy(temp_string,"");
				}
				| NOT LB LOGICAL_EXPN1 RB{
					strcpy(temp_string, "!");
					strcat(temp_string,"(");
					strcat(temp_string,$3);
					strcat(temp_string,")");
					strcpy($$,temp_string);
					strcpy(temp_string,"");

				}
				| LOGICAL_EXPN2 {strcpy($$,$1);}
LOGICAL_EXPN2	: A_EXPN COMP_OPERATOR A_EXPN{
					strcpy(temp_string,$1.code);strcat(temp_string,$2);
					strcat(temp_string,$3.code);strcpy($$,temp_string);
					strcpy(temp_string, "");
				}
COMP_OPERATOR	: ET {strcpy($$,"==");} | IS {strcpy($$,"==");} | GT {strcpy($$,">");} | LT {strcpy($$,"<");} 
				| GTE {strcpy($$,">=");} | LTE {strcpy($$,"<=");} | ISNOT {strcpy($$,"!=");} | NE {strcpy($$,"!=");}
LOGICAL_OPERATOR	: AND {strcpy($$," && ");} | OR {strcpy($$," || ");}

A_EXPN	: A_EXPN OPR_PREC1 A_EXPN	
				{	
					$$.isValue=1;
					if($1.data_depth==$3.data_depth)
					{
						$$.data_depth=$1.data_depth;
						if($1.type==$3.type)
						{
							$$.type=$1.type;
						}else
						{
							yyerror("Type mismatch in operands");
							exit(0);	
						}
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
					strcpy(temp_string,$1.code);
					strcat(temp_string,$2);
					strcat(temp_string,$3.code);
					strcpy($$.code,temp_string);
					strcpy(temp_string,"");
				}

		|A_EXPN OPR_PREC2 A_EXPN
				{
					if($1.type!=$3.type)
					{
						yyerror("Type mismatch in operands");exit(0);
					}
					if(is_modulus){
						if($1.type!=0 || $3.type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if($1.data_depth!=0 || $3.data_depth!=0)
					{
						printf("\nInvalid operands to binary %s", $2);exit(0);
					}	
					$$.isValue=1;
					$$.data_depth=0;
					$$.type=$1.type;
					strcpy(temp_string,$1.code);
					strcat(temp_string,$2);
					strcat(temp_string,$3.code);
					strcpy($$.code,temp_string);
					strcpy(temp_string,"");
				}
		| LB A_EXPN RB {
			$$.isValue = $2.isValue;
			$$.data_depth = $2.data_depth;
			$$.type = $2.type;
			strcpy(temp_string,"(");
			strcat(temp_string,$2.code);
			strcat(temp_string,")");
			strcpy($$.code,temp_string);
			strcpy(temp_string,"");
		}		
		| INCR_DCR_EXPN {
			$$.type=$1.type;
			$$.data_depth=$1.data_depth;	
			$$.isValue=1;
			strcpy($$.code, $1.code);
		}
		| VAR {
			struct symbol_table column = get_column($1);
			$$.type = column.type;
			$$.data_depth = column.pointerDepth;
			$$.isValue = 0;
			strcpy($$.var_name, $1);
			strcpy($$.code, $1);
		}
		| FUNC_CALL {
			$$.type = func_column.func_type.type;//Return types
			$$.data_depth = func_column.func_type.data_depth;
			$$.isValue = func_column.func_type.isValue;
			strcpy($$.code,$1);
		}
		| INT_NUMBER {
			$$.type = 0;
			$$.data_depth = 0;	
			$$.isValue = 1;
			strcpy($$.code, $1.code);
		}
		| FLOAT_NUMBER {
			$$.type = 2;
			$$.data_depth = 0;	
			$$.isValue = 1;
			strcpy($$.code, $1.code);
		}
		| MUL A_EXPN
			{
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
				strcpy(temp_string,"*");
				strcat(temp_string, $2.code);
				strcpy($$.code,temp_string);
				strcpy(temp_string,"");										
			}
		| ARRAY_ACCESS {
			if(dims!=get_array_dimensions($1.var_name) && (RWmode == 0)){
				printf("\n Error: Indexing error in array: %s\n", $1.var_name);exit(0);
			}
			$$.type=$1.type;
			$$.data_depth=$1.data_depth;
			$$.isValue=0;
			strcpy($$.code, $1.code);
			dims=0;
		}			
		| AMPER A_EXPN	
			{		
				if($2.isValue==1)
				{
					yyerror("lvalue required for unary operator &");
					exit(0);
				}
				$$.type=$2.type;
				$$.data_depth=$2.data_depth+1;
				$$.isValue=1;
				strcpy(temp_string,"&");
				strcat(temp_string,$2.code);
				strcpy($$.code,temp_string);
				strcpy(temp_string,"");			
			}

ARRAY_ACCESS : ARRAY_ACCESS LSQRB A_EXPN RSQRB
			{	
				dims++;
				if($3.data_depth!=0 || $3.type!=0)
				{
					yyerror("Array index integer expected\n");
					exit(0);
				}
				else if($1.data_depth==0)
				{
					yyerror("Subscripted value neither array nor pointer");
					exit(0);
				}
				else
				{
					$$.type=$1.type;
					$$.data_depth=$1.data_depth-1;
					$$.isValue=0;
					strcpy($$.var_name, $1.var_name);
					strcpy(temp_string, $1.code);
					strcat(temp_string, "[");
					strcat(temp_string, $3.code);
					strcat(temp_string, "]");
					strcpy($$.code, temp_string);
					strcpy(temp_string, "");
				}
			}
			| VAR LSQRB A_EXPN RSQRB{
				struct symbol_table column = get_column($1);
				dims++;
				if($3.data_depth!=0 || $3.type!=0)
				{
					yyerror("Array index integer expected\n");
					exit(0);
				}
				else if(column.pointerDepth==0)
				{
					yyerror("Subscripted value neither array nor pointer");
					exit(0);
				}
				else
				{
					$$.type = column.type;
					$$.data_depth = column.pointerDepth-1;
					$$.isValue = 0;
					strcpy($$.var_name, $1);
					strcpy(temp_string, $1);
					strcat(temp_string, "[");
					strcat(temp_string, $3.code);
					strcat(temp_string, "]");
					strcpy($$.code, temp_string);
					strcpy(temp_string,"");
				}
			}

INCR_DCR_EXPN : A_EXPN UNARY_OPERATORS {
				if($$.isValue==1)
				{
					yyerror("lvalue required");exit(0);
				}else
				{
					$$.type=$1.type;
					$$.data_depth=$1.data_depth;	
					$$.isValue=1;
				}
				strcpy(temp_string, $1.code);
				strcat(temp_string, $2);
				strcpy($$.code, temp_string);
				strcpy(temp_string,"");
			}

UNARY_OPERATORS: UPLUS {strcpy($$, "++");}| UMINUS {strcpy($$, "--");}
OPR_PREC1: PLUS {strcpy($$, "+");}| MINUS {strcpy($$, "-");}
OPR_PREC2: DIV {strcpy($$, "/");} 
		| MUL {strcpy($$, "*");} 
		| EXP {strcpy($$, "^");} 
		| MOD {strcpy($$, "%"); is_modulus = 1;}

INDENTATION : TAB {/*printf("<TAB>");*/$$ = 1;} | INDENTATION TAB {/*printf("<INDENTATION TAB>");*/$$++;}

%%

void push_table(int mode){
	if(mode){
		printf("{\n");
	}
    struct symbol_table_stack * node = (struct symbol_table_stack *)malloc(sizeof(struct symbol_table_stack));
    node->var_count = -1;
    
    if(pointer == NULL){
		node->ind_level = 1;
        pointer = node;
    }
    else{
		node->ind_level = pointer->ind_level + 1;
        pointer->next = node;
        node->prev = pointer;
        pointer = node;
    }
}

void pop_table(){
	//display_symbol_table();
	print_tabs(0);
	printf("}\n");
    if(pointer != NULL){
        if(pointer->prev == NULL){
            pointer = NULL;
        }
        else{
            pointer = pointer->prev;
            pointer->next = NULL;
        }        
    }
}

struct symbol_table get_column(char var[30]){
    struct symbol_table_stack * current = pointer;
    if(lookup_in_table(var,0)!=-1){        
        while(current != NULL){
            for(int i=0; i<=current->var_count; i++)
            {
                if(strcmp(current->var_list[i].var_name, var)==0)
                {
                    return current->var_list[i];
                }
            }
            current = current->prev;
        }
	}
	else{
		printf("\n variable \"%s\" undeclared\n",var);exit(0);
	}
	return current->var_list[0];
}

int lookup_in_table(char var[30], int mode) //mode (0->check all nodes) (1->check current node) 
{
    struct symbol_table_stack * current = pointer;
    while(current != NULL){
        for(int i=0; i<=current->var_count; i++)
        {
            if(strcmp(current->var_list[i].var_name, var)==0)
            {
                return current->var_list[i].type;
            }
        }
        if(mode == 1){
            return -1;
        }
        current = current->prev; 
    }    
	return -1;
}
void insert_to_table(char var[30], int type, int is_Array, int dims, int ptr_depth, int array_dim[5])
{
	if (lookup_in_table(var,1) == -1)
	{
		pointer->var_count++;
		strcpy(pointer->var_list[pointer->var_count].var_name, var);
    	pointer->var_list[pointer->var_count].type = type;
		if (is_Array){
			pointer->var_list[pointer->var_count].dim = dims+1;
			pointer->var_list[pointer->var_count].pointerDepth = dims+1;
			for(int i = 0; i <= dims; i++){
				pointer->var_list[pointer->var_count].dim_bounds[i] = array_dim[i];
				//printf("\n%d\n",pointer->var_list[var_count].dim_bounds[i]);
			}
			is_Array=0;
			dims = 0;
		}
		else{
			pointer->var_list[pointer->var_count].dim = 0;
			for(int i = 0; i < 5; i++){
				pointer->var_list[pointer->var_count].dim_bounds[i] = -1;
			}
		}
		if(ptr_depth > 0){
			pointer->var_list[pointer->var_count].pointerDepth = ptr_depth;
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
    struct symbol_table_stack * current = pointer;
    while(current != NULL){
        for(int i=0; i<=current->var_count; i++)
        {
            if(strcmp(current->var_list[i].var_name, var)==0)
            {
                return current->var_list[i].dim;
            }
        }
        current = current->prev;
    }
	printf("\n variable \"%s\" undeclared\n",var);exit(0);
}
void display_symbol_table(){
    struct symbol_table_stack * current = pointer;
    while(current != NULL){
        printf("\n+------------------------------SYMBOL TABLE------------------------------+\n");
        printf("|Var name\t\tType\tPtrDepth\tDim\tDim Bounds\t |\n");
        for(int i=0; i<=current->var_count; i++)
        {
            printf("|%s\t\t\t%d\t%d\t\t%d\t{", current->var_list[i].var_name, current->var_list[i].type, current->var_list[i].pointerDepth, current->var_list[i].dim);
            for(int j=0; j<5; j++){
                printf("%d ",current->var_list[i].dim_bounds[j]);
            }
            printf("}|\n");
        }
        printf("+------------------------------------------------------------------------+\n");
        current = current->prev;
    }
}
void display_function_table(){
    printf("\n+------------------------------FUNCTION TABLE------------------------------+\n");
    printf("|Func name\t\tType\tData Depth\tParas\tParameter Types\t |\n");
    for(int i=0; i<=func_count; i++)
    {
        printf("|%s\t\t%d\t%d\t%d\t", func_list[i].func_name, func_list[i].func_type.type,func_list[i].func_type.data_depth, func_list[i].paras);
        for(int j=0; j<func_list[i].paras; j++){
            printf("{%d, %d}",func_list[i].para_sym[j].type, func_list[i].para_sym[j].data_depth);
        }
		printf("\n");
    }
    printf("+--------------------------------------------------------------------------+\n");
}
void format_string(char str[200]){
	if (RWmode == 0){ //for Header Files
		int i = 0;
		while(str[i]!='\0'){
			i++;
		}
		if (str[i-3]!='.' && str[i-2]!='h'){
			yyerror("Invalid format for header file.");exit(0);
		}
	}
	else{
		format_spec_counter = 0;
		char specifiers[5] = {'d','c','f','l','s'};
		int i = 0;
		while(str[i]!='\0'){
			if(str[i] == '%'){
				//printf(" %c%c ",str[i],str[i+1]);
				if (RWmode == 1 && str[i+1]=='s'){
					array_format_spec[format_spec_counter] = 1;
					format_spec_counter++;	
				}
				else{
					for (int j=0;j<5;j++){
						if(str[i+1]==specifiers[j]){
							array_format_spec[format_spec_counter] = j; //j will act as type-> 0 for int, 1 for char etc
							format_spec_counter++;
							break;
						}
					}
				}
			}
			i++;
		}
	}
}
void check_ind(int current_ind){
	if(current_ind < pointer->ind_level){
		int indd = pointer->ind_level - current_ind;
		while(indd!=0){
			pop_table();
			indd--;
		}
	}
	if(current_ind != pointer->ind_level){
		yyerror("Indentation Error");exit(0);
	}
	print_tabs(1);
}
struct functions func_lookup(char str[30]){
	for (int i = 0; i <= func_count; i++){
		if(strcmp(str, func_list[i].func_name)==0){
			return func_list[i];
		}
	}
	printf("Parsing Failed\nLine Number: %d Function: %s is not defined.\n",yylineno, str);
	exit(0);
	return func_list[0];
}
void check_func(char str[30]){
	for (int i = 0; i <= func_count; i++){
		if(strcmp(str, func_list[i].func_name)==0){
			yyerror("Function already exists.");exit(0);
		}
	}
}
void print_tabs(int mode){
	int indd;
	if(mode==0){
		if(pointer->prev!=NULL)
			indd=pointer->prev->ind_level;
		else
			indd=0;
	}
	else
		indd=pointer->ind_level;
	for(int i = 0; i<indd;i++){
		printf("  ");
	}
}
int main()
{
    yyparse();
	if(success){
    	printf("\nParsing Successful\n");
	}
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	return 0;
}