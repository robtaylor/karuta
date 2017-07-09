/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         z_yyparse
#define yylex           z_yylex
#define yyerror         z_yyerror
#define yydebug         z_yydebug
#define yynerrs         z_yynerrs

#define yylval          z_yylval
#define yychar          z_yychar

/* Copy the first part of user declarations.  */
#line 2 "src/fe/parser.ypp" /* yacc.c:339  */

#include "base/annotation_builder.h"
#include "base/sym.h"
#include "fe/builder.h"
#include "fe/emitter.h"
#include "fe/enum_decl.h"
#include "fe/expr.h"
#include "fe/nodecode.h"
#include "fe/scanner.h"
#include "fe/stmt.h"
#include "fe/var_decl.h"

extern int yylex();
extern void yyerror(const char *msg);


#line 91 "src/fe/libparse_la-parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_Z_YY_SRC_FE_LIBPARSE_LA_PARSER_HPP_INCLUDED
# define YY_Z_YY_SRC_FE_LIBPARSE_LA_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int z_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    K_DEF = 258,
    K_FUNC = 259,
    K_ENUM = 260,
    K_IMPORT = 261,
    K_ASSIGN = 262,
    K_SHIFT = 263,
    K_INT = 264,
    K_BOOL = 265,
    K_STRING = 266,
    K_OBJECT = 267,
    K_THREAD = 268,
    K_CHANNEL = 269,
    K_MAILBOX = 270,
    K_VAR = 271,
    K_ADD_SUB = 272,
    K_LG_COMPARE = 273,
    K_EQ_COMPARE = 274,
    K_INC_DEC = 275,
    K_CONST = 276,
    K_IF = 277,
    K_ELSE = 278,
    K_RETURN = 279,
    K_GOTO = 280,
    K_FOR = 281,
    K_SPAWN = 282,
    K_WHILE = 283,
    K_DO = 284,
    K_CONTINUE = 285,
    K_SWITCH = 286,
    K_CASE = 287,
    K_DEFAULT = 288,
    K_BREAK = 289,
    NUM = 290,
    SYM = 291,
    STR = 292,
    K_LOGIC_OR = 293,
    K_LOGIC_AND = 294,
    K_BIT_CONCAT = 295,
    SIGN = 296,
    ADDRESS = 297
  };
#endif
/* Tokens.  */
#define K_DEF 258
#define K_FUNC 259
#define K_ENUM 260
#define K_IMPORT 261
#define K_ASSIGN 262
#define K_SHIFT 263
#define K_INT 264
#define K_BOOL 265
#define K_STRING 266
#define K_OBJECT 267
#define K_THREAD 268
#define K_CHANNEL 269
#define K_MAILBOX 270
#define K_VAR 271
#define K_ADD_SUB 272
#define K_LG_COMPARE 273
#define K_EQ_COMPARE 274
#define K_INC_DEC 275
#define K_CONST 276
#define K_IF 277
#define K_ELSE 278
#define K_RETURN 279
#define K_GOTO 280
#define K_FOR 281
#define K_SPAWN 282
#define K_WHILE 283
#define K_DO 284
#define K_CONTINUE 285
#define K_SWITCH 286
#define K_CASE 287
#define K_DEFAULT 288
#define K_BREAK 289
#define NUM 290
#define SYM 291
#define STR 292
#define K_LOGIC_OR 293
#define K_LOGIC_AND 294
#define K_BIT_CONCAT 295
#define SIGN 296
#define ADDRESS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/fe/parser.ypp" /* yacc.c:355  */

  class ArrayInitializer *array;
  class Expr *expr;
  class EnumDecl *enum_decl;
  class Stmt *stmt;
  class VarDecl *var_decl;
  class VarDeclSet *var_decl_set;
  class NstBlock *block;
  const char *str;
  sym_t sym;
  uint64_t num;
  struct WidthSpec width_spec;
  class Annotation *annotation;
  class AnnotationValue *annotation_value;
  class AnnotationValueSet *annotation_value_set;

#line 232 "src/fe/libparse_la-parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE z_yylval;

int z_yyparse (void);

