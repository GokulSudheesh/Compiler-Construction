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
    INCLUDE = 258,
    HEADER_FILE = 259,
    MAIN = 260,
    DOTH = 261,
    DOTC = 262,
    HASH = 263,
    DOUBLEQ = 264,
    LB = 265,
    RB = 266,
    LCB = 267,
    RCB = 268,
    LSB = 269,
    RSB = 270,
    COMMA = 271,
    SC = 272,
    UPLUS = 273,
    UMINUS = 274,
    EXP = 275,
    QUESM = 276,
    COLON = 277,
    STAR = 278,
    AMPERSAND = 279,
    PLUS = 280,
    MINUS = 281,
    MOD = 282,
    MUL = 283,
    DIV = 284,
    EQCOMPARE = 285,
    NEQCOMPARE = 286,
    EQ = 287,
    GTE = 288,
    LTE = 289,
    GT = 290,
    LT = 291,
    NOT = 292,
    AND = 293,
    OR = 294,
    IF = 295,
    ELSE = 296,
    FOR = 297,
    DO = 298,
    WHILE = 299,
    VAR = 300,
    NUMINT = 301,
    COMMENT = 302,
    INT = 303,
    CHAR = 304,
    FLOAT = 305,
    DOUBLE = 306
  };
#endif
/* Tokens.  */
#define INCLUDE 258
#define HEADER_FILE 259
#define MAIN 260
#define DOTH 261
#define DOTC 262
#define HASH 263
#define DOUBLEQ 264
#define LB 265
#define RB 266
#define LCB 267
#define RCB 268
#define LSB 269
#define RSB 270
#define COMMA 271
#define SC 272
#define UPLUS 273
#define UMINUS 274
#define EXP 275
#define QUESM 276
#define COLON 277
#define STAR 278
#define AMPERSAND 279
#define PLUS 280
#define MINUS 281
#define MOD 282
#define MUL 283
#define DIV 284
#define EQCOMPARE 285
#define NEQCOMPARE 286
#define EQ 287
#define GTE 288
#define LTE 289
#define GT 290
#define LT 291
#define NOT 292
#define AND 293
#define OR 294
#define IF 295
#define ELSE 296
#define FOR 297
#define DO 298
#define WHILE 299
#define VAR 300
#define NUMINT 301
#define COMMENT 302
#define INT 303
#define CHAR 304
#define FLOAT 305
#define DOUBLE 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "testtest.y"

int data_type;
char var_name[30];
int num_int; 

#line 165 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
