/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 33 "globaliser/parser.yc" /* yacc.c:339  */

#include <stdio.h>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
#include <assert.h>
#include "../sim/num_stacks.h"
using namespace std;

#define YYERROR_VERBOSE
#define YYSTYPE struct node_t *
#define YYMAXDEPTH 1000000
#define YYINITDEPTH 10000

// Debugging: 
//#define YYDEBUG 1

#include "handle_global.h"

extern int lineno;
extern int yylex();
extern string ws_text;
extern string token_text;
extern string attr_text;
extern string lex_text;
void setup_globals(const char *);

static void yyerror(const char *s);

#include "node.h"


#line 100 "globaliser/parser.tab.cc" /* yacc.c:339  */

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
   by #include "parser.tab.hh".  */
#ifndef YY_YY_GLOBALISER_PARSER_TAB_HH_INCLUDED
# define YY_YY_GLOBALISER_PARSER_TAB_HH_INCLUDED
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
    IDENTIFIER = 258,
    TYPEDEF_NAME = 259,
    INTEGER = 260,
    FLOATING = 261,
    CHARACTER = 262,
    STRING = 263,
    WS = 264,
    ELLIPSIS = 265,
    ADDEQ = 266,
    SUBEQ = 267,
    MULEQ = 268,
    DIVEQ = 269,
    MODEQ = 270,
    XOREQ = 271,
    ANDEQ = 272,
    OREQ = 273,
    SL = 274,
    SR = 275,
    SLEQ = 276,
    SREQ = 277,
    EQ = 278,
    NOTEQ = 279,
    LTEQ = 280,
    GTEQ = 281,
    ANDAND = 282,
    OROR = 283,
    PLUSPLUS = 284,
    MINUSMINUS = 285,
    ARROW = 286,
    AUTO = 287,
    BREAK = 288,
    CASE = 289,
    CHAR = 290,
    CONST = 291,
    CONTINUE = 292,
    DEFAULT = 293,
    DO = 294,
    DOUBLE = 295,
    ELSE = 296,
    ENUM = 297,
    EXTERN = 298,
    FLOAT = 299,
    FOR = 300,
    GOTO = 301,
    IF = 302,
    INT = 303,
    LONG = 304,
    REGISTER = 305,
    RETURN = 306,
    SHORT = 307,
    SIGNED = 308,
    SIZEOF = 309,
    STATIC = 310,
    STRUCT = 311,
    SWITCH = 312,
    TYPEDEF = 313,
    UNION = 314,
    UNSIGNED = 315,
    VOID = 316,
    VOLATILE = 317,
    WHILE = 318,
    ATTRIBUTE = 319,
    TYPEOF = 320,
    ALIGNOF = 321,
    ASM = 322,
    GCC_BUILTIN_TYPES_COMPATIBLE = 323,
    OFFSETOF = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GLOBALISER_PARSER_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "globaliser/parser.tab.cc" /* yacc.c:358  */

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
#define YYFINAL  99
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  178
/* YYNRULES -- Number of rules.  */
#define YYNRULES  423
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  667

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    93,     2,     2,     2,    91,    81,     2,
      73,    74,    72,    82,    70,    83,    92,    85,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    71,
      89,    80,    90,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    84,    76,    86,     2,     2,     2,
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
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    90,    94,    95,    96,    97,    98,    99,
     103,   107,   114,   119,   120,   128,   129,   133,   164,   173,
     177,   181,   185,   189,   193,   200,   201,   208,   209,   210,
     211,   216,   217,   223,   230,   231,   232,   233,   234,   235,
     239,   240,   244,   248,   253,   258,   266,   267,   271,   273,
     278,   279,   281,   286,   287,   289,   294,   295,   297,   299,
     301,   306,   307,   309,   314,   315,   320,   321,   326,   327,
     332,   333,   338,   339,   345,   346,   348,   356,   357,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     378,   379,   386,   390,   395,   403,   436,   444,   446,   447,
     448,   449,   450,   454,   458,   459,   460,   461,   462,   466,
     467,   475,   481,   485,   490,   495,   500,   504,   509,   514,
     519,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   539,   544,   552,   553,   554,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   575,   588,
     602,   609,   613,   620,   630,   638,   651,   652,   653,   654,
     658,   659,   663,   664,   672,   676,   680,   684,   695,   709,
     712,   723,   726,   733,   744,   745,   750,   751,   753,   758,
     763,   767,   772,   776,   784,   785,   789,   794,   803,   804,
     809,   817,   823,   827,   834,   838,   843,   848,   855,   862,
     874,   881,   895,   907,   914,   919,   926,   931,   938,   945,
     957,   964,   981,   982,   983,   984,   988,   989,   993,   998,
    1006,  1007,  1019,  1023,  1027,  1039,  1044,  1052,  1053,  1058,
    1059,  1060,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,
    1080,  1085,  1086,  1087,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1111,  1112,  1114,  1116,  1119,  1123,  1127,  1139,
    1144,  1149,  1157,  1162,  1167,  1172,  1180,  1181,  1188,  1189,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1213,  1220,
    1224,  1236,  1240,  1257,  1258,  1266,  1281,  1300,  1303,  1312,
    1313,  1325,  1329,  1341,  1342,  1353,  1357,  1358,  1366,  1371,
    1379,  1380,  1388,  1389,  1393,  1397,  1401,  1403,  1410,  1414,
    1419,  1423,  1427,  1431,  1435,  1439,  1443,  1447,  1454,  1461,
    1462,  1463,  1464,  1470,  1471,  1488,  1489,  1496,  1501,  1520,
    1521,  1525,  1533,  1540,  1546,  1555,  1556,  1557,  1558,  1559,
    1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569,
    1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1580,
    1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,
    1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,
    1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,
    1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,  1620,
    1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,
    1631,  1632,  1633,  1634,  1635,  1638,  1639,  1640,  1641,  1643,
    1644,  1645,  1646,  1647
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPEDEF_NAME", "INTEGER",
  "FLOATING", "CHARACTER", "STRING", "WS", "ELLIPSIS", "ADDEQ", "SUBEQ",
  "MULEQ", "DIVEQ", "MODEQ", "XOREQ", "ANDEQ", "OREQ", "SL", "SR", "SLEQ",
  "SREQ", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND", "OROR", "PLUSPLUS",
  "MINUSMINUS", "ARROW", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "ATTRIBUTE", "TYPEOF",
  "ALIGNOF", "ASM", "GCC_BUILTIN_TYPES_COMPATIBLE", "OFFSETOF", "','",
  "';'", "'*'", "'('", "')'", "'{'", "'}'", "'['", "']'", "':'", "'='",
  "'&'", "'+'", "'-'", "'|'", "'/'", "'~'", "'?'", "'^'", "'<'", "'>'",
  "'%'", "'.'", "'!'", "$accept", "primary_expression", "identifier",
  "strings", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "old_function_declaration",
  "declaration", "declaration_specifiers_noattr", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "storage_class_specifier_noattr", "type_specifier",
  "final_type_specifier", "type_modifier_specifier",
  "struct_or_union_specifier", "specifier_qualifier_list",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_specifier_qualifier_list", "tqm", "tms_end",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "declarator",
  "s_declarator", "direct_declarator", "type_extension",
  "s_direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "param_abstract_declarator",
  "param_direct_abstract_declarator", "initializer",
  "struct_period_initializer", "constant_optional_range",
  "initializer_list", "statement", "labeled_statement", "asm_statement",
  "asm_argument", "maybe_asm_operands", "asm_operands", "asm_operand",
  "asm_clobbers", "asm_string_literal", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "start_c", "translation_unit", "external_declaration",
  "function_definition", "comma_t", "semicolon_t", "asterisk_t",
  "left_bracket_t", "right_bracket_t", "left_brace_t", "right_brace_t",
  "left_square_t", "right_square_t", "colon_t", "equals_t", "ampersand_t",
  "plus_t", "minus_t", "or_t", "divide_t", "tilde_t", "question_t",
  "hat_t", "less_than_t", "greater_than_t", "percent_t", "period_t",
  "exclamation_t", "goto_t", "continue_t", "break_t", "return_t", "if_t",
  "switch_t", "else_t", "for_t", "do_t", "while_t", "case_t", "default_t",
  "ellipsis_t", "const_t", "volatile_t", "enum_t", "struct_t", "union_t",
  "void_t", "char_t", "short_t", "int_t", "long_t", "float_t", "double_t",
  "signed_t", "unsigned_t", "typedef_name_t", "typedef_t", "extern_t",
  "static_t", "auto_t", "register_t", "muleq_t", "diveq_t", "modeq_t",
  "addeq_t", "subeq_t", "sleq_t", "sreq_t", "andeq_t", "xoreq_t", "oreq_t",
  "oror_t", "andand_t", "noteq_t", "eq_t", "lteq_t", "gteq_t", "sl_t",
  "sr_t", "plusplus_t", "minusminus_t", "sizeof_t", "arrow_t",
  "identifier_t", "integer_t", "character_t", "floating_t", "string_t",
  "typeof_t", "alignof_t", "offsetof_t", "asm_t",
  "gcc_builtin_types_compat_t", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      44,    59,    42,    40,    41,   123,   125,    91,    93,    58,
      61,    38,    43,    45,   124,    47,   126,    63,    94,    60,
      62,    37,    46,    33
};
# endif