#endif /* !YY_Z_YY_SRC_FE_LIBPARSE_LA_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "src/fe/libparse_la-parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   868

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  266

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    60,     2,     2,    46,     2,
      55,    56,    47,     2,    38,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    61,
       2,     2,     2,    39,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    44,    59,    49,     2,     2,     2,
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
      35,    36,    37,    41,    42,    43,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    95,    98,   100,   105,   107,   111,
     113,   115,   119,   121,   125,   127,   131,   133,   137,   139,
     143,   143,   147,   154,   154,   156,   160,   161,   164,   167,
     170,   175,   179,   180,   183,   185,   187,   189,   193,   196,
     200,   202,   206,   208,   212,   214,   218,   222,   226,   231,
     231,   231,   235,   239,   243,   250,   252,   254,   256,   261,
     264,   268,   270,   272,   273,   274,   275,   277,   279,   280,
     281,   282,   283,   284,   285,   287,   288,   290,   292,   293,
     294,   298,   302,   302,   306,   306,   310,   310,   314,   319,
     325,   329,   332,   337,   342,   347,   362,   371,   377,   384,
     388,   396,   399,   400,   403,   406,   410,   415,   419,   421,
     425,   428,   430,   432,   434,   436,   438,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460,   462,   464,
     466,   468,   470,   472,   474,   476,   478,   481,   486,   488,
     492,   496,   501,   503
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_DEF", "K_FUNC", "K_ENUM", "K_IMPORT",
  "K_ASSIGN", "K_SHIFT", "K_INT", "K_BOOL", "K_STRING", "K_OBJECT",
  "K_THREAD", "K_CHANNEL", "K_MAILBOX", "K_VAR", "K_ADD_SUB",
  "K_LG_COMPARE", "K_EQ_COMPARE", "K_INC_DEC", "K_CONST", "K_IF", "K_ELSE",
  "K_RETURN", "K_GOTO", "K_FOR", "K_SPAWN", "K_WHILE", "K_DO",
  "K_CONTINUE", "K_SWITCH", "K_CASE", "K_DEFAULT", "K_BREAK", "NUM", "SYM",
  "STR", "','", "'?'", "':'", "K_LOGIC_OR", "K_LOGIC_AND", "K_BIT_CONCAT",
  "'|'", "'^'", "'&'", "'*'", "'!'", "'~'", "SIGN", "ADDRESS", "'.'",
  "'['", "']'", "'('", "')'", "'@'", "'{'", "'}'", "'#'", "';'", "$accept",
  "input", "IMPORT_PARAM_HEAD", "ANNOTATION_VALUE",
  "ANNOTATION_VALUE_LIST", "ANNOTATION_OR_EMPTY", "RETURN_TYPE",
  "RETURN_TYPE_LIST", "RETURN_SPEC", "FUNC_DECL", "$@1", "FUNC_DECL_HEAD",
  "FUNC_DECL_NAME", "STMT_LIST", "VAR_DECL_TAIL", "VAR_DECL", "WIDTH_SPEC",
  "ARG_DECL", "ARG_DECL_LIST", "ARRAY_SPEC", "EMPTY_OR_ARRAY_SPEC",
  "ARRAY_ELM", "ARRAY_ELM_LIST", "ARRAY_INITIALIZER", "$@2", "$@3",
  "VAR_DECL_STMT", "TYPE_NAME", "LABEL", "RETURN", "STMT", "EOS",
  "THREAD_DECL_STMT", "$@4", "CHANNEL_DECL_STMT", "$@5",
  "MAILBOX_DECL_STMT", "$@6", "IF_COND_PART", "IF_WITH_ELSE", "IF_STMT",
  "FOR_HEAD", "FOR_COND_PART", "FOR_STMT", "WHILE_COND_PART", "WHILE_STMT",
  "DO_WHILE_HEAD", "DO_WHILE_BODY", "DO_WHILE_STMT", "SWITCH_STMT",
  "CASES_LIST", "CASE", "BLOCK", "BLOCK_HEAD", "ENUM_DECL",
  "ENUM_ITEM_LIST", "EXPR", "VAR", "FUNCALL_HEAD", "FUNCALL", "ARG_LIST", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    44,    63,
      58,   293,   294,   295,   124,    94,    38,    42,    33,   126,
     296,   297,    46,    91,    93,    40,    41,    64,   123,   125,
      35,    59
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -145,   181,  -145,   124,    -2,  -145,  -145,  -145,   811,   811,
      65,  -145,    10,    69,    24,    76,  -145,    82,  -145,    -7,
    -145,   811,   811,   811,   811,    59,  -145,  -145,   131,  -145,
      -3,    77,  -145,   807,  -145,  -145,    77,    77,    77,    91,
     -14,  -145,   811,    87,  -145,    91,  -145,    91,   125,  -145,
    -145,  -145,  -145,   -16,   317,   811,  -145,  -145,  -145,  -145,
    -145,  -145,   128,   -21,    77,   128,   128,   128,   106,    22,
      22,   811,    38,    77,   811,   106,    77,   811,   811,  -145,
    -145,    22,    22,    22,   411,   110,   128,    80,   811,    -5,
     163,  -145,  -145,  -145,   317,  -145,  -145,  -145,   148,  -145,
    -145,   656,   811,  -145,  -145,   117,   235,  -145,   126,   811,
     811,   811,   811,   811,  -145,   811,   811,   811,   811,   811,
     811,   811,   811,   811,   811,   811,  -145,   656,   120,   126,
     143,   144,  -145,     0,     3,    15,   427,  -145,  -145,   364,
    -145,   468,   484,  -145,   149,  -145,    29,  -145,  -145,    -4,
     128,   656,   134,  -145,   132,  -145,  -145,   525,   811,  -145,
     131,  -145,   697,     4,    99,    45,   773,   697,   640,   752,
     765,   368,   122,   227,   769,    22,  -145,   582,  -145,  -145,
    -145,    20,    24,   147,   147,  -145,  -145,  -145,   156,   184,
       5,  -145,    40,    17,    55,  -145,  -145,  -145,    70,  -145,
     137,   159,  -145,  -145,  -145,    91,   541,   811,   811,  -145,
     166,  -145,  -145,   -24,   -24,  -145,   156,  -145,    51,   167,
    -145,   149,  -145,   -24,  -145,  -145,  -145,  -145,   292,  -145,
     158,   128,   176,  -145,  -145,   712,   599,  -145,  -145,  -145,
    -145,  -145,   177,  -145,  -145,  -145,    17,  -145,  -145,  -145,
    -145,   182,  -145,  -145,  -145,    44,  -145,   -24,   176,   160,
      17,  -145,  -145,  -145,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    12,     1,     0,     0,    82,    84,    86,     0,     0,
       0,    60,     0,     0,     0,     0,    98,     0,   137,   110,
     136,     0,     0,     0,     0,     0,   106,    81,    20,     3,
      44,     0,    75,     0,     4,    61,     0,     0,     0,     0,
       0,    69,     0,     0,    70,     0,    71,     0,     0,    72,
      73,    68,    26,     0,     0,   142,   116,    55,    56,    58,
      57,   138,     0,     0,     0,     0,     0,     0,   110,   134,
     133,     0,     0,     0,     0,     0,     0,     0,     0,    59,
     140,   119,   117,   118,     0,     0,     0,     0,     0,     0,
      45,    52,    74,    67,     0,    78,    79,    80,    90,    92,
      91,    94,     0,    97,    99,     0,    12,    63,    33,     0,
       0,     0,     0,     0,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   143,     0,    32,
       0,     0,    76,     0,     0,     0,     0,    65,    64,     0,
      77,     0,     0,   111,     9,    31,    34,    23,    24,     0,
      38,    53,     0,    42,     0,    66,    89,     0,     0,   105,
       0,    27,   123,   122,   120,   124,   125,   114,     0,   130,
     131,   126,   128,   129,   127,   121,   115,     0,   141,   139,
     108,     0,     0,     0,     0,    88,    93,    96,     0,     0,
       0,    10,     0,    34,     0,    30,    28,    26,     0,    40,
       0,    39,    43,    49,    54,     0,     0,     0,     0,   112,
       0,   107,    83,    34,    34,   104,   101,   102,     0,     0,
       8,     0,    13,    34,    37,    29,    35,    36,    12,    25,
      18,     0,     0,    95,   100,   135,     0,   109,    85,    87,
     103,     7,     0,     6,    11,    21,    34,    22,    41,    46,
      47,    50,   113,     5,    16,     0,    15,    34,     0,     0,
      34,    19,    14,    48,    51,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,    -6,  -145,   220,   -38,  -145,  -145,  -145,
    -145,  -145,  -145,    26,  -144,  -145,  -128,  -145,  -145,  -145,
    -145,   -34,  -145,  -145,  -145,  -145,  -145,    -1,  -145,  -145,
     224,    90,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     186,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,    11,   -28,  -145,  -145,  -145,    -8,     6,  -145,    -9,
    -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   190,   191,   192,   160,   254,   255,   247,    29,
      87,   149,   150,   106,   145,    30,   224,   200,   201,    90,
      91,   250,   251,   204,   232,   259,    31,   257,    32,    33,
     161,    35,    36,    65,    37,    66,    38,    67,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     216,   217,    51,    52,    53,   181,    54,   146,    55,    56,
     128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      69,    70,    62,    73,    88,    76,   199,   182,    10,    63,
     183,    98,   100,    81,    82,    83,    84,   103,   195,   104,
      61,   111,   184,   223,   114,    94,    57,    58,    59,    60,
     152,   130,    61,    79,   101,    64,   194,   131,    57,    58,
      59,    60,   114,   219,    26,    27,    72,   127,    80,   153,
      89,   123,   130,   110,   197,   130,   124,   125,   210,   108,
      75,   220,   111,   136,   223,   114,   139,   130,   129,   141,
     142,   133,   134,   135,   124,   125,   193,   194,   221,   211,
     151,   130,   260,   147,   148,   238,   239,   248,   241,   194,
     226,   227,   123,    80,   157,    85,   222,   124,   125,    27,
     261,   162,   163,   164,   165,   166,   242,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   256,   114,
      71,    92,   130,    93,    74,   229,    95,    96,    97,   262,
     110,    77,   256,    57,    58,    59,    60,    78,    27,   111,
     112,   113,   114,   107,   126,   196,   123,    86,   102,    26,
     206,   124,   125,   105,   132,   198,    57,    58,    59,    60,
      61,    80,   137,   138,    61,   144,   140,   121,   122,   123,
     154,   156,   158,   212,   124,   125,   178,   233,   130,   179,
     180,     2,   213,   214,   155,   189,     3,     4,   202,   215,
     203,   218,   225,   230,     5,     6,     7,   231,     8,   235,
     236,     9,   237,    10,   243,    11,    12,    13,    14,    15,
      16,   249,    17,   246,   253,   244,    18,    19,    20,   264,
     258,    28,   265,   228,   263,    34,    99,   240,    21,    22,
      23,     0,     0,     0,     0,   110,    24,     0,    25,    26,
       3,     4,    27,     0,   111,   112,   113,   114,     5,     6,
       7,     0,     8,     0,     0,     9,     0,    10,     0,    11,
      12,    13,    14,    15,    16,     0,    17,     0,     0,     0,
      18,    19,    20,   122,   123,     0,     0,     0,     0,   124,
     125,     0,    21,    22,    23,     0,     0,     0,     0,     0,
      24,     0,    25,    26,   159,     0,    27,     3,     4,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       0,     0,     9,     0,    10,     0,    11,    12,    13,    14,
      15,    16,     0,    17,   109,   110,     0,    18,    19,    20,
       0,     0,     0,     0,   111,   112,   113,   114,     0,    21,
      22,    23,     0,     0,     0,     0,     0,    24,     0,    25,
      26,   245,     0,    27,     0,   115,   116,     0,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,   124,
     125,   109,   110,     0,     0,     0,   110,     0,    27,     0,
       0,   111,   112,   113,   114,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,     0,   117,   118,   119,   120,   121,
     122,   123,   120,   121,   122,   123,   124,   125,   109,   110,
     124,   125,     0,     0,     0,   186,     0,     0,   111,   112,
     113,   114,     0,     0,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   113,   114,     0,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,   124,   125,   115,   116,   143,   117,   118,
     119,   120,   121,   122,   123,   109,   110,     0,     0,   124,
     125,     0,     0,   185,     0,   111,   112,   113,   114,     0,
       0,   109,   110,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,     0,   115,   116,     0,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
     124,   125,   115,   116,   187,   117,   118,   119,   120,   121,
     122,   123,   109,   110,     0,     0,   124,   125,     0,     0,
     188,     0,   111,   112,   113,   114,     0,     0,   109,   110,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,     0,   115,   116,     0,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,   124,   125,   115,
     116,   205,   117,   118,   119,   120,   121,   122,   123,   109,
     110,     0,     0,   124,   125,     0,     0,   234,     0,   111,
     112,   113,   114,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   208,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,   124,   125,   209,   115,   116,     0,
     117,   118,   119,   120,   121,   122,   123,   109,   110,     0,
       0,   124,   125,   252,     0,     0,     0,   111,   112,   113,
     114,     0,     0,   109,   110,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,   113,   114,     0,   115,   116,
     207,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,   124,   125,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   109,   110,     0,     0,   124,   125,
       0,     0,     0,     0,   111,   112,   113,   114,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,     0,     0,     0,   116,     0,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,   124,
     125,   116,     0,   117,   118,   119,   120,   121,   122,   123,
     110,     0,     0,     0,   124,   125,     0,     0,     0,   111,
     112,   113,   114,   110,     0,     0,     0,   110,     0,     0,
       0,   110,   111,   112,   113,   114,   111,   112,   113,   114,
     111,   112,     0,   114,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,   124,   125,     0,     0,   119,   120,
     121,   122,   123,     0,     0,     0,   123,   124,   125,     0,
     123,   124,   125,     0,     8,   124,   125,     9,     8,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    68,    20,     0,    18,    68,    20,     0,
       0,     0,     0,     0,    21,    22,    23,     0,    21,    22,
      23,     0,    24,     0,     0,     0,    24,     0,    27
};

