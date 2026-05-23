/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse indra_parse
#define yylex   indra_lex
#define yyerror indra_error
#define yylval  indra_lval
#define yychar  indra_char
#define yydebug indra_debug
#define yynerrs indra_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT_TYPE = 259,
     STRING = 260,
     LLKEY = 261,
     VECTOR = 262,
     QUATERNION = 263,
     LIST = 264,
     STATE = 265,
     EVENT = 266,
     JUMP = 267,
     RETURN = 268,
     STATE_ENTRY = 269,
     STATE_EXIT = 270,
     TOUCH_START = 271,
     TOUCH = 272,
     TOUCH_END = 273,
     COLLISION_START = 274,
     COLLISION = 275,
     COLLISION_END = 276,
     LAND_COLLISION_START = 277,
     LAND_COLLISION = 278,
     LAND_COLLISION_END = 279,
     TIMER = 280,
     CHAT = 281,
     SENSOR = 282,
     NO_SENSOR = 283,
     CONTROL = 284,
     AT_TARGET = 285,
     NOT_AT_TARGET = 286,
     AT_ROT_TARGET = 287,
     NOT_AT_ROT_TARGET = 288,
     MONEY = 289,
     EMAIL = 290,
     RUN_TIME_PERMISSIONS = 291,
     INVENTORY = 292,
     ATTACH = 293,
     DATASERVER = 294,
     MOVING_START = 295,
     MOVING_END = 296,
     REZ = 297,
     OBJECT_REZ = 298,
     LINK_MESSAGE = 299,
     REMOTE_DATA = 300,
     HTTP_RESPONSE = 301,
     HTTP_REQUEST = 302,
     TRANSACTION_RESULT = 303,
     PATH_UPDATE = 304,
     EXPERIENCE_PERMISSIONS = 305,
     EXPERIENCE_PERMISSIONS_DENIED = 306,
     IDENTIFIER = 307,
     STATE_DEFAULT = 308,
     INTEGER_CONSTANT = 309,
     INTEGER_TRUE = 310,
     INTEGER_FALSE = 311,
     FP_CONSTANT = 312,
     STRING_CONSTANT = 313,
     INC_OP = 314,
     DEC_OP = 315,
     ADD_ASSIGN = 316,
     SUB_ASSIGN = 317,
     MUL_ASSIGN = 318,
     DIV_ASSIGN = 319,
     MOD_ASSIGN = 320,
     EQ = 321,
     NEQ = 322,
     GEQ = 323,
     LEQ = 324,
     BOOLEAN_AND = 325,
     BOOLEAN_OR = 326,
     SHIFT_LEFT = 327,
     SHIFT_RIGHT = 328,
     IF = 329,
     ELSE = 330,
     FOR = 331,
     DO = 332,
     WHILE = 333,
     PRINT = 334,
     PERIOD = 335,
     ZERO_VECTOR = 336,
     ZERO_ROTATION = 337,
     TOUCH_INVALID_VECTOR = 338,
     TOUCH_INVALID_TEXCOORD = 339,
     LOWER_THAN_ELSE = 340,
     INITIALIZER = 341
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT_TYPE 259
#define STRING 260
#define LLKEY 261
#define VECTOR 262
#define QUATERNION 263
#define LIST 264
#define STATE 265
#define EVENT 266
#define JUMP 267
#define RETURN 268
#define STATE_ENTRY 269
#define STATE_EXIT 270
#define TOUCH_START 271
#define TOUCH 272
#define TOUCH_END 273
#define COLLISION_START 274
#define COLLISION 275
#define COLLISION_END 276
#define LAND_COLLISION_START 277
#define LAND_COLLISION 278
#define LAND_COLLISION_END 279
#define TIMER 280
#define CHAT 281
#define SENSOR 282
#define NO_SENSOR 283
#define CONTROL 284
#define AT_TARGET 285
#define NOT_AT_TARGET 286
#define AT_ROT_TARGET 287
#define NOT_AT_ROT_TARGET 288
#define MONEY 289
#define EMAIL 290
#define RUN_TIME_PERMISSIONS 291
#define INVENTORY 292
#define ATTACH 293
#define DATASERVER 294
#define MOVING_START 295
#define MOVING_END 296
#define REZ 297
#define OBJECT_REZ 298
#define LINK_MESSAGE 299
#define REMOTE_DATA 300
#define HTTP_RESPONSE 301
#define HTTP_REQUEST 302
#define TRANSACTION_RESULT 303
#define PATH_UPDATE 304
#define EXPERIENCE_PERMISSIONS 305
#define EXPERIENCE_PERMISSIONS_DENIED 306
#define IDENTIFIER 307
#define STATE_DEFAULT 308
#define INTEGER_CONSTANT 309
#define INTEGER_TRUE 310
#define INTEGER_FALSE 311
#define FP_CONSTANT 312
#define STRING_CONSTANT 313
#define INC_OP 314
#define DEC_OP 315
#define ADD_ASSIGN 316
#define SUB_ASSIGN 317
#define MUL_ASSIGN 318
#define DIV_ASSIGN 319
#define MOD_ASSIGN 320
#define EQ 321
#define NEQ 322
#define GEQ 323
#define LEQ 324
#define BOOLEAN_AND 325
#define BOOLEAN_OR 326
#define SHIFT_LEFT 327
#define SHIFT_RIGHT 328
#define IF 329
#define ELSE 330
#define FOR 331
#define DO 332
#define WHILE 333
#define PRINT 334
#define PERIOD 335
#define ZERO_VECTOR 336
#define ZERO_ROTATION 337
#define TOUCH_INVALID_VECTOR 338
#define TOUCH_INVALID_TEXCOORD 339
#define LOWER_THAN_ELSE 340
#define INITIALIZER 341




