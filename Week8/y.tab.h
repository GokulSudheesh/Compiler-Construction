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
    HASH = 258,
    INCLUDE = 259,
    HEADER_FILE = 260,
    MAIN = 261,
    LB = 262,
    RB = 263,
    LCB = 264,
    RCB = 265,
    LSQRB = 266,
    RSQRB = 267,
    SC = 268,
    COLON = 269,
    QMARK = 270,
    COMA = 271,
    IF = 272,
    ELSE_IF = 273,
    ELSE = 274,
    FOR = 275,
    DO = 276,
    WHILE = 277,
    PRINTF = 278,
    SCANF = 279,
    ET = 280,
    EQ = 281,
    GT = 282,
    LT = 283,
    GTE = 284,
    LTE = 285,
    NE = 286,
    AMPER = 287,
    OR = 288,
    NOT = 289,
    DQUOTE = 290,
    PLUS = 291,
    MINUS = 292,
    MUL = 293,
    DIV = 294,
    MOD = 295,
    EXP = 296,
    UPLUS = 297,
    UMINUS = 298,
    INT = 299,
    CHAR = 300,
    FLOAT = 301,
    DOUBLE = 302,
    VAR = 303,
    INT_NUMBER = 304,
    FLOAT_NUMBER = 305,
    Q_STRING = 306
  };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define HEADER_FILE 260
#define MAIN 261
#define LB 262
#define RB 263
#define LCB 264
#define RCB 265
#define LSQRB 266
#define RSQRB 267
#define SC 268
#define COLON 269
#define QMARK 270
#define COMA 271
#define IF 272
#define ELSE_IF 273
#define ELSE 274
#define FOR 275
#define DO 276
#define WHILE 277
#define PRINTF 278
#define SCANF 279
#define ET 280
#define EQ 281
#define GT 282
#define LT 283
#define GTE 284
#define LTE 285
#define NE 286
#define AMPER 287
#define OR 288
#define NOT 289
#define DQUOTE 290
#define PLUS 291
#define MINUS 292
#define MUL 293
#define DIV 294
#define MOD 295
#define EXP 296
#define UPLUS 297
#define UMINUS 298
#define INT 299
#define CHAR 300
#define FLOAT 301
#define DOUBLE 302
#define VAR 303
#define INT_NUMBER 304
#define FLOAT_NUMBER 305
#define Q_STRING 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "projectMOD.y"

int data_type;
char var_name[30];
int integer_val;
float float_val;
char q_string[200];
struct 
	{
		char var_name[30];
		int type;
		int  data_depth;
		int isValue;
	}EXPN_type;

#line 174 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
