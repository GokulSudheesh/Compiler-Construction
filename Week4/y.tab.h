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
    COLON = 265,
    QMARK = 266,
    COMA = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    DO = 271,
    WHILE = 272,
    VAR = 273,
    NUMBER = 274,
    ET = 275,
    EQ = 276,
    GT = 277,
    LT = 278,
    GTE = 279,
    LTE = 280,
    NE = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    PLUS = 285,
    MINUS = 286,
    MUL = 287,
    DIV = 288,
    MOD = 289,
    EXP = 290,
    UPLUS = 291,
    UMINUS = 292,
    INT = 293,
    CHAR = 294,
    FLOAT = 295,
    DOUBLE = 296
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
#define COLON 265
#define QMARK 266
#define COMA 267
#define IF 268
#define ELSE 269
#define FOR 270
#define DO 271
#define WHILE 272
#define VAR 273
#define NUMBER 274
#define ET 275
#define EQ 276
#define GT 277
#define LT 278
#define GTE 279
#define LTE 280
#define NE 281
#define AND 282
#define OR 283
#define NOT 284
#define PLUS 285
#define MINUS 286
#define MUL 287
#define DIV 288
#define MOD 289
#define EXP 290
#define UPLUS 291
#define UMINUS 292
#define INT 293
#define CHAR 294
#define FLOAT 295
#define DOUBLE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "projectMOD.y"

int data_type;
char var_name[30];

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