/* Copy the first part of user declarations.  */
#line 1 "indra.y"

	#include "linden_common.h"
	#include "lscript_tree.h"

	// yyscan_t is the reentrant flex scanner handle (void* under the hood).
	typedef void* yyscan_t;

	int yylex(yyscan_t scanner);
	int yyerror(yyscan_t scanner, const char *msg);

    #if LL_LINUX
    // broken yacc codegen...  --ryan.
    #define getenv getenv_workaround
    #endif

    #ifdef LL_WINDOWS
	#pragma warning (disable : 4702) // warning C4702: unreachable code
	#pragma warning( disable : 4065 )	// warning: switch statement contains 'default' but no 'case' labels
	#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "indra.y"
{
	S32								ival;
	F32								fval;
	char							*sval;
	class LLScriptType				*type;
	class LLScriptConstant			*constant;
	class LLScriptIdentifier		*identifier;
	class LLScriptSimpleAssignable	*assignable;
	class LLScriptGlobalVariable	*global;
	class LLScriptEvent				*event;
	class LLScriptEventHandler		*handler;
	class LLScriptExpression		*expression;
	class LLScriptStatement			*statement;
	class LLScriptGlobalFunctions	*global_funcs;
	class LLScriptFunctionDec		*global_decl;
	class LLScriptState				*state;
	class LLScritpGlobalStorage		*global_store;
	class LLScriptScript			*script;
}
/* Line 193 of yacc.c.  */
#line 317 "indra.y.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 330 "indra.y.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  223
/* YYNRULES -- Number of states.  */
#define YYNSTATES  622

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,     2,     2,    97,    98,     2,
     101,   102,    95,    94,   104,    88,     2,    96,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    86,
      92,    91,    93,     2,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   105,     2,   106,   100,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   107,    99,   108,    90,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   103
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    15,    17,    20,
      23,    28,    30,    32,    34,    36,    38,    40,    42,    44,
      46,    49,    51,    53,    55,    58,    60,    62,    70,    72,
      74,    76,    86,    88,    92,    95,    97,   101,   103,   105,
     107,   109,   111,   113,   115,   117,   122,   127,   133,   139,
     141,   145,   148,   150,   153,   155,   158,   163,   169,   171,
     174,   177,   180,   183,   186,   189,   192,   195,   198,   201,
     204,   207,   210,   213,   216,   219,   222,   225,   228,   231,
     234,   237,   240,   243,   246,   249,   252,   255,   258,   261,
     264,   267,   270,   273,   276,   279,   282,   285,   288,   292,
     296,   302,   308,   314,   320,   326,   332,   338,   344,   350,
     362,   366,   378,   382,   391,   409,   415,   421,   427,   436,
     440,   444,   448,   463,   469,   473,   485,   491,   497,   512,
     533,   548,   560,   572,   581,   587,   596,   599,   603,   605,
     608,   610,   614,   618,   622,   626,   630,   633,   636,   639,
     641,   647,   655,   665,   673,   679,   682,   687,   688,   690,
     692,   696,   697,   699,   701,   705,   706,   708,   710,   714,
     716,   720,   724,   728,   732,   736,   740,   744,   748,   752,
     756,   760,   764,   768,   772,   776,   780,   784,   788,   792,
     796,   800,   804,   808,   812,   815,   818,   821,   824,   827,
     829,   831,   835,   840,   845,   850,   857,   859,   861,   863,
     865,   868,   871,   876,   881,   883,   891,   893,   895,   897,
     907,   909,   913,   915
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     110,     0,    -1,   111,   130,    -1,   130,    -1,   112,    -1,
     112,   111,    -1,   114,    -1,   127,    -1,   126,    52,    -1,
     113,    86,    -1,   113,    91,   115,    86,    -1,   116,    -1,
     123,    -1,    52,    -1,   117,    -1,   120,    -1,   119,    -1,
     118,    -1,    58,    -1,    57,    -1,    88,    57,    -1,    54,
      -1,    55,    -1,    56,    -1,    88,    54,    -1,   121,    -1,
     122,    -1,    92,   115,   104,   115,   104,   115,    93,    -1,
      81,    -1,    83,    -1,    84,    -1,    92,   115,   104,   115,
     104,   115,   104,   115,    93,    -1,    82,    -1,   105,   124,
     106,    -1,   105,   106,    -1,   125,    -1,   125,   104,   124,
      -1,   116,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1,    52,   101,   102,
     174,    -1,   113,   101,   102,   174,    -1,    52,   101,   128,
     102,   174,    -1,   113,   101,   128,   102,   174,    -1,   129,
      -1,   129,   104,   128,    -1,   126,    52,    -1,   132,    -1,
     132,   131,    -1,   133,    -1,   133,   131,    -1,    53,   107,
     134,   108,    -1,    10,    52,   107,   134,   108,    -1,   135,
      -1,   135,   134,    -1,   136,   174,    -1,   137,   174,    -1,
     138,   174,    -1,   139,   174,    -1,   140,   174,    -1,   141,
     174,    -1,   142,   174,    -1,   143,   174,    -1,   144,   174,
      -1,   145,   174,    -1,   146,   174,    -1,   159,   174,    -1,
     160,   174,    -1,   161,   174,    -1,   162,   174,    -1,   147,
     174,    -1,   148,   174,    -1,   149,   174,    -1,   150,   174,
      -1,   151,   174,    -1,   152,   174,    -1,   153,   174,    -1,
     154,   174,    -1,   155,   174,    -1,   156,   174,    -1,   163,
     174,    -1,   157,   174,    -1,   158,   174,    -1,   164,   174,
      -1,   165,   174,    -1,   166,   174,    -1,   167,   174,    -1,
     168,   174,    -1,   169,   174,    -1,   170,   174,    -1,   171,
     174,    -1,   172,   174,    -1,   173,   174,    -1,    14,   101,
     102,    -1,    15,   101,   102,    -1,    16,   101,     3,    52,
     102,    -1,    17,   101,     3,    52,   102,    -1,    18,   101,
       3,    52,   102,    -1,    19,   101,     3,    52,   102,    -1,
      20,   101,     3,    52,   102,    -1,    21,   101,     3,    52,
     102,    -1,    22,   101,     7,    52,   102,    -1,    23,   101,
       7,    52,   102,    -1,    24,   101,     7,    52,   102,    -1,
      30,   101,     3,    52,   104,     7,    52,   104,     7,    52,
     102,    -1,    31,   101,   102,    -1,    32,   101,     3,    52,
     104,     8,    52,   104,     8,    52,   102,    -1,    33,   101,
     102,    -1,    34,   101,     6,    52,   104,     3,    52,   102,
      -1,    35,   101,     5,    52,   104,     5,    52,   104,     5,
      52,   104,     5,    52,   104,     3,    52,   102,    -1,    36,
     101,     3,    52,   102,    -1,    37,   101,     3,    52,   102,
      -1,    38,   101,     6,    52,   102,    -1,    39,   101,     6,
      52,   104,     5,    52,   102,    -1,    40,   101,   102,    -1,
      41,   101,   102,    -1,    25,   101,   102,    -1,    26,   101,
       3,    52,   104,     5,    52,   104,     6,    52,   104,     5,
      52,   102,    -1,    27,   101,     3,    52,   102,    -1,    28,
     101,   102,    -1,    29,   101,     6,    52,   104,     3,    52,
     104,     3,    52,   102,    -1,    42,   101,     3,    52,   102,
      -1,    43,   101,     6,    52,   102,    -1,    44,   101,     3,
      52,   104,     3,    52,   104,     5,    52,   104,     6,    52,
     102,    -1,    45,   101,     3,    52,   104,     6,    52,   104,
       6,    52,   104,     5,    52,   104,     3,    52,   104,     5,
      52,   102,    -1,    46,   101,     6,    52,   104,     3,    52,
     104,     9,    52,   104,     5,    52,   102,    -1,    47,   101,
       6,    52,   104,     5,    52,   104,     5,    52,   102,    -1,
      48,   101,     6,    52,   104,     3,    52,   104,     5,    52,
     102,    -1,    49,   101,     3,    52,   104,     9,    52,   102,
      -1,    50,   101,     6,    52,   102,    -1,    51,   101,     6,
      52,   104,     3,    52,   102,    -1,   107,   108,    -1,   107,
     175,   108,    -1,   176,    -1,   175,   176,    -1,    86,    -1,
      10,    52,    86,    -1,    10,    53,    86,    -1,    12,    52,
      86,    -1,    87,    52,    86,    -1,    13,   184,    86,    -1,
      13,    86,    -1,   184,    86,    -1,   177,    86,    -1,   174,
      -1,    74,   101,   184,   102,   176,    -1,    74,   101,   184,
     102,   176,    75,   176,    -1,    76,   101,   178,    86,   184,
      86,   178,   102,   176,    -1,    77,   176,    78,   101,   184,
     102,    86,    -1,    78,   101,   184,   102,   176,    -1,   126,
      52,    -1,   126,    52,    91,   184,    -1,    -1,   179,    -1,
     184,    -1,   184,   104,   179,    -1,    -1,   181,    -1,   184,
      -1,   184,   104,   181,    -1,    -1,   183,    -1,   184,    -1,
     184,   104,   183,    -1,   185,    -1,   191,    91,   184,    -1,
     191,    61,   184,    -1,   191,    62,   184,    -1,   191,    63,
     184,    -1,   191,    64,   184,    -1,   191,    65,   184,    -1,
     184,    66,   184,    -1,   184,    67,   184,    -1,   184,    69,
     184,    -1,   184,    68,   184,    -1,   184,    92,   184,    -1,
     184,    93,   184,    -1,   184,    94,   184,    -1,   184,    88,
     184,    -1,   184,    95,   184,    -1,   184,    96,   184,    -1,
     184,    97,   184,    -1,   184,    98,   184,    -1,   184,    99,
     184,    -1,   184,   100,   184,    -1,   184,    70,   184,    -1,
     184,    71,   184,    -1,   184,    72,   184,    -1,   184,    73,
     184,    -1,    88,   184,    -1,    89,   184,    -1,    90,   184,
      -1,    59,   191,    -1,    60,   191,    -1,   186,    -1,   187,
      -1,   101,   184,   102,    -1,   101,   126,   102,   191,    -1,
     101,   126,   102,   117,    -1,   101,   126,   102,   187,    -1,
     101,   126,   102,   101,   184,   102,    -1,   188,    -1,   189,
      -1,   190,    -1,   191,    -1,   191,    59,    -1,   191,    60,
      -1,    52,   101,   180,   102,    -1,    79,   101,   184,   102,
      -1,   117,    -1,    92,   184,   104,   184,   104,   184,    93,
      -1,    81,    -1,    83,    -1,    84,    -1,    92,   184,   104,
     184,   104,   184,   104,   184,    93,    -1,    82,    -1,   105,
     182,   106,    -1,    52,    -1,    52,    80,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   287,   287,   293,   302,   306,   314,   319,   327,   335,
     340,   348,   352,   359,   366,   371,   378,   383,   388,   396,
     400,   407,   411,   415,   419,   426,   430,   437,   442,   459,
     476,   496,   501,   525,   530,   538,   542,   550,   557,   562,
     567,   572,   577,   582,   587,   595,   602,   607,   614,   622,
     626,   634,   644,   648,   656,   660,   668,   678,   688,   692,
     700,   705,   710,   715,   720,   725,   730,   735,   740,   745,
     750,   755,   760,   765,   770,   775,   780,   785,   790,   795,
     800,   805,   810,   815,   820,   825,   830,   835,   840,   845,
     850,   855,   860,   865,   870,   875,   880,   885,   893,   901,
     909,   919,   929,   939,   949,   959,   969,   979,   989,   999,
    1013,  1021,  1035,  1043,  1055,  1073,  1083,  1093,  1103,  1115,
    1123,  1131,  1139,  1155,  1165,  1173,  1187,  1197,  1207,  1223,
    1243,  1259,  1273,  1287,  1299,  1309,  1321,  1326,  1334,  1338,
    1346,  1351,  1358,  1365,  1372,  1379,  1384,  1389,  1394,  1398,
    1402,  1408,  1415,  1421,  1427,  1436,  1443,  1454,  1457,  1464,
    1469,  1478,  1481,  1488,  1493,  1502,  1505,  1512,  1517,  1525,
    1529,  1534,  1539,  1544,  1549,  1554,  1559,  1564,  1569,  1574,
    1579,  1584,  1589,  1594,  1599,  1604,  1609,  1614,  1619,  1624,
    1629,  1634,  1639,  1644,  1652,  1657,  1662,  1667,  1672,  1677,
    1681,  1685,  1693,  1698,  1705,  1710,  1718,  1722,  1726,  1730,
    1734,  1739,  1744,  1751,  1756,  1764,  1769,  1786,  1803,  1823,
    1828,  1852,  1860,  1867
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT_TYPE", "STRING",
  "LLKEY", "VECTOR", "QUATERNION", "LIST", "STATE", "EVENT", "JUMP",
  "RETURN", "STATE_ENTRY", "STATE_EXIT", "TOUCH_START", "TOUCH",
  "TOUCH_END", "COLLISION_START", "COLLISION", "COLLISION_END",
  "LAND_COLLISION_START", "LAND_COLLISION", "LAND_COLLISION_END", "TIMER",
  "CHAT", "SENSOR", "NO_SENSOR", "CONTROL", "AT_TARGET", "NOT_AT_TARGET",
  "AT_ROT_TARGET", "NOT_AT_ROT_TARGET", "MONEY", "EMAIL",
  "RUN_TIME_PERMISSIONS", "INVENTORY", "ATTACH", "DATASERVER",
  "MOVING_START", "MOVING_END", "REZ", "OBJECT_REZ", "LINK_MESSAGE",
  "REMOTE_DATA", "HTTP_RESPONSE", "HTTP_REQUEST", "TRANSACTION_RESULT",
  "PATH_UPDATE", "EXPERIENCE_PERMISSIONS", "EXPERIENCE_PERMISSIONS_DENIED",
  "IDENTIFIER", "STATE_DEFAULT", "INTEGER_CONSTANT", "INTEGER_TRUE",
  "INTEGER_FALSE", "FP_CONSTANT", "STRING_CONSTANT", "INC_OP", "DEC_OP",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "EQ", "NEQ", "GEQ", "LEQ", "BOOLEAN_AND", "BOOLEAN_OR", "SHIFT_LEFT",
  "SHIFT_RIGHT", "IF", "ELSE", "FOR", "DO", "WHILE", "PRINT", "PERIOD",
  "ZERO_VECTOR", "ZERO_ROTATION", "TOUCH_INVALID_VECTOR",
  "TOUCH_INVALID_TEXCOORD", "LOWER_THAN_ELSE", "';'", "'@'", "'-'", "'!'",
  "'~'", "'='", "'<'", "'>'", "'+'", "'*'", "'/'", "'%'", "'&'", "'|'",
  "'^'", "'('", "')'", "INITIALIZER", "','", "'['", "']'", "'{'", "'}'",
  "$accept", "lscript_program", "globals", "global", "name_type",
  "global_variable", "simple_assignable", "simple_assignable_no_list",
  "constant", "fp_constant", "integer_constant", "special_constant",
  "vector_constant", "quaternion_constant", "list_constant",
  "list_entries", "list_entry", "typename", "global_function",
  "function_parameters", "function_parameter", "states", "other_states",
  "default", "state", "state_body", "event", "state_entry", "state_exit",
  "touch_start", "touch", "touch_end", "collision_start", "collision",
  "collision_end", "land_collision_start", "land_collision",
  "land_collision_end", "at_target", "not_at_target", "at_rot_target",
  "not_at_rot_target", "money", "email", "run_time_permissions",
  "inventory", "attach", "dataserver", "moving_start", "moving_end",
  "timer", "chat", "sensor", "no_sensor", "control", "rez", "object_rez",
  "link_message", "remote_data", "http_response", "http_request",
  "transaction_result", "path_update", "experience_permissions",
  "experience_permissions_denied", "compound_statement", "statements",
  "statement", "declaration", "forexpressionlist", "nextforexpressionlist",
  "funcexpressionlist", "nextfuncexpressionlist", "listexpressionlist",
  "nextlistexpressionlist", "expression", "unaryexpression", "typecast",
  "unarypostfixexpression", "vector_initializer", "quaternion_initializer",
  "list_initializer", "lvalue", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,    59,    64,    45,    33,
     126,    61,    60,    62,    43,    42,    47,    37,    38,   124,
      94,    40,    41,   341,    44,    91,    93,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   110,   111,   111,   112,   112,   113,   114,
     114,   115,   115,   116,   116,   116,   117,   117,   117,   118,
     118,   119,   119,   119,   119,   120,   120,   121,   121,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   127,   127,   128,
     128,   129,   130,   130,   131,   131,   132,   133,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   174,   175,   175,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   177,   178,   178,   179,
     179,   180,   180,   181,   181,   182,   182,   183,   183,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   185,   185,   185,   185,   185,   185,
     185,   185,   186,   186,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   188,   188,   188,   188,   189,
     189,   190,   191,   191
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     1,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     1,     7,     1,     1,
       1,     9,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     5,     1,
       3,     2,     1,     2,     1,     2,     4,     5,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       5,     5,     5,     5,     5,     5,     5,     5,     5,    11,
       3,    11,     3,     8,    17,     5,     5,     5,     8,     3,
       3,     3,    14,     5,     3,    11,     5,     5,    14,    20,
      14,    11,    11,     8,     5,     8,     2,     3,     1,     2,
       1,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       5,     7,     9,     7,     5,     2,     4,     0,     1,     1,
       3,     0,     1,     1,     3,     0,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     1,
       1,     3,     4,     4,     4,     6,     1,     1,     1,     1,
       2,     2,     4,     4,     1,     7,     1,     1,     1,     9,
       1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     4,     0,     6,     0,     7,     3,    52,     0,
       0,     1,     2,     5,     9,     0,     0,     8,     0,    53,
      54,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    21,    22,    23,    19,    18,    28,
      32,    29,    30,     0,     0,     0,     0,    11,    14,    17,
      16,    15,    25,    26,    12,     0,     0,     0,    55,     0,
      45,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    86,    87,    71,    72,    73,
      74,    85,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    24,    20,     0,    34,    37,     0,    35,    10,
      46,     0,     0,     0,     0,     0,   222,     0,     0,     0,
       0,     0,     0,     0,   216,   220,   217,   218,   140,     0,
       0,     0,     0,     0,     0,   165,   136,   214,     0,   149,
       0,   138,     0,     0,   169,   199,   200,   206,   207,   208,
     209,    47,    50,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,   124,     0,     0,
     110,     0,   112,     0,     0,     0,     0,     0,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,    48,     0,     0,     0,     0,   146,
       0,     0,   161,   222,   197,   198,     0,   157,     0,     0,
       0,     0,    21,    19,   194,   195,   196,     0,     0,     0,
       0,   166,   167,   155,   137,   139,   148,     0,     0,     0,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    57,   141,   142,   143,
     145,   223,     0,   162,   163,     0,     0,   158,   159,     0,
       0,     0,   144,     0,     0,   201,   221,     0,     0,   176,
     177,   179,   178,   190,   191,   192,   193,   183,   180,   181,
     182,   184,   185,   186,   187,   188,   189,   171,   172,   173,
     174,   175,   170,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,   123,     0,     0,     0,     0,     0,   115,
     116,   117,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   134,     0,     0,   212,     0,     0,     0,     0,     0,
       0,   213,     0,     0,   203,   204,   202,   168,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   150,     0,   160,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,   157,
       0,     0,   205,     0,     0,     0,     0,   113,     0,   118,
       0,     0,     0,     0,     0,   133,   135,     0,   151,     0,
     153,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   219,     0,   125,
     109,   111,     0,     0,     0,     0,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     128,     0,   130,     0,     0,     0,     0,   114,     0,     0,
       0,   129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,   126,   127,   257,   129,
     130,   131,   132,   133,   134,   227,   228,   258,    16,    33,
      34,    17,    29,    18,    30,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   259,   260,   261,   262,   416,
     417,   412,   413,   340,   341,   263,   264,   265,   266,   267,
     268,   269,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -238
