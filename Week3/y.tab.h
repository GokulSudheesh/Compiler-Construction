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
    NULL_TOK = 266,
    IF = 267,
    ELSE = 268,
    VAR = 269,
    ET = 270,
    EQ = 271,
    GT = 272,
    LT = 273,
    GTE = 274,
    LTE = 275,
    NE = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    PLUS = 280,
    MINUS = 281,
    MUL = 282,
    DIV = 283,
    MOD = 284,
    EXP = 285,
    UPLUS = 286,
    UMINUS = 287,
    INT = 288,
    CHAR = 289,
    FLOAT = 290,
    DOUBLE = 291
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
#define NULL_TOK 266
#define IF 267
#define ELSE 268
#define VAR 269
#define ET 270
#define EQ 271
#define GT 272
#define LT 273
#define GTE 274
#define LTE 275
#define NE 276
#define AND 277
#define OR 278
#define NOT 279
#define PLUS 280
#define MINUS 281
#define MUL 282
#define DIV 283
#define MOD 284
#define EXP 285
#define UPLUS 286
#define UMINUS 287
#define INT 288
#define CHAR 289
#define FLOAT 290
#define DOUBLE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "projectMOD.y"

int data_type;
char var_name[30];

#line 134 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