#define YYPACT_NINF -533

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-533)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2244,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,   154,
    2278,  2278,  -533,    44,  -533,  2278,  2210,   323,    19,  -533,
      21,  2244,  -533,  -533,  -533,   410,    77,  -533,  -533,    37,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,   -36,   208,
     166,  -533,  1420,  -533,  -533,  -533,  -533,   -23,   403,   -23,
    -533,  -533,   154,  2278,  2278,  2278,  -533,  2210,  1337,  -533,
    -533,  -533,  -533,  -533,  -533,   217,  1872,   -36,   323,  -533,
    -533,  -533,  -533,   410,   -19,   -23,    55,  1689,   -36,    57,
    -533,    77,  -533,  -533,  -533,  2210,  1790,   403,  -533,   403,
    -533,    83,  1242,    -5,  -533,  -533,   372,   166,    -2,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,     6,    57,   385,  -533,  2158,   676,   218,   173,
     281,   160,   333,    29,    27,    68,   107,    11,  -533,  -533,
     166,  -533,   154,  -533,  -533,  -533,  -533,  1337,  -533,  -533,
    -533,  -533,  -533,  -533,  1605,  -533,  -533,  -533,  -533,  -533,
    -533,    55,    93,    93,  1902,   -36,   -36,   -36,  1521,   -36,
    2158,     6,  2158,  2158,  2158,  -533,  -533,  -533,  -533,   -36,
     -36,   -36,  -533,  -533,    86,   -19,   119,  -533,   126,  -533,
    -533,  -533,  -533,  -533,   129,  -533,    57,  -533,  -533,  -533,
      55,    -2,    61,  -533,   126,  2315,   368,  2315,   -19,    57,
      57,   -19,     6,  -533,  -533,  -533,     6,  -533,  -533,    -2,
    1760,  2158,   369,     6,   403,  -533,  -533,  -533,  -533,  -533,
     166,  -533,     6,   146,   137,  -533,   174,  2158,  -533,    -5,
    1899,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,   -36,  -533,   403,  -533,  1521,  -533,  -533,
    1973,  2158,   369,  -533,  -533,   369,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  2158,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  2158,  2158,  2158,  2158,  2158,  -533,  -533,  2158,  2158,
    -533,  -533,  -533,  -533,  2158,  2158,  2158,  2158,  -533,  -533,
    2158,  2158,  2158,  -533,  2158,  -533,  2158,  -533,  2158,  -533,
    -533,  2003,  2158,  2158,  -533,  -533,  -533,   126,   -19,  1521,
      93,  -533,  -533,   166,  -533,  2087,  2158,  1902,   134,  2158,
     224,     6,  1521,  -533,  2117,  -533,  -533,  1605,  1689,  2315,
    2315,  -533,   140,  -533,   146,   212,  1872,  -533,   388,    55,
    -533,  -533,    54,    61,  2158,    24,  -533,  -533,  -533,   146,
    -533,   146,   761,  1872,  -533,  -533,   -19,    93,    28,  1790,
    1790,  -533,    61,  -533,   129,   167,   167,  1790,  -533,   169,
    -533,  2158,   217,  1872,   146,   -19,  -533,  -533,  1899,  -533,
    1899,  1689,  -533,  -533,   126,  -533,  -533,    96,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,   218,   218,   173,   173,
     281,   281,   281,   281,   160,   160,   333,    29,    27,    68,
      66,  2158,   107,  -533,  -533,  1437,  1337,  -533,  -533,   126,
     -19,   126,   166,  1902,   -36,   126,  -533,  2158,  1521,  -533,
     -19,   126,   -19,   119,   119,   146,   287,  1872,   -19,  -533,
     129,  -533,  -533,  -533,  -533,  -533,    24,  -533,  -533,  -533,
    -533,   146,   287,  1872,   -19,   -19,  -533,   129,  -533,    93,
    -533,     6,   119,  -533,   -36,    55,  -533,  -533,  1760,  -533,
      -2,  -533,  -533,  -533,  -533,  -533,   -19,   126,  -533,   129,
    -533,  -533,  -533,  -533,   126,   -19,  2158,  -533,  -533,  2158,
    -533,  -533,  1760,  -533,   -19,  1521,  1521,  1521,  1902,   166,
    1973,  2158,  1521,  -533,  -533,  -533,  -533,  -533,  2158,  2315,
     -19,  -533,   129,  -533,  -533,  -533,  -533,   -19,  -533,   129,
    -533,  -533,  -533,  -533,  -533,    28,    28,  2158,   129,  -533,
    -533,  2117,  -533,  -533,  -533,  -533,  -533,  -533,  -533,    61,
    -533,  -533,   210,  -533,  -533,   166,  1973,  1973,   126,  1521,
     126,  -533,   126,   -19,  -533,  -533,  -533,  -533,     6,  -533,
     126,    57,  -533,  1790,  1760,  -533,  -533,  1521,  1973,   126,
    1521,   126,  1521,  1521,  -533,    93,  -533,  -533,    57,  -533,
     -36,    61,  -533,  -533,   126,  1521,  1521,  -533,  1521,  -533,
    -533,  -533,   119,  -533,  2158,  1760,  -533,  1521,  -533,  -533,
    -533,    57,   126,  -533,  -533,  -533,  -533
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     323,   414,   386,   390,   378,   372,   383,   374,   388,   382,
     380,   381,   391,   379,   384,   389,   375,   387,   376,   385,
     377,   373,   419,   422,   336,   337,   338,   195,   328,     0,
     104,   106,   130,     0,   131,   108,     0,   192,     0,   329,
       0,   324,   325,   327,   330,   213,     0,   188,   189,     0,
     160,   161,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   132,   113,   114,   115,   116,   190,    12,     0,     0,
       0,   109,   112,    96,   103,   105,   340,   153,   169,   154,
     107,   298,     0,    98,   100,   102,   334,     0,     0,   117,
     118,   119,   120,   342,   202,   169,     0,     0,   191,     1,
     326,   216,   215,   212,     0,   183,     0,     0,     0,     0,
     335,     0,    95,   345,   332,     0,     0,   169,   341,   169,
     162,     0,     0,   169,   166,   151,   169,     0,   112,    94,
      97,    99,   101,   299,   333,   415,   417,   416,   418,   410,
     411,   361,   369,   360,   370,   367,   366,   359,   363,   362,
     412,   364,   368,   420,   423,   421,   346,   347,   348,   351,
     358,    15,     2,     7,    27,    40,     0,    46,    50,    53,
      56,    61,    64,    66,    68,    70,    72,    74,    77,    90,
       0,   277,     0,   300,   270,   271,   272,     0,   273,   274,
     275,   276,   302,    35,     0,   296,    34,    36,    37,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,    13,     0,
       0,     0,   339,   225,   224,     0,   218,   220,     0,   201,
     343,     2,    46,    92,     0,   198,     0,   217,   214,   196,
       0,   186,     0,   184,     0,   157,   227,   159,     0,     0,
     295,     0,   283,   110,   331,   357,     2,   252,   111,     0,
       0,     0,     0,     0,   169,   152,   163,   150,   344,   204,
       0,   174,   176,   194,     0,   165,     0,     0,   205,   169,
     171,   135,   136,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   137,     0,   170,   169,    93,     0,    14,   413,
       0,     0,     0,    23,    24,     0,    30,   395,   396,   392,
     393,   394,   400,   399,   401,   397,   398,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   350,
     356,     0,     0,     0,     0,     0,   408,   409,     0,     0,
     406,   407,   354,   355,     0,     0,     0,     0,   405,   404,
       0,     0,     0,   353,     0,   349,     0,   403,     0,   402,
     352,     0,     0,     0,   303,   301,   297,     0,     0,     0,
       0,   319,   320,     0,   321,     0,     0,     0,     0,     0,
     266,     0,     0,    28,     0,    29,    31,     0,     0,     0,
       0,   222,   241,   223,   242,     0,     0,   199,   169,     0,
     200,   197,     0,     0,     0,     0,   180,   133,   156,   229,
     228,   230,   169,     0,   158,   134,     0,     0,   287,     0,
       0,   268,     0,   255,     0,   262,   263,     0,   149,     0,
     164,     0,   169,     0,   193,     0,   177,   167,   171,   168,
     171,     0,   155,   278,     0,    25,    18,     0,    19,    20,
      21,    22,    78,    47,    48,    49,    51,    52,    54,    55,
      57,    58,    59,    60,    63,    62,    65,    67,    69,    71,
       0,     0,    73,    91,     8,     0,     0,   318,   322,     0,
       0,     0,     0,     0,     0,     0,   371,     0,     0,   280,
       0,     0,     0,     0,     0,   243,   169,     0,     0,   249,
       0,   245,   221,   219,   226,   203,     0,   179,   187,   185,
     182,   231,   169,     0,     0,     0,   237,     0,   233,     0,
     281,   284,   288,   289,     0,     0,   257,   256,     0,   253,
       0,   264,   265,   258,   175,   178,     0,     0,   211,     0,
     208,   206,   173,   172,     0,     0,     0,    17,    16,     0,
      76,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,   279,    32,    10,     9,     0,     0,
       0,   250,     0,   247,   244,   246,   181,     0,   239,     0,
     235,   238,   232,   234,   282,   287,     0,     0,     0,   269,
     254,     0,   209,   210,   207,   147,   148,    26,    75,     0,
      45,     3,   304,   307,   306,     0,     0,     0,     0,     0,
       0,   308,     0,     0,   251,   248,   240,   236,   285,   290,
       0,     0,   259,     0,     0,    43,   365,     0,     0,     0,
       0,     0,     0,     0,   310,     0,    11,    33,     0,   291,
       0,     0,    44,   305,     0,     0,     0,   311,     0,   312,
     314,   309,   286,   293,     0,     0,   260,     0,   313,   315,
     316,     0,     0,   261,   317,   294,   292
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -533,  -533,     0,  -101,  -533,  -533,    59,  -533,   744,   135,
     159,   156,   157,   -91,   -90,   -81,   -46,   -43,  -533,   238,
     -65,  -533,   443,   377,   -55,    43,  -533,    42,   234,   155,
    -533,  -533,   296,  -533,   202,   204,   -66,  -533,    50,  -104,
     -94,  -111,  -208,  -533,  -215,   214,    90,  -389,   921,   299,
    -272,   301,  -533,  -260,   476,  -533,  -388,  -533,   -40,   -56,
    -184,   -32,   -25,   -29,     5,   -60,    79,   145,  -532,   597,
    -533,   153,   164,  -168,  -533,  -156,  -533,   -98,   -18,   361,
      73,  -533,  -533,  -533,  -533,  -533,  -533,   394,  -533,   184,
     161,  1092,   101,   363,    17,   340,   540,   775,  -143,  -160,
    -171,  -166,  -164,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,   283,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,    88,  -533,  -533,    53,  -533,  -533,  -533,  -533,
    -533,  -109,  -105,   -96,   -92,   -88,   -87,   -59,   -52,   -51,
     147,   -13,   -11,    -8,    31,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,   291,   297,  -533,  -533,  -533,  -533,
    -533,  -533,  -157,   -47,  -533,  -533,    16,  -533
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   161,   231,   163,   164,   444,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   317,   180,   380,    81,   181,    82,   182,    70,    71,
      30,    83,    31,   279,   438,    32,   246,    33,   119,   120,
     121,   122,   439,   270,   271,    34,   242,   243,    35,   128,
     272,    37,    94,   273,    38,   103,   225,   226,   227,   228,
     248,   410,   411,   393,   394,   421,   259,   381,   422,   183,
     184,   185,   251,   521,   522,   523,   652,   524,   186,    87,
     187,   188,   189,   190,   191,    40,    41,    42,    43,   363,
     192,   193,   194,   229,    88,   125,   261,   235,   277,   116,
     196,   197,   198,   356,   332,   199,   361,   354,   344,   345,
     333,   262,   200,   201,   202,   203,   204,   205,   206,   627,
     207,   208,   209,   210,   211,   487,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   362,   358,   350,   351,
     346,   347,   338,   339,   212,   213,   214,   305,    67,   215,
     216,   217,   218,    68,   219,   220,    69,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      27,   224,   352,   334,   435,   335,   298,   318,   250,   391,
     368,   252,   294,   283,   434,   266,   509,   284,    86,   297,
     599,    99,     1,    89,   514,    90,   285,     1,    91,    27,
     286,     5,   133,    77,   287,   288,   138,    26,    27,   359,
       1,    27,    29,    28,   536,    12,    27,     1,     2,   105,
      78,   257,    76,    97,   114,   222,   258,    21,     1,    89,
     133,    90,   138,   289,    91,   138,   106,    92,   382,   134,
     290,   291,    74,    75,    89,   293,    90,    80,   113,    91,
       1,   404,    27,    29,    28,   268,     1,     2,   162,     1,
       2,   641,    26,   298,   117,   223,   126,   254,   360,   420,
     118,    46,    89,    92,    90,    93,   241,    91,   570,   418,
     156,    27,    76,   419,    97,   353,   256,   509,    92,    76,
     427,   269,   240,   435,   577,   130,   131,   132,   222,   431,
      46,   110,   434,   260,   357,   402,   110,   118,    95,    46,
       1,     2,    46,     1,     2,   268,    92,    46,   250,    25,
      26,   252,   355,    39,    24,    25,    26,     1,    25,    26,
     266,    44,   268,    93,    24,   268,   110,   264,   437,   107,
     109,   283,     1,     2,   230,   284,   295,     1,     2,   408,
      79,   414,    27,    46,   285,   340,   341,   162,   286,   110,
      73,   266,   287,   288,    39,   257,   110,   152,   236,    95,
     222,   370,    44,   490,   492,   493,   494,   230,   162,   249,
      26,   369,    46,    26,   534,     1,     2,    93,   471,    26,
       1,   289,   276,    93,   269,    24,    25,    26,   290,   291,
     542,   112,   543,   293,   486,   445,   110,    24,   488,   124,
     241,    25,    26,   129,     5,   298,    25,    26,   268,   342,
     343,   626,   452,     5,   111,   157,   158,   545,    12,   255,
     256,   466,   425,   263,   467,   300,   253,    12,   278,   292,
      21,   383,   385,   386,   269,   468,   269,   260,   124,    21,
     124,    26,   275,    46,    25,    26,   222,   124,   296,    93,
      25,   222,   334,   334,   335,   335,   352,   162,   473,    36,
     336,   337,   448,   329,   224,   450,   375,   376,   377,   330,
     379,   111,   469,   384,   384,   387,   127,   250,   224,   472,
     388,   389,   390,     5,   280,   395,   281,   549,    72,   283,
     403,   283,    84,   284,   233,   284,   282,    12,   224,    98,
      36,   364,   285,    73,   285,   104,   286,   412,   286,    21,
     287,   288,   287,   288,   257,   257,   348,   349,   502,   526,
     527,   222,   257,   371,   372,   374,   498,   533,    84,   162,
     591,   278,     1,     2,   432,   276,   537,   276,   585,   289,
     515,   289,   162,    84,   511,   613,   290,   291,   290,   291,
      23,   293,   269,   293,   441,   269,    26,   495,   486,   504,
      93,   369,   224,   245,   369,   241,   424,   263,     5,   426,
     398,    84,   399,   416,   139,   140,   299,   618,   224,   256,
     256,   278,    12,   278,     5,   124,   405,   256,   195,   269,
     619,   430,   223,   115,    21,   100,   260,   260,    12,     5,
      25,    26,   476,    24,   260,    93,     5,   302,   233,   449,
      21,   503,   451,    12,   429,   303,   124,   265,    26,   267,
      12,   304,    93,   257,     0,    21,   484,   239,   589,   456,
     457,     0,    21,   234,    24,   638,   162,   255,     0,   118,
       0,   597,    25,     0,   250,   250,     0,   257,   162,     0,
     245,     0,   552,   395,     0,   496,   395,   458,   459,   233,
     460,   461,   462,   463,   531,   532,   241,   464,   465,     0,
     412,     0,   512,   412,     0,   233,     0,     0,     0,     0,
     250,   102,   480,   640,     0,   588,     0,   366,   256,     0,
     276,   477,     0,     0,   478,   432,     0,   250,   483,   278,
     653,   245,   278,   245,     0,   260,     0,     0,     0,     0,
     244,     0,   256,     0,     0,   162,   162,   162,   257,   257,
     250,     0,   162,   665,   589,     0,   263,   263,     0,   260,
       0,     0,     0,     0,   263,     0,   278,    96,   520,   238,
       0,     0,   406,     0,     0,   561,     0,   506,   397,     0,
     257,   400,     0,     0,     0,   589,   496,   274,     0,     0,
     423,     0,     0,     0,   428,     0,   528,   407,   623,   162,
       0,   415,   512,     0,   417,     0,     0,     0,     0,     0,
       0,     0,   553,   256,   256,   587,     0,   162,   546,     0,
     162,     0,   162,   162,   233,   442,     0,   367,    96,     0,
     260,   260,   233,   558,   560,   162,   162,   373,   162,     0,
       0,   233,     0,     0,   436,   256,     0,   162,     0,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,   233,
       0,   233,   260,     0,     0,   263,     0,   568,   569,     0,
     584,     0,     0,   245,   245,   245,   245,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,   315,   316,   263,
     392,     0,     0,     0,   301,     0,   586,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   606,
     607,   399,   409,     0,     0,   233,     0,     0,     0,     0,
     474,   475,     0,     0,     0,   233,     0,   245,     0,     0,
       0,   654,     0,   507,   447,   510,     0,     0,     0,     0,
       0,   233,   274,     0,     0,     0,   113,     0,   499,     0,
       0,     0,   529,     0,   396,   505,   628,     0,     0,     0,
     263,   263,     0,   500,     0,   516,     0,     0,     0,   519,
       0,   508,     0,   624,   365,     0,   413,   598,     0,     0,
     517,     0,     0,     0,     0,   538,   651,     5,   541,     0,
       0,     0,   263,     0,   470,   378,     0,   547,   535,     0,
     539,    12,     0,   433,     0,     0,   554,     0,   479,   481,
     482,     0,   485,    21,     0,   655,     0,   367,     0,   233,
     367,   491,     0,    25,    26,   222,   661,     0,    93,     0,
     232,     0,   555,   556,   557,     0,   576,     0,   562,     0,
       0,     0,     0,   565,   566,   567,     0,     0,     0,   571,
       0,   574,     0,     0,   563,   245,     0,     0,   590,     0,
       0,   392,     0,     0,   572,   578,     0,   581,   582,     0,
       0,     0,     0,     0,   544,     0,     0,     0,   409,     0,
     579,     0,   600,     0,   443,     0,     0,     0,     0,   592,
     593,     0,     0,     0,     0,   274,     0,   595,   596,     0,
     306,     0,     0,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,   609,     0,     0,   559,     0,     0,     0,
       0,     0,   396,   614,   497,   396,     0,     0,     0,   625,
     616,     0,     0,     0,     0,     0,     0,     0,     0,   413,
       0,   513,   413,     0,   232,     0,     0,    85,   525,     0,
       0,     0,     0,     0,   642,     0,   101,     0,   622,   630,
     632,   633,     0,   635,   433,   636,   637,     0,     0,   489,
       0,   656,     0,   639,     0,     0,     0,     0,     0,     0,
     108,   645,   646,    85,   648,   663,     0,     0,     0,   123,
       0,   605,     0,   608,   610,   232,     0,   657,    85,   401,
       0,   612,     0,     0,     0,     0,   123,     0,     0,     0,
       0,   232,     0,     0,   237,   666,     0,     0,   247,     0,
     620,     0,     0,     0,     0,   497,    85,     0,   123,     0,
     123,     0,     0,     0,   123,     0,     0,   123,     0,   629,
     631,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   644,     0,   365,     0,   453,   454,   455,   232,   232,
       0,     0,   232,   232,     0,   564,     0,     0,   232,   232,
     232,   232,    45,     0,   232,   232,   232,   662,   232,     0,
     232,     0,   232,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,     0,
       0,    45,     0,     0,     0,   525,   525,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,    45,    45,     0,
     232,     0,     0,     0,     0,     0,     0,     0,   232,     0,
       0,     0,   602,   603,   604,     0,     0,   232,     0,   611,
       0,     0,     0,     0,     0,     0,   247,     0,   247,     0,
       0,   501,     0,     0,    45,   232,     0,   232,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,   518,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,   530,
     123,   440,     0,    45,     0,     0,   634,     0,   540,     0,
       0,     0,     0,    45,     0,   232,   123,     0,     0,   551,
       0,     0,   548,     0,   643,     0,     0,   647,     0,   649,
     650,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   658,   659,     0,   660,     2,     0,     0,     0,
       0,     0,     0,     0,   664,     0,     0,   232,     0,     0,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   573,     0,    45,   575,     0,     4,     0,     0,
       0,     0,     6,     0,     7,     0,     9,     0,   580,     0,
      10,    11,   583,   232,    13,    14,     0,     0,    16,     0,
       0,    18,    19,    20,     0,     0,     0,    22,   247,   247,
     247,   247,     0,     0,   594,     0,    45,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,   232,     0,     0,    45,     0,
       1,     2,   135,   136,   137,   138,     0,   615,     0,     0,
       0,     0,     0,   123,   617,     0,     0,     0,     0,   440,
       0,   440,   247,   621,     0,     0,   139,   140,    45,     3,
     141,   142,     4,     5,   143,   144,   145,     6,     0,     7,
       8,     9,   146,   147,   148,    10,    11,    12,   149,    13,
      14,   150,    15,    16,   151,    17,    18,    19,    20,    21,
     152,     0,    22,   153,    23,   154,   155,     0,    24,    25,
      26,     0,    76,   118,     0,     0,     0,   123,   156,   157,
     158,     0,     0,   159,     2,     0,     0,     0,     0,     0,
     160,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       1,     2,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     7,     8,     9,     0,   139,   140,    10,    11,
      12,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     0,     0,    22,     0,    45,     0,     0,
     247,   150,     0,     0,     0,    76,     0,     0,     0,     0,
     113,     0,     0,   153,    45,   154,   155,     0,     0,    25,
      26,     0,    76,     0,     0,     0,     0,     0,   156,   157,
     158,    45,     0,   159,     1,     2,   135,   136,   137,   138,
     160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   331,
     139,   140,     0,     3,   141,   142,     4,     5,   143,   144,
     145,     6,     0,     7,     8,     9,   146,   147,   148,    10,
      11,    12,   149,    13,    14,   150,    15,    16,   151,    17,
      18,    19,    20,    21,   152,     0,    22,   153,    23,   154,
     155,     0,    24,    25,    26,     0,    76,     0,     0,     0,
       0,     0,   156,   157,   158,     0,     0,   159,     1,     2,
     135,   136,   137,   138,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   140,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     7,     0,     9,
       0,     0,     0,    10,    11,    12,     0,    13,    14,   150,
       0,    16,     0,     0,    18,    19,    20,    21,     0,     0,
      22,   153,     0,   154,   155,     0,     0,    25,    26,     0,
      76,     0,     0,     0,     0,     0,   156,   157,   158,     0,
       0,   159,     1,     2,   135,   136,   137,   138,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     6,
       0,     7,     0,     9,     0,     0,     0,    10,    11,    12,
       0,    13,    14,   150,     0,    16,     0,     0,    18,    19,
      20,    21,     0,     0,    22,   153,     0,   154,   155,     0,
       0,    25,    26,     1,     2,   135,   136,   137,   138,     0,
     156,   157,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,   160,     0,     0,     0,     0,     0,     0,   139,
     140,     0,     0,     1,     2,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,     0,     0,     0,     0,   139,
     140,     0,     0,     0,     0,     0,   153,     0,   154,   155,
       0,     0,    25,    26,     0,    76,   118,    93,     0,     0,
       0,   156,   157,   158,   150,     0,   159,     0,     0,     0,
       0,     0,   255,   160,     0,     0,   153,     0,   154,   155,
       0,     0,    25,    26,     0,    76,     0,    93,     0,     0,
       0,   156,   157,   158,     0,     1,   159,   135,   136,   137,
     138,     0,   255,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,   140,     0,     0,     1,     0,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
       0,   139,   140,     0,     4,     5,     0,     0,   153,     6,
     154,   155,     0,     9,    25,    26,     0,    10,    11,    12,
     230,    13,    14,   156,   157,   158,   150,     0,   159,    19,
      20,    21,     0,     0,    22,   160,     0,     0,   153,     0,
     154,   155,     0,    24,    25,    26,     1,     0,   135,   136,
     137,   138,     0,   156,   157,   158,     0,     0,   159,     0,
       0,     0,     0,     0,     0,   160,     0,     0,     0,     0,
       0,     0,   139,   140,     0,     0,     1,     0,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,     0,     0,
       0,     0,   139,   140,     0,     0,     0,     0,     0,   153,
       0,   154,   155,     0,     0,    25,    26,   222,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   150,     0,   159,
       0,     0,     0,     0,     0,     0,   160,     0,     0,   153,
       0,   154,   155,     0,     0,    25,    26,     0,     0,     0,
       0,     0,   268,     0,   156,   157,   158,     0,     0,   159,
       1,     2,   135,   136,   137,   138,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       1,     0,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,   139,   140,     0,     0,
       0,     0,     0,   153,     0,   154,   155,     0,     0,    25,
      26,     1,     0,   135,   136,   137,   138,     0,   156,   157,
     158,   150,     0,   159,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   153,     0,   154,   155,   139,   140,    25,
      26,     0,    76,     0,     0,     0,     0,     0,   156,   157,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
     160,     0,   150,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,   154,   155,     0,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,   156,
     157,   158,     3,     0,   159,     4,     5,     1,     2,     0,
       6,   160,     7,     8,     9,     0,     0,     0,    10,    11,
      12,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     0,     0,    22,     3,     0,     0,     4,
       5,     0,     2,     0,     6,    76,     7,     8,     9,     0,
       0,     0,    10,    11,    12,     0,    13,    14,     0,    15,
      16,     0,    17,    18,    19,    20,    21,     0,     0,    22,
       3,    23,     0,     4,     5,    24,    25,    26,     6,     2,
       7,     8,     9,     0,     0,     0,    10,    11,    12,     0,
      13,    14,     0,    15,    16,     0,    17,    18,    19,    20,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     7,     0,     9,
       0,     0,     0,    10,    11,    12,     0,    13,    14,     0,
       0,    16,     0,     0,    18,    19,    20,    21,     0,     0,
      22
};

