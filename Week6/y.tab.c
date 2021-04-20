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

#line 98 "y.tab.c"

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
    ELSE = 273,
    FOR = 274,
    DO = 275,
    WHILE = 276,
    ET = 277,
    EQ = 278,
    GT = 279,
    LT = 280,
    GTE = 281,
    LTE = 282,
    NE = 283,
    AMPER = 284,
    OR = 285,
    NOT = 286,
    DQUOTE = 287,
    PLUS = 288,
    MINUS = 289,
    MUL = 290,
    DIV = 291,
    MOD = 292,
    EXP = 293,
    UPLUS = 294,
    UMINUS = 295,
    INT = 296,
    CHAR = 297,
    FLOAT = 298,
    DOUBLE = 299,
    VAR = 300,
    NUMBER = 301
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
#define ET 277
#define EQ 278
#define GT 279
#define LT 280
#define GTE 281
#define LTE 282
#define NE 283
#define AMPER 284
#define OR 285
#define NOT 286
#define DQUOTE 287
#define PLUS 288
#define MINUS 289
#define MUL 290
#define DIV 291
#define MOD 292
#define EXP 293
#define UPLUS 294
#define UMINUS 295
#define INT 296
#define CHAR 297
#define FLOAT 298
#define DOUBLE 299
#define VAR 300
#define NUMBER 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "projectMOD.y"

int data_type;
char var_name[30];
int integer_val;
struct 
	{
		int  data_depth;
		int type;
		int isValue;
	}EXPN_type;