static const yytype_int16 yycheck[] =
{
       8,     9,     3,    12,     7,    14,   150,     7,    22,     3,
       7,    39,    40,    21,    22,    23,    24,    45,   146,    47,
      36,    17,     7,    47,    20,    33,     9,    10,    11,    12,
      35,    52,    36,    40,    42,    37,    60,    58,     9,    10,
      11,    12,    20,    38,    58,    61,    36,    55,    55,    54,
      53,    47,    52,     8,    58,    52,    52,    53,    38,    53,
      36,    56,    17,    71,    47,    20,    74,    52,    62,    77,
      78,    65,    66,    67,    52,    53,    47,    60,    38,    59,
      88,    52,    38,     3,     4,   213,   214,   231,    37,    60,
      35,    36,    47,    55,   102,    36,    56,    52,    53,    61,
      56,   109,   110,   111,   112,   113,    55,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   246,    20,
      55,    31,    52,    33,    55,    55,    36,    37,    38,   257,
       8,    55,   260,     9,    10,    11,    12,    55,    61,    17,
      18,    19,    20,    53,    54,   146,    47,    16,    61,    58,
     158,    52,    53,    28,    64,   149,     9,    10,    11,    12,
      36,    55,    72,    73,    36,    55,    76,    45,    46,    47,
       7,    23,    55,   182,    52,    53,    56,   205,    52,    36,
      36,     0,   183,   184,    94,    36,     5,     6,    54,    33,
      58,     7,   193,    56,    13,    14,    15,    38,    17,   207,
     208,    20,    36,    22,    37,    24,    25,    26,    27,    28,
      29,    35,    31,    55,    37,   221,    35,    36,    37,    59,
      38,     1,   260,   197,   258,     1,    40,   216,    47,    48,
      49,    -1,    -1,    -1,    -1,     8,    55,    -1,    57,    58,
       5,     6,    61,    -1,    17,    18,    19,    20,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    -1,    22,    -1,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      35,    36,    37,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    57,    58,    59,    -1,    61,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    17,
      -1,    -1,    20,    -1,    22,    -1,    24,    25,    26,    27,
      28,    29,    -1,    31,     7,     8,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,
      58,    59,    -1,    61,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,     7,     8,    -1,    -1,    -1,     8,    -1,    61,    -1,
      -1,    17,    18,    19,    20,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    44,    45,    46,    47,    52,    53,     7,     8,
      52,    53,    -1,    -1,    -1,    61,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    38,    39,    56,    41,    42,
      43,    44,    45,    46,    47,     7,     8,    -1,    -1,    52,
      53,    -1,    -1,    56,    -1,    17,    18,    19,    20,    -1,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    53,    38,    39,    56,    41,    42,    43,    44,    45,
      46,    47,     7,     8,    -1,    -1,    52,    53,    -1,    -1,
      56,    -1,    17,    18,    19,    20,    -1,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    38,
      39,    56,    41,    42,    43,    44,    45,    46,    47,     7,
       8,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,     7,     8,    -1,
      -1,    52,    53,    54,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,     7,     8,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
       8,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    17,
      18,    19,    20,     8,    -1,    -1,    -1,     8,    -1,    -1,
      -1,     8,    17,    18,    19,    20,    17,    18,    19,    20,
      17,    18,    -1,    20,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    47,    52,    53,    -1,
      47,    52,    53,    -1,    17,    52,    53,    20,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    47,    48,
      49,    -1,    55,    -1,    -1,    -1,    55,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     5,     6,    13,    14,    15,    17,    20,
      22,    24,    25,    26,    27,    28,    29,    31,    35,    36,
      37,    47,    48,    49,    55,    57,    58,    61,    67,    71,
      77,    88,    90,    91,    92,    93,    94,    96,    98,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   114,   115,   116,   118,   120,   121,     9,    10,    11,
      12,    36,    89,   119,    37,    95,    97,    99,    36,   118,
     118,    55,    36,   121,    55,    36,   121,    55,    55,    40,
      55,   118,   118,   118,   118,    36,    16,    72,     7,    53,
      81,    82,    93,    93,   118,    93,    93,    93,   114,   102,
     114,   118,    61,   114,   114,    28,    75,    93,   119,     7,
       8,    17,    18,    19,    20,    38,    39,    41,    42,    43,
      44,    45,    46,    47,    52,    53,    93,   118,   122,   119,
      52,    58,    93,   119,   119,   119,   118,    93,    93,   118,
      93,   118,   118,    56,    55,    76,   119,     3,     4,    73,
      74,   118,    35,    54,     7,    93,    23,   118,    55,    59,
      67,    92,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,    56,    36,
      36,   117,     7,     7,     7,    56,    61,    56,    56,    36,
      64,    65,    66,    47,    60,    78,    89,    58,   119,    76,
      79,    80,    54,    58,    85,    56,   118,    40,    40,    54,
      38,    59,   121,    89,    89,    33,   112,   113,     7,    38,
      56,    38,    56,    47,    78,    89,    35,    36,    75,    55,
      56,    38,    86,   114,    56,   118,   118,    36,    78,    78,
     113,    37,    55,    37,    65,    59,    55,    70,    76,    35,
      83,    84,    54,    37,    68,    69,    78,    89,    38,    87,
      38,    56,    78,    83,    59,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      72,    71,    73,    73,    73,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    84,    84,    86,
      87,    85,    88,    88,    88,    89,    89,    89,    89,    90,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    95,    94,    97,    96,    99,    98,   100,   101,
     102,   102,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   112,   113,   114,   115,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   121,   122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     4,     3,     3,     2,     0,
       1,     3,     0,     5,     2,     1,     1,     3,     0,     3,
       0,     6,     4,     1,     1,     3,     0,     2,     2,     3,
       2,     3,     3,     2,     0,     2,     2,     2,     0,     1,
       1,     3,     2,     3,     0,     1,     1,     1,     3,     0,
       0,     5,     2,     3,     4,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     3,     2,     2,
       2,     1,     0,     5,     0,     6,     0,     6,     4,     3,
       2,     2,     2,     4,     2,     5,     4,     2,     1,     2,
       5,     5,     1,     2,     1,     3,     1,     5,     1,     3,
       1,     3,     4,     6,     3,     3,     1,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     5,     1,     1,     1,     3,
       2,     3,     0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 93 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1649 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 94 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1656 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1663 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation_value) = AnnotationBuilder::BuildStrParam((yyvsp[-3].sym), (yyvsp[0].str));
}
#line 1671 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  AnnotationBuilder::AddStrParam((yyvsp[-2].annotation_value), (yyvsp[0].str));
  (yyval.annotation_value) = (yyvsp[-2].annotation_value);
}
#line 1680 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation_value) = AnnotationBuilder::BuildStrParam((yyvsp[-2].sym), (yyvsp[0].str));
}
#line 1688 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 107 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation_value) = (yyvsp[-1].annotation_value);
}
#line 1696 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation_value_set) = AnnotationBuilder::BuildParamSet(nullptr, nullptr);
}
#line 1704 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation_value_set) = AnnotationBuilder::BuildParamSet(nullptr, (yyvsp[0].annotation_value));
}
#line 1712 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation_value_set) = AnnotationBuilder::BuildParamSet((yyvsp[-2].annotation_value_set), (yyvsp[0].annotation_value));
}
#line 1720 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation) = Emitter::SetAnnotation(sym_null, nullptr);
}
#line 1728 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.annotation) = Emitter::SetAnnotation((yyvsp[-3].sym), (yyvsp[-1].annotation_value_set));
}
#line 1736 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl) = Builder::ReturnType((yyvsp[-1].sym), (yyvsp[0].width_spec).width, (yyvsp[0].width_spec).name);
}
#line 1744 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl) = Builder::ReturnType(sym_int, (yyvsp[0].width_spec).width, (yyvsp[0].width_spec).name);
}
#line 1752 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 131 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
 (yyval.var_decl_set) = Builder::ReturnDeclList(nullptr, (yyvsp[0].var_decl));
}
#line 1760 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 133 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
 (yyval.var_decl_set) = Builder::ReturnDeclList((yyvsp[-2].var_decl_set), (yyvsp[0].var_decl));
}
#line 1768 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl_set) = Builder::ReturnDeclList(nullptr, nullptr);
}
#line 1776 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl_set) = (yyvsp[-1].var_decl_set);
}
#line 1784 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "src/fe/parser.ypp" /* yacc.c:1646  */
    {Emitter::SetCurrentFunctionAnnotation((yyvsp[0].annotation));}