static const yytype_int16 yycheck[] =
{
       0,    95,   173,   169,   276,   169,   163,   167,   109,   224,
     194,   109,   123,   122,   274,   119,   405,   122,    36,   162,
     552,     0,     3,    36,   412,    36,   122,     3,    36,    29,
     122,    36,    87,    33,   122,   122,     8,    73,    38,    28,
       3,    41,     0,     0,   432,    50,    46,     3,     4,    49,
      33,   116,    75,    37,    72,    74,   116,    62,     3,    72,
     115,    72,     8,   122,    72,     8,    49,    36,   211,    87,
     122,   122,    30,    31,    87,   122,    87,    35,    80,    87,
       3,   241,    82,    41,    41,    79,     3,     4,    88,     3,
       4,   623,    73,   250,    77,    95,    79,   115,    87,   259,
      76,     0,   115,    72,   115,    77,   106,   115,   496,   252,
      81,   111,    75,   256,    98,    88,   116,   506,    87,    75,
     263,   121,   105,   395,   512,    83,    84,    85,    74,   272,
      29,    70,   392,   116,    27,   236,    70,    76,    37,    38,
       3,     4,    41,     3,     4,    79,   115,    46,   249,    72,
      73,   249,    84,     0,    71,    72,    73,     3,    72,    73,
     264,     0,    79,    77,    71,    79,    70,   117,   279,    68,
      69,   280,     3,     4,    78,   280,   126,     3,     4,   245,
      33,   247,   182,    82,   280,    25,    26,   187,   280,    70,
      29,   295,   280,   280,    41,   260,    70,    63,    97,    98,
      74,   201,    41,   387,   388,   389,   390,    78,   208,   108,
      73,   194,   111,    73,   429,     3,     4,    77,   361,    73,
       3,   280,   121,    77,   224,    71,    72,    73,   280,   280,
     438,    70,   440,   280,    10,   300,    70,    71,   381,    78,
     240,    72,    73,    82,    36,   402,    72,    73,    79,    89,
      90,    41,   317,    36,    70,    82,    83,   441,    50,    92,
     260,   352,   262,   116,   354,   164,   111,    50,   121,   122,
      62,   212,   213,   214,   274,   356,   276,   260,   117,    62,
     119,    73,   121,   182,    72,    73,    74,   126,   127,    77,
      72,    74,   458,   459,   458,   459,   467,   297,   363,     0,
      19,    20,   302,    85,   398,   305,   205,   206,   207,    91,
     209,   127,   358,   212,   213,   214,    82,   418,   412,   362,
     219,   220,   221,    36,   122,   224,   122,   470,    29,   438,
     240,   440,    36,   438,    96,   440,   122,    50,   432,    38,
      41,   180,   438,   182,   440,    46,   438,   246,   440,    62,
     438,   438,   440,   440,   419,   420,    23,    24,   398,   419,
     420,    74,   427,   202,   203,   204,   395,   427,    72,   369,
     530,   224,     3,     4,   273,   274,   432,   276,   521,   438,
     412,   440,   382,    87,   409,   569,   438,   438,   440,   440,
      67,   438,   392,   440,   293,   395,    73,   392,    10,   399,
      77,   384,   496,   107,   387,   405,   261,   260,    36,   262,
     226,   115,   228,   249,    29,    30,    31,   585,   512,   419,
     420,   274,    50,   276,    36,   264,   242,   427,    88,   429,
     586,   270,   432,    72,    62,    41,   419,   420,    50,    36,
      72,    73,   369,    71,   427,    77,    36,   164,   210,   302,
      62,   398,   305,    50,   270,   164,   295,   117,    73,   119,
      50,   164,    77,   528,    -1,    62,   378,   104,   528,   334,
     335,    -1,    62,    96,    71,   618,   476,    92,    -1,    76,
      -1,   546,    72,    -1,   585,   586,    -1,   552,   488,    -1,
     194,    -1,   475,   392,    -1,   394,   395,   338,   339,   261,
     344,   345,   346,   347,   425,   426,   506,   350,   351,    -1,
     409,    -1,   411,   412,    -1,   277,    -1,    -1,    -1,    -1,
     621,    45,   375,   621,    -1,   525,    -1,   187,   528,    -1,
     429,   370,    -1,    -1,   373,   434,    -1,   638,   377,   392,
     638,   245,   395,   247,    -1,   528,    -1,    -1,    -1,    -1,
     107,    -1,   552,    -1,    -1,   555,   556,   557,   623,   624,
     661,    -1,   562,   661,   624,    -1,   419,   420,    -1,   552,
      -1,    -1,    -1,    -1,   427,    -1,   429,    37,   417,   103,
      -1,    -1,   242,    -1,    -1,   484,    -1,   403,   225,    -1,
     655,   228,    -1,    -1,    -1,   655,   495,   121,    -1,    -1,
     260,    -1,    -1,    -1,   264,    -1,   422,   244,   591,   609,
      -1,   248,   511,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,   623,   624,   524,    -1,   627,   444,    -1,
     630,    -1,   632,   633,   396,   295,    -1,   194,    98,    -1,
     623,   624,   404,   482,   483,   645,   646,   204,   648,    -1,
      -1,   413,    -1,    -1,   277,   655,    -1,   657,    -1,    -1,
      -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,   431,
      -1,   433,   655,    -1,    -1,   528,    -1,   493,   494,    -1,
     519,    -1,    -1,   387,   388,   389,   390,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,   552,
     224,    -1,    -1,    -1,   164,    -1,   522,    -1,    -1,   471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   558,
     559,   537,   246,    -1,    -1,   487,    -1,    -1,    -1,    -1,
     367,   368,    -1,    -1,    -1,   497,    -1,   441,    -1,    -1,
      -1,   640,    -1,   403,   301,   405,    -1,    -1,    -1,    -1,
      -1,   513,   276,    -1,    -1,    -1,    80,    -1,   395,    -1,
      -1,    -1,   422,    -1,   224,   402,   605,    -1,    -1,    -1,
     623,   624,    -1,   396,    -1,   412,    -1,    -1,    -1,   416,
      -1,   404,    -1,   599,   187,    -1,   246,   549,    -1,    -1,
     413,    -1,    -1,    -1,    -1,   432,   635,    36,   435,    -1,
      -1,    -1,   655,    -1,   361,   208,    -1,   444,   431,    -1,
     433,    50,    -1,   273,    -1,    -1,   476,    -1,   375,   376,
     377,    -1,   379,    62,    -1,   641,    -1,   384,    -1,   591,
     387,   388,    -1,    72,    73,    74,   652,    -1,    77,    -1,
      96,    -1,   479,   480,   481,    -1,   506,    -1,   485,    -1,
      -1,    -1,    -1,   490,   491,   492,    -1,    -1,    -1,   496,
      -1,   498,    -1,    -1,   487,   569,    -1,    -1,   528,    -1,
      -1,   395,    -1,    -1,   497,   512,    -1,   514,   515,    -1,
      -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,   412,    -1,
     513,    -1,   552,    -1,   297,    -1,    -1,    -1,    -1,   536,
     537,    -1,    -1,    -1,    -1,   429,    -1,   544,   545,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,
      -1,    -1,    -1,   560,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,   392,   570,   394,   395,    -1,    -1,    -1,   599,
     577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
      -1,   411,   412,    -1,   210,    -1,    -1,    36,   418,    -1,
      -1,    -1,    -1,    -1,   624,    -1,    45,    -1,   591,   606,
     607,   608,    -1,   610,   434,   612,   613,    -1,    -1,   382,
      -1,   641,    -1,   620,    -1,    -1,    -1,    -1,    -1,    -1,
      69,   628,   629,    72,   631,   655,    -1,    -1,    -1,    78,
      -1,   558,    -1,   560,   561,   261,    -1,   644,    87,   234,
      -1,   568,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,   277,    -1,    -1,   103,   662,    -1,    -1,   107,    -1,
     587,    -1,    -1,    -1,    -1,   495,   115,    -1,   117,    -1,
     119,    -1,    -1,    -1,   123,    -1,    -1,   126,    -1,   606,
     607,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   628,    -1,   476,    -1,   331,   332,   333,   334,   335,
      -1,    -1,   338,   339,    -1,   488,    -1,    -1,   344,   345,
     346,   347,     0,    -1,   350,   351,   352,   654,   354,    -1,
     356,    -1,   358,    -1,    -1,    -1,   362,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,   585,   586,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,    -1,
      -1,    -1,   555,   556,   557,    -1,    -1,   413,    -1,   562,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,   247,    -1,
      -1,   396,    -1,    -1,    82,   431,    -1,   433,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,   413,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,   424,
     279,   280,    -1,   111,    -1,    -1,   609,    -1,   433,    -1,
      -1,    -1,    -1,   121,    -1,   471,   295,    -1,    -1,   475,
      -1,    -1,   447,    -1,   627,    -1,    -1,   630,    -1,   632,
     633,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   645,   646,    -1,   648,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   657,    -1,    -1,   513,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   497,    -1,   182,   500,    -1,    35,    -1,    -1,
      -1,    -1,    40,    -1,    42,    -1,    44,    -1,   513,    -1,
      48,    49,   517,   549,    52,    53,    -1,    -1,    56,    -1,
      -1,    59,    60,    61,    -1,    -1,    -1,    65,   387,   388,
     389,   390,    -1,    -1,   539,    -1,   224,    -1,    -1,   398,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   412,    -1,   591,    -1,    -1,   246,    -1,
       3,     4,     5,     6,     7,     8,    -1,   572,    -1,    -1,
      -1,    -1,    -1,   432,   579,    -1,    -1,    -1,    -1,   438,
      -1,   440,   441,   588,    -1,    -1,    29,    30,   276,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,    75,    76,    -1,    -1,    -1,   496,    81,    82,
      83,    -1,    -1,    86,     4,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    -1,    29,    30,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    58,    59,
      60,    61,    62,    -1,    -1,    65,    -1,   395,    -1,    -1,
     569,    54,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    66,   412,    68,    69,    -1,    -1,    72,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,   429,    -1,    86,     3,     4,     5,     6,     7,     8,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,   457,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    86,     3,     4,
       5,     6,     7,     8,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    48,    49,    50,    -1,    52,    53,    54,
      -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      65,    66,    -1,    68,    69,    -1,    -1,    72,    73,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    86,     3,     4,     5,     6,     7,     8,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      -1,    52,    53,    54,    -1,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    65,    66,    -1,    68,    69,    -1,
      -1,    72,    73,     3,     4,     5,     6,     7,     8,    -1,
      81,    82,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      -1,    -1,    72,    73,    -1,    75,    76,    77,    -1,    -1,
      -1,    81,    82,    83,    54,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    66,    -1,    68,    69,
      -1,    -1,    72,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    81,    82,    83,    -1,     3,    86,     5,     6,     7,
       8,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,     3,    -1,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    29,    30,    -1,    35,    36,    -1,    -1,    66,    40,
      68,    69,    -1,    44,    72,    73,    -1,    48,    49,    50,
      78,    52,    53,    81,    82,    83,    54,    -1,    86,    60,
      61,    62,    -1,    -1,    65,    93,    -1,    -1,    66,    -1,
      68,    69,    -1,    71,    72,    73,     3,    -1,     5,     6,
       7,     8,    -1,    81,    82,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,     3,    -1,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    68,    69,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    54,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    66,
      -1,    68,    69,    -1,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    -1,    -1,    86,
       3,     4,     5,     6,     7,     8,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
       3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    68,    69,    -1,    -1,    72,
      73,     3,    -1,     5,     6,     7,     8,    -1,    81,    82,
      83,    54,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    66,    -1,    68,    69,    29,    30,    72,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    54,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    32,    -1,    86,    35,    36,     3,     4,    -1,
      40,    93,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    58,    59,
      60,    61,    62,    -1,    -1,    65,    32,    -1,    -1,    35,
      36,    -1,     4,    -1,    40,    75,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    -1,    -1,    65,
      32,    67,    -1,    35,    36,    71,    72,    73,    40,     4,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    58,    59,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    48,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,    32,    35,    36,    40,    42,    43,    44,
      48,    49,    50,    52,    53,    55,    56,    58,    59,    60,
      61,    62,    65,    67,    71,    72,    73,    96,   119,   121,
     124,   126,   129,   131,   139,   142,   143,   145,   148,   165,
     179,   180,   181,   182,   184,   185,   186,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   262,   267,   270,
     122,   123,   143,   184,   121,   121,    75,    96,   188,   234,
     121,   118,   120,   125,   126,   142,   172,   173,   188,   235,
     236,   237,   238,    77,   146,   186,   190,   270,   145,     0,
     181,   142,   148,   149,   143,    96,   188,   186,   142,   186,
      70,   183,   184,    80,   172,   173,   193,   188,    76,   132,
     133,   134,   135,   142,   184,   189,   188,   122,   143,   184,
     121,   121,   121,   118,   172,     5,     6,     7,     8,    29,
      30,    33,    34,    37,    38,    39,    45,    46,    47,    51,
      54,    57,    63,    66,    68,    69,    81,    82,    83,    86,
      93,    95,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   119,   121,   163,   164,   165,   172,   174,   175,   176,
     177,   178,   184,   185,   186,   189,   194,   195,   196,   199,
     206,   207,   208,   209,   210,   211,   212,   214,   215,   216,
     217,   218,   258,   259,   260,   263,   264,   265,   266,   268,
     269,   271,    74,    96,   134,   150,   151,   152,   153,   187,
      78,    96,   102,   113,   117,   191,   186,   142,   148,   187,
     188,    96,   140,   141,   116,   126,   130,   142,   154,   186,
      97,   166,   171,   123,   172,    92,    96,   114,   159,   160,
     188,   190,   205,   234,   132,   189,   133,   189,    79,    96,
     137,   138,   144,   147,   148,   184,   186,   192,   234,   127,
     128,   129,   139,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   267,   135,   132,   184,   192,   266,    31,
     186,   190,   205,   258,   259,   261,   102,    11,    12,    13,
      14,    15,    16,    17,    18,    21,    22,   115,   193,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    85,
      91,   185,   198,   204,   195,   196,    19,    20,   256,   257,
      25,    26,    89,    90,   202,   203,   254,   255,    23,    24,
     252,   253,   194,    88,   201,    84,   197,    27,   251,    28,
      87,   200,   250,   183,   184,   163,   189,   116,   154,   188,
      96,   184,   184,   116,   184,   186,   186,   186,   163,   186,
     117,   161,   192,   100,   186,   100,   100,   186,   186,   186,
     186,   138,   148,   157,   158,   186,   190,   187,   183,   183,
     187,   191,    97,   140,   193,   183,   189,   187,   130,   148,
     155,   156,   186,   190,   130,   187,   166,   187,   192,   192,
     193,   159,   162,   189,   161,    96,   234,   192,   189,   183,
     184,   192,   186,   190,   147,   144,   117,   135,   128,   136,
     142,   186,   189,   163,    99,   114,   187,   116,    96,   234,
      96,   234,   114,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   105,   106,   106,   107,   108,   109,   110,
     116,   192,   111,   114,   187,   187,   174,   184,   184,   116,
     234,   116,   116,   184,   216,   116,    10,   219,   192,   163,
     154,   116,   154,   154,   154,   158,   186,   190,   157,   187,
     117,   191,   152,   219,    96,   187,   183,   189,   117,   141,
     189,   156,   186,   190,   150,   155,   187,   117,   191,   187,
     184,   167,   168,   169,   171,   190,   159,   159,   183,   189,
     191,   160,   160,   159,   138,   117,   150,   153,   187,   117,
     191,   187,   136,   136,   116,   154,   183,   187,   191,   192,
     113,   102,   188,   234,   189,   187,   187,   187,   184,   116,
     184,   186,   187,   117,   163,   187,   187,   187,   183,   183,
     150,   187,   117,   191,   187,   191,   189,   150,   187,   117,
     191,   187,   187,   191,   184,   192,   183,   186,    96,   159,
     189,   193,   187,   187,   191,   187,   187,   114,   113,   162,
     189,   187,   163,   163,   163,   116,   184,   184,   116,   187,
     116,   163,   116,   154,   187,   191,   187,   191,   167,   169,
     116,   191,   117,   188,   183,   189,    41,   213,   184,   116,
     187,   116,   187,   187,   163,   187,   187,   187,   192,   187,
     171,   162,   189,   163,   116,   187,   187,   163,   187,   163,
     163,   184,   170,   171,   186,   183,   189,   187,   163,   163,
     163,   183,   116,   189,   163,   171,   187
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   101,   101,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   125,   125,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   143,   143,   144,   144,   145,   145,   145,   145,   145,
     145,   145,   145,   146,   147,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   153,   153,   154,   154,   155,
     155,   155,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   157,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   162,   162,
     163,   163,   163,   163,   163,   163,   163,   163,   164,   164,
     164,   165,   165,   166,   166,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   176,   176,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   178,   178,
     178,   178,   178,   179,   179,   180,   180,   181,   181,   181,
     181,   182,   182,   182,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     1,     1,     1,     1,     3,     4,
       4,     6,     1,     1,     2,     1,     4,     4,     3,     3,
       3,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     6,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     6,     7,     5,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     2,     3,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     5,
       4,     3,     4,     2,     2,     5,     2,     1,     2,     1,
       1,     1,     1,     2,     3,     2,     1,     3,     3,     0,
       2,     0,     2,     2,     1,     3,     1,     2,     3,     5,
       4,     6,     5,     2,     1,     3,     1,     3,     1,     1,
       1,     2,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     2,     4,     1,     1,     3,     4,     3,     4,
       4,     3,     2,     1,     3,     2,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     4,     1,     3,     4,     2,     3,     3,     3,     5,
       7,     8,     2,     2,     3,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     5,     6,     1,     3,     5,     7,     0,     1,     1,
       3,     4,     7,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     5,     7,
       6,     7,     7,     8,     7,     8,     8,     9,     3,     2,
       2,     2,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     4,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
        case 3:
#line 91 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
    }