#line 254 "y.tab.c"

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
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    66,    66,    67,    67,    68,    68,    68,
      69,    70,    70,    70,    72,    73,    76,    79,    80,    83,
      86,    87,    92,    97,   102,   106,   111,   116,   117,   121,
     125,   129,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   145,   167,   185,   185,   186,   186,   186,   187,
     188,   189,   198,   198,   198,   198,   198,   198,   199,   199,
     201,   204,   209,   218,   224,   235,   247,   247,   261,   261,
     277,   305,   333,   343,   353,   364,   374,   380,   386,   398,
     408,   421,   427,   436,   436
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "HEADER_FILE", "MAIN",
  "LB", "RB", "LCB", "RCB", "LSQRB", "RSQRB", "SC", "COLON", "QMARK",
  "COMA", "IF", "ELSE", "FOR", "DO", "WHILE", "ET", "EQ", "GT", "LT",
  "GTE", "LTE", "NE", "AMPER", "OR", "NOT", "DQUOTE", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "EXP", "UPLUS", "UMINUS", "INT", "CHAR", "FLOAT",
  "DOUBLE", "VAR", "NUMBER", "$accept", "prm", "HEADERS", "HEADER",
  "HEADER2", "BODY", "BODY2", "DECLARATION_STATEMENTS", "VAR_LIST",
  "PTR_VAR", "PTR_DEPTH", "ARRAY_DECLARATION", "ARRAY_SIZE", "MAIN_TYPE",
  "DATA_TYPE", "PROGRAM_STATEMENTS", "POINTER_STATEMENTS",
  "POINTER_STATEMENTS_LHS", "LOGICAL_EXPN", "LOGICAL_EXPN1",
  "LOGICAL_EXPN2", "LOGICAL_EXPN2_ARTH", "COMP_OPERATOR",
  "LOGICAL_OPERATOR", "VAR_EXPN1", "VAR_EXPN2", "VAR_ARRAY_ACCESS_LHS",
  "VAR_ARRAY_ACCESS_RHS", "ARRAY_ACCESS", "$@1", "$@2", "A_EXPN",
  "UNARY_OPERATORS", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    11,    17,   -16,    10,   -13,   -64,   -64,    22,   -64,
      31,    28,    50,    14,   -64,     2,    58,   -64,    39,    60,
      65,   -64,   -64,    51,   -64,   -64,   -64,   -64,   115,    91,
     -25,   -64,     4,   -64,   122,   123,   129,   124,    27,     3,
     -64,    91,    91,   126,   117,   128,   130,   121,   139,     7,
     162,   160,   132,   170,    24,    27,   180,    27,   177,   -64,
     181,    56,   -64,    75,   -64,   133,     4,   146,    91,     4,
      27,   133,   -64,    27,   -64,   -64,     5,   -64,   -64,   -64,
     -64,    27,   -64,   -64,    27,   -64,   144,   -25,   182,   -64,
     -25,   -64,   -25,   185,     0,   116,   -64,    24,    67,   183,
     184,   166,   -64,    24,   -64,   -64,   -64,   -64,   -64,   -64,
      27,    27,    27,    27,    27,    27,    27,   -64,   188,    54,
     187,   191,   189,   116,    27,   133,   -64,   -64,   133,   133,
     186,   -64,   156,   -64,   -64,    24,   -64,   -64,    38,   194,
     -64,    56,   -64,    78,    78,    67,    67,    67,   167,   195,
     183,     4,   190,   197,   125,    27,   -64,   196,    46,    98,
      91,    91,   199,   200,    91,   -64,   145,   -64,   -64,   203,
     204,   164,     4,   205,   -64,   202,   192,    21,   209,   210,
     -64,   211,   212,     5,   213,   206,    91,    91,    91,   -64,
     214,   215,   216,   -64,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,    27,     0,     3,
       0,     9,     0,     0,     8,     0,     0,     5,     0,     0,
       0,     6,     7,     0,    28,    29,    30,    31,     0,    11,
       0,     2,     0,    33,     0,     0,     0,     0,     0,     0,
      10,    11,    11,     0,     0,     0,     0,     0,    23,    18,
       0,    20,     0,    19,     0,     0,     0,     0,    79,    77,
       0,    45,    47,     0,    81,    51,     0,     0,    11,     0,
       0,    43,    68,     0,    83,    84,    64,    63,    12,    13,
      35,     0,    32,    34,     0,    22,     0,     0,    24,    14,
       0,    21,     0,     0,     0,    51,    82,     0,    80,    65,
       0,     0,    59,     0,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,    60,    66,    62,    42,    61,
       0,    15,     0,    17,    16,     0,    49,    76,     0,     0,
      58,    46,    50,    70,    71,    72,    73,    74,    75,     0,
      64,     0,     0,     0,     0,     0,    26,     0,     0,    44,
      11,    11,     0,     0,    11,    69,     0,    25,    48,     0,
       0,     0,     0,     0,    67,     0,    37,     0,     0,     0,
      39,     0,     0,     0,     0,     0,    11,    11,    11,    40,
       0,     0,     0,    36,    38,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   219,   -64,   -64,   -64,   -41,   207,    -3,   -64,
     179,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -63,   -45,
     -64,   118,   -64,   -64,   165,    62,   -64,   -64,   -56,   -64,
     -64,   -33,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    15,    28,    40,    41,    50,    51,
      52,    53,    88,     8,    30,    42,    43,    44,    60,    61,
      62,    63,   110,   103,    45,    46,    47,    64,    76,   155,
     124,    65,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    79,    99,   118,    77,    71,   122,    18,   136,    94,
      48,    54,    10,     1,    72,     5,   126,     6,    86,    11,
      49,    95,    96,    87,    98,     7,    73,   121,    12,   101,
     102,    54,    72,    55,    70,    56,    13,   123,    17,    57,
     125,   127,    74,    75,    74,    75,   159,    19,   128,    58,
      59,   129,   138,    55,   168,    93,    55,    16,   141,    57,
      74,    75,    57,   150,    14,    72,    20,   101,   102,    58,
      59,    21,    58,    59,    23,   101,   102,    73,   143,   144,
     145,   146,   147,   148,   131,   101,   102,   133,   162,   134,
     158,   154,    24,    25,    26,    27,    22,   104,    32,   105,
     106,   107,   108,   109,    33,   116,    74,    75,    34,   179,
      35,    36,    37,   113,   114,   115,   116,    74,    75,   169,
     170,   183,   166,   173,   137,    31,    38,   -48,   -48,    66,
      67,    69,    24,    25,    26,    27,    39,   165,    68,    80,
      81,    82,    77,    83,    84,   190,   191,   192,   127,   111,
     112,   113,   114,   115,   116,    74,    75,   174,   111,   112,
     113,   114,   115,   116,    74,    75,   111,   112,   113,   114,
     115,   116,    74,    75,    48,    89,    90,    91,   111,   112,
     113,   114,   115,   116,    74,    75,    92,    97,    72,   100,
     130,   119,   135,   132,   126,   140,   149,   153,   156,   139,
     151,   152,   157,   160,   161,   116,   164,   172,   167,   177,
     182,   163,   171,   175,   176,   180,   181,   184,   185,   189,
     186,   187,   188,     9,   193,   194,   195,    85,   142,     0,
      29,     0,   120,   178
};