#line 1790 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EndFunction();
}
#line 1798 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::SetCurrentFunctionParams();
  Emitter::SetCurrentFunctionArgs((yyvsp[-2].var_decl_set));
  Emitter::SetCurrentFunctionReturns((yyvsp[0].var_decl_set));
}
#line 1808 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::BeginFunction((yyvsp[-1].expr));
}
#line 1816 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 160 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1823 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1830 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 164 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  auto *vd = Builder::MaybePtrVar((yyvsp[-1].expr), false);
  (yyval.var_decl) = Builder::BuildVarDecl(true, (yyvsp[0].sym), nullptr, vd);
}
#line 1839 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  auto *vd = Builder::MaybePtrVar((yyvsp[-2].expr), true);
  (yyval.var_decl) = Builder::BuildVarDecl(true, (yyvsp[0].sym), nullptr, vd);
}
#line 1848 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  auto *vd = Builder::MaybePtrVar((yyvsp[-1].expr), (yyvsp[0].width_spec).is_ptr);
  (yyval.var_decl) = Builder::BuildVarDecl(false, (yyvsp[0].width_spec).name, (yyvsp[0].width_spec).width, vd);
}
#line 1857 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 175 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  Builder::SetVarDeclAnnotation((yyvsp[0].var_decl), (yyvsp[-2].annotation));
  (yyval.var_decl) = (yyvsp[0].var_decl);
}
#line 1867 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 179 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1874 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 180 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 1881 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.width_spec) = WidthSpec::Int(false, 32, false);
}
#line 1889 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.width_spec) = WidthSpec::Int(false, (yyvsp[0].num), false);
}
#line 1897 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 187 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.width_spec) = WidthSpec::Name((yyvsp[0].sym), false, false);
}
#line 1905 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 189 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.width_spec).is_ptr = true;
}
#line 1913 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  /* no arguments */
  (yyval.var_decl_set) = nullptr;
}
#line 1922 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl_set) = (yyvsp[0].var_decl_set);
}
#line 1930 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 200 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl_set) = Builder::ArgDeclList(nullptr, (yyvsp[0].var_decl));
}
#line 1938 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 202 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.var_decl_set) = Builder::ArgDeclList((yyvsp[-2].var_decl_set), (yyvsp[0].var_decl));
}
#line 1946 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 206 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.num) = 0;
}
#line 1954 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 208 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.num) = (yyvsp[-1].num);
}
#line 1962 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.num) = -1;
}
#line 1970 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.num) = (yyvsp[0].num);
}
#line 1978 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 218 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.num) = (yyvsp[0].num);
}
#line 1986 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 222 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ArrayInitializer *array = new ArrayInitializer;
  array->num_.push_back((yyvsp[0].num));
  (yyval.array) = array;
}
#line 1996 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 226 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyvsp[-2].array)->num_.push_back((yyvsp[0].num));
  (yyval.array) = (yyvsp[-2].array);
}
#line 2005 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 231 "src/fe/parser.ypp" /* yacc.c:1646  */
    { ScannerInterface::InArrayElmDecl(); }