#line 2196 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2202 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 100 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2210 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2218 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2226 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval)->type = node_t::t_string; }
#line 2232 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 121 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyval)->type = node_t::t_string_list;
    }
#line 2241 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
    }
#line 2249 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    

        /* Ignore the identifier part of a function call, but only if there is
         * a simple function name there. The grammar also allows a complex
         * expression here, e.g., a function call returning a function pointer.
         * In such a case we wouldn't want to do anything. 
         *
         * The above isn't the full story. We only want to ignore this
         * identifier if we know it to be a function symbol. The reason is that
         * the identifier could be a function pointer, which possibly needs
         * globalising.
         *
         * Still, this isn't 100% correct. If a static local variable shadowed
         * the name of a function here, this could wouldn't know and it would
         * ignore the static variable. This decision should really be delayed
         * until analysis in node_t; as that is our real semantic analysis
         * stage. At the time of writing this has proved to be sufficient, but
         * this should be fixed in the future.
         *
         * TODO: check that we still need this code. The semantic analysis has
         * improved a lot in node_t; it may be that we no longer need this
         * check.
         */
        if ((yyvsp[-3])->children.empty()) {
            if (is_function((yyvsp[-3])->s_identifier)) {
                (yyvsp[-3])->b_ignore = true;
            }
        }
    }
