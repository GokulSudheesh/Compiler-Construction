/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "projectMOD.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);
	int yylineno;
	int success = 0;
	int current_data_type;
	int is_modulus = 0;
	char current_operator;
	int is_Array;
	int dims;
	int array_dim[5];
	int ptr_depth;
	int array_format_spec[20];
	int format_spec_counter=0;
	int RWmode; // 1 -> read mode, 2 -> write mode
	
	struct symbol_table{char var_name[30]; int type; int dim; int pointerDepth; int dim_bounds[5];};
	struct symbol_table_stack{
    	struct symbol_table var_list[100];
    	int var_count;
    	struct symbol_table_stack * prev;
    	struct symbol_table_stack * next;
	};
	struct symbol_table_stack * pointer = NULL;

	extern void push_table();
	extern void pop_table();
	struct symbol_table get_column(char var[30]);
	extern int lookup_in_table(char var[30], int mode);
	extern void insert_to_table(char var[30], int type);
	extern int get_array_dimensions(char var[30]);
	extern void display_symbol_table();
	extern void format_string(char str[200]);

#line 108 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 277 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    78,    82,    82,    83,    83,    84,    84,
      84,    85,    86,    86,    86,    88,    88,    89,    92,    95,
      96,    97,   100,   103,   104,   105,   119,   124,   129,   134,
     138,   143,   148,   149,   153,   157,   161,   166,   167,   168,
     169,   170,   170,   170,   170,   171,   172,   172,   173,   173,
     173,   174,   174,   176,   176,   182,   182,   190,   201,   213,
     213,   214,   223,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   235,   236,   236,   238,   257,   257,   258,   258,
     258,   259,   260,   261,   261,   261,   261,   261,   261,   262,
     262,   264,   300,   320,   325,   330,   337,   342,   347,   361,
     370,   382,   403,   425,   437,   437,   438,   438,   439,   440,
     441,   442
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "HEADER_FILE", "MAIN",
  "LB", "RB", "LCB", "RCB", "LSQRB", "RSQRB", "SC", "COLON", "QMARK",
  "COMA", "IF", "ELSE_IF", "ELSE", "FOR", "DO", "WHILE", "PRINTF", "SCANF",
  "ET", "EQ", "GT", "LT", "GTE", "LTE", "NE", "AMPER", "OR", "NOT",
  "DQUOTE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EXP", "UPLUS", "UMINUS",
  "INT", "CHAR", "FLOAT", "DOUBLE", "VAR", "INT_NUMBER", "FLOAT_NUMBER",
  "Q_STRING", "$accept", "prm", "$@1", "HEADERS", "HEADER", "HEADER2",
  "BODY", "BODY2", "DECLARATION_STATEMENTS", "VAR_LIST", "VAR_LIST2",
  "PTR_VAR", "PTR_DEPTH", "ARRAY_DECLARATION", "ARRAY_SIZE", "MAIN_TYPE",
  "DATA_TYPE", "PROGRAM_STATEMENTS", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "WRITE_STATEMENT", "$@9", "$@10", "VAR_LIST_OP",
  "READ_STATEMENT", "$@11", "VAR_LIST_IP", "CONDITIONAL_STATEMENTS",
  "IF_STATEMENT", "$@12", "ELSE_IF_STATEMENT", "$@13", "$@14",
  "ELSE_STATEMENT", "$@15", "ASSIGNMENT_STATEMENT", "LOGICAL_EXPN",
  "LOGICAL_EXPN1", "LOGICAL_EXPN2", "COMP_OPERATOR", "LOGICAL_OPERATOR",
  "A_EXPN", "ARRAY_ACCESS", "INCR_DCR_EXPN", "UNARY_OPERATORS",
  "OPR_PREC1", "OPR_PREC2", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    16,    22,    -9,    14,   -26,   -82,   -82,    32,   -82,
      55,     6,    70,    51,   -82,    -4,    54,   -82,    45,    42,
      73,   -82,   -82,   -82,    69,    79,   -82,   -82,   -82,   -82,
      78,   189,   -27,   -82,    43,   -82,    -2,   -82,    86,    91,
      90,    96,    98,    35,    35,    89,   -82,   -82,   -82,   189,
     189,   -82,   -82,    40,    95,   291,    99,   104,    68,    -3,
     105,   106,   108,    61,   109,   110,     5,   113,   119,   -18,
     -82,   215,   -82,    -2,    35,   -82,    -2,    88,    35,   -82,
      33,    35,   -82,   -82,   114,   103,    46,   -82,   -82,    35,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    35,
      35,    35,   -82,   -82,    92,   -27,    35,   126,   -82,   -27,
     -27,   -82,   -27,   132,   127,   135,     8,     5,   133,   117,
     -82,     5,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    35,
     144,   265,   141,   189,   147,   -82,    93,   229,    -2,   -82,
     149,   -82,   282,   282,   282,   237,   145,   -82,   282,   115,
     -82,   -82,   -82,   146,    35,     5,   -82,    17,   158,   -82,
     -18,   282,   159,    -2,   148,   160,   154,   -82,   163,   189,
      -2,   -82,   -82,   161,   -82,   164,   245,    19,    37,   -82,
     -82,   162,   -82,   -82,    35,   168,   169,   170,   -82,   172,
      35,   -82,   189,   189,    35,   165,   189,   174,   273,   -82,
     -82,   177,   -82,   -82,   178,   180,   282,   184,   186,   185,
     181,    35,   189,   -82,   -82,   -82,   188,    -2,   -82,   -82,
     -82,   190,   189,   191,   -82,   195,   -82,   198,   205,   189,
     202,   -82,   -82,   206,   -82,   189,   -82,   207,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     5,     0,     1,    32,     0,     4,
       0,    10,     0,     0,     9,     0,     0,     6,     0,     0,
       0,     7,     8,     2,     0,     0,    33,    34,    35,    36,
       0,    12,     0,    16,     0,     3,     0,    38,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    11,    12,
      12,    39,    45,    63,     0,     0,    99,    94,    28,    21,
       0,    24,    23,     0,    22,    53,     0,     0,     0,    77,
      79,     0,    94,     0,     0,    48,     0,     0,     0,   100,
      98,     0,    13,    14,     0,     0,    65,    64,    37,     0,
     106,   107,   109,   108,   111,   110,   104,   105,   103,     0,
       0,     0,    40,    27,     0,     0,     0,    29,    15,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,    93,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,    12,     0,    59,     0,     0,     0,    73,
       0,    66,    75,    91,    92,     0,     0,    17,    25,     0,
      20,    19,    18,     0,     0,     0,    81,     0,     0,    89,
      78,    82,     0,     0,     0,     0,     0,   102,     0,    12,
       0,   101,    31,     0,    54,     0,    58,     0,    76,    41,
      67,     0,    49,    46,     0,     0,     0,     0,    30,     0,
       0,    80,    12,    12,     0,     0,    12,     0,    62,    69,
      74,     0,    56,    57,     0,     0,     0,    94,     0,     0,
       0,     0,    12,    71,    42,    68,     0,     0,    47,    60,
      61,     0,    12,     0,    51,     0,    70,     0,     0,    12,
       0,    72,    43,     0,    50,    12,    52,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   214,   -82,   -82,   -82,   -46,   175,   -81,
     -82,   -82,   166,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    29,   -82,
     -82,     9,   -82,   -82,   -82,   -82,   -82,   -82,   136,   -82,
     151,   -66,   -60,   -82,   -82,   -82,   -10,   -82,   -31,   -82,
     -82,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    24,     3,     4,    15,    30,    48,    49,    60,
      61,    62,    63,    64,   107,     8,    32,    50,   192,   223,
     235,   196,   133,   195,   229,    33,   113,   114,   175,    51,
     166,   197,    52,    53,   193,    86,   212,   222,    87,   169,
      54,    68,    69,    70,   129,   121,    55,    56,    72,    98,
      99,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    18,    10,    82,    83,    66,   116,   130,   104,    11,
     134,    58,    66,   105,   119,   120,   156,     1,    57,    57,
       5,    59,     6,   106,   147,   178,    71,   191,   150,   151,
      43,   152,    67,    79,    80,     7,    44,    43,    12,   115,
     119,   120,    78,    44,    19,    14,    45,    46,    47,   119,
     120,   119,   120,    45,    46,    47,    71,   157,    84,    85,
      13,   160,    20,   131,   140,    85,   131,    43,   136,   -80,
     -80,   137,   168,    44,    95,    96,    97,    16,    17,   142,
      21,    22,    23,    45,    46,    47,    34,   164,    35,   143,
     144,   145,    25,    73,    65,   177,   148,   181,    74,    75,
      81,   122,    57,    76,   187,    77,    58,   131,    88,   111,
     101,   131,   139,    26,    27,    28,    29,   102,   108,   161,
     117,   138,   109,   186,   110,   112,   -55,   118,   131,    90,
      91,    92,    93,    94,    95,    96,    97,   149,    57,   135,
     153,   146,   155,   154,   176,   131,   204,   205,   158,   159,
     209,   225,   162,   131,   163,   165,   170,   172,   182,   174,
     131,    57,    57,   207,   173,    57,   221,   179,   180,   183,
     184,   185,   189,   188,   198,   194,   227,   199,   201,   200,
     176,    57,   210,   233,   206,   202,   213,   208,   214,   237,
     215,    57,   216,   217,   219,   218,    36,   224,    57,    31,
     226,   198,    37,   230,    57,   228,    38,   131,   231,    39,
      40,    41,    25,    42,   232,   234,   236,   238,     9,   203,
     220,    43,   141,   122,   103,   132,     0,    44,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    45,    46,    47,
     123,   167,   124,   125,   126,   127,   128,     0,     0,   171,
       0,    90,    91,    92,    93,    94,    95,    96,    97,     0,
       0,   190,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    90,    91,    92,    93,    94,    95,    96,
      97,    90,    91,    92,    93,    94,    95,    96,    97,   211,
     123,     0,   124,   125,   126,   127,   128,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    90,
      91,    92,    93,    94,    95,    96,    97,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    90,    91,    92,
      93,    94,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
      31,     5,    28,    49,    50,     7,    66,    73,    11,    35,
      76,    38,     7,    16,    32,    33,     8,     3,    49,    50,
       4,    48,     0,    26,   105,     8,    36,     8,   109,   110,
      32,   112,    34,    43,    44,    44,    38,    32,     6,    34,
      32,    33,     7,    38,    48,    39,    48,    49,    50,    32,
      33,    32,    33,    48,    49,    50,    66,   117,    18,    19,
       5,   121,     8,    73,    18,    19,    76,    32,    78,    32,
      33,    81,   138,    38,    41,    42,    43,     7,    27,    89,
      35,    39,     9,    48,    49,    50,     7,   133,    10,    99,
     100,   101,    23,     7,    51,   155,   106,   163,     7,     9,
      11,     8,   133,     7,   170,     7,    38,   117,    13,    48,
      11,   121,     9,    44,    45,    46,    47,    13,    13,   129,
       7,     7,    16,   169,    16,    16,    16,     8,   138,    36,
      37,    38,    39,    40,    41,    42,    43,    11,   169,    51,
       8,    49,     7,    16,   154,   155,   192,   193,    15,    32,
     196,   217,     8,   163,    13,     8,     7,    12,    10,    13,
     170,   192,   193,   194,    49,   196,   212,     9,     9,     9,
      16,     8,     8,    12,   184,    13,   222,     9,     8,    10,
     190,   212,     8,   229,   194,    13,     9,    22,    10,   235,
      10,   222,     8,     7,    13,    10,     7,     9,   229,    24,
      10,   211,    13,     8,   235,    14,    17,   217,    10,    20,
      21,    22,    23,    24,     9,    13,    10,    10,     4,   190,
     211,    32,    86,     8,    58,    74,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      25,    12,    27,    28,    29,    30,    31,    -1,    -1,    12,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    16,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    36,    37,    38,    39,    40,    41,    42,
      43,    36,    37,    38,    39,    40,    41,    42,    43,    16,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    36,
      37,    38,    39,    40,    41,    42,    43,    26,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    36,    37,    38,
      39,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    53,    55,    56,     4,     0,    44,    67,    55,
      28,    35,     6,     5,    39,    57,     7,    27,     5,    48,
       8,    35,    39,     9,    54,    23,    44,    45,    46,    47,
      58,    60,    68,    77,     7,    10,     7,    13,    17,    20,
      21,    22,    24,    32,    38,    48,    49,    50,    59,    60,
      69,    81,    84,    85,    92,    98,    99,   100,    38,    48,
      61,    62,    63,    64,    65,    51,     7,    34,    93,    94,
      95,    98,   100,     7,     7,     9,     7,     7,     7,    98,
      98,    11,    59,    59,    18,    19,    87,    90,    13,    26,
      36,    37,    38,    39,    40,    41,    42,    43,   101,   102,
     103,    11,    13,    64,    11,    16,    26,    66,    13,    16,
      16,    48,    16,    78,    79,    34,    94,     7,     8,    32,
      33,    97,     8,    25,    27,    28,    29,    30,    31,    96,
      93,    98,    92,    74,    93,    51,    98,    98,     7,     9,
      18,    90,    98,    98,    98,    98,    49,    61,    98,    11,
      61,    61,    61,     8,    16,     7,     8,    94,    15,    32,
      94,    98,     8,    13,    59,     8,    82,    12,    93,    91,
       7,    12,    12,    49,    13,    80,    98,    94,     8,     9,
       9,    93,    10,     9,    16,     8,    59,    93,    12,     8,
      16,     8,    70,    86,    13,    75,    73,    83,    98,     9,
      10,     8,    13,    80,    59,    59,    98,   100,    22,    59,
       8,    16,    88,     9,    10,    10,     8,     7,    10,    13,
      83,    59,    89,    71,     9,    93,    10,    59,    14,    76,
       8,    10,     9,    59,    13,    72,    10,    59,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    54,    53,    55,    55,    56,    56,    57,    57,
      57,    58,    59,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    63,    64,    64,    65,
      66,    66,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    70,    71,    72,    69,    69,    73,    69,    74,    75,
      69,    76,    69,    78,    77,    79,    77,    80,    80,    82,
      81,    83,    83,    84,    84,    84,    84,    86,    85,    88,
      87,    89,    87,    91,    90,    92,    93,    93,    94,    94,
      94,    94,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   101,   101,   102,   102,   103,   103,
     103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     2,     1,     5,     6,     3,     1,
       0,     2,     0,     2,     2,     3,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     2,     2,     1,     2,
       4,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     0,     0,     0,    14,     1,     0,     8,     0,     0,
      11,     0,    12,     0,     6,     0,     8,     3,     1,     0,
       8,     3,     1,     1,     2,     2,     3,     0,     8,     0,
       8,     0,     9,     0,     5,     3,     4,     1,     3,     1,
       4,     3,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     3,     1,     1,     1,     1,     2,     1,
       2,     4,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 78 "projectMOD.y"
                                           {push_table();}