static const yytype_int16 yypact[] =
{
      98,  -238,  -238,  -238,  -238,  -238,  -238,  -238,   -92,   -94,
      37,    10,    70,   -76,  -238,    13,  -238,  -238,    54,    39,
     941,  -238,  -238,  -238,  -238,   267,    46,  -238,    15,  -238,
      54,   -38,    16,   -31,   -32,   -21,   -20,   -18,   -16,   -15,
     -14,   -13,   -11,    -9,    -6,    -3,     7,     8,     9,    11,
      33,    41,    42,    45,    48,    51,    53,    60,    73,    74,
      75,    78,    79,    80,    88,    92,    95,   134,   135,   136,
     137,   139,   145,   -17,   941,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,   -43,   267,   -22,    -4,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,   -38,   146,     4,  -238,   287,
    -238,  -238,   -38,   421,   148,   149,   110,   144,   174,   244,
     255,   256,   254,   258,   260,   160,   269,   270,   161,   268,
     273,   175,   282,   196,   283,   297,   300,   301,   305,   306,
     211,   213,   313,   311,   317,   323,   324,   326,   327,   331,
     329,   330,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,   234,  -238,  -238,   246,   236,  -238,
    -238,   -38,   941,   -26,   304,   565,   -72,   310,   310,   257,
     266,   487,   277,   286,  -238,  -238,  -238,  -238,  -238,   337,
     604,   643,   643,   643,   526,   643,  -238,  -238,   338,  -238,
     397,  -238,   271,  1077,  -238,  -238,  -238,  -238,  -238,  -238,
     321,  -238,  -238,  -238,  -238,   339,   341,   344,   345,   346,
     356,   359,   361,   363,  -238,   368,   369,  -238,   379,   380,
    -238,   381,  -238,   382,   383,   384,   385,   387,   388,  -238,
    -238,   389,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   267,  -238,   187,  -238,   360,   386,   391,   396,  -238,
    1112,   417,   643,   390,  -238,  -238,   643,   643,   423,   643,
     643,   402,  -238,  -238,   -39,  -238,  -238,   707,   401,   927,
     400,  -238,   746,   416,  -238,  -238,  -238,   643,   643,   643,
     643,   643,   643,   643,   643,  -238,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   643,  -238,  -238,   643,   643,
     643,   643,   643,   643,   406,   418,   419,   420,   422,   424,
     425,   426,   434,   405,   435,   436,   444,   445,   446,   447,
     450,   451,   452,   453,   454,   456,   455,   458,   463,   468,
     483,   485,   488,   489,   491,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,   494,  -238,   759,   940,   427,  -238,   798,   437,
     977,   990,  -238,   643,   226,  -238,  -238,   643,   643,  1274,
    1274,    72,    72,  1230,  1230,    76,    76,   -39,    72,    72,
     -39,  -238,  -238,  -238,    90,   350,  1243,  1182,  1182,  1182,
    1182,  1182,  1182,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,   505,  -238,   508,   507,   509,   512,   511,  -238,
    -238,  -238,   513,  -238,  -238,   516,   517,   522,   550,   557,
     582,  -238,   594,   267,  -238,   643,   487,   643,   643,   643,
     487,  -238,   811,   643,  -238,  -238,   -19,  -238,  1182,   546,
     547,   548,   549,   551,   552,   554,   559,   560,   561,   574,
     576,   577,   578,   -65,  -238,   527,  1147,  -238,  1027,  -238,
     643,  1040,   528,   529,   530,   531,   534,   533,   536,   535,
     537,   538,   539,   541,   563,   566,  -238,   267,   487,   643,
     564,   850,  -238,   634,   649,   660,   661,  -238,   666,  -238,
     667,   668,   664,   670,   671,  -238,  -238,   584,  -238,   579,
    -238,   682,   643,   626,   627,   628,   630,   632,   637,   638,
     639,   652,   654,  -238,   487,  1195,   603,   606,   608,   609,
     610,   611,   612,   613,   616,   617,  -238,   682,   708,  -238,
    -238,  -238,   715,   706,   716,   718,  -238,  -238,   676,   677,
     678,   691,   693,   644,   645,   648,   647,   650,  -238,   744,
    -238,   750,  -238,   702,   703,   655,   656,  -238,   751,   710,
     657,  -238
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -238,  -238,   755,  -238,  -238,  -238,  -123,  -122,   -25,  -238,
    -238,  -238,  -238,  -238,  -238,   457,  -238,    12,  -238,   -10,
    -238,   747,   738,  -238,  -238,   -67,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,   122,  -238,  -237,  -238,   230,
     293,  -238,   299,  -238,   355,  -233,  -238,  -238,   362,  -238,
    -238,  -238,  -232
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     128,   224,   320,   226,   328,   324,   325,   183,   321,    19,
      24,   222,    15,    20,   223,    25,   136,   334,   335,   336,
     337,   339,   342,   345,    15,    26,   316,   317,   536,   322,
     113,    32,   114,   115,   116,   117,   118,    21,    32,   537,
     366,   367,     1,     2,     3,     4,     5,     6,     7,     1,
       2,     3,     4,     5,     6,     7,   360,   361,   362,   119,
     120,   121,   122,     9,    28,    27,   123,   137,   141,   139,
     124,   142,   143,     1,     2,     3,     4,     5,     6,     7,
     144,   145,   229,   146,   225,   147,   148,   149,   150,   414,
     151,   182,   152,   415,   418,   153,   420,   421,   154,   128,
     128,     1,     2,     3,     4,     5,     6,     7,   155,   156,
     157,   232,   158,   275,   429,   430,   431,   432,   433,   434,
     435,   436,     8,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   272,   159,   447,   448,   449,   450,   451,
     452,    31,   160,   161,   353,   354,   162,   276,   135,   163,
       8,     9,   164,   140,   165,    32,   347,   348,   349,   350,
     356,   166,   353,   354,   356,   315,   359,   360,   361,   362,
     359,   360,   361,   362,   167,   168,   169,   277,   356,   170,
     171,   172,   357,   358,   359,   360,   361,   362,   404,   173,
     492,   226,   496,   174,   342,   498,   175,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   176,   177,   178,   179,   113,
     180,   114,   115,   116,   117,   118,   181,   278,   231,   515,
     273,   274,   414,   519,   516,   418,   518,   230,   279,   280,
     521,   281,   284,   287,   271,   282,   338,   283,   119,   120,
     121,   122,   285,   286,   288,   123,   289,   290,   236,   124,
     114,   115,   116,   117,   118,   291,   128,   541,   128,   293,
       1,     2,     3,     4,     5,     6,     7,   233,   292,   234,
     235,   558,   294,   295,   296,   243,   418,   244,   245,   246,
     247,   297,   298,   299,   123,   300,   301,   302,   253,   113,
     303,   114,   115,   116,   117,   118,   304,   493,   439,   575,
     305,   255,   306,   307,   308,   309,   310,   586,   311,   236,
     313,   114,   115,   116,   117,   118,   237,   238,   119,   120,
     121,   122,   312,   314,   439,   123,   318,   346,   326,   124,
     513,   239,   323,   240,   241,   242,   243,   327,   244,   245,
     246,   247,   125,   248,   249,   250,   251,   252,   329,   253,
     366,   367,   368,   369,   370,   371,   372,   330,   254,   331,
     343,   374,   255,   375,   139,   256,   376,   377,   378,   494,
       1,     2,     3,     4,     5,     6,     7,   233,   379,   234,
     235,   380,   373,   381,   557,   382,   347,   348,   349,   350,
     383,   384,   353,   354,     1,     2,     3,     4,     5,     6,
       7,   385,   386,   387,   388,   389,   390,   391,   356,   392,
     393,   394,   357,   358,   359,   360,   361,   362,   363,   236,
     365,   114,   115,   116,   117,   118,   237,   238,   128,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   406,   411,
     321,   239,   407,   240,   241,   242,   243,   408,   244,   245,
     246,   247,   409,   248,   249,   250,   251,   252,   422,   253,
       1,     2,     3,     4,     5,     6,     7,   233,   254,   234,
     235,   419,   255,   424,   139,   344,   426,   428,   453,   462,
     499,   500,   128,   487,   501,   503,   504,   502,   505,   506,
     454,   455,   456,   507,   457,   508,   458,   459,   460,     1,
       2,     3,     4,     5,     6,     7,   461,   463,   489,   236,
     464,   114,   115,   116,   117,   118,   237,   238,   465,   466,
     467,   468,   469,   470,   471,   509,   473,   472,   474,   475,
     510,   239,   476,   240,   241,   242,   243,   477,   244,   245,
     246,   247,   478,   248,   249,   250,   251,   252,   236,   253,
     114,   115,   116,   117,   118,   237,   238,   479,   254,   480,
     481,   511,   255,   482,   139,   483,   484,   512,   522,   523,
     524,   525,   538,   526,   527,   243,   528,   244,   245,   246,
     247,   529,   530,   531,   250,   251,   252,   236,   253,   114,
     115,   116,   117,   118,   237,   238,   532,   254,   533,   534,
     535,   255,   543,   544,   545,   546,   547,   548,   549,   550,
     563,   551,   552,   553,   243,   554,   244,   245,   246,   247,
     560,   319,   564,   250,   251,   252,   236,   253,   332,   115,
     116,   333,   118,   237,   238,   555,   254,   565,   556,   566,
     255,   567,   568,   570,   569,   571,   572,   573,   576,   577,
     578,   574,   579,   243,   580,   244,   245,   246,   247,   581,
     582,   583,   250,   251,   252,   236,   253,   114,   115,   116,
     117,   118,   237,   238,   584,   254,   585,   588,   589,   255,
     590,   591,   600,   598,   592,   593,   594,   595,   596,   597,
     599,   601,   243,   602,   244,   245,   246,   247,   603,   604,
     605,   250,   251,   252,   236,   253,   114,   115,   116,   117,
     118,   237,   238,   606,   254,   607,   608,   613,   255,   609,
     610,   611,   612,   614,   615,   616,   619,   617,    22,   621,
     618,   243,   620,   244,   245,   246,   247,    23,   138,   559,
     405,   251,   252,   347,   348,   349,   350,   351,   352,   353,
     354,   517,   497,   254,   514,     0,   495,   255,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,     0,     0,
       0,   423,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,     0,   347,   348,   349,   350,   351,
     352,   353,   354,     0,   356,     0,     0,     0,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   356,     0,     0,
     427,   357,   358,   359,   360,   361,   362,   363,   364,   365,
       0,     0,     0,   485,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,     0,   347,   348,   349,
     350,   351,   352,   353,   354,     0,   356,     0,     0,     0,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   356,
       0,     0,   488,   357,   358,   359,   360,   361,   362,   363,
     364,   365,     0,     0,     0,   520,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,     0,
       0,     0,   357,   561,   359,   360,   361,   362,   363,   364,
     365,     0,     0,     0,   562,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,     0,   347,   348,   349,   350,
     351,   352,   353,   354,     0,   356,     0,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   356,   425,
       0,     0,   357,   358,   359,   360,   361,   362,   363,   364,
     365,     0,   486,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,     0,   347,   348,   349,   350,
     351,   352,   353,   354,     0,   356,     0,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   356,   490,
       0,     0,   357,   358,   359,   360,   361,   362,   363,   364,
     365,     0,   491,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,     0,   347,   348,   349,   350,
     351,   352,   353,   354,     0,   356,     0,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   356,   540,
       0,     0,   357,   358,   359,   360,   361,   362,   363,   364,
     365,     0,   542,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   355,     0,   356,     0,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,     0,
     356,     0,     0,     0,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   539,     0,   356,     0,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
       0,   347,   348,   349,   350,   351,   352,   353,   354,     0,
     356,     0,     0,     0,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   356,     0,     0,     0,   357,   587,   359,
     360,   361,   362,   363,   364,   365,   347,   348,   349,   350,
       0,     0,   353,   354,     0,     0,     0,     0,     0,   347,
     348,   349,   350,     0,     0,   353,   354,     0,   356,     0,
       0,     0,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   356,     0,     0,     0,   357,   358,   359,   360,   361,
     362,   363,   349,   350,     0,     0,   353,   354,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,     0,     0,     0,   357,   358,   359,   360,
     361,   362
};

