/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    HEADER = 258,
    MAIN = 259,
    LB = 260,
    RB = 261,
    LCB = 262,
    RCB = 263,
    SC = 264,
    COMA = 265,
    EQ = 266,
    PLUS = 267,
    STAR = 268,
    LSB = 269,
    RSB = 270,
    UPLUS = 271,
    VAR_LABEL = 272,
    INT = 273,
    CHAR = 274,
    UNSIGNED = 275,
    SHORT = 276,
    LONG = 277,
    AMB = 278,
    NUM = 279
  };
#endif
/* Tokens.  */
#define HEADER 258
#define MAIN 259
#define LB 260
#define RB 261
#define LCB 262
#define RCB 263
#define SC 264
#define COMA 265
#define EQ 266
#define PLUS 267
#define STAR 268
#define LSB 269
#define RSB 270
#define UPLUS 271
#define VAR_LABEL 272
#define INT 273
#define CHAR 274
#define UNSIGNED 275
#define SHORT 276
#define LONG 277
#define AMB 278
#define NUM 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 70 "project.y"
//yylval spec, shared memory of size 30 bytes
	char test_name[30];//whole memory will be utilized
	int type_info;//first 4 bytes will be interpreted as an integer, rest unused
	int ptr_depth;//first 4 bytes will be interpreted as an integer, rest unused

	struct
	{
		char name[30];// variable
		int pointer_depth;
	}ext_var;


	struct 
	{
			int name;
			int is_unsigned;
			int length_spec;
	}ext_type;



	struct 
	{
		int  data_depth;
		int type;
		int isValue;
	}expn_type;


#line 135 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