#line 1642 "y.tab.c"
    break;

  case 3:
#line 78 "projectMOD.y"
                                                                    {
							pop_table();
							success=1;
						   }
#line 1651 "y.tab.c"
    break;

  case 8:
#line 84 "projectMOD.y"
                           {/*printf("<HEADER2 VAR DIV>");*/}
#line 1657 "y.tab.c"
    break;

  case 9:
#line 84 "projectMOD.y"
                                                                    {/*printf("<DIV>");*/}
#line 1663 "y.tab.c"
    break;

  case 10:
#line 84 "projectMOD.y"
                                                                                                         {/*printf("<HEADER2->Epsilon>");*/}
#line 1669 "y.tab.c"
    break;

  case 15:
#line 88 "projectMOD.y"
                                              {}
#line 1675 "y.tab.c"
    break;

  case 17:
#line 89 "projectMOD.y"
                             {
				insert_to_table((yyvsp[-2].var_name),current_data_type);
			    }
#line 1683 "y.tab.c"
    break;

  case 18:
#line 92 "projectMOD.y"
                                          {
		//printf("<ARRAY_DECLARATION COMA VAR_LIST>");
	}
#line 1691 "y.tab.c"
    break;

  case 21:
#line 97 "projectMOD.y"
              {
		insert_to_table((yyvsp[0].var_name),current_data_type);
	      }