static const yytype_int16 yycheck[] =
{
      25,   124,   235,   125,   241,   237,   238,    74,    80,   101,
      86,    54,     0,   107,    57,    91,    26,   250,   251,   252,
     253,   254,   255,   260,    12,   101,    52,    53,    93,   101,
      52,    19,    54,    55,    56,    57,    58,     0,    26,   104,
      59,    60,     3,     4,     5,     6,     7,     8,     9,     3,
       4,     5,     6,     7,     8,     9,    95,    96,    97,    81,
      82,    83,    84,    53,    10,    52,    88,    52,    52,   107,
      92,   102,   104,     3,     4,     5,     6,     7,     8,     9,
     101,   101,    86,   101,   106,   101,   101,   101,   101,   322,
     101,   108,   101,   326,   327,   101,   329,   330,   101,   124,
     125,     3,     4,     5,     6,     7,     8,     9,   101,   101,
     101,   107,   101,     3,   347,   348,   349,   350,   351,   352,
     353,   354,    52,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   143,   101,   368,   369,   370,   371,   372,
     373,   102,   101,   101,    72,    73,   101,     3,   102,   101,
      52,    53,   101,    31,   101,   143,    66,    67,    68,    69,
      88,   101,    72,    73,    88,   232,    94,    95,    96,    97,
      94,    95,    96,    97,   101,   101,   101,     3,    88,   101,
     101,   101,    92,    93,    94,    95,    96,    97,   311,   101,
     423,   313,   424,   101,   427,   428,   101,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   101,   101,   101,   101,    52,
     101,    54,    55,    56,    57,    58,   101,     3,   102,   486,
     102,   102,   485,   490,   487,   488,   489,   135,     3,     3,
     493,     7,   102,   102,   142,     7,   254,     7,    81,    82,
      83,    84,     3,     3,     6,    88,     3,   102,    52,    92,
      54,    55,    56,    57,    58,     3,   311,   520,   313,     6,
       3,     4,     5,     6,     7,     8,     9,    10,   102,    12,
      13,   538,     5,     3,     3,    79,   539,    81,    82,    83,
      84,     6,     6,   102,    88,   102,     3,     6,    92,    52,
       3,    54,    55,    56,    57,    58,     3,   101,   561,   562,
       6,   105,     6,     6,     3,     6,     6,   574,   104,    52,
     104,    54,    55,    56,    57,    58,    59,    60,    81,    82,
      83,    84,   106,   231,   587,    88,    52,    86,   101,    92,
     483,    74,    52,    76,    77,    78,    79,   101,    81,    82,
      83,    84,   105,    86,    87,    88,    89,    90,   101,    92,
      59,    60,    61,    62,    63,    64,    65,   101,   101,    52,
      52,    52,   105,    52,   107,   108,    52,    52,    52,   424,
       3,     4,     5,     6,     7,     8,     9,    10,    52,    12,
      13,    52,    91,    52,   537,    52,    66,    67,    68,    69,
      52,    52,    72,    73,     3,     4,     5,     6,     7,     8,
       9,    52,    52,    52,    52,    52,    52,    52,    88,    52,
      52,    52,    92,    93,    94,    95,    96,    97,    98,    52,
     100,    54,    55,    56,    57,    58,    59,    60,   483,    52,
      52,    52,    52,    52,    52,    52,    52,    52,   108,    52,
      80,    74,    86,    76,    77,    78,    79,    86,    81,    82,
      83,    84,    86,    86,    87,    88,    89,    90,    86,    92,
       3,     4,     5,     6,     7,     8,     9,    10,   101,    12,
      13,    78,   105,   102,   107,   108,   106,    91,   102,   104,
       5,     3,   537,    86,     7,     3,     5,     8,     5,     3,
     102,   102,   102,     6,   102,     3,   102,   102,   102,     3,
       4,     5,     6,     7,     8,     9,   102,   102,   101,    52,
     104,    54,    55,    56,    57,    58,    59,    60,   104,   104,
     104,   104,   102,   102,   102,     5,   102,   104,   102,   104,
       3,    74,   104,    76,    77,    78,    79,   104,    81,    82,
      83,    84,   104,    86,    87,    88,    89,    90,    52,    92,
      54,    55,    56,    57,    58,    59,    60,   104,   101,   104,
     102,     9,   105,   104,   107,   104,   102,     3,    52,    52,
      52,    52,    75,    52,    52,    79,    52,    81,    82,    83,
      84,    52,    52,    52,    88,    89,    90,    52,    92,    54,
      55,    56,    57,    58,    59,    60,    52,   101,    52,    52,
      52,   105,   104,   104,   104,   104,   102,   104,   102,   104,
       6,   104,   104,   104,    79,   104,    81,    82,    83,    84,
      86,    86,     3,    88,    89,    90,    52,    92,    54,    55,
      56,    57,    58,    59,    60,   102,   101,     7,   102,     8,
     105,     5,     5,     9,     6,     5,     5,    93,    52,    52,
      52,   102,    52,    79,    52,    81,    82,    83,    84,    52,
      52,    52,    88,    89,    90,    52,    92,    54,    55,    56,
      57,    58,    59,    60,    52,   101,    52,   104,   102,   105,
     102,   102,     6,     5,   104,   104,   104,   104,   102,   102,
       5,     5,    79,     5,    81,    82,    83,    84,    52,    52,
      52,    88,    89,    90,    52,    92,    54,    55,    56,    57,
      58,    59,    60,    52,   101,    52,   102,     3,   105,   104,
     102,   104,   102,     3,    52,    52,     5,   102,    11,   102,
     104,    79,    52,    81,    82,    83,    84,    12,    30,   539,
     313,    89,    90,    66,    67,    68,    69,    70,    71,    72,
      73,   488,   427,   101,   485,    -1,   424,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   104,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    88,    -1,    -1,
     104,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,   104,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    88,
      -1,    -1,   104,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,   104,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,   102,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,   102,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,   102,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    66,    67,    68,    69,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    73,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    68,    69,    -1,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    52,    53,
     110,   111,   112,   113,   114,   126,   127,   130,   132,   101,
     107,     0,   130,   111,    86,    91,   101,    52,    10,   131,
     133,   102,   126,   128,   129,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    52,    54,    55,    56,    57,    58,    81,
      82,    83,    84,    88,    92,   105,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   102,   128,    52,   131,   107,
     174,    52,   102,   104,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   108,   134,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,    54,    57,   115,   106,   116,   124,   125,    86,
     174,   102,   107,    10,    12,    13,    52,    59,    60,    74,
      76,    77,    78,    79,    81,    82,    83,    84,    86,    87,
      88,    89,    90,    92,   101,   105,   108,   117,   126,   174,
     175,   176,   177,   184,   185,   186,   187,   188,   189,   190,
     191,   174,   128,   102,   102,     3,     3,     3,     3,     3,
       3,     7,     7,     7,   102,     3,     3,   102,     6,     3,
     102,     3,   102,     6,     5,     3,     3,     6,     6,   102,
     102,     3,     6,     3,     3,     6,     6,     6,     3,     6,
       6,   104,   106,   104,   174,   134,    52,    53,    52,    86,
     184,    80,   101,    52,   191,   191,   101,   101,   176,   101,
     101,    52,    54,    57,   184,   184,   184,   184,   126,   184,
     182,   183,   184,    52,   108,   176,    86,    66,    67,    68,
      69,    70,    71,    72,    73,    86,    88,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    59,    60,    61,    62,
      63,    64,    65,    91,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,   115,   124,   108,    86,    86,    86,
      86,    52,   180,   181,   184,   184,   178,   179,   184,    78,
     184,   184,    86,   104,   102,   102,   106,   104,    91,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   104,   102,   104,   104,   104,   104,   104,   102,
     102,   102,   104,   102,   102,   104,   104,   104,   104,   104,
     104,   102,   104,   104,   102,   104,   102,    86,   104,   101,
     102,   102,   184,   101,   117,   187,   191,   183,   184,     5,
       3,     7,     8,     3,     5,     5,     3,     6,     3,     5,
       3,     9,     3,   115,   181,   176,   184,   179,   184,   176,
     104,   184,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    93,   104,    75,    86,
     102,   184,   102,   104,   104,   104,   104,   102,   104,   102,
     104,   104,   104,   104,   104,   102,   102,   115,   176,   178,
      86,    93,   104,     6,     3,     7,     8,     5,     5,     6,
       9,     5,     5,    93,   102,   184,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,   176,    93,   104,   102,
     102,   102,   104,   104,   104,   104,   102,   102,     5,     5,
       6,     5,     5,    52,    52,    52,    52,    52,   102,   104,
     102,   104,   102,     3,     3,    52,    52,   102,   104,     5,
      52,   102
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex (scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    yyscan_t scanner;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (scanner);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    yyscan_t scanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, yyscan_t scanner)
#else
static void
yy_reduce_print (yyvsp, yyrule, scanner)
    YYSTYPE *yyvsp;
    int yyrule;
    yyscan_t scanner;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , scanner);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, scanner); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, scanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    yyscan_t scanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (scanner);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 52: /* "IDENTIFIER" */