#line 2284 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        if ((yyvsp[-2])->children.empty()) {
            if (is_function((yyvsp[-2])->s_identifier)) {
                (yyvsp[-2])->b_ignore = true;
            }
        }
    }
#line 2297 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 174 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); (yyvsp[0])->s_identifier = string(""); 
    }
#line 2305 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); (yyvsp[0])->s_identifier = string(""); 
    }
#line 2313 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); (yyvsp[0])->s_identifier = string(""); 
    }
#line 2321 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); (yyvsp[0])->s_identifier = string(""); 
    }
#line 2329 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 190 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
    }
#line 2337 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
    }
#line 2345 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 202 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2353 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 209 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2359 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 210 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2365 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 212 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyval)->check_for_ampersand_reference_special_case();
    }
#line 2374 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2380 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 2388 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2396 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 241 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 2404 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 245 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 2412 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 250 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2420 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 255 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2428 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 260 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2436 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 268 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 2444 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 272 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2450 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2456 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 280 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2462 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 282 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2468 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 288 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2474 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 290 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2480 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 296 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2486 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 298 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2492 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 300 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2498 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 302 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2504 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 308 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2510 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 310 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2516 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 316 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2522 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 322 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2528 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 328 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2534 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 334 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2540 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 340 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2546 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 347 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 2552 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 349 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        /* This is crazy syntax right here! But gcc accepts it... */
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2561 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 358 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 2569 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 380 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
    }