#line 1699 "y.tab.c"
    break;

  case 22:
#line 100 "projectMOD.y"
                            {
		//printf("<ARRAY_DECLARATION>");
	}
#line 1707 "y.tab.c"
    break;

  case 25:
#line 105 "projectMOD.y"
                          {
				if ((yyvsp[0].EXPN_type).data_depth!=0){
					yyerror("Incompatible pointer type in assignment");
					exit(0);
				}
				if (!((current_data_type == 2 && (yyvsp[0].EXPN_type).type == 0) || (current_data_type == 3 && (yyvsp[0].EXPN_type).type == 0)
				|| (current_data_type == 3 && (yyvsp[0].EXPN_type).type == 2))){
					if (current_data_type != (yyvsp[0].EXPN_type).type){
						yyerror("Incompatible types.");
						exit(0);
					}
				}
				insert_to_table((yyvsp[-2].var_name),current_data_type);
			}
#line 1726 "y.tab.c"
    break;

  case 26:
#line 119 "projectMOD.y"
                              {
				//printf("<PTR_DEPTH VAR>");
				insert_to_table((yyvsp[0].var_name),current_data_type);
				ptr_depth = 0;
			}
#line 1736 "y.tab.c"
    break;

  case 27:
#line 124 "projectMOD.y"
                              {
				//printf("<MUL PTR_DEPTH>");
				ptr_depth++;

			}
