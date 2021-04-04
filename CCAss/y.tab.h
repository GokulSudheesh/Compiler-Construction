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
    TAB = 264,
    SC = 265,
    COLON = 266,
    QMARK = 267,
    COMA = 268,
    IF = 269,
    ELSE = 270,
    FOR = 271,
    DO = 272,
    WHILE = 273,
    VAR = 274,
    NUMBER = 275,
    ET = 276,
    EQ = 277,
    GT = 278,
    LT = 279,
    GTE = 280,
    LTE = 281,
    NE = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    PLUS = 286,
    MINUS = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    EXP = 291,
    UPLUS = 292,
    UMINUS = 293,
    INT = 294,
    CHAR = 295,
    FLOAT = 296,
    DOUBLE = 297
  };
#endif
/* Tokens.  */
#define HEADER 258
#define MAIN 259
#define LB 260
#define RB 261
#define LCB 262
#define RCB 263
#define TAB 264
#define SC 265
#define COLON 266
#define QMARK 267
#define COMA 268
#define IF 269
#define ELSE 270
#define FOR 271
#define DO 272
#define WHILE 273
#define VAR 274
#define NUMBER 275
#define ET 276
#define EQ 277
#define GT 278
#define LT 279
#define GTE 280
#define LTE 281
#define NE 282
#define AND 283
#define OR 284
#define NOT 285
#define PLUS 286
#define MINUS 287
#define MUL 288
#define DIV 289
#define MOD 290
#define EXP 291
#define UPLUS 292
#define UMINUS 293
#define INT 294
#define CHAR 295
#define FLOAT 296
#define DOUBLE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "projectMOD.y"

int data_type;
char var_name[30];

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