static const yytype_int16 yycheck[] =
{
      41,    42,    58,    66,    39,    38,    69,     5,     8,    54,
      35,     7,    25,     3,    11,     4,    11,     0,    11,    32,
      45,    54,    55,    16,    57,    41,    23,    68,     6,    29,
      30,     7,    11,    29,     7,    31,     5,    70,    24,    35,
      73,    76,    39,    40,    39,    40,     8,    45,    81,    45,
      46,    84,    97,    29,     8,    31,    29,     7,   103,    35,
      39,    40,    35,   119,    36,    11,     8,    29,    30,    45,
      46,    32,    45,    46,     9,    29,    30,    23,   111,   112,
     113,   114,   115,   116,    87,    29,    30,    90,   151,    92,
     135,   124,    41,    42,    43,    44,    36,    22,     7,    24,
      25,    26,    27,    28,    13,    38,    39,    40,    17,   172,
      19,    20,    21,    35,    36,    37,    38,    39,    40,   160,
     161,   177,   155,   164,     8,    10,    35,    29,    30,     7,
       7,     7,    41,    42,    43,    44,    45,    12,     9,    13,
      23,    13,   177,    13,    23,   186,   187,   188,   183,    33,
      34,    35,    36,    37,    38,    39,    40,    12,    33,    34,
      35,    36,    37,    38,    39,    40,    33,    34,    35,    36,
      37,    38,    39,    40,    35,    13,    16,    45,    33,    34,
      35,    36,    37,    38,    39,    40,    16,     7,    11,     8,
      46,    45,     7,    11,    11,    29,     8,     8,    12,    15,
      13,    10,    46,     9,     9,    38,     9,     7,    12,    45,
      18,    21,    13,    10,    10,    10,    14,     8,     8,    13,
       9,     9,     9,     4,    10,    10,    10,    48,   110,    -1,
      23,    -1,    67,   171
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,    49,    50,     4,     0,    41,    60,    49,
      25,    32,     6,     5,    36,    51,     7,    24,     5,    45,
       8,    32,    36,     9,    41,    42,    43,    44,    52,    54,
      61,    10,     7,    13,    17,    19,    20,    21,    35,    45,
      53,    54,    62,    63,    64,    71,    72,    73,    35,    45,
      55,    56,    57,    58,     7,    29,    31,    35,    45,    46,
      65,    66,    67,    68,    74,    78,     7,     7,     9,     7,
       7,    78,    11,    23,    39,    40,    75,    79,    53,    53,
      13,    23,    13,    13,    23,    57,    11,    16,    59,    13,
      16,    45,    16,    31,    66,    78,    78,     7,    78,    75,
       8,    29,    30,    70,    22,    24,    25,    26,    27,    28,
      69,    33,    34,    35,    36,    37,    38,    79,    65,    45,
      71,    53,    65,    78,    77,    78,    11,    79,    78,    78,
      46,    55,    11,    55,    55,     7,     8,     8,    66,    15,
      29,    66,    68,    78,    78,    78,    78,    78,    78,     8,
      75,    13,    10,     8,    78,    76,    12,    46,    66,     8,
       9,     9,    65,    21,     9,    12,    78,    12,     8,    53,
      53,    13,     7,    53,    12,    10,    10,    45,    72,    65,
      10,    14,    18,    75,     8,     8,     9,     9,     9,    13,
      53,    53,    53,    10,    10,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      52,    53,    53,    53,    54,    55,    55,    55,    55,    55,
      55,    56,    57,    57,    58,    59,    59,    60,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    65,    65,    66,    66,    66,    66,
      67,    68,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    74,    76,    75,    77,    75,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     1,     5,     6,     3,     1,     0,
       2,     0,     2,     2,     3,     3,     3,     3,     1,     1,
       1,     2,     2,     1,     2,     4,     3,     1,     1,     1,
       1,     1,     2,     1,     2,     2,    11,     7,    11,     7,
       9,    11,     3,     2,     4,     1,     3,     1,     4,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     3,     3,     2,     2,     2,     0,     5,     0,     4,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     1,
       2,     1,     2,     1,     1
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
#line 63 "projectMOD.y"
                                                    {
							printf("\n parsing successful\n");
						   }
#line 1572 "y.tab.c"
    break;

  case 7:
#line 68 "projectMOD.y"
                           {/*printf("<HEADER2 VAR DIV>");*/}
#line 1578 "y.tab.c"
    break;

  case 8:
#line 68 "projectMOD.y"
                                                                    {/*printf("<DIV>");*/}
#line 1584 "y.tab.c"
    break;

  case 9:
#line 68 "projectMOD.y"
                                                                                                         {/*printf("<HEADER2->Epsilon>");*/}
#line 1590 "y.tab.c"
    break;

  case 14:
#line 72 "projectMOD.y"
                                              {}
#line 1596 "y.tab.c"
    break;

  case 15:
#line 73 "projectMOD.y"
                             {
				insert_to_table((yyvsp[-2].var_name),current_data_type);
			    }
#line 1604 "y.tab.c"
    break;

  case 16:
#line 76 "projectMOD.y"
                                          {
		//printf("<ARRAY_DECLARATION COMA VAR_LIST>");
	}
#line 1612 "y.tab.c"
    break;

  case 18:
#line 80 "projectMOD.y"
              {
		insert_to_table((yyvsp[0].var_name),current_data_type);
	      }
#line 1620 "y.tab.c"
    break;

  case 19:
#line 83 "projectMOD.y"
                            {
		//printf("<ARRAY_DECLARATION>");
	}
#line 1628 "y.tab.c"
    break;

  case 21:
#line 87 "projectMOD.y"
                              {
				//printf("<PTR_DEPTH VAR>");
				insert_to_table((yyvsp[0].var_name),current_data_type);
				ptr_depth = 0;
			}
#line 1638 "y.tab.c"
    break;

  case 22:
#line 92 "projectMOD.y"
                              {
				//printf("<MUL PTR_DEPTH>");
				ptr_depth++;

			}
#line 1648 "y.tab.c"
    break;

  case 23:
#line 97 "projectMOD.y"
                              {				
				//printf("<MUL>");
				ptr_depth = 0;
				ptr_depth++;
			}
#line 1658 "y.tab.c"
    break;

  case 24:
#line 102 "projectMOD.y"
                                  {
		is_Array = 1;
		insert_to_table((yyvsp[-1].var_name),current_data_type);
	}
#line 1667 "y.tab.c"
    break;

  case 25:
#line 106 "projectMOD.y"
                                           {
				dims++;
				array_dim[dims] = (yyvsp[-1].integer_val);
				//printf("<ARRAY_SIZE LSQRB %d RSQRB>", $3);
			}
#line 1677 "y.tab.c"
    break;

  case 26:
#line 111 "projectMOD.y"
                                             {
				dims = 0;
				array_dim[dims] = (yyvsp[-1].integer_val);
				//printf("<LSQRB %d RSQRB>", $2);
			}
#line 1687 "y.tab.c"
    break;

  case 28:
#line 117 "projectMOD.y"
                {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1696 "y.tab.c"
    break;

  case 29:
#line 121 "projectMOD.y"
                {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1705 "y.tab.c"
    break;

  case 30:
#line 125 "projectMOD.y"
                {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1714 "y.tab.c"
    break;

  case 31:
#line 129 "projectMOD.y"
                 {
			(yyval.data_type)=(yyvsp[0].data_type);
			current_data_type=(yyvsp[0].data_type);
		}
#line 1723 "y.tab.c"
    break;

  case 42:
#line 145 "projectMOD.y"
                                                     {
						if((yyvsp[-2].EXPN_type).type!=(yyvsp[0].EXPN_type).type)
						{
							yyerror("\ntype mismatch in the expression\n");
							exit(0);
						}else if((yyvsp[-2].EXPN_type).data_depth!=(yyvsp[0].EXPN_type).data_depth)
						{
							printf("\n Line number: %d Warning : Incompatible pointer type in assignment",yylineno);
						}
						else if((yyvsp[-2].EXPN_type).isValue==1)
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
#line 1750 "y.tab.c"
    break;

  case 43:
#line 167 "projectMOD.y"
                                     {
							if((yyvsp[0].EXPN_type).data_depth==0)
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
								(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
								(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth-1;
								(yyval.EXPN_type).isValue=0;
							}
							expn_type = -1;
						}
#line 1773 "y.tab.c"
    break;

  case 51:
#line 189 "projectMOD.y"
                                 {
						if (is_modulus){
							if(expn_type!=0){
								yyerror("Modulus operator reserved for integers."); exit(0);
							}
							is_modulus = 0;
						}
						expn_type = -1;
					}
#line 1787 "y.tab.c"
    break;

  case 60:
#line 201 "projectMOD.y"
                                {	
					check_EXPNtype_lhs((yyvsp[-2].var_name));
			}
#line 1795 "y.tab.c"
    break;

  case 61:
#line 204 "projectMOD.y"
                                                         {
					//printf("<VAR_ARRAY_ACCESS_LHS EQ A_EXPN SC>");
					check_EXPNtype_lhs((yyvsp[-2].var_name));					
			}
#line 1804 "y.tab.c"
    break;

  case 62:
#line 209 "projectMOD.y"
                                                   {
				if(lookup_in_table((yyvsp[-2].var_name))==-1){
					printf("\n variable \"%s\" undeclared\n",(yyvsp[-2].var_name));exit(0);
				}
				if(dims!=get_array_dimensions((yyvsp[-2].var_name))){
					printf("\n Error: Indexing error in array: %s\n", (yyvsp[-2].var_name));
					exit(0);
				}				
			}
#line 1818 "y.tab.c"
    break;

  case 63:
#line 218 "projectMOD.y"
                                              {
				if(lookup_in_table((yyvsp[-1].var_name))==-1){
					printf("\n variable \"%s\" undeclared\n",(yyvsp[-1].var_name));exit(0);
				}
			}
#line 1828 "y.tab.c"
    break;

  case 64:
#line 224 "projectMOD.y"
                                           {
					strcpy((yyval.var_name),(yyvsp[-1].var_name));
					if(get_array_dimensions((yyvsp[-1].var_name))==0){
						yyerror("Subscripted value neither array nor pointer");
						exit(0);
					}
					if(dims!=get_array_dimensions((yyvsp[-1].var_name))){
						printf("\n Error: Indexing error in array: %s\n", (yyvsp[-1].var_name));
						exit(0);
					}					
				}
#line 1844 "y.tab.c"
    break;

  case 65:
#line 235 "projectMOD.y"
                                           {
						check_EXPNtype_rhs((yyvsp[-1].var_name));
						strcpy((yyval.var_name),(yyvsp[-1].var_name));
						if(get_array_dimensions((yyvsp[-1].var_name))==0){
							yyerror("Subscripted value neither array nor pointer");
							exit(0);
						}
						if(dims!=get_array_dimensions((yyvsp[-1].var_name))){
							printf("\n Error: Indexing error in array: %s\n", (yyvsp[-1].var_name));
							exit(0);
						}						
				}
#line 1861 "y.tab.c"
    break;

  case 66:
#line 247 "projectMOD.y"
                                     {expn_type_temp = expn_type; expn_type = -1;}
#line 1867 "y.tab.c"
    break;

  case 67:
#line 247 "projectMOD.y"
                                                                                                {
					dims++;
					//printf("<ARRAY_ACCESS LSQRB %s RSQRB>");
					if (is_modulus){
						if(expn_type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if((yyvsp[-1].EXPN_type).data_depth!=0 || (yyvsp[-1].EXPN_type).type!=0){
						yyerror("\nError: Arrays must be indexed by int values."); exit(0);
					}
					expn_type = expn_type_temp;
				}
#line 1886 "y.tab.c"
    break;

  case 68:
#line 261 "projectMOD.y"
                                        {expn_type_temp = expn_type; expn_type = -1;}
#line 1892 "y.tab.c"
    break;

  case 69:
#line 261 "projectMOD.y"
                                                                                                   {
					dims=0;
					dims++;
					//printf("<LSQRB %s RSQRB>");
					if (is_modulus){
						if(expn_type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if((yyvsp[-1].EXPN_type).data_depth!=0 || (yyvsp[-1].EXPN_type).type!=0){
						yyerror("\nError: Arrays must be indexed by int values."); exit(0);
					}
					expn_type = expn_type_temp;
				}
#line 1912 "y.tab.c"
    break;

  case 70:
#line 277 "projectMOD.y"
                            {
			(yyval.EXPN_type).isValue=1;
			isValue=1;
			if((yyvsp[-2].EXPN_type).data_depth==(yyvsp[0].EXPN_type).data_depth)
			{
				(yyval.EXPN_type).data_depth=(yyvsp[-2].EXPN_type).data_depth;
				(yyval.EXPN_type).type=(yyvsp[-2].EXPN_type).type;
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
#line 1945 "y.tab.c"
    break;

  case 71:
#line 305 "projectMOD.y"
                                     {
			(yyval.EXPN_type).isValue=1;
			isValue=1;
			if((yyvsp[-2].EXPN_type).data_depth==(yyvsp[0].EXPN_type).data_depth)
			{
				(yyval.EXPN_type).data_depth=(yyvsp[-2].EXPN_type).data_depth;
				(yyval.EXPN_type).type=(yyvsp[-2].EXPN_type).type;
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
#line 1978 "y.tab.c"
    break;

  case 72:
#line 333 "projectMOD.y"
                                   {
			if((yyvsp[-2].EXPN_type).data_depth!=0 || (yyvsp[0].EXPN_type).data_depth!=0)
			{
				yyerror("Invalid operands to binary operator *");exit(0);	
			}	
			(yyval.EXPN_type).isValue = 1;
			isValue=1;
			(yyval.EXPN_type).data_depth = 0;
			(yyval.EXPN_type).type = (yyvsp[-2].EXPN_type).type;
		}
#line 1993 "y.tab.c"
    break;

  case 73:
#line 343 "projectMOD.y"
                                   {
			if((yyvsp[-2].EXPN_type).data_depth!=0 || (yyvsp[0].EXPN_type).data_depth!=0)
			{
				yyerror("Invalid operands to binary operator /");exit(0);	
			}	
			(yyval.EXPN_type).isValue = 1;
			isValue=1;
			(yyval.EXPN_type).data_depth = 0;
			(yyval.EXPN_type).type = (yyvsp[-2].EXPN_type).type;
		}
#line 2008 "y.tab.c"
    break;

  case 74:
#line 353 "projectMOD.y"
                                    {
			is_modulus = 1;
			if((yyvsp[-2].EXPN_type).data_depth!=0 || (yyvsp[0].EXPN_type).data_depth!=0)
			{
				yyerror("Invalid operands to binary operator %");exit(0);	
			}	
			(yyval.EXPN_type).isValue = 1;
			isValue=1;
			(yyval.EXPN_type).data_depth = 0;
			(yyval.EXPN_type).type = (yyvsp[-2].EXPN_type).type;
		}
#line 2024 "y.tab.c"
    break;

  case 75:
#line 364 "projectMOD.y"
                                    {
			if((yyvsp[-2].EXPN_type).data_depth!=0 || (yyvsp[0].EXPN_type).data_depth!=0)
			{
				yyerror("Invalid operands to binary operator ^");exit(0);	
			}	
			(yyval.EXPN_type).isValue = 1;
			isValue=1;
			(yyval.EXPN_type).data_depth = 0;
			(yyval.EXPN_type).type = (yyvsp[-2].EXPN_type).type;
		}
#line 2039 "y.tab.c"
    break;

  case 76:
#line 374 "projectMOD.y"
                               {
			isValue = 0;//only for pointers
			(yyval.EXPN_type).isValue = (yyvsp[-1].EXPN_type).isValue;
			(yyval.EXPN_type).data_depth = (yyvsp[-1].EXPN_type).data_depth;
			(yyval.EXPN_type).type = (yyvsp[-1].EXPN_type).type;
		}
#line 2050 "y.tab.c"
    break;

  case 77:
#line 380 "projectMOD.y"
                         {
			expn_type = 0;
			(yyval.EXPN_type).type = 0;
			(yyval.EXPN_type).data_depth = 0;	
			(yyval.EXPN_type).isValue = 1;
		}
#line 2061 "y.tab.c"
    break;

  case 78:
#line 386 "projectMOD.y"
                                         {
			if((yyval.EXPN_type).isValue==1)
			{
				yyerror("lvalue required");exit(0);
			}else
			{
				(yyval.EXPN_type).type=(yyvsp[-1].EXPN_type).type;
				(yyval.EXPN_type).data_depth=(yyvsp[-1].EXPN_type).data_depth;	
				(yyval.EXPN_type).isValue=1;
				isValue=1;
			}
		}
#line 2078 "y.tab.c"
    break;

  case 79:
#line 398 "projectMOD.y"
                      {		
			isValue = 0;//only for pointers	
			struct symbol_table column = get_column((yyvsp[0].var_name));
			(yyval.EXPN_type).type = column.type;
			(yyval.EXPN_type).data_depth = column.pointerDepth;
			(yyval.EXPN_type).isValue = 0;
			if (column.pointerDepth==0){
				check_EXPNtype_rhs((yyvsp[0].var_name));
			}
		}
#line 2093 "y.tab.c"
    break;

  case 80:
#line 408 "projectMOD.y"
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
#line 2111 "y.tab.c"
    break;

  case 81:
#line 421 "projectMOD.y"
                                       {
			struct symbol_table column = get_column((yyvsp[0].var_name));
			(yyval.EXPN_type).type = column.type;
			(yyval.EXPN_type).data_depth = column.pointerDepth-dims;
			(yyval.EXPN_type).isValue = 0;
		}
#line 2122 "y.tab.c"
    break;

  case 82:
#line 427 "projectMOD.y"
                               {
			if((yyvsp[0].EXPN_type).isValue){
				yyerror("lvalue required for unary operator &");exit(0);
			}
			(yyval.EXPN_type).type=(yyvsp[0].EXPN_type).type;
			(yyval.EXPN_type).data_depth=(yyvsp[0].EXPN_type).data_depth+1;
			(yyval.EXPN_type).isValue=1;
		}
#line 2135 "y.tab.c"
    break;


#line 2139 "y.tab.c"

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
#line 438 "projectMOD.y"


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