#line 30 "indra.y"
	{ delete[] (yyvaluep->sval); };
#line 1923 "indra.y.cpp"
	break;
      case 53: /* "STATE_DEFAULT" */
#line 30 "indra.y"
	{ delete[] (yyvaluep->sval); };
#line 1928 "indra.y.cpp"
	break;
      case 58: /* "STRING_CONSTANT" */
#line 30 "indra.y"
	{ delete[] (yyvaluep->sval); };
#line 1933 "indra.y.cpp"
	break;

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (yyscan_t scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (yyscan_t scanner)
#else
int
yyparse (scanner)
    yyscan_t scanner;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 288 "indra.y"
    {
		(yyval.script) = new LLScriptScript((yyvsp[(1) - (2)].global_store), (yyvsp[(2) - (2)].state));
		gAllocationManager->addAllocation((yyval.script));
		gScriptp = (yyval.script);
	;}
    break;

  case 3:
#line 294 "indra.y"
    {
		(yyval.script) = new LLScriptScript(NULL, (yyvsp[(1) - (1)].state));
		gAllocationManager->addAllocation((yyval.script));
		gScriptp = (yyval.script);
	;}
    break;

  case 4:
#line 303 "indra.y"
    {
		(yyval.global_store) = (yyvsp[(1) - (1)].global_store);
	;}
    break;

  case 5:
#line 307 "indra.y"
    {
		(yyval.global_store) = (yyvsp[(1) - (2)].global_store);
		(yyvsp[(1) - (2)].global_store)->addGlobal((yyvsp[(2) - (2)].global_store));
	;}
    break;

  case 6:
#line 315 "indra.y"
    {
		(yyval.global_store) = new LLScritpGlobalStorage((yyvsp[(1) - (1)].global));
		gAllocationManager->addAllocation((yyval.global_store));
	;}
    break;

  case 7:
#line 320 "indra.y"
    {
		(yyval.global_store) = new LLScritpGlobalStorage((yyvsp[(1) - (1)].global_funcs));
		gAllocationManager->addAllocation((yyval.global_store));
	;}
    break;

  case 8:
#line 328 "indra.y"
    {
		(yyval.identifier) = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].type));	
		gAllocationManager->addAllocation((yyval.identifier));
	;}
    break;

  case 9:
#line 336 "indra.y"
    {
		(yyval.global) = new LLScriptGlobalVariable(gLine, gColumn, (yyvsp[(1) - (2)].identifier)->mType, (yyvsp[(1) - (2)].identifier), NULL);
		gAllocationManager->addAllocation((yyval.global));
	;}
    break;

  case 10:
#line 341 "indra.y"
    {
		(yyval.global) = new LLScriptGlobalVariable(gLine, gColumn, (yyvsp[(1) - (4)].identifier)->mType, (yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].assignable));
		gAllocationManager->addAllocation((yyval.global));
	;}
    break;

  case 11:
#line 349 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 12:
#line 353 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 13:
#line 360 "indra.y"
    {
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (1)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.assignable) = new LLScriptSAIdentifier(gLine, gColumn, id);	
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 14:
#line 367 "indra.y"
    {
		(yyval.assignable) = new LLScriptSAConstant(gLine, gColumn, (yyvsp[(1) - (1)].constant));
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 15:
#line 372 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 16:
#line 379 "indra.y"
    {
		(yyval.constant) = new LLScriptConstantInteger(gLine, gColumn, (yyvsp[(1) - (1)].ival));
		gAllocationManager->addAllocation((yyval.constant));
	;}
    break;

  case 17:
#line 384 "indra.y"
    {
		(yyval.constant) = new LLScriptConstantFloat(gLine, gColumn, (yyvsp[(1) - (1)].fval));
		gAllocationManager->addAllocation((yyval.constant));
	;}
    break;

  case 18:
#line 389 "indra.y"
    {
		(yyval.constant) = new LLScriptConstantString(gLine, gColumn, (yyvsp[(1) - (1)].sval));
		gAllocationManager->addAllocation((yyval.constant));
	;}
    break;

  case 19:
#line 397 "indra.y"
    {
		(yyval.fval) = (yyvsp[(1) - (1)].fval);
	;}
    break;

  case 20:
#line 401 "indra.y"
    {
		(yyval.fval) = -(yyvsp[(2) - (2)].fval);
	;}
    break;

  case 21:
#line 408 "indra.y"
    {
		(yyval.ival) = (yyvsp[(1) - (1)].ival);
	;}
    break;

  case 22:
#line 412 "indra.y"
    {
		(yyval.ival) = (yyvsp[(1) - (1)].ival);
	;}
    break;

  case 23:
#line 416 "indra.y"
    {
		(yyval.ival) = (yyvsp[(1) - (1)].ival);
	;}
    break;

  case 24:
#line 420 "indra.y"
    {
		(yyval.ival) = -(yyvsp[(2) - (2)].ival);
	;}
    break;

  case 25:
#line 427 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 26:
#line 431 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 27:
#line 438 "indra.y"
    {
		(yyval.assignable) = new LLScriptSAVector(gLine, gColumn, (yyvsp[(2) - (7)].assignable), (yyvsp[(4) - (7)].assignable), (yyvsp[(6) - (7)].assignable));
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 28:
#line 443 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptSAConstant *sa0 = new LLScriptSAConstant(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptSAConstant *sa1 = new LLScriptSAConstant(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptSAConstant *sa2 = new LLScriptSAConstant(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		(yyval.assignable) = new LLScriptSAVector(gLine, gColumn, sa0, sa1, sa2);
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 29:
#line 460 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptSAConstant *sa0 = new LLScriptSAConstant(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptSAConstant *sa1 = new LLScriptSAConstant(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptSAConstant *sa2 = new LLScriptSAConstant(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		(yyval.assignable) = new LLScriptSAVector(gLine, gColumn, sa0, sa1, sa2);
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 30:
#line 477 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, -1.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptSAConstant *sa0 = new LLScriptSAConstant(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, -1.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptSAConstant *sa1 = new LLScriptSAConstant(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptSAConstant *sa2 = new LLScriptSAConstant(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		(yyval.assignable) = new LLScriptSAVector(gLine, gColumn, sa0, sa1, sa2);
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 31:
#line 497 "indra.y"
    {
		(yyval.assignable) = new LLScriptSAQuaternion(gLine, gColumn, (yyvsp[(2) - (9)].assignable), (yyvsp[(4) - (9)].assignable), (yyvsp[(6) - (9)].assignable), (yyvsp[(8) - (9)].assignable));
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 32:
#line 502 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptSAConstant *sa0 = new LLScriptSAConstant(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptSAConstant *sa1 = new LLScriptSAConstant(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptSAConstant *sa2 = new LLScriptSAConstant(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		LLScriptConstantFloat *cf3 = new LLScriptConstantFloat(gLine, gColumn, 1.f);
		gAllocationManager->addAllocation(cf3);
		LLScriptSAConstant *sa3 = new LLScriptSAConstant(gLine, gColumn, cf3);
		gAllocationManager->addAllocation(sa3);
		(yyval.assignable) = new LLScriptSAQuaternion(gLine, gColumn, sa0, sa1, sa2, sa3);
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 33:
#line 526 "indra.y"
    {
		(yyval.assignable) = new LLScriptSAList(gLine, gColumn, (yyvsp[(2) - (3)].assignable));
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 34:
#line 531 "indra.y"
    {
		(yyval.assignable) = new LLScriptSAList(gLine, gColumn, NULL);
		gAllocationManager->addAllocation((yyval.assignable));
	;}
    break;

  case 35:
#line 539 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 36:
#line 543 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (3)].assignable);
		(yyvsp[(1) - (3)].assignable)->addAssignable((yyvsp[(3) - (3)].assignable));
	;}
    break;

  case 37:
#line 551 "indra.y"
    {
		(yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	;}
    break;

  case 38:
#line 558 "indra.y"
    {  
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_INTEGER);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 39:
#line 563 "indra.y"
    {  
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_FLOATINGPOINT);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 40:
#line 568 "indra.y"
    {  
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_STRING);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 41:
#line 573 "indra.y"
    {  
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_KEY);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 42:
#line 578 "indra.y"
    {  
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_VECTOR);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 43:
#line 583 "indra.y"
    {  
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_QUATERNION);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 44:
#line 588 "indra.y"
    {
		(yyval.type) = new LLScriptType(gLine, gColumn, LST_LIST);
		gAllocationManager->addAllocation((yyval.type));
	;}
    break;

  case 45:
#line 596 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (4)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.global_funcs) = new LLScriptGlobalFunctions(gLine, gColumn, NULL, id, NULL, (yyvsp[(4) - (4)].statement));
		gAllocationManager->addAllocation((yyval.global_funcs));
	;}
    break;

  case 46:
#line 603 "indra.y"
    {
		(yyval.global_funcs) = new LLScriptGlobalFunctions(gLine, gColumn, (yyvsp[(1) - (4)].identifier)->mType, (yyvsp[(1) - (4)].identifier), NULL, (yyvsp[(4) - (4)].statement));
		gAllocationManager->addAllocation((yyval.global_funcs));
	;}
    break;

  case 47:
#line 608 "indra.y"
    {
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (5)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.global_funcs) = new LLScriptGlobalFunctions(gLine, gColumn, NULL, id, (yyvsp[(3) - (5)].global_decl), (yyvsp[(5) - (5)].statement));
		gAllocationManager->addAllocation((yyval.global_funcs));
	;}
    break;

  case 48:
#line 615 "indra.y"
    {  
		(yyval.global_funcs) = new LLScriptGlobalFunctions(gLine, gColumn, (yyvsp[(1) - (5)].identifier)->mType, (yyvsp[(1) - (5)].identifier), (yyvsp[(3) - (5)].global_decl), (yyvsp[(5) - (5)].statement));
		gAllocationManager->addAllocation((yyval.global_funcs));
	;}
    break;

  case 49:
#line 623 "indra.y"
    {  
		(yyval.global_decl) = (yyvsp[(1) - (1)].global_decl);
	;}
    break;

  case 50:
#line 627 "indra.y"
    {  
		(yyval.global_decl) = (yyvsp[(1) - (3)].global_decl);
		(yyvsp[(1) - (3)].global_decl)->addFunctionParameter((yyvsp[(3) - (3)].global_decl));
	;}
    break;

  case 51:
#line 635 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (2)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.global_decl) = new LLScriptFunctionDec(gLine, gColumn, (yyvsp[(1) - (2)].type), id);
		gAllocationManager->addAllocation((yyval.global_decl));
	;}
    break;

  case 52:
#line 645 "indra.y"
    {  
		(yyval.state) = (yyvsp[(1) - (1)].state);
	;}
    break;

  case 53:
#line 649 "indra.y"
    {  
		(yyval.state) = (yyvsp[(1) - (2)].state);
		(yyvsp[(1) - (2)].state)->mNextp = (yyvsp[(2) - (2)].state);
	;}
    break;

  case 54:
#line 657 "indra.y"
    {  
		(yyval.state) = (yyvsp[(1) - (1)].state);
	;}
    break;

  case 55:
#line 661 "indra.y"
    {  
		(yyval.state) = (yyvsp[(1) - (2)].state);
		(yyvsp[(1) - (2)].state)->addState((yyvsp[(2) - (2)].state));
	;}
    break;

  case 56:
#line 669 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (4)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.state) = new LLScriptState(gLine, gColumn, LSSTYPE_DEFAULT, id, (yyvsp[(3) - (4)].handler));
		gAllocationManager->addAllocation((yyval.state));
	;}
    break;

  case 57:
#line 679 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (5)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.state) = new LLScriptState(gLine, gColumn, LSSTYPE_USER, id, (yyvsp[(4) - (5)].handler));
		gAllocationManager->addAllocation((yyval.state));
	;}
    break;

  case 58:
#line 689 "indra.y"
    {  
		(yyval.handler) = (yyvsp[(1) - (1)].handler);
	;}
    break;

  case 59:
#line 693 "indra.y"
    {  
		(yyval.handler) = (yyvsp[(1) - (2)].handler);
		(yyvsp[(1) - (2)].handler)->addEvent((yyvsp[(2) - (2)].handler));
	;}
    break;

  case 60:
