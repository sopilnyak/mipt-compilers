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




/* Copy the first part of user declarations.  */
#line 3 "syntax_analyzer.y" /* yacc.c:339  */

    #include "print_visitor.h"

    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <memory>

    extern FILE* yyin;
    extern int yylex();
    extern int yyparse();

    void yyerror(const char* s);
    void print_();

    PrintVisitor* printer = new PrintVisitor("./output.gv");

#line 84 "syntax_analyzer.tab.c" /* yacc.c:339  */

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
   by #include "syntax_analyzer.tab.h".  */
#ifndef YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
# define YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    CLASS = 258,
    EXTENDS = 259,
    PUBLIC = 260,
    PRIVATE = 261,
    STATICVOIDMAIN = 262,
    SYSTEMOUT = 263,
    STRING = 264,
    INT = 265,
    BOOLEAN = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    LENGTH = 270,
    TRUE = 271,
    FALSE = 272,
    THIS = 273,
    NEW = 274,
    RETURN = 275,
    AND = 276,
    OR = 277,
    LEFTRBRACKET = 278,
    RIGHTRBRACKET = 279,
    LEFTCBRACKET = 280,
    RIGHTCBRACKET = 281,
    LEFTSBRACKET = 282,
    RIGHTSBRACKET = 283,
    QUESTION = 284,
    SEMICOLON = 285,
    EXCLAMATION = 286,
    LESS = 287,
    GREATER = 288,
    LEQ = 289,
    GEQ = 290,
    EQUALS = 291,
    DOT = 292,
    COMMA = 293,
    PLUS = 294,
    MINUS = 295,
    MULTIPLY = 296,
    DIVIDE = 297,
    MOD = 298,
    IDENTIFIER = 299,
    INTEGERLITERAL = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "syntax_analyzer.y" /* yacc.c:355  */

    int intval;
    char* id;
    char* value;
    Program* program;
    MainClass* mainClass;
    ClassDeclarationList* classes;
    ClassDeclaration* classDeclaration;
    VarDeclarationList* varDeclarations;
    VarDeclaration* varDeclaration;
    MethodDeclarationList* methodDeclarations;
    MethodDeclaration* methodDeclaration;
    MethodModifier* methodModifier;
    ArgumentList* arguments;
    IType* type;
    PrimitiveType* primitiveType;
    ClassType* classType;
    StatementList* statements;
    IStatement* statement;
    ExpressionList* expressions;
    IExpression* expression;
    Id* identifier;