#line 2577 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 391 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_declaration;
    }
#line 2586 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 396 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        (yyval)->b_ignore = true;
    }
#line 2595 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 404 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));

        if((yyvsp[-2])->check_typedef()) {
            // If it is a typedef there should only be one interesting 
            // identifier in init_declarator_list.
            const node_t *i = (yyvsp[-1])->get_identifier();
            assert(i);
            string new_type_name = i->s_identifier;
            string old_type_name = (yyval)->find_typedef_type();
            bool is_function = (yyval)->get_function_declaration_b();
            global_define_type(new_type_name, old_type_name,
                               is_function);
 
            // TODO: enforce only one of the following bools with a checl
            // bool fd = $$->get_function_declaration_b();
            // bool fp = $$->get_function_pointer();
        } else {
            /* This is the node for a... declaration. These are the
             * sub trees we are interested in. Mark it as such. */
            (yyval)->type = node_t::t_declaration;
            (yyval)->do_void_declaration_special_case();
            if((yyval)->get_extern() && !(yyval)->b_ignore && 
                    !(yyval)->b_function_declaration) {
                // Generally we handle declarations at a higher level, but to
                // handle externs within blocks of code, we need to handle
                // the declaration here.
                (yyval)->handle_global();
                (yyval)->b_ignore = true; // Don't try and handle it again later.
            }
        }
    }
#line 2632 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 437 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        (yyval)->b_ignore = true;
    }
#line 2641 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 445 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2647 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 447 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2653 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 449 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2659 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 455 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
    }
#line 2667 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 459 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2673 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 461 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 2679 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 468 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_init_declarator_list;
    }
#line 2688 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 476 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->b_init_declarator = true;
        (yyval)->type = node_t::t_init_declarator;
    }