#line 701 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 61:
#line 706 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 62:
#line 711 "indra.y"
    {
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 63:
#line 716 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 64:
#line 721 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 65:
#line 726 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 66:
#line 731 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 67:
#line 736 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 68:
#line 741 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 69:
#line 746 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 70:
#line 751 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 71:
#line 756 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 72:
#line 761 "indra.y"
    {
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 73:
#line 766 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 74:
#line 771 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 75:
#line 776 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 76:
#line 781 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 77:
#line 786 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 78:
#line 791 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 79:
#line 796 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 80:
#line 801 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 81:
#line 806 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 82:
#line 811 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 83:
#line 816 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 84:
#line 821 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 85:
#line 826 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 86:
#line 831 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 87:
#line 836 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 88:
#line 841 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 89:
#line 846 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 90:
#line 851 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 91:
#line 856 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 92:
#line 861 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 93:
#line 866 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 94:
#line 871 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 95:
#line 876 "indra.y"
    {  
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 96:
#line 881 "indra.y"
    {
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 97:
#line 886 "indra.y"
    {
		(yyval.handler) = new LLScriptEventHandler(gLine, gColumn, (yyvsp[(1) - (2)].event), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.handler));
	;}
    break;

  case 98:
#line 894 "indra.y"
    {  
		(yyval.event) = new LLScriptStateEntryEvent(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 99:
#line 902 "indra.y"
    {  
		(yyval.event) = new LLScriptStateExitEvent(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 100:
#line 910 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptTouchStartEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 101:
#line 920 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptTouchEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 102:
#line 930 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptTouchEndEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 103:
#line 940 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptCollisionStartEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 104:
#line 950 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptCollisionEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 105:
#line 960 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptCollisionEndEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 106:
#line 970 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptLandCollisionStartEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 107:
#line 980 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptLandCollisionEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 108:
#line 990 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptLandCollisionEndEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 109:
#line 1000 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (11)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (11)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (11)].sval));	
		gAllocationManager->addAllocation(id3);
		(yyval.event) = new LLScriptAtTarget(gLine, gColumn, id1, id2, id3);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 110:
#line 1014 "indra.y"
    {  
		(yyval.event) = new LLScriptNotAtTarget(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 111:
#line 1022 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (11)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (11)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (11)].sval));	
		gAllocationManager->addAllocation(id3);
		(yyval.event) = new LLScriptAtRotTarget(gLine, gColumn, id1, id2, id3);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 112:
#line 1036 "indra.y"
    {  
		(yyval.event) = new LLScriptNotAtRotTarget(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 113:
#line 1044 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (8)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (8)].sval));	
		gAllocationManager->addAllocation(id2);
		(yyval.event) = new LLScriptMoneyEvent(gLine, gColumn, id1, id2);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 114:
#line 1056 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (17)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (17)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (17)].sval));	
		gAllocationManager->addAllocation(id3);
		LLScriptIdentifier	*id4 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(13) - (17)].sval));	
		gAllocationManager->addAllocation(id4);
		LLScriptIdentifier	*id5 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(16) - (17)].sval));	
		gAllocationManager->addAllocation(id5);
		(yyval.event) = new LLScriptEmailEvent(gLine, gColumn, id1, id2, id3, id4, id5);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 115:
#line 1074 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptRTPEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 116:
#line 1084 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptInventoryEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 117:
#line 1094 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptAttachEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 118:
#line 1104 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (8)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (8)].sval));	
		gAllocationManager->addAllocation(id2);
		(yyval.event) = new LLScriptDataserverEvent(gLine, gColumn, id1, id2);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 119:
#line 1116 "indra.y"
    {  
		(yyval.event) = new LLScriptMovingStartEvent(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 120:
#line 1124 "indra.y"
    {  
		(yyval.event) = new LLScriptMovingEndEvent(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 121:
#line 1132 "indra.y"
    {  
		(yyval.event) = new LLScriptTimerEvent(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 122:
#line 1140 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (14)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (14)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (14)].sval));	
		gAllocationManager->addAllocation(id3);
		LLScriptIdentifier	*id4 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(13) - (14)].sval));	
		gAllocationManager->addAllocation(id4);
		(yyval.event) = new LLScriptChatEvent(gLine, gColumn, id1, id2, id3, id4);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 123:
#line 1156 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptSensorEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 124:
#line 1166 "indra.y"
    {  
		(yyval.event) = new LLScriptNoSensorEvent(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 125:
#line 1174 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (11)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (11)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (11)].sval));	
		gAllocationManager->addAllocation(id3);
		(yyval.event) = new LLScriptControlEvent(gLine, gColumn, id1, id2, id3);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 126:
#line 1188 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptRezEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 127:
#line 1198 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));	
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptObjectRezEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 128:
#line 1208 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (14)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (14)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (14)].sval));	
		gAllocationManager->addAllocation(id3);
		LLScriptIdentifier	*id4 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(13) - (14)].sval));	
		gAllocationManager->addAllocation(id4);
		(yyval.event) = new LLScriptLinkMessageEvent(gLine, gColumn, id1, id2, id3, id4);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 129:
#line 1224 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (20)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (20)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (20)].sval));	
		gAllocationManager->addAllocation(id3);
		LLScriptIdentifier	*id4 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(13) - (20)].sval));	
		gAllocationManager->addAllocation(id4);
		LLScriptIdentifier	*id5 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(16) - (20)].sval));	
		gAllocationManager->addAllocation(id4);
		LLScriptIdentifier	*id6 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(19) - (20)].sval));	
		gAllocationManager->addAllocation(id4);
		(yyval.event) = new LLScriptRemoteEvent(gLine, gColumn, id1, id2, id3, id4, id5, id6);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 130:
#line 1244 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (14)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (14)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (14)].sval));	
		gAllocationManager->addAllocation(id3);
		LLScriptIdentifier	*id4 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(13) - (14)].sval));	
		gAllocationManager->addAllocation(id4);
		(yyval.event) = new LLScriptHTTPResponseEvent(gLine, gColumn, id1, id2, id3, id4);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 131:
#line 1260 "indra.y"
    {  
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (11)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (11)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (11)].sval));	
		gAllocationManager->addAllocation(id3);
		(yyval.event) = new LLScriptHTTPRequestEvent(gLine, gColumn, id1, id2, id3);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 132:
#line 1274 "indra.y"
    {
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (11)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (11)].sval));	
		gAllocationManager->addAllocation(id2);
		LLScriptIdentifier	*id3 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(10) - (11)].sval));	
		gAllocationManager->addAllocation(id3);
		(yyval.event) = new LLScriptTransactionResultEvent(gLine, gColumn, id1, id2, id3);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 133:
#line 1288 "indra.y"
    {
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (8)].sval));	
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (8)].sval));	
		gAllocationManager->addAllocation(id2);
		(yyval.event) = new LLScriptPathUpdateEvent(gLine, gColumn, id1, id2);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 134:
#line 1300 "indra.y"
    {
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (5)].sval));
		gAllocationManager->addAllocation(id1);
		(yyval.event) = new LLScriptExperiencePermissionsEvent(gLine, gColumn, id1);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 135:
#line 1310 "indra.y"
    {
		LLScriptIdentifier	*id1 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(4) - (8)].sval));
		gAllocationManager->addAllocation(id1);
		LLScriptIdentifier	*id2 = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(7) - (8)].sval));
		gAllocationManager->addAllocation(id2);
		(yyval.event) = new LLScriptExperiencePermissionsDeniedEvent(gLine, gColumn, id1, id2);
		gAllocationManager->addAllocation((yyval.event));
	;}
    break;

  case 136:
#line 1322 "indra.y"
    {  
		(yyval.statement) = new LLScriptCompoundStatement(gLine, gColumn, NULL);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 137:
#line 1327 "indra.y"
    {  
		(yyval.statement) = new LLScriptCompoundStatement(gLine, gColumn, (yyvsp[(2) - (3)].statement));
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 138:
#line 1335 "indra.y"
    {  
		(yyval.statement) = (yyvsp[(1) - (1)].statement);
	;}
    break;

  case 139:
#line 1339 "indra.y"
    {  
		(yyval.statement) = new LLScriptStatementSequence(gLine, gColumn, (yyvsp[(1) - (2)].statement), (yyvsp[(2) - (2)].statement));
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 140:
#line 1347 "indra.y"
    {  
		(yyval.statement) = new LLScriptNOOP(gLine, gColumn);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 141:
#line 1352 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (3)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.statement) = new LLScriptStateChange(gLine, gColumn, id);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 142:
#line 1359 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (3)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.statement) = new LLScriptStateChange(gLine, gColumn, id);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 143:
#line 1366 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (3)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.statement) = new LLScriptJump(gLine, gColumn, id);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 144:
#line 1373 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (3)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.statement) = new LLScriptLabel(gLine, gColumn, id);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 145:
#line 1380 "indra.y"
    {  
		(yyval.statement) = new LLScriptReturn(gLine, gColumn, (yyvsp[(2) - (3)].expression));
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 146:
#line 1385 "indra.y"
    {  
		(yyval.statement) = new LLScriptReturn(gLine, gColumn, NULL);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 147:
#line 1390 "indra.y"
    {  
		(yyval.statement) = new LLScriptExpressionStatement(gLine, gColumn, (yyvsp[(1) - (2)].expression));
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 148:
#line 1395 "indra.y"
    {  
		(yyval.statement) = (yyvsp[(1) - (2)].statement);
	;}
    break;

  case 149:
#line 1399 "indra.y"
    { 
		(yyval.statement) = (yyvsp[(1) - (1)].statement);
	;}
    break;

  case 150:
#line 1403 "indra.y"
    {  
		(yyval.statement) = new LLScriptIf(gLine, gColumn, (yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
		(yyvsp[(5) - (5)].statement)->mAllowDeclarations = FALSE;
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 151:
#line 1409 "indra.y"
    {  
		(yyval.statement) = new LLScriptIfElse(gLine, gColumn, (yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));
		(yyvsp[(5) - (7)].statement)->mAllowDeclarations = FALSE;
		(yyvsp[(7) - (7)].statement)->mAllowDeclarations = FALSE;
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 152:
#line 1416 "indra.y"
    {  
		(yyval.statement) = new LLScriptFor(gLine, gColumn, (yyvsp[(3) - (9)].expression), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].statement));
		(yyvsp[(9) - (9)].statement)->mAllowDeclarations = FALSE;
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 153:
#line 1422 "indra.y"
    {  
		(yyval.statement) = new LLScriptDoWhile(gLine, gColumn, (yyvsp[(2) - (7)].statement), (yyvsp[(5) - (7)].expression));
		(yyvsp[(2) - (7)].statement)->mAllowDeclarations = FALSE;
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 154:
#line 1428 "indra.y"
    {  
		(yyval.statement) = new LLScriptWhile(gLine, gColumn, (yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
		(yyvsp[(5) - (5)].statement)->mAllowDeclarations = FALSE;
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 155:
#line 1437 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (2)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.statement) = new LLScriptDeclaration(gLine, gColumn, (yyvsp[(1) - (2)].type), id, NULL);
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 156:
#line 1444 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(2) - (4)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.statement) = new LLScriptDeclaration(gLine, gColumn, (yyvsp[(1) - (4)].type), id, (yyvsp[(4) - (4)].expression));
		gAllocationManager->addAllocation((yyval.statement));
	;}
    break;

  case 157:
#line 1454 "indra.y"
    {  
		(yyval.expression) = NULL;
	;}
    break;

  case 158:
#line 1458 "indra.y"
    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 159:
#line 1465 "indra.y"
    {  
		(yyval.expression) = new LLScriptForExpressionList(gLine, gColumn, (yyvsp[(1) - (1)].expression), NULL);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 160:
#line 1470 "indra.y"
    {
		(yyval.expression) = new LLScriptForExpressionList(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 161:
#line 1478 "indra.y"
    {  
		(yyval.expression) = NULL;
	;}
    break;

  case 162:
#line 1482 "indra.y"
    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 163:
#line 1489 "indra.y"
    {  
		(yyval.expression) = new LLScriptFuncExpressionList(gLine, gColumn, (yyvsp[(1) - (1)].expression), NULL);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 164:
#line 1494 "indra.y"
    {
		(yyval.expression) = new LLScriptFuncExpressionList(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 165:
#line 1502 "indra.y"
    {  
		(yyval.expression) = NULL;
	;}
    break;

  case 166:
#line 1506 "indra.y"
    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 167:
#line 1513 "indra.y"
    {  
		(yyval.expression) = new LLScriptListExpressionList(gLine, gColumn, (yyvsp[(1) - (1)].expression), NULL);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 168:
#line 1518 "indra.y"
    {
		(yyval.expression) = new LLScriptListExpressionList(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 169:
#line 1526 "indra.y"
    {  
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 170:
#line 1530 "indra.y"
    {  
		(yyval.expression) = new LLScriptAssignment(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 171:
#line 1535 "indra.y"
    {  
		(yyval.expression) = new LLScriptAddAssignment(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 172:
#line 1540 "indra.y"
    {  
		(yyval.expression) = new LLScriptSubAssignment(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 173:
#line 1545 "indra.y"
    {  
		(yyval.expression) = new LLScriptMulAssignment(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 174:
#line 1550 "indra.y"
    {  
		(yyval.expression) = new LLScriptDivAssignment(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 175:
#line 1555 "indra.y"
    {  
		(yyval.expression) = new LLScriptModAssignment(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 176:
#line 1560 "indra.y"
    {  
		(yyval.expression) = new LLScriptEquality(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 177:
#line 1565 "indra.y"
    {  
		(yyval.expression) = new LLScriptNotEquals(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 178:
#line 1570 "indra.y"
    {  
		(yyval.expression) = new LLScriptLessEquals(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 179:
#line 1575 "indra.y"
    {  
		(yyval.expression) = new LLScriptGreaterEquals(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 180:
#line 1580 "indra.y"
    {  
		(yyval.expression) = new LLScriptLessThan(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 181:
#line 1585 "indra.y"
    {  
		(yyval.expression) = new LLScriptGreaterThan(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 182:
#line 1590 "indra.y"
    {  
		(yyval.expression) = new LLScriptPlus(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 183:
#line 1595 "indra.y"
    {  
		(yyval.expression) = new LLScriptMinus(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 184:
#line 1600 "indra.y"
    {  
		(yyval.expression) = new LLScriptTimes(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 185:
#line 1605 "indra.y"
    {  
		(yyval.expression) = new LLScriptDivide(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 186:
#line 1610 "indra.y"
    {  
		(yyval.expression) = new LLScriptMod(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 187:
#line 1615 "indra.y"
    {  
		(yyval.expression) = new LLScriptBitAnd(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 188:
#line 1620 "indra.y"
    {  
		(yyval.expression) = new LLScriptBitOr(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 189:
#line 1625 "indra.y"
    {  
		(yyval.expression) = new LLScriptBitXor(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 190:
#line 1630 "indra.y"
    {  
		(yyval.expression) = new LLScriptBooleanAnd(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 191:
#line 1635 "indra.y"
    {  
		(yyval.expression) = new LLScriptBooleanOr(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 192:
#line 1640 "indra.y"
    {
		(yyval.expression) = new LLScriptShiftLeft(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 193:
#line 1645 "indra.y"
    {
		(yyval.expression) = new LLScriptShiftRight(gLine, gColumn, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 194:
#line 1653 "indra.y"
    {  
		(yyval.expression) = new LLScriptUnaryMinus(gLine, gColumn, (yyvsp[(2) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 195:
#line 1658 "indra.y"
    {  
		(yyval.expression) = new LLScriptBooleanNot(gLine, gColumn, (yyvsp[(2) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 196:
#line 1663 "indra.y"
    {  
		(yyval.expression) = new LLScriptBitNot(gLine, gColumn, (yyvsp[(2) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 197:
#line 1668 "indra.y"
    {  
		(yyval.expression) = new LLScriptPreIncrement(gLine, gColumn, (yyvsp[(2) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 198:
#line 1673 "indra.y"
    {  
		(yyval.expression) = new LLScriptPreDecrement(gLine, gColumn, (yyvsp[(2) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 199:
#line 1678 "indra.y"
    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 200:
#line 1682 "indra.y"
    {  
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 201:
#line 1686 "indra.y"
    {  
		(yyval.expression) = new LLScriptParenthesis(gLine, gColumn, (yyvsp[(2) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 202:
#line 1694 "indra.y"
    {
		(yyval.expression) = new LLScriptTypeCast(gLine, gColumn, (yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 203:
#line 1699 "indra.y"
    {
		LLScriptConstantExpression *temp =  new LLScriptConstantExpression(gLine, gColumn, (yyvsp[(4) - (4)].constant));
		gAllocationManager->addAllocation(temp);
		(yyval.expression) = new LLScriptTypeCast(gLine, gColumn, (yyvsp[(2) - (4)].type), temp);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 204:
#line 1706 "indra.y"
    {
		(yyval.expression) = new LLScriptTypeCast(gLine, gColumn, (yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 205:
#line 1711 "indra.y"
    {
		(yyval.expression) = new LLScriptTypeCast(gLine, gColumn, (yyvsp[(2) - (6)].type), (yyvsp[(5) - (6)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 206:
#line 1719 "indra.y"
    {  
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 207:
#line 1723 "indra.y"
    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 208:
#line 1727 "indra.y"
    {  
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 209:
#line 1731 "indra.y"
    {  
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	;}
    break;

  case 210:
#line 1735 "indra.y"
    {  
		(yyval.expression) = new LLScriptPostIncrement(gLine, gColumn, (yyvsp[(1) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 211:
#line 1740 "indra.y"
    {  
		(yyval.expression) = new LLScriptPostDecrement(gLine, gColumn, (yyvsp[(1) - (2)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 212:
#line 1745 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (4)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.expression) = new LLScriptFunctionCall(gLine, gColumn, id, (yyvsp[(3) - (4)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 213:
#line 1752 "indra.y"
    {  
		(yyval.expression) = new LLScriptPrint(gLine, gColumn, (yyvsp[(3) - (4)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 214:
#line 1757 "indra.y"
    {  
		(yyval.expression) = new LLScriptConstantExpression(gLine, gColumn, (yyvsp[(1) - (1)].constant));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 215:
#line 1765 "indra.y"
    {
		(yyval.expression) = new LLScriptVectorInitializer(gLine, gColumn, (yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].expression), (yyvsp[(6) - (7)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 216:
#line 1770 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptConstantExpression *sa0 = new LLScriptConstantExpression(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptConstantExpression *sa1 = new LLScriptConstantExpression(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptConstantExpression *sa2 = new LLScriptConstantExpression(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		(yyval.expression) = new LLScriptVectorInitializer(gLine, gColumn, sa0, sa1, sa2);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 217:
#line 1787 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptConstantExpression *sa0 = new LLScriptConstantExpression(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptConstantExpression *sa1 = new LLScriptConstantExpression(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptConstantExpression *sa2 = new LLScriptConstantExpression(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		(yyval.expression) = new LLScriptVectorInitializer(gLine, gColumn, sa0, sa1, sa2);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 218:
#line 1804 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, -1.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptConstantExpression *sa0 = new LLScriptConstantExpression(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, -1.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptConstantExpression *sa1 = new LLScriptConstantExpression(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptConstantExpression *sa2 = new LLScriptConstantExpression(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		(yyval.expression) = new LLScriptVectorInitializer(gLine, gColumn, sa0, sa1, sa2);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 219:
#line 1824 "indra.y"
    {
		(yyval.expression) = new LLScriptQuaternionInitializer(gLine, gColumn, (yyvsp[(2) - (9)].expression), (yyvsp[(4) - (9)].expression), (yyvsp[(6) - (9)].expression), (yyvsp[(8) - (9)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 220:
#line 1829 "indra.y"
    {
		LLScriptConstantFloat *cf0 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf0);
		LLScriptConstantExpression *sa0 = new LLScriptConstantExpression(gLine, gColumn, cf0);
		gAllocationManager->addAllocation(sa0);
		LLScriptConstantFloat *cf1 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf1);
		LLScriptConstantExpression *sa1 = new LLScriptConstantExpression(gLine, gColumn, cf1);
		gAllocationManager->addAllocation(sa1);
		LLScriptConstantFloat *cf2 = new LLScriptConstantFloat(gLine, gColumn, 0.f);
		gAllocationManager->addAllocation(cf2);
		LLScriptConstantExpression *sa2 = new LLScriptConstantExpression(gLine, gColumn, cf2);
		gAllocationManager->addAllocation(sa2);
		LLScriptConstantFloat *cf3 = new LLScriptConstantFloat(gLine, gColumn, 1.f);
		gAllocationManager->addAllocation(cf3);
		LLScriptConstantExpression *sa3 = new LLScriptConstantExpression(gLine, gColumn, cf3);
		gAllocationManager->addAllocation(sa3);
		(yyval.expression) = new LLScriptQuaternionInitializer(gLine, gColumn, sa0, sa1, sa2, sa3);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 221:
#line 1853 "indra.y"
    {  
		(yyval.expression) = new LLScriptListInitializer(gLine, gColumn, (yyvsp[(2) - (3)].expression));
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 222:
#line 1861 "indra.y"
    {  
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (1)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.expression) = new LLScriptLValue(gLine, gColumn, id, NULL);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;

  case 223:
#line 1868 "indra.y"
    {
		LLScriptIdentifier	*id = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(1) - (3)].sval));	
		gAllocationManager->addAllocation(id);
		LLScriptIdentifier	*ac = new LLScriptIdentifier(gLine, gColumn, (yyvsp[(3) - (3)].sval));	
		gAllocationManager->addAllocation(id);
		(yyval.expression) = new LLScriptLValue(gLine, gColumn, id, ac);
		gAllocationManager->addAllocation((yyval.expression));
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 4255 "indra.y.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (scanner, yymsg);
	  }
	else
	  {
	    yyerror (scanner, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, scanner);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, scanner);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, scanner);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1878 "indra.y"