#line 195 "syntax_analyzer.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "syntax_analyzer.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   101,   101,   102,   105,   111,   112,   115,   116,   117,
     118,   119,   120,   121,   122,   125,   126,   129,   132,   133,
     136,   137,   138,   139,   142,   143,   146,   147,   148,   151,
     152,   153,   154,   157,   158,   161,   162,   163,   164,   165,
     166,   169,   170,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END", "error", "$undefined", "CLASS", "EXTENDS", "PUBLIC", "PRIVATE",
  "STATICVOIDMAIN", "SYSTEMOUT", "STRING", "INT", "BOOLEAN", "IF", "ELSE",
  "WHILE", "LENGTH", "TRUE", "FALSE", "THIS", "NEW", "RETURN", "AND", "OR",
  "LEFTRBRACKET", "RIGHTRBRACKET", "LEFTCBRACKET", "RIGHTCBRACKET",
  "LEFTSBRACKET", "RIGHTSBRACKET", "QUESTION", "SEMICOLON", "EXCLAMATION",
  "LESS", "GREATER", "LEQ", "GEQ", "EQUALS", "DOT", "COMMA", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "MOD", "IDENTIFIER", "INTEGERLITERAL",
  "$accept", "goal", "main_class", "classes", "class", "var_declarations",
  "var_declaration", "method_declarations", "method_declaration",
  "method_modifier", "arguments", "type", "statements", "statement",
  "expressions", "expression", "id", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -36,    25,   139,   -57,     2,   -57,   -57,   -36,   148,
     -57,    18,     5,   -57,   -57,    26,   -36,     0,    50,    24,
     -57,   -57,    29,   -57,   -57,     8,   -57,    80,   -57,    -8,
     -36,   -57,    49,    35,    55,   -57,   -57,    96,   -57,   -57,
     -36,    48,    67,   -57,   115,   112,   -57,   -57,    73,   -57,
      75,   -57,   131,   -57,    -8,   -36,   -57,    51,   -36,    88,
     104,    -8,   -57,   108,   120,   -36,   195,   121,   123,   127,
     218,   195,   157,   164,   -57,    23,   -57,   135,    23,   218,
     218,   218,   -57,   -57,   -57,    -6,   218,   218,   -57,   229,
     -57,   173,   218,   180,   218,   -57,   218,   218,   109,   252,
     275,   298,   126,   140,   321,   528,   218,   218,   218,   128,
     218,     7,   218,   218,   218,   218,   -57,   344,   218,   367,
     390,   413,   -57,   132,   195,   195,   218,   134,   -57,   528,
     528,   436,   -57,   528,   -57,   147,   528,   528,   528,   528,
     149,   459,   154,   137,   -57,   -57,   161,   -57,   482,   -57,
     -57,   209,   -57,   165,   -57,   218,   195,   -57,   -57,    53,
     528,   -57,   505,   -57,   -57,   218,   -57,   528
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    63,     0,     1,     3,     0,     0,
       6,     0,     0,     2,     5,     0,     0,     0,     0,     0,
      24,    25,    31,    30,     7,     0,    16,     0,    19,     0,
       0,    32,     0,     0,     0,     8,    15,     0,     9,    18,
       0,     0,     0,    11,     0,     0,    29,    10,     0,    17,
       0,    12,     0,    13,    28,     0,    14,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    32,    26,     0,     0,     0,
       0,     0,    55,    56,    58,     0,     0,     0,    54,     0,
      57,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,    62,    43,
      49,     0,    23,    44,    51,     0,    45,    46,    47,    48,
       0,     0,     0,     0,    39,    38,     0,    37,     0,    60,
      50,     0,    21,     0,    22,     0,     0,    59,    53,     0,
      42,    20,     0,    36,    52,     0,    40,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -57,   174,    -2,   -24,    22,   159,   -57,
     -57,    13,    33,   -56,   -57,     1,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    25,    26,    27,    28,    29,
      57,    30,    73,    74,   159,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,    36,    22,    23,   102,    20,    21,    12,     4,    16,
      22,    23,     1,    20,    21,    19,    31,    95,    22,    23,
      36,    95,   134,    15,    31,     6,    24,    11,    31,    41,
      17,    44,    31,    18,    35,    95,     4,    95,     4,    48,
      20,    21,    40,    31,     4,    22,    23,    37,    36,    33,
      96,     4,     4,    31,    59,    45,    34,    62,    42,    97,
      31,    43,    72,    75,    76,    78,    52,    58,   146,   147,
      78,    75,    78,    32,    65,    60,    78,   164,    49,     4,
      99,   100,   101,    46,   103,    20,    21,   104,   105,    61,
      78,   165,    78,   117,    50,   119,    54,   120,   121,    77,
     163,    20,    21,    55,    91,    93,    38,   129,   130,   131,
     135,   133,    63,   136,   137,   138,   139,    20,    21,   141,
      20,    21,    47,    78,    78,    22,    23,   148,    67,    64,
      22,    23,    68,    66,    69,   122,    20,    21,    53,     7,
      70,    51,     8,    67,    79,    71,    80,    68,    13,    69,
      81,     8,   160,   126,   132,    78,   162,    56,   149,     4,
      71,    98,   145,   127,     4,    67,   167,    22,    23,    68,
     151,    69,    67,   155,   156,   152,    68,    92,    69,     4,
     154,    67,    71,    14,    94,    68,    39,    69,    67,    71,
       0,   161,    68,     0,    69,     0,    39,     0,    71,   116,
     118,     4,     0,    67,    39,    71,     0,    68,     4,    69,
       0,    39,     0,     0,     0,     0,     0,     4,     0,     0,
      71,     0,     0,     0,     4,    82,    83,    84,    85,     0,
       0,     0,    86,   158,    82,    83,    84,    85,     0,     4,
      87,    86,     0,     0,     0,     0,     0,     0,     0,    87,
     106,   107,     0,     4,    88,     0,   108,     0,     0,   109,
       0,   110,     4,    88,     0,     0,   111,     0,   112,   113,
     114,     0,   115,   106,   107,     0,   123,     0,     0,   108,
       0,     0,     0,     0,   110,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,   106,   107,     0,   124,
       0,     0,   108,     0,     0,     0,     0,   110,     0,     0,
       0,     0,   111,     0,   112,   113,   114,     0,   115,   106,
     107,     0,   125,     0,     0,   108,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   111,     0,   112,   113,   114,
       0,   115,   106,   107,     0,   128,     0,     0,   108,     0,
       0,     0,     0,   110,     0,     0,     0,     0,   111,     0,
     112,   113,   114,     0,   115,   106,   107,     0,     0,     0,
       0,   108,     0,     0,   140,     0,   110,     0,     0,     0,
       0,   111,     0,   112,   113,   114,     0,   115,   106,   107,
       0,     0,     0,     0,   108,     0,     0,   142,     0,   110,
       0,     0,     0,     0,   111,     0,   112,   113,   114,     0,
     115,   106,   107,     0,     0,     0,     0,   108,   143,     0,
       0,     0,   110,     0,     0,     0,     0,   111,     0,   112,
     113,   114,     0,   115,   106,   107,     0,     0,     0,     0,
     108,     0,     0,   144,     0,   110,     0,     0,     0,     0,
     111,     0,   112,   113,   114,     0,   115,   106,   107,     0,
       0,     0,     0,   108,   150,     0,     0,     0,   110,     0,
       0,     0,     0,   111,     0,   112,   113,   114,     0,   115,
     106,   107,     0,     0,     0,     0,   108,     0,     0,   153,
       0,   110,     0,     0,     0,     0,   111,     0,   112,   113,
     114,     0,   115,   106,   107,     0,     0,     0,     0,   108,
     157,     0,     0,     0,   110,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,   106,   107,     0,     0,
       0,     0,   108,     0,     0,   166,     0,   110,     0,     0,
       0,     0,   111,     0,   112,   113,   114,     0,   115,   106,
     107,     0,     0,     0,     0,   108,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   111,     0,   112,   113,   114,
       0,   115
};

