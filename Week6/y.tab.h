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
    ELSE = 273,
    FOR = 274,
    DO = 275,
    WHILE = 276,
    VAR = 277,
    NUMBER = 278,
    ET = 279,
    EQ = 280,
    GT = 281,
    LT = 282,
    GTE = 283,
    LTE = 284,
    NE = 285,
    AND = 286,
    OR = 287,
    NOT = 288,
    DQUOTE = 289,
    PLUS = 290,
    MINUS = 291,
    MUL = 292,
    DIV = 293,
    MOD = 294,
    EXP = 295,
    UPLUS = 296,
    UMINUS = 297,
    INT = 298,
    CHAR = 299,
    FLOAT = 300,
    DOUBLE = 301
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
#define ELSE 273
#define FOR 274
#define DO 275
#define WHILE 276
#define VAR 277
#define NUMBER 278
#define ET 279
#define EQ 280
#define GT 281
#define LT 282
#define GTE 283
#define LTE 284
#define NE 285
#define AND 286
#define OR 287
#define NOT 288
#define DQUOTE 289
#define PLUS 290
#define MINUS 291
#define MUL 292
#define DIV 293
#define MOD 294
#define EXP 295
#define UPLUS 296
#define UMINUS 297
#define INT 298
#define CHAR 299
#define FLOAT 300
#define DOUBLE 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "projectMOD2.y"

int data_type;
char var_name[30];

#line 154 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