#line 2698 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 486 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->b_typedef = true;
    }
#line 2707 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 491 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_extern = true;
    }
#line 2716 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 496 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_static = true;
    }
#line 2725 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 505 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->b_typedef = true;
    }
#line 2734 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 510 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_extern = true;
    }
#line 2743 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 515 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_static = true;
    }
#line 2752 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 523 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2758 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 524 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2764 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 525 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2770 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 526 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2776 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 527 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2782 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 528 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2788 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 529 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2794 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 530 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2800 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 531 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2806 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 532 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2812 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 533 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2818 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 535 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]);
        (yyval)->b_typedefed_name = true;
    }
#line 2827 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 540 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_typeof;
    }
#line 2836 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 545 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_typeof;
    }
#line 2845 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 555 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->b_typedefed_name = true;
    }
#line 2854 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 562 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2860 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 563 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2866 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 564 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2872 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 565 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2878 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 566 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2884 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 567 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2890 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 568 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2896 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 569 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2902 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 570 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2908 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 572 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2916 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 576 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2924 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 590 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        global_define_struct((yyvsp[-3])->s_identifier);

        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        (yyval)->s_struct = (yyvsp[-3])->s_identifier;
        (yyvsp[-3])->s_identifier = string(""); // see below for reason

        // We don't want to consider function declarations within a
        // structure
        (yyvsp[-1])->clear_function_declaration();
        (yyvsp[-1])->clear_typedefed();
    }
#line 2941 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 603 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        (yyvsp[-1])->clear_function_declaration();
        (yyvsp[-1])->clear_typedefed();
    }
#line 2951 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 610 "globaliser/parser.yc" /* yacc.c:1646  */
    {
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2959 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 614 "globaliser/parser.yc" /* yacc.c:1646  */
    {  
        global_define_struct((yyvsp[-2])->s_identifier);
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));  
        (yyval)->s_struct = (yyvsp[-2])->s_identifier;
        (yyvsp[-2])->s_identifier = string("");
    }
#line 2970 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 621 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        global_declare_struct((yyvsp[0])->s_identifier);
        // We don't want to know about the identifier here, it is just
        // part of the type name.
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyval)->s_struct = (yyvsp[0])->s_identifier;
        (yyvsp[0])->s_identifier = string("");
    }
#line 2983 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 631 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        global_declare_struct((yyvsp[0])->s_identifier);
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyval)->s_struct = (yyvsp[0])->s_identifier;
        (yyvsp[0])->s_identifier = string("");
        (yyvsp[0])->b_typedefed_name = false;
    }
#line 2995 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 640 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        global_define_struct((yyvsp[-3])->s_identifier);
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->s_struct = (yyvsp[-3])->s_identifier;
        (yyvsp[-3])->b_typedefed_name = false;
        (yyvsp[-1])->clear_function_declaration();
        (yyvsp[-1])->clear_typedefed();
    }
#line 3008 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 651 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3014 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 653 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3020 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 665 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    
    }
#line 3028 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 673 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3036 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 677 "globaliser/parser.yc" /* yacc.c:1646  */
    {
	(yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
    }
#line 3044 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 685 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if((yyvsp[-2]) && (yyvsp[0]))
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        else if((yyvsp[-2]))
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]));
        else if((yyvsp[0]))
            (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        else
            (yyval) = new node_t((yyvsp[-1]));
    }
#line 3059 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 696 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if((yyvsp[-2]) && (yyvsp[0]))
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        else if((yyvsp[-2]))
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]));
        else if((yyvsp[0]))
            (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        else
            (yyval) = new node_t((yyvsp[-1]));
    }
#line 3074 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 709 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = NULL;
    }
#line 3082 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 713 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if((yyvsp[0])) {
            (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        } else {
            (yyval) = (yyvsp[-1]);
        }
    }
#line 3094 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 723 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = NULL;
    }
#line 3102 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 727 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if((yyvsp[0]))
            (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        else
            (yyval) = new node_t((yyvsp[-1]));
    }
#line 3113 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 734 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if((yyvsp[0]))
            (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        else
            (yyval) = new node_t((yyvsp[-1]));
    }
#line 3124 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 175:
#line 746 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3130 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 752 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    }
#line 3136 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 754 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 3142 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 759 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        (yyvsp[-3])->s_identifier = string();
    }
#line 3151 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 764 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3159 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 768 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyvsp[-4])->s_identifier = string();
    }
#line 3168 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 773 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3176 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 777 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyvsp[0])->s_identifier = string();
    }
#line 3185 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 785 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 3191 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 790 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        global_define_variable((yyvsp[0])->s_identifier, false, true, false, false, "");
        (yyvsp[0])->s_identifier = string();
    }
#line 3200 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 795 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        global_define_variable((yyvsp[-2])->s_identifier, false, true, false, false, "");
        (yyvsp[-2])->s_identifier = string();
    }
#line 3210 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 805 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_volatile = true;
    }
#line 3219 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 810 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_register = true;
    }
#line 3228 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 818 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyval)->i_function_pointer = 1;
        (yyval)->type = node_t::t_declarator;
    }
#line 3238 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 828 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        (yyval)->i_function_pointer = 1;
        (yyval)->type = node_t::t_declarator;
    }
#line 3248 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 839 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->type = node_t::t_direct_declarator;
    }
#line 3257 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 844 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->i_function_pointer = (yyvsp[-1])->i_function_pointer + 1;
    }
#line 3266 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 849 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_direct_declarator_array;
        (yyval)->b_unbounded_array = true; // For now. Need to think about
                                      // this.
    }
#line 3277 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 856 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_direct_declarator_array;
        (yyval)->b_unbounded_array = true;
    }
#line 3287 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 863 "globaliser/parser.yc" /* yacc.c:1646  */
    {   
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        if((yyvsp[-3])->i_function_pointer == 2) {
            // We are a function pointer!
            (yyval)->i_function_pointer = 3;
        } else {        
            (yyval)->type = node_t::t_function_declaration;
            (yyval)->b_function_declaration = true;
        }
        (yyvsp[-1])->b_declaration_list = true;
    }
#line 3303 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 875 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        (yyval)->type = node_t::t_function_declaration;
        (yyval)->b_function_declaration = true;
        (yyvsp[-1])->b_declaration_list = true;
    }
#line 3314 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 882 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        
        if((yyvsp[-2])->i_function_pointer == 2) {
            // We are a function pointer!
            (yyval)->i_function_pointer = 3;
        } else {        
            (yyval)->type = node_t::t_function_declaration;
            (yyval)->b_function_declaration = true;
        }

        //$$->b_ignore = true;
    }
#line 3332 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 896 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
    }
#line 3340 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 908 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3348 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 915 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->type = node_t::t_direct_declarator;
    }
#line 3357 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 920 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->s_identifier = (yyval)->s_token;
        (yyval)->b_typedefed_name = true;
        (yyval)->type = node_t::t_direct_declarator;
    }
#line 3368 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 927 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->i_function_pointer = (yyvsp[-1])->i_function_pointer + 1;
    }
#line 3377 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 932 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_direct_declarator_array;
        (yyval)->b_unbounded_array = true; // For now. Need to think about
                                      // this.
    }
#line 3388 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 939 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_direct_declarator_array;
        (yyval)->b_unbounded_array = true;
    }
#line 3398 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 946 "globaliser/parser.yc" /* yacc.c:1646  */
    {   
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        if((yyvsp[-3])->i_function_pointer == 2) {
            // We are a function pointer!
            (yyval)->i_function_pointer = 3;
        } else {        
            (yyval)->type = node_t::t_function_declaration;
            (yyval)->b_function_declaration = true;
        }
        (yyvsp[-1])->b_declaration_list = true;
    }
#line 3414 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 958 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        (yyval)->type = node_t::t_function_declaration;
        (yyval)->b_function_declaration = true;
        (yyvsp[-1])->b_declaration_list = true;
    }
#line 3425 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 965 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
        
        if((yyvsp[-2])->i_function_pointer == 2) {
            // We are a function pointer!
            (yyval)->i_function_pointer = 3;
        } else {        
            (yyval)->type = node_t::t_function_declaration;
            (yyval)->b_function_declaration = true;
        }

        (yyval)->b_ignore = true;
    }
#line 3443 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 981 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3449 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 983 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 3455 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 984 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3461 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 989 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3467 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 994 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->type = node_t::t_parameter_type_list;
    }
#line 3476 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 999 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        (yyval)->type = node_t::t_parameter_type_list;
    }
#line 3485 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 1008 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3493 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 1020 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
    }
#line 3501 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 1024 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
    }
#line 3509 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 1040 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->b_ignore = true; 
    }
#line 3518 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 1045 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        (yyval)->b_ignore = true;
    }
#line 3527 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 1054 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    }
#line 3533 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 1060 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3539 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 1065 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3545 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 1067 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    }
#line 3551 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 1069 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3557 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 1071 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3563 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 1073 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3569 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 1075 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    }
#line 3575 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 1077 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3581 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 1079 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3587 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 1081 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3593 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 1087 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3599 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 1092 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3605 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 1094 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    }
#line 3611 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 1096 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3617 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 1098 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3623 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 1100 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3629 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 1102 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));    }
#line 3635 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 1104 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3641 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 1106 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3647 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 253:
#line 1113 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3653 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 1115 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3659 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 1117 "globaliser/parser.yc" /* yacc.c:1646  */
    {   (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));   }
#line 3665 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 256:
#line 1120 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3673 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 1124 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3681 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 1128 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3689 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 1141 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3697 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 1146 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3705 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 1151 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3713 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 1158 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        (yyvsp[0])->s_identifier = string();
    }
#line 3722 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 1163 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        (yyvsp[0])->s_identifier = string();
    }
#line 3731 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 1168 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyvsp[-1])->s_identifier = string();
    }