static const yytype_int16 yycheck[] =
{
       1,    25,    10,    11,    10,     5,     6,     8,    44,     4,
      10,    11,     3,     5,     6,    16,    17,    73,    10,    11,
      44,    77,    15,     5,    25,     0,    26,    25,    29,    30,
      25,    33,    33,     7,    26,    91,    44,    93,    44,    40,
       5,     6,    29,    44,    44,    10,    11,    25,    72,    25,
      27,    44,    44,    54,    55,    33,    27,    58,     9,    36,
      61,    26,    64,    64,    65,    66,    44,    54,   124,   125,
      71,    72,    73,    23,    61,    24,    77,    24,    30,    44,
      79,    80,    81,    28,    85,     5,     6,    86,    87,    38,
      91,    38,    93,    92,    27,    94,    23,    96,    97,    66,
     156,     5,     6,    28,    71,    72,    26,   106,   107,   108,
     111,   110,    24,   112,   113,   114,   115,     5,     6,   118,
       5,     6,    26,   124,   125,    10,    11,   126,     8,    25,
      10,    11,    12,    25,    14,    26,     5,     6,    26,     0,
      20,    26,     3,     8,    23,    25,    23,    12,     0,    14,
      23,     3,   151,    27,    26,   156,   155,    26,    24,    44,
      25,    26,    30,    23,    44,     8,   165,    10,    11,    12,
      23,    14,     8,    36,    13,    26,    12,    20,    14,    44,
      26,     8,    25,     9,    20,    12,    27,    14,     8,    25,
      -1,    26,    12,    -1,    14,    -1,    37,    -1,    25,    26,
      20,    44,    -1,     8,    45,    25,    -1,    12,    44,    14,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      25,    -1,    -1,    -1,    44,    16,    17,    18,    19,    -1,
      -1,    -1,    23,    24,    16,    17,    18,    19,    -1,    44,
      31,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      21,    22,    -1,    44,    45,    -1,    27,    -1,    -1,    30,
      -1,    32,    44,    45,    -1,    -1,    37,    -1,    39,    40,
      41,    -1,    43,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    -1,    43,    21,    22,    -1,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    -1,    43,    21,
      22,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,
      -1,    43,    21,    22,    -1,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    40,    41,    -1,    43,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    -1,    39,    40,    41,    -1,    43,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,
      43,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,
      40,    41,    -1,    43,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    -1,    43,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,    43,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,
      41,    -1,    43,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    -1,    43,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    -1,    43,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,
      -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    48,    44,    62,     0,     0,     3,    49,
      50,    25,    62,     0,    50,     5,     4,    25,     7,    62,
       5,     6,    10,    11,    26,    51,    52,    53,    54,    55,
      57,    62,    23,    25,    27,    26,    52,    53,    26,    54,
      57,    62,     9,    26,    51,    53,    28,    26,    62,    30,
      27,    26,    53,    26,    23,    28,    26,    56,    57,    62,
      24,    38,    62,    24,    25,    57,    25,     8,    12,    14,
      20,    25,    51,    58,    59,    62,    62,    58,    62,    23,
      23,    23,    16,    17,    18,    19,    23,    31,    45,    61,
      62,    58,    20,    58,    20,    59,    27,    36,    26,    61,
      61,    61,    10,    62,    61,    61,    21,    22,    27,    30,
      32,    37,    39,    40,    41,    43,    26,    61,    20,    61,
      61,    61,    26,    24,    24,    24,    27,    23,    24,    61,
      61,    61,    26,    61,    15,    62,    61,    61,    61,    61,
      30,    61,    30,    28,    30,    30,    59,    59,    61,    24,
      28,    23,    26,    30,    26,    36,    13,    28,    24,    60,
      61,    26,    61,    59,    24,    38,    30,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,    15,     2,     1,     4,     5,     5,
       6,     6,     7,     7,     8,     2,     1,     3,     2,     1,
      13,    12,    12,    11,     1,     1,     4,     2,     0,     3,
       1,     1,     1,     2,     1,     3,     7,     5,     5,     4,
       7,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     6,     5,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 47: /* goal  */
#line 95 "syntax_analyzer.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).program); }
#line 1309 "syntax_analyzer.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 101 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.program) = new Program((yyvsp[-2].mainClass), (yyvsp[-1].classes)); (yyval.program)->accept(printer); print_(); }
#line 1597 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.program) = new Program((yyvsp[-1].mainClass), nullptr); (yyval.program)->accept(printer); print_(); }
#line 1603 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 108 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.mainClass) = new MainClass((yyvsp[-13].identifier), (yyvsp[-5].identifier), (yyvsp[-2].statements)); print_(); }
#line 1609 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classes) = new ClassDeclarationList((yyvsp[-1].classes), (yyvsp[0].classDeclaration)); print_(); }
#line 1615 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 112 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classes) = new ClassDeclarationList(nullptr, (yyvsp[0].classDeclaration)); print_(); }
#line 1621 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-2].identifier), nullptr, nullptr, nullptr); print_(); }
#line 1627 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-3].identifier), nullptr, (yyvsp[-1].varDeclarations), nullptr); print_(); }
#line 1633 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-3].identifier), nullptr, nullptr, (yyvsp[-1].methodDeclarations)); print_(); }
#line 1639 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-4].identifier), nullptr, (yyvsp[-2].varDeclarations), (yyvsp[-1].methodDeclarations)); print_(); }
#line 1645 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-4].identifier), (yyvsp[-2].identifier), nullptr, nullptr); print_(); }
#line 1651 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-5].identifier), (yyvsp[-3].identifier), (yyvsp[-1].varDeclarations), nullptr); print_(); }
#line 1657 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-5].identifier), (yyvsp[-3].identifier), nullptr, (yyvsp[-1].methodDeclarations)); print_(); }
#line 1663 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.classDeclaration) = new ClassDeclaration((yyvsp[-6].identifier), (yyvsp[-4].identifier), (yyvsp[-2].varDeclarations), (yyvsp[-1].methodDeclarations)); print_(); }
#line 1669 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.varDeclarations) = new VarDeclarationList((yyvsp[-1].varDeclarations), (yyvsp[0].varDeclaration)); print_(); }
#line 1675 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.varDeclarations) = new VarDeclarationList(nullptr, (yyvsp[0].varDeclaration)); print_(); }
#line 1681 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.varDeclaration) = new VarDeclaration((yyvsp[-2].type), (yyvsp[-1].identifier)); print_(); }
#line 1687 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodDeclarations) = new MethodDeclarationList((yyvsp[-1].methodDeclarations), (yyvsp[0].methodDeclaration)); print_(); }
#line 1693 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodDeclarations) = new MethodDeclarationList(nullptr, (yyvsp[0].methodDeclaration)); print_(); }
#line 1699 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodDeclaration) = new MethodDeclaration((yyvsp[-12].methodModifier), (yyvsp[-11].type), (yyvsp[-10].identifier), (yyvsp[-8].arguments), (yyvsp[-5].varDeclarations), (yyvsp[-4].statements), (yyvsp[-2].expression)); print_(); }
#line 1705 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 137 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodDeclaration) = new MethodDeclaration((yyvsp[-11].methodModifier), (yyvsp[-10].type), (yyvsp[-9].identifier), (yyvsp[-7].arguments), (yyvsp[-4].varDeclarations), nullptr, (yyvsp[-2].expression)); print_(); }
#line 1711 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 138 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodDeclaration) = new MethodDeclaration((yyvsp[-11].methodModifier), (yyvsp[-10].type), (yyvsp[-9].identifier), (yyvsp[-7].arguments), nullptr, (yyvsp[-4].statements), (yyvsp[-2].expression)); print_(); }
#line 1717 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 139 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodDeclaration) = new MethodDeclaration((yyvsp[-10].methodModifier), (yyvsp[-9].type), (yyvsp[-8].identifier), (yyvsp[-6].arguments), nullptr, nullptr, (yyvsp[-2].expression)); print_(); }
#line 1723 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 142 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodModifier) = new MethodModifier(T_PUBLIC); print_(); }
#line 1729 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 143 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.methodModifier) = new MethodModifier(T_PRIVATE); print_(); }
#line 1735 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 146 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.arguments) = new ArgumentList((yyvsp[-3].arguments), (yyvsp[-1].type), (yyvsp[0].identifier)); print_(); }
#line 1741 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 147 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.arguments) = new ArgumentList((yyvsp[-1].type), (yyvsp[0].identifier)); print_(); }
#line 1747 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 148 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.arguments) = nullptr; print_(); }
#line 1753 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 151 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(T_INT_ARRAY); print_(); }
#line 1759 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 152 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(T_BOOLEAN); print_(); }
#line 1765 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 153 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(T_INT); print_(); }
#line 1771 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.type) = new ClassType((yyvsp[0].identifier)); print_(); }
#line 1777 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statements) = new StatementList((yyvsp[-1].statements), (yyvsp[0].statement)); print_(); }
#line 1783 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 158 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statements) = new StatementList(nullptr, (yyvsp[0].statement)); print_(); }
#line 1789 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 161 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statement) = new Statements((yyvsp[-1].statements)); print_(); }
#line 1795 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 162 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElseStatement((yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement)); print_(); }
#line 1801 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statement) = new WhileStatement((yyvsp[-2].expression), (yyvsp[0].statement)); print_(); }
#line 1807 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 164 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statement) = new SystemOutStatement((yyvsp[-2].expression)); print_(); }
#line 1813 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 165 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statement) = new AssignStatement((yyvsp[-3].identifier), (yyvsp[-1].expression)); print_(); }
#line 1819 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 166 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayAssignStatement((yyvsp[-6].identifier), (yyvsp[-4].expression), (yyvsp[-1].expression)); print_(); }
#line 1825 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 169 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expressions) = new ExpressionList((yyvsp[-2].expressions), (yyvsp[0].expression)); print_(); }
#line 1831 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 170 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expressions) = new ExpressionList((yyvsp[0].expression)); print_(); }
#line 1837 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_AND, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1843 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 174 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_LESS, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1849 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 175 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_PLUS, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1855 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 176 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_MINUS, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1861 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 177 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_MULTIPLY, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1867 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 178 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_MOD, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1873 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 179 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryExpression(T_OR, (yyvsp[-2].expression), (yyvsp[0].expression)); print_(); }
#line 1879 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 180 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArrayMemberExpression((yyvsp[-3].expression), (yyvsp[-1].expression)); print_(); }
#line 1885 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 181 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArrayLengthExpression((yyvsp[-2].expression)); print_(); }
#line 1891 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 182 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new CallMemberExpression((yyvsp[-5].expression), (yyvsp[-3].identifier), (yyvsp[-1].expressions)); print_(); }
#line 1897 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 183 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new CallMemberExpression((yyvsp[-4].expression), (yyvsp[-2].identifier), nullptr); print_(); }
#line 1903 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 184 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new IntegerExpression(yylval.intval); }
#line 1909 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 185 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BooleanExpression(T_TRUE); print_(); }
#line 1915 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 186 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new BooleanExpression(T_FALSE); print_(); }
#line 1921 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 187 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new IdExpression((yyvsp[0].identifier)); print_(); }
#line 1927 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 188 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new ThisExpression(); print_(); }
#line 1933 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 189 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new IntArrayExpression((yyvsp[-1].expression)); print_(); }
#line 1939 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 190 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new ObjectExpression((yyvsp[-2].identifier)); print_(); }
#line 1945 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 191 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = new NotExpression((yyvsp[0].expression)); print_(); }
#line 1951 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 192 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); print_(); }
#line 1957 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 195 "syntax_analyzer.y" /* yacc.c:1646  */
    { (yyval.identifier) = new Id(yylval.id); print_(); }
#line 1963 "syntax_analyzer.tab.c" /* yacc.c:1646  */
    break;


#line 1967 "syntax_analyzer.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 198 "syntax_analyzer.y" /* yacc.c:1906  */


int main() 
{
    yyin = stdin;
    do {
        yyparse();
    } while(!feof(yyin));
    delete printer;

    return 0;
}

void yyerror(char const* s) 
{
    fprintf(stderr, "%s\n", s);
    exit(1);
}

void print_() {
    fprintf(stdout, "from %d to %d line; from %d to %d column [%s]\n", yylloc.first_line, yylloc.last_line, yylloc.first_column, yylloc.last_column, yylval.value);
}