#line 1746 "y.tab.c"
    break;

  case 28:
#line 129 "projectMOD.y"
                              {				
				//printf("<MUL>");
				ptr_depth = 0;
				ptr_depth++;
			}
#line 1756 "y.tab.c"
    break;

  case 29:
#line 134 "projectMOD.y"
                                  {
		is_Array = 1;
		insert_to_table((yyvsp[-1].var_name),current_data_type);
	}
#line 1765 "y.tab.c"
    break;

  case 30:
#line 138 "projectMOD.y"
                                               {
				dims++;
				array_dim[dims] = (yyvsp[-1].integer_val);
				//printf("<ARRAY_SIZE LSQRB %d RSQRB>", $3);
			}
#line 1775 "y.tab.c"
    break;

  case 31:
#line 143 "projectMOD.y"
                                                 {
				dims = 0;
				array_dim[dims] = (yyvsp[-1].integer_val);
				//printf("<LSQRB %d RSQRB>", $2);
			}
#line 1785 "y.tab.c"
    break;

  case 33:
#line 149 "projectMOD.y"
                {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1794 "y.tab.c"
    break;

  case 34:
#line 153 "projectMOD.y"
                {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1803 "y.tab.c"
    break;

  case 35:
#line 157 "projectMOD.y"
                {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1812 "y.tab.c"
    break;

  case 36:
#line 161 "projectMOD.y"
                 {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1821 "y.tab.c"
    break;

  case 41:
#line 170 "projectMOD.y"
                                                               {push_table();}
#line 1827 "y.tab.c"
    break;

  case 42:
#line 170 "projectMOD.y"
                                                                                         {pop_table();}
#line 1833 "y.tab.c"
    break;

  case 43:
#line 170 "projectMOD.y"
                                                                                                                  {push_table();}
#line 1839 "y.tab.c"
    break;

  case 44:
#line 170 "projectMOD.y"
                                                                                                                                            {pop_table();}
#line 1845 "y.tab.c"
    break;

  case 46:
#line 172 "projectMOD.y"
                                                               {push_table();}
#line 1851 "y.tab.c"
    break;

  case 47:
#line 172 "projectMOD.y"
                                                                                         {pop_table();}
#line 1857 "y.tab.c"
    break;

  case 48:
#line 173 "projectMOD.y"
                                         {push_table();}
#line 1863 "y.tab.c"
    break;

  case 49:
#line 173 "projectMOD.y"
                                                                   {pop_table();}
#line 1869 "y.tab.c"
    break;

  case 51:
#line 174 "projectMOD.y"
                                                                                                      {push_table();}
#line 1875 "y.tab.c"
    break;

  case 52:
#line 174 "projectMOD.y"
                                                                                                                                {pop_table();}
#line 1881 "y.tab.c"
    break;

  case 53:
#line 176 "projectMOD.y"
                                     {RWmode = 2; format_string((yyvsp[0].q_string));}
#line 1887 "y.tab.c"
    break;

  case 54:
#line 176 "projectMOD.y"
                                                                            {
					RWmode = 0;
					if(format_spec_counter!=0){
						yyerror("More arguments expected to printf function."); exit(0);
					}
				}
#line 1898 "y.tab.c"
    break;

  case 55:
#line 182 "projectMOD.y"
                                                     {RWmode = 2; format_string((yyvsp[0].q_string));}
#line 1904 "y.tab.c"
    break;

  case 56:
#line 182 "projectMOD.y"
                                                                                                             {
					//printf("%d",format_spec_counter);
					RWmode = 0;
					if(format_spec_counter != 0){
						printf("Parsing Failed\nLine Number %d: %d more arguments required.\n", yylineno, format_spec_counter);
						exit(0);
					}
				}
#line 1917 "y.tab.c"
    break;

  case 57:
#line 190 "projectMOD.y"
                                      {
				//printf("<A_EXPN COMA VAR_LIST_OP>");
				if(array_format_spec[--format_spec_counter] == 4){
					if((yyvsp[-2].EXPN_type).data_depth != 1 || (yyvsp[-2].EXPN_type).type != 1){
						yyerror("Format '%s' expects argument of type 'char *'"); exit(0);
					}
				}
				else if (array_format_spec[format_spec_counter] != (yyvsp[-2].EXPN_type).type){
					yyerror("Type mismatch in arguments."); exit(0);
				}			
			}
#line 1933 "y.tab.c"
    break;

  case 58:
#line 201 "projectMOD.y"
                                 {
				//printf("<A_EXPN>");
				if(array_format_spec[--format_spec_counter] == 4){
					if((yyvsp[0].EXPN_type).data_depth != 1 || (yyvsp[0].EXPN_type).type != 1){
						yyerror("Format '%s' expects argument of type 'char *'"); exit(0);
					}
				}
				else if (array_format_spec[format_spec_counter] != (yyvsp[0].EXPN_type).type){
					yyerror("Type mismatch in arguments."); exit(0);
				}				
			}
#line 1949 "y.tab.c"
    break;

  case 59:
#line 213 "projectMOD.y"
                                   {RWmode = 1; format_string((yyvsp[0].q_string));}
#line 1955 "y.tab.c"
    break;

  case 60:
#line 213 "projectMOD.y"
                                                                                           {RWmode = 0;}
#line 1961 "y.tab.c"
    break;

  case 61:
#line 214 "projectMOD.y"
                                      {
				//printf("<A_EXPN COMA VAR_LIST_IP>");
				if (array_format_spec[--format_spec_counter] != (yyvsp[-2].EXPN_type).type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				else if ((yyvsp[-2].EXPN_type).data_depth != 1){
					yyerror("Error in reference depth."); exit(0);
				}		
			}
#line 1975 "y.tab.c"
    break;

  case 62:
#line 223 "projectMOD.y"
                                 {
				//printf("<A_EXPN>");
				if (array_format_spec[--format_spec_counter] != (yyvsp[0].EXPN_type).type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				else if ((yyvsp[0].EXPN_type).data_depth != 1){
					yyerror("Error in reference depth."); exit(0);
				}				
			}
#line 1989 "y.tab.c"
    break;

  case 67:
#line 234 "projectMOD.y"
                                         {push_table();}
#line 1995 "y.tab.c"
    break;

  case 68:
#line 234 "projectMOD.y"
                                                                   {pop_table();}
#line 2001 "y.tab.c"
    break;

  case 69:
#line 235 "projectMOD.y"
                                                   {push_table();}
#line 2007 "y.tab.c"
    break;

  case 70:
#line 235 "projectMOD.y"
                                                                             {pop_table();}
#line 2013 "y.tab.c"
    break;

  case 71:
#line 235 "projectMOD.y"
                                                                                                                                               {push_table();}
#line 2019 "y.tab.c"
    break;

  case 72:
#line 235 "projectMOD.y"
                                                                                                                                                                         {pop_table();}
#line 2025 "y.tab.c"
    break;

  case 73:
#line 236 "projectMOD.y"
                          {push_table();}
#line 2031 "y.tab.c"
    break;

  case 74:
#line 236 "projectMOD.y"
                                                    {pop_table();}
#line 2037 "y.tab.c"
    break;

  case 75:
#line 239 "projectMOD.y"
                                {
					if((yyvsp[-2].EXPN_type).type!=(yyvsp[0].EXPN_type).type)
					{
						yyerror("Incompatible type in assignment");
						exit(0);
					}else if((yyvsp[-2].EXPN_type).data_depth!=(yyvsp[0].EXPN_type).data_depth)
					{
						//yyerror("Incompatible pointer type in assignment");
						//exit(0);
						printf("\n Line number: %d Warning : Incompatible pointer type in assignment",yylineno);
					}
					else if((yyvsp[-2].EXPN_type).isValue==1)
					{
						yyerror("lvalue required as left operand of the assignment operator");
						exit(0);
					}	
				}
#line 2059 "y.tab.c"
    break;

  case 91:
#line 265 "projectMOD.y"
                                {	
					(yyval.EXPN_type).isValue=1;
					if((yyvsp[-2].EXPN_type).data_depth==(yyvsp[0].EXPN_type).data_depth)
					{
						(yyval.EXPN_type).data_depth=(yyvsp[-2].EXPN_type).data_depth;
						if((yyvsp[-2].EXPN_type).type==(yyvsp[0].EXPN_type).type)
						{
							(yyval.EXPN_type).type=(yyvsp[-2].EXPN_type).type;
						}else
						{
							yyerror("Type mismatch in operands");
							exit(0);	
						}
					}
					else if((yyvsp[-2].EXPN_type).data_depth==0)
					{	
						if((yyvsp[-2].EXPN_type).type==0)
						{	(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth;
							(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
						}
					}
					else if((yyvsp[0].EXPN_type).data_depth==0)
					{	
						if((yyvsp[0].EXPN_type).type==0)
						{	(yyval.EXPN_type).data_depth=(yyvsp[-2].EXPN_type).data_depth;
							(yyval.EXPN_type).type=(yyvsp[-2].EXPN_type).type;
						}
					}
					else
					{
						yyerror("Type mismatch in dereferencing operands");
						exit(0);						
					}
				}
#line 2098 "y.tab.c"
    break;

  case 92:
#line 301 "projectMOD.y"
                                {
					if((yyvsp[-2].EXPN_type).type!=(yyvsp[0].EXPN_type).type)
					{
						yyerror("Type mismatch in operands");exit(0);
					}
					if(is_modulus){
						if((yyvsp[-2].EXPN_type).type!=0 || (yyvsp[0].EXPN_type).type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if((yyvsp[-2].EXPN_type).data_depth!=0 || (yyvsp[0].EXPN_type).data_depth!=0)
					{
						printf("\nInvalid operands to binary %c", current_operator);exit(0);
					}	
					(yyval.EXPN_type).isValue=1;
					(yyval.EXPN_type).data_depth=0;
					(yyval.EXPN_type).type=(yyvsp[-2].EXPN_type).type;	
				}
#line 2122 "y.tab.c"
    break;

  case 93:
#line 320 "projectMOD.y"
                               {
			(yyval.EXPN_type).isValue = (yyvsp[-1].EXPN_type).isValue;
			(yyval.EXPN_type).data_depth = (yyvsp[-1].EXPN_type).data_depth;
			(yyval.EXPN_type).type = (yyvsp[-1].EXPN_type).type;
		}
#line 2132 "y.tab.c"
    break;

  case 94:
#line 325 "projectMOD.y"
                                {
			(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
			(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth;	
			(yyval.EXPN_type).isValue=1;
		}
#line 2142 "y.tab.c"
    break;

  case 95:
#line 330 "projectMOD.y"
                      {
			struct symbol_table column = get_column((yyvsp[0].var_name));
			(yyval.EXPN_type).type = column.type;
			(yyval.EXPN_type).data_depth = column.pointerDepth;
			(yyval.EXPN_type).isValue = 0;
			strcpy((yyval.EXPN_type).var_name, (yyvsp[0].var_name));
		}
#line 2154 "y.tab.c"
    break;

  case 96:
#line 337 "projectMOD.y"
                             {
			(yyval.EXPN_type).type = 0;
			(yyval.EXPN_type).data_depth = 0;	
			(yyval.EXPN_type).isValue = 1;
		}
#line 2164 "y.tab.c"
    break;

  case 97:
#line 342 "projectMOD.y"
                               {
			(yyval.EXPN_type).type = 2;
			(yyval.EXPN_type).data_depth = 0;	
			(yyval.EXPN_type).isValue = 1;
		}
#line 2174 "y.tab.c"
    break;

  case 98:
#line 348 "projectMOD.y"
                        {
				if((yyvsp[0].EXPN_type).data_depth==0)
				{
					yyerror("Invalid operand to unary \'*\' operator");
					exit(0);
				}
				else
				{
					(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
					(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth-1;
					(yyval.EXPN_type).isValue=0;
				}										
			}
#line 2192 "y.tab.c"
    break;

  case 99:
#line 361 "projectMOD.y"
                               {
			if(dims!=get_array_dimensions((yyvsp[0].EXPN_type).var_name) && (RWmode == 0)){
				printf("\n Error: Indexing error in array: %s\n", (yyvsp[0].EXPN_type).var_name);exit(0);
			}
			(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
			(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth;
			(yyval.EXPN_type).isValue=0;
			dims=0;
		}
#line 2206 "y.tab.c"
    break;

  case 100:
#line 371 "projectMOD.y"
                        {		
				if((yyvsp[0].EXPN_type).isValue==1)
				{
					yyerror("lvalue required for unary operator &");
					exit(0);
				}
				(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
				(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth+1;
				(yyval.EXPN_type).isValue=1;						
			}
#line 2221 "y.tab.c"
    break;

  case 101:
#line 383 "projectMOD.y"
                        {	
				dims++;
				if((yyvsp[-1].EXPN_type).data_depth!=0 || (yyvsp[-1].EXPN_type).type!=0)
				{
					yyerror("Array index integer expected\n");
					exit(0);
				}
				else if((yyvsp[-3].EXPN_type).data_depth==0)
				{
					yyerror("Subscripted value neither array nor pointer");
					exit(0);
				}
				else
				{
					(yyval.EXPN_type).type=(yyvsp[-3].EXPN_type).type;
					(yyval.EXPN_type).data_depth=(yyvsp[-3].EXPN_type).data_depth-1;
					(yyval.EXPN_type).isValue=0;
					strcpy((yyval.EXPN_type).var_name, (yyvsp[-3].EXPN_type).var_name);
				}
			}
#line 2246 "y.tab.c"
    break;

  case 102:
#line 403 "projectMOD.y"
                                                {
				struct symbol_table column = get_column((yyvsp[-3].var_name));
				dims++;
				if((yyvsp[-1].EXPN_type).data_depth!=0 || (yyvsp[-1].EXPN_type).type!=0)
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
					(yyval.EXPN_type).type = column.type;
					(yyval.EXPN_type).data_depth = column.pointerDepth-1;
					(yyval.EXPN_type).isValue = 0;
					strcpy((yyval.EXPN_type).var_name, (yyvsp[-3].var_name));
				}
			}
#line 2272 "y.tab.c"
    break;

  case 103:
#line 425 "projectMOD.y"
                                       {
				if((yyval.EXPN_type).isValue==1)
				{
					yyerror("lvalue required");exit(0);
				}else
				{
					(yyval.EXPN_type).type=(yyvsp[-1].EXPN_type).type;
					(yyval.EXPN_type).data_depth=(yyvsp[-1].EXPN_type).data_depth;	
					(yyval.EXPN_type).isValue=1;
				}
			}
#line 2288 "y.tab.c"
    break;

  case 108:
#line 439 "projectMOD.y"
               {current_operator='/';}
#line 2294 "y.tab.c"
    break;

  case 109:
#line 440 "projectMOD.y"
                      {current_operator='*';}
#line 2300 "y.tab.c"
    break;

  case 110:
#line 441 "projectMOD.y"
                      {current_operator='^';}
#line 2306 "y.tab.c"
    break;

  case 111:
#line 442 "projectMOD.y"
                      {current_operator='%'; is_modulus = 1;}
#line 2312 "y.tab.c"
    break;


#line 2316 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 444 "projectMOD.y"


void push_table(){
    struct symbol_table_stack * node = (struct symbol_table_stack *)malloc(sizeof(struct symbol_table_stack));
    node->var_count = -1;
    
    if(pointer == NULL){
        pointer = node;
    }
    else{
        pointer->next = node;
        node->prev = pointer;
        pointer = node;
    }
}

void pop_table(){
	display_symbol_table();
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
void insert_to_table(char var[30], int type)
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
void format_string(char str[200]){
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