#line 2011 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 231 "src/fe/parser.ypp" /* yacc.c:1646  */
    {ScannerInterface::EndArrayElmDecl(); }
#line 2017 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 231 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.array) = (yyvsp[-2].array);
}
#line 2025 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 235 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  Builder::SetArrayLength((yyvsp[-1].var_decl), (yyvsp[0].num));
  (yyval.var_decl_set) = Builder::VarDeclList(nullptr, (yyvsp[-1].var_decl));
}
#line 2035 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 239 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  (yyvsp[-2].var_decl)->SetInitialVal((yyvsp[0].expr));
  (yyval.var_decl_set) = Builder::VarDeclList(nullptr, (yyvsp[-2].var_decl));
}
#line 2045 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 243 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  Builder::SetArrayLength((yyvsp[-3].var_decl), (yyvsp[-2].num));
  Builder::SetArrayInitializer((yyvsp[-3].var_decl), (yyvsp[0].array));
  (yyval.var_decl_set) = Builder::VarDeclList(nullptr, (yyvsp[-3].var_decl));
}
#line 2056 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 250 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.sym) = sym_int;
}
#line 2064 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 252 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.sym) = sym_bool;
}
#line 2072 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 254 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.sym) = sym_object;
}
#line 2080 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 256 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.sym) = sym_string;
}
#line 2088 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 261 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2095 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 264 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
}
#line 2103 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 268 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  /* empty stmt */
}
#line 2111 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 270 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitExprStmt((yyvsp[-1].expr));
}
#line 2119 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 272 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2126 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 273 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2133 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 274 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2140 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 275 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitReturnStmt((yyvsp[-1].expr));
}
#line 2148 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 277 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitReturnStmt(nullptr);
}
#line 2156 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 279 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2163 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 280 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2170 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 281 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2177 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 282 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2184 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2191 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 284 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2198 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 285 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitVarDeclStmtSet((yyvsp[-1].var_decl_set));
}
#line 2206 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 288 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitImportStmt((yyvsp[-1].str));
}
#line 2214 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 290 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitSpawnStmt((yyvsp[-1].expr));
}
#line 2222 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 292 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2229 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 293 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2236 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 294 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2243 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 298 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::EndSemiColonStatement();
}
#line 2251 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 302 "src/fe/parser.ypp" /* yacc.c:1646  */
    {ScannerInterface::InSemiColonStatement();}