#line 3740 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 1173 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        (yyvsp[-1])->s_identifier = string();
    }
#line 3749 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 1182 "globaliser/parser.yc" /* yacc.c:1646  */
    {
	(yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3757 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 1190 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
    }
#line 3765 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 1214 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        /* Ignore label identifiers, we don't want to globalise them */
        (yyvsp[-2])->b_ignore = true;
    }
#line 3775 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 1221 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3783 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 1225 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
   
    }
#line 3792 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 1237 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3800 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 1241 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3808 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 284:
#line 1259 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if ((yyvsp[0])) {
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        } else {
            (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]));
        }
    }
#line 3820 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 1267 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if ((yyvsp[-2]) && (yyvsp[0])) {
            (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        }
        else if ((yyvsp[-2])) {
            (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]));
        }
        else if ((yyvsp[0])) {
            (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]));
        }
        else {
            (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]));
        }
    }
#line 3839 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 1282 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        if ((yyvsp[-4]) && (yyvsp[-2])) {
            (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        }
        else if ((yyvsp[-4])) {
            (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]));
        }
        else if ((yyvsp[-2])) {
            (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
        }
        else {
            (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]));
        }
    }
#line 3858 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 1300 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = NULL;
    }
#line 3866 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 1314 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3874 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 1326 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3882 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 292:
#line 1330 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3890 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 294:
#line 1343 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 3898 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 296:
#line 1357 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3904 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 297:
#line 1359 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        (yyval)->type = node_t::t_compound_statement;
    }
#line 3913 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 298:
#line 1367 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]);
        (yyval)->b_declaration_list = true;
    }
#line 3922 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 299:
#line 1372 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
        (yyval)->b_declaration_list = true;
    }
#line 3931 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 301:
#line 1381 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));
        (yyval)->type = node_t::t_statement_list;
    }
#line 3940 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 303:
#line 1389 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 3946 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 304:
#line 1394 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3954 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 305:
#line 1398 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3962 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 306:
#line 1402 "globaliser/parser.yc" /* yacc.c:1646  */
    {    (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    }
#line 3968 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 307:
#line 1404 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3976 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 308:
#line 1411 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3984 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 309:
#line 1416 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 3992 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 310:
#line 1420 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4000 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 311:
#line 1424 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4008 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 312:
#line 1428 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4016 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 313:
#line 1432 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4024 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 314:
#line 1436 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4032 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 315:
#line 1440 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4040 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 316:
#line 1444 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4048 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 317:
#line 1448 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-8]), (yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));    
    }
#line 4056 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 318:
#line 1455 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
        /* The identifier after the 'goto' is a label, so we ignore the
           identifier; we do not want to globalise it. */
        (yyvsp[-1])->b_ignore = true;
    }
#line 4067 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 319:
#line 1461 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 4073 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 320:
#line 1462 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 4079 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 321:
#line 1463 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); }
#line 4085 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 322:
#line 1464 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 4091 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 324:
#line 1472 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        // Post-process the AST, possibly removing nodes we find we don't want.
        // See the documentation in handle_global.cc
        extern_global_array_initialisers_special_case();

        fputs("#include \"num_stacks.h\"\n", stdout);
        // Print out the resulting tree
        (yyval)->print();
        // Clean up 
        delete (yyval); 
        // Make sure there is a newline at end of file to stop gcc complaining
        fputs("\n", stdout);
    }
#line 4109 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 326:
#line 1490 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0])); 
    }
#line 4117 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 327:
#line 1497 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]); 
        (yyval)->handle_global_references();
    }
#line 4126 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 328:
#line 1502 "globaliser/parser.yc" /* yacc.c:1646  */
    { 
        (yyval) = (yyvsp[0]);

        if ((yyval)->get_function_declaration_b()) {
            node_t* n = (yyval)->get_function_declaration();
            node_t* iden = n->get_identifier();
            global_define_function(iden->s_identifier, true); 
        }

        // New
        if(!(yyval)->check_typedef()) {
            (yyval)->handle_global();
            (yyval)->b_toplevel = true;
        } else {
            // If its a typedef we can ignore it later
            (yyval)->b_ignore = true;
        }
    }
#line 4149 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 331:
#line 1526 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));        
        (yyvsp[-2])->b_ignore = true;
        (yyvsp[-2])->b_declaration_list = true;
        (yyvsp[-1])->b_declaration_list = true;
        global_define_function((yyvsp[-2])->get_identifier()->s_identifier, false);
    }
#line 4161 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 332:
#line 1534 "globaliser/parser.yc" /* yacc.c:1646  */
    {
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));            
        (yyvsp[-1])->b_ignore = true;
        (yyvsp[-1])->b_declaration_list = true;
        global_define_function((yyvsp[-1])->get_identifier()->s_identifier, false);
    }
#line 4172 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 333:
#line 1541 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));            
        (yyvsp[-2])->b_ignore = true;
        global_define_function((yyvsp[-2])->get_identifier()->s_identifier, false);
    }
#line 4182 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 334:
#line 1547 "globaliser/parser.yc" /* yacc.c:1646  */
    {    
        (yyval) = new node_t((yyvsp[-1]), (yyvsp[0]));                
        (yyvsp[-1])->b_ignore = true;
        global_define_function((yyvsp[-1])->get_identifier()->s_identifier, false);
    }
#line 4192 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 335:
#line 1555 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4198 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 336:
#line 1556 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4204 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 337:
#line 1557 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4210 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 338:
#line 1558 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4216 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 339:
#line 1559 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4222 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 340:
#line 1560 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4228 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 341:
#line 1561 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4234 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 342:
#line 1562 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4240 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 343:
#line 1563 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4246 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 344:
#line 1564 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4252 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 345:
#line 1565 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4258 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 346:
#line 1566 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4264 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 347:
#line 1567 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4270 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 348:
#line 1568 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4276 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 349:
#line 1569 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4282 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 350:
#line 1570 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4288 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 351:
#line 1571 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4294 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 352:
#line 1572 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4300 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 353:
#line 1573 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4306 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 354:
#line 1574 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4312 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 355:
#line 1575 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4318 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 356:
#line 1576 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4324 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 357:
#line 1577 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4330 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 358:
#line 1578 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4336 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 359:
#line 1580 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4342 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 360:
#line 1581 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4348 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 361:
#line 1582 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4354 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 362:
#line 1583 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4360 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 363:
#line 1584 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4366 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 364:
#line 1585 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4372 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 365:
#line 1586 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4378 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 366:
#line 1587 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4384 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 367:
#line 1588 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4390 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 368:
#line 1589 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4396 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 369:
#line 1590 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4402 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 370:
#line 1591 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4408 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 371:
#line 1592 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4414 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 372:
#line 1593 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4420 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 373:
#line 1594 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4426 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 374:
#line 1595 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4432 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 375:
#line 1596 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4438 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 376:
#line 1597 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4444 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 377:
#line 1598 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4450 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 378:
#line 1599 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4456 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 379:
#line 1600 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4462 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 380:
#line 1601 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4468 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 381:
#line 1602 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4474 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 382:
#line 1603 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4480 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 383:
#line 1604 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4486 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 384:
#line 1605 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4492 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 385:
#line 1606 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4498 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 386:
#line 1607 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4504 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 387:
#line 1608 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4510 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 388:
#line 1609 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4516 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 389:
#line 1610 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4522 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 390:
#line 1611 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4528 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 391:
#line 1612 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4534 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 392:
#line 1613 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4540 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 393:
#line 1614 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4546 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 394:
#line 1615 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4552 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 395:
#line 1616 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4558 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 396:
#line 1617 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4564 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 397:
#line 1618 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4570 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 398:
#line 1619 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4576 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 399:
#line 1620 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4582 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 400:
#line 1621 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4588 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 401:
#line 1622 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4594 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 402:
#line 1623 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4600 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 403:
#line 1624 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4606 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 404:
#line 1625 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4612 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 405:
#line 1626 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4618 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 406:
#line 1627 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4624 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 407:
#line 1628 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4630 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 408:
#line 1629 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4636 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 409:
#line 1630 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4642 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 410:
#line 1631 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4648 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 411:
#line 1632 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4654 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 412:
#line 1633 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4660 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 413:
#line 1634 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4666 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 414:
#line 1635 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); 
                                     (yyval)->s_identifier = (yyval)->s_token;
                                   }
#line 4674 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 415:
#line 1638 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4680 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 416:
#line 1639 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4686 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 417:
#line 1640 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4692 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 418:
#line 1641 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4698 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 419:
#line 1643 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4704 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 420:
#line 1644 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4710 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 421:
#line 1645 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4716 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 422:
#line 1646 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4722 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;

  case 423:
#line 1647 "globaliser/parser.yc" /* yacc.c:1646  */
    { (yyval) = new node_t(); }
#line 4728 "globaliser/parser.tab.cc" /* yacc.c:1646  */
    break;


#line 4732 "globaliser/parser.tab.cc" /* yacc.c:1646  */
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
#line 1649 "globaliser/parser.yc" /* yacc.c:1906  */


extern int charno;
extern char *yytext;

static void
yyerror(const char *s)
{
    fprintf(stderr, "Line %d: Char %d: %s (last token was '%s')\n", 
        lineno, charno, s, yytext);
    exit(1);
}

#if YYDEBUG
extern int yydebug;
#endif

int opt_verbose = 0;
const char *progname = NULL;

int
main(int argc, char *argv[])
{
    int i;
    lineno = 1;
    charno = 0;

#if YYDEBUG
    yydebug = 1;
#endif

    progname = argv[0];

    for(i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            if(argv[i][1] == 'v')
                opt_verbose++;
        } else {
            setup_globals(argv[i]);
        }
    }

    yyparse();

    return 0;
}

/* vim:syn=yacc  
*/