#line 2257 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 302 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitThreadDeclStmt((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 2265 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 306 "src/fe/parser.ypp" /* yacc.c:1646  */
    {ScannerInterface::InSemiColonStatement();}
#line 2271 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 306 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitChannelDeclStmt((yyvsp[-3].expr), (yyvsp[-1].sym), (yyvsp[0].width_spec).width, (yyvsp[0].width_spec).name);
}
#line 2279 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 310 "src/fe/parser.ypp" /* yacc.c:1646  */
    {ScannerInterface::InSemiColonStatement();}
#line 2285 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 310 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitMailboxDeclStmt((yyvsp[-3].expr), (yyvsp[-1].sym), (yyvsp[0].width_spec).width, (yyvsp[0].width_spec).name);
}
#line 2293 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 314 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.stmt) = Emitter::EmitIfStmt((yyvsp[-1].expr));
  Emitter::EmitLabel((yyval.stmt)->label_t_);
}
#line 2302 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 319 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.stmt) = (yyvsp[-2].stmt);
  Emitter::EmitGoto((yyvsp[-2].stmt)->label_join_);
  Emitter::EmitLabel((yyvsp[-2].stmt)->label_f_);
}
#line 2312 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 325 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.block) = nullptr;
  Emitter::EmitLabel((yyvsp[-1].stmt)->label_f_);
  Emitter::EmitLabel((yyvsp[-1].stmt)->label_join_);
}
#line 2322 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 329 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.block) = nullptr;
  Emitter::EmitLabel((yyvsp[-1].stmt)->label_join_);
}
#line 2331 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 332 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.block) = nullptr;
  Emitter::EmitLabel((yyvsp[-1].stmt)->label_join_);
}
#line 2340 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 337 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::BeginBlock();
  Emitter::EmitExprStmt((yyvsp[-1].expr));
}
#line 2349 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 342 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.stmt) = Emitter::EmitForStmt((yyvsp[0].expr));
  Emitter::EmitLabel((yyval.stmt)->label_t_);
}
#line 2358 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 347 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  // join:
  // cond_expr
  // if (cond_expr)
  //  t:
  //  block
  //  repeat_expr
  // goto join:
  //  f:
  Emitter::EmitExprStmt((yyvsp[-2].expr));
  Emitter::EmitGoto((yyvsp[-4].stmt)->label_join_);
  Emitter::EmitLabel((yyvsp[-4].stmt)->label_f_);
  Emitter::EndBlock();
}
#line 2377 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 362 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::BeginBlock();
  // Emit a dummy insn before label_join so that compiler can
  // find a insn after the label.
  Emitter::EmitNop();
  (yyval.stmt) = Emitter::EmitWhileStmt((yyvsp[-1].expr));
  Emitter::EmitLabel((yyval.stmt)->label_t_);
}
#line 2390 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 371 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitGoto((yyvsp[-1].stmt)->label_join_);
  Emitter::EmitLabel((yyvsp[-1].stmt)->label_f_);
  Emitter::EndBlock();
}
#line 2400 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 377 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::BeginBlock();
  Emitter::EmitNop();
  (yyval.stmt) = Builder::DoWhileStmt();
  Emitter::EmitLabel((yyval.stmt)->label_join_);
}
#line 2411 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 384 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.stmt) = (yyvsp[-1].stmt);
}
#line 2419 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 388 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitDoWhileStmt((yyvsp[-4].stmt), (yyvsp[-1].expr));
  Emitter::EmitLabel((yyvsp[-4].stmt)->label_t_);
  Emitter::EmitGoto((yyvsp[-4].stmt)->label_join_);
  Emitter::EmitLabel((yyvsp[-4].stmt)->label_f_);
  Emitter::EndBlock();
}
#line 2431 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 396 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2438 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 399 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2445 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 400 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2452 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 403 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
}
#line 2459 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 406 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EndBlock();
}
#line 2467 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 410 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  /* open new bindings */
  Emitter::BeginBlock();
}
#line 2476 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 415 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  Emitter::EmitEnumTypeDeclStmt((yyvsp[-3].expr), (yyvsp[-1].enum_decl));
}
#line 2484 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 419 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.enum_decl) = Builder::EnumItemList(nullptr, (yyvsp[0].sym));
}
#line 2492 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 421 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.enum_decl) = Builder::EnumItemList((yyvsp[-2].enum_decl), (yyvsp[0].sym));
}
#line 2500 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 425 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  (yyval.expr) = Builder::SymExpr((yyvsp[0].sym));
}
#line 2509 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 428 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = (yyvsp[-1].expr);
}
#line 2517 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 430 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::ArrayRefExpr((yyvsp[-3].expr), (yyvsp[-1].expr));
}
#line 2525 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 432 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BitRangeRefExpr((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr));
}
#line 2533 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 434 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_COMMA);
}
#line 2541 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 436 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_ELM_REF);
}
#line 2549 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 438 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = (yyvsp[0].expr);
}
#line 2557 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 440 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::LogicInvertExpr((yyvsp[0].expr));
}
#line 2565 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 442 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BitInvertExpr((yyvsp[0].expr));
}
#line 2573 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 444 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::RefExpr((yyvsp[0].expr));
}
#line 2581 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 446 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].num));
}
#line 2589 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 448 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_MUL);
}
#line 2597 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 450 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].num));
}
#line 2605 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 452 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].num));
}
#line 2613 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 454 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].num));
}
#line 2621 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 456 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].num));
}
#line 2629 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 458 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_CONCAT);
}
#line 2637 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 460 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_AND);
}
#line 2645 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 462 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_OR);
}
#line 2653 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 464 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_XOR);
}
#line 2661 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 466 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_LOR);
}
#line 2669 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 468 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::BinopExpr((yyvsp[-2].expr), (yyvsp[0].expr), BINOP_LAND);
}
#line 2677 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 470 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::IncDecExpr((yyvsp[-1].expr), (yyvsp[0].num), true);
}
#line 2685 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 472 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::IncDecExpr((yyvsp[0].expr), (yyvsp[-1].num), false);
}
#line 2693 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 474 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::SignedExpr((yyvsp[-1].num), (yyvsp[0].expr));
}
#line 2701 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 476 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::TriTerm((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 2709 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 478 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  (yyval.expr) = Builder::StrExpr((yyvsp[0].str));
}
#line 2718 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 481 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  (yyval.expr) = Builder::NumExpr((yyvsp[0].num));
}
#line 2727 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 486 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::SymExpr((yyvsp[0].sym));
}
#line 2735 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 488 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::ElmSymRefExpr((yyvsp[-2].expr), (yyvsp[0].sym));
}
#line 2743 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 492 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = Builder::SymExpr((yyvsp[-1].sym));
}
#line 2751 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 496 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  ScannerInterface::InSemiColonStatement();
  (yyval.expr) = Builder::FuncallExpr((yyvsp[-2].expr), (yyvsp[-1].expr));
}
#line 2760 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 501 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = nullptr;
}
#line 2768 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 503 "src/fe/parser.ypp" /* yacc.c:1646  */
    {
  (yyval.expr) = (yyvsp[0].expr);
}
#line 2776 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
    break;


#line 2780 "src/fe/libparse_la-parser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 507 "src/fe/parser.ypp" /* yacc.c:1906  */

