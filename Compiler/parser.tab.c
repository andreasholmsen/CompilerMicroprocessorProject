/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h> 
#include "parser.tab.h"
#include "./memory/symbolTable.h"
#include "./memory/stack.h"

int yylex(void);
int yyerror(const char *s);

// Labels for if statements
int label_ptr = 0;
int end_labels[1024];
int end_ptr = -1;
#define push_end_label end_labels[++end_ptr] = label_ptr++
#define pop_end_label end_labels[end_ptr--]
#define peek_end_label end_labels[end_ptr]

// Writing instruction output
struct Instruction {
        char code;
        int a, b, c;
};
struct Instruction code[4096];
int code_ptr = 0;
#define add_code(inst,res,op1,op2) code[code_ptr++]=(struct Instruction){inst, res, op1, op2}

FILE *f_asm;
FILE *f_bin;


extern FILE *yyin;

#line 105 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tEQ = 3,                        /* tEQ  */
  YYSYMBOL_tPLUS = 4,                      /* tPLUS  */
  YYSYMBOL_tMINUS = 5,                     /* tMINUS  */
  YYSYMBOL_tMULT = 6,                      /* tMULT  */
  YYSYMBOL_tDIV = 7,                       /* tDIV  */
  YYSYMBOL_tOPAR = 8,                      /* tOPAR  */
  YYSYMBOL_tCPAR = 9,                      /* tCPAR  */
  YYSYMBOL_tOCURLY = 10,                   /* tOCURLY  */
  YYSYMBOL_tCCURLY = 11,                   /* tCCURLY  */
  YYSYMBOL_tVOID = 12,                     /* tVOID  */
  YYSYMBOL_tMAIN = 13,                     /* tMAIN  */
  YYSYMBOL_tINT = 14,                      /* tINT  */
  YYSYMBOL_tCONST = 15,                    /* tCONST  */
  YYSYMBOL_tCOMMA = 16,                    /* tCOMMA  */
  YYSYMBOL_tPRINTF = 17,                   /* tPRINTF  */
  YYSYMBOL_tSEMIC = 18,                    /* tSEMIC  */
  YYSYMBOL_tINF = 19,                      /* tINF  */
  YYSYMBOL_tSUP = 20,                      /* tSUP  */
  YYSYMBOL_tEQU = 21,                      /* tEQU  */
  YYSYMBOL_tERROR = 22,                    /* tERROR  */
  YYSYMBOL_tIF = 23,                       /* tIF  */
  YYSYMBOL_tELSE = 24,                     /* tELSE  */
  YYSYMBOL_tELSIF = 25,                    /* tELSIF  */
  YYSYMBOL_tWHILE = 26,                    /* tWHILE  */
  YYSYMBOL_tSTAR = 27,                     /* tSTAR  */
  YYSYMBOL_tADDR = 28,                     /* tADDR  */
  YYSYMBOL_tNUM = 29,                      /* tNUM  */
  YYSYMBOL_tID = 30,                       /* tID  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_Program = 32,                   /* Program  */
  YYSYMBOL_DeclarationPart = 33,           /* DeclarationPart  */
  YYSYMBOL_Block = 34,                     /* Block  */
  YYSYMBOL_Line = 35,                      /* Line  */
  YYSYMBOL_IfElseStatement = 36,           /* IfElseStatement  */
  YYSYMBOL_IfStatement = 37,               /* IfStatement  */
  YYSYMBOL_Cond = 38,                      /* Cond  */
  YYSYMBOL_ElsifStatements = 39,           /* ElsifStatements  */
  YYSYMBOL_ElsifStatement = 40,            /* ElsifStatement  */
  YYSYMBOL_ElseStatement = 41,             /* ElseStatement  */
  YYSYMBOL_WhileStatement = 42,            /* WhileStatement  */
  YYSYMBOL_tWhileCond = 43,                /* tWhileCond  */
  YYSYMBOL_Term = 44,                      /* Term  */
  YYSYMBOL_Expr = 45,                      /* Expr  */
  YYSYMBOL_Assignment = 46,                /* Assignment  */
  YYSYMBOL_Declaration = 47,               /* Declaration  */
  YYSYMBOL_DeclaratorList = 48,            /* DeclaratorList  */
  YYSYMBOL_Declarator = 49,                /* Declarator  */
  YYSYMBOL_ConstDeclaratorList = 50,       /* ConstDeclaratorList  */
  YYSYMBOL_ConstDeclarator = 51            /* ConstDeclarator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    59,    62,    63,    66,    67,    70,    71,
      72,    73,    74,    77,    78,    79,    80,    83,    86,    90,
      91,    94,    97,   101,   104,   106,   107,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   124,
     129,   130,   133,   134,   137,   138,   141,   142,   145
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tEQ", "tPLUS",
  "tMINUS", "tMULT", "tDIV", "tOPAR", "tCPAR", "tOCURLY", "tCCURLY",
  "tVOID", "tMAIN", "tINT", "tCONST", "tCOMMA", "tPRINTF", "tSEMIC",
  "tINF", "tSUP", "tEQU", "tERROR", "tIF", "tELSE", "tELSIF", "tWHILE",
  "tSTAR", "tADDR", "tNUM", "tID", "$accept", "Program", "DeclarationPart",
  "Block", "Line", "IfElseStatement", "IfStatement", "Cond",
  "ElsifStatements", "ElsifStatement", "ElseStatement", "WhileStatement",
  "tWhileCond", "Term", "Expr", "Assignment", "Declaration",
  "DeclaratorList", "Declarator", "ConstDeclaratorList", "ConstDeclarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    14,    43,     6,   -53,    23,    38,   117,    42,    30,
      48,    60,   -53,     1,   -53,    68,    61,    -9,   -53,   -53,
      21,   -53,    66,    62,    63,   117,    75,   -53,    69,    49,
       1,     1,     1,     1,     1,   -53,   -53,    74,   -53,   116,
       1,   -53,   -53,    79,     1,    21,   -53,   -53,     1,   -53,
     117,    81,     1,    30,    87,   -53,    77,    92,    59,    98,
     116,   116,    -9,     1,     1,     1,     1,     1,     1,     1,
     116,    -9,    84,   -53,   -53,    91,   -53,   -53,   116,   -53,
       1,    49,    88,   -53,    31,    59,    59,   -53,   -53,    20,
      20,    20,    33,    -9,    99,   116,   -53,   -53,   -53,   -53,
      47,    -9,   -53,    65,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    24,     0,     0,     5,     6,    11,
      13,    12,     0,     0,     0,     0,    44,    40,    42,     0,
       0,     0,     0,     0,     0,    25,    26,     0,    27,    18,
       0,     3,     7,     0,     0,    14,    20,    15,     0,     8,
       0,     0,     0,     0,     0,    41,    46,     0,    33,     0,
      38,    37,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    19,    16,     0,     4,     2,    45,    43,
       0,     0,     0,    28,     0,    29,    30,    31,    32,    34,
      35,    36,     0,     0,     0,    48,    47,     9,    17,    22,
       0,     0,    21,     0,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -18,   -52,   -17,   -53,   -53,   -32,   -53,    70,
      71,   -53,   -53,   -53,   -29,   -53,   -53,    55,   -53,    29,
     -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    16,    17,    18,    19,    20,    37,    45,    46,
      47,    21,    22,    38,    39,    23,    24,    27,    28,    55,
      56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    57,    58,    59,    60,    61,    31,    51,    11,    32,
      84,    70,    72,    12,    13,     5,    75,    14,     6,    92,
       1,    15,     3,    78,    63,    64,    65,    66,    33,    34,
      35,    36,    76,     7,    85,    86,    87,    88,    89,    90,
      91,   100,    98,     4,    99,    43,    44,     8,    11,   103,
      11,    95,    25,    12,    13,    12,    13,    14,   102,    14,
      26,    15,    29,    15,    11,    65,    66,    42,    30,    12,
      13,    40,    41,    14,    48,    42,   104,    15,    52,    54,
      49,    50,    11,    42,    62,    53,    42,    12,    13,    71,
      80,    14,    77,    81,    93,    15,    63,    64,    65,    66,
      94,    82,    63,    64,    65,    66,    97,    83,    79,   101,
      96,    67,    68,    69,     0,    73,    74,    67,    68,    69,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,    11,    67,    68,    69,     0,    12,
      13,     0,     0,    14,     0,     0,     0,    15
};

static const yytype_int8 yycheck[] =
{
      17,    30,    31,    32,    33,    34,     5,    25,    17,     8,
      62,    40,    44,    22,    23,     9,    48,    26,    12,    71,
      13,    30,     8,    52,     4,     5,     6,     7,    27,    28,
      29,    30,    50,    10,    63,    64,    65,    66,    67,    68,
      69,    93,    11,     0,    11,    24,    25,     9,    17,   101,
      17,    80,    10,    22,    23,    22,    23,    26,    11,    26,
      30,    30,    14,    30,    17,     6,     7,    84,     8,    22,
      23,     3,    11,    26,     8,    92,    11,    30,     3,    30,
      18,    18,    17,   100,    10,    16,   103,    22,    23,    10,
       3,    26,    11,    16,    10,    30,     4,     5,     6,     7,
       9,     9,     4,     5,     6,     7,    18,     9,    53,    10,
      81,    19,    20,    21,    -1,    45,    45,    19,    20,    21,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    17,    19,    20,    21,    -1,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    32,     8,     0,     9,    12,    10,     9,    14,
      15,    17,    22,    23,    26,    30,    33,    34,    35,    36,
      37,    42,    43,    46,    47,    10,    30,    48,    49,    14,
       8,     5,     8,    27,    28,    29,    30,    38,    44,    45,
       3,    11,    35,    24,    25,    39,    40,    41,     8,    18,
      18,    33,     3,    16,    30,    50,    51,    45,    45,    45,
      45,    45,    10,     4,     5,     6,     7,    19,    20,    21,
      45,    10,    38,    40,    41,    38,    33,    11,    45,    48,
       3,    16,     9,     9,    34,    45,    45,    45,    45,    45,
      45,    45,    34,    10,     9,    45,    50,    18,    11,    11,
      34,    10,    11,    34,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    34,    34,    35,    35,
      35,    35,    35,    36,    36,    36,    36,    37,    38,    39,
      39,    40,    41,    42,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     6,     3,     1,     1,     2,     2,     5,
       1,     1,     1,     1,     2,     2,     3,     5,     1,     2,
       1,     5,     4,     7,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     2,     2,     3,
       2,     3,     1,     3,     1,     3,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: tMAIN tOPAR tVOID tCPAR tOCURLY DeclarationPart tCCURLY  */
#line 58 "parser.y"
                                                                  {;}
#line 1213 "parser.tab.c"
    break;

  case 3: /* Program: tMAIN tOPAR tCPAR tOCURLY DeclarationPart tCCURLY  */
#line 59 "parser.y"
                                                            {;}
#line 1219 "parser.tab.c"
    break;

  case 4: /* DeclarationPart: Declaration tSEMIC DeclarationPart  */
#line 62 "parser.y"
                                                     {;}
#line 1225 "parser.tab.c"
    break;

  case 5: /* DeclarationPart: Block  */
#line 63 "parser.y"
                        {;}
#line 1231 "parser.tab.c"
    break;

  case 8: /* Line: Assignment tSEMIC  */
#line 70 "parser.y"
                            {;}
#line 1237 "parser.tab.c"
    break;

  case 9: /* Line: tPRINTF tOPAR Expr tCPAR tSEMIC  */
#line 71 "parser.y"
                                          {add_code('C', (yyvsp[-2].addr), 0, 0);}
#line 1243 "parser.tab.c"
    break;

  case 10: /* Line: tERROR  */
#line 72 "parser.y"
                 {printf("Encountered Error\n");}
#line 1249 "parser.tab.c"
    break;

  case 11: /* Line: IfElseStatement  */
#line 73 "parser.y"
                          {}
#line 1255 "parser.tab.c"
    break;

  case 12: /* Line: WhileStatement  */
#line 74 "parser.y"
                         {}
#line 1261 "parser.tab.c"
    break;

  case 13: /* IfElseStatement: IfStatement  */
#line 77 "parser.y"
                              {add_code('L', pop_end_label, 0, 0);(yyval.nb) = (yyvsp[0].nb);}
#line 1267 "parser.tab.c"
    break;

  case 14: /* IfElseStatement: IfStatement ElsifStatements  */
#line 78 "parser.y"
                                              {add_code('L', pop_end_label, 0, 0);(yyval.nb) = (yyvsp[-1].nb);}
#line 1273 "parser.tab.c"
    break;

  case 15: /* IfElseStatement: IfStatement ElseStatement  */
#line 79 "parser.y"
                                            {add_code('L', pop_end_label, 0, 0);(yyval.nb) = (yyvsp[-1].nb);}
#line 1279 "parser.tab.c"
    break;

  case 16: /* IfElseStatement: IfStatement ElsifStatements ElseStatement  */
#line 80 "parser.y"
                                                            {add_code('L', pop_end_label, 0, 0);(yyval.nb) = (yyvsp[-2].nb);}
#line 1285 "parser.tab.c"
    break;

  case 17: /* IfStatement: tIF Cond tOCURLY Block tCCURLY  */
#line 83 "parser.y"
                                                 {push_end_label; (yyval.nb) = label_ptr; add_code('7', peek_end_label, 0, 0); add_code('L', (yyvsp[-3].nb),0,0); }
#line 1291 "parser.tab.c"
    break;

  case 18: /* Cond: Expr  */
#line 86 "parser.y"
                     {(yyval.nb) = label_ptr; add_code('8', (yyvsp[0].addr), label_ptr++, 0);}
#line 1297 "parser.tab.c"
    break;

  case 19: /* ElsifStatements: ElsifStatements ElsifStatement  */
#line 90 "parser.y"
                                                 {}
#line 1303 "parser.tab.c"
    break;

  case 20: /* ElsifStatements: ElsifStatement  */
#line 91 "parser.y"
                                 {}
#line 1309 "parser.tab.c"
    break;

  case 21: /* ElsifStatement: tELSIF Cond tOCURLY Block tCCURLY  */
#line 94 "parser.y"
                                                    {(yyval.nb) = (yyvsp[-3].nb); add_code('7', peek_end_label, 0, 0); add_code('L', (yyvsp[-3].nb), 0, 0);}
#line 1315 "parser.tab.c"
    break;

  case 22: /* ElseStatement: tELSE tOCURLY Block tCCURLY  */
#line 97 "parser.y"
                                              {}
#line 1321 "parser.tab.c"
    break;

  case 23: /* WhileStatement: tWhileCond tOPAR Cond tCPAR tOCURLY Block tCCURLY  */
#line 101 "parser.y"
                                                                    {add_code('7', pop_end_label,0,0);  add_code('L', (yyvsp[-4].nb),0,0);}
#line 1327 "parser.tab.c"
    break;

  case 24: /* tWhileCond: tWHILE  */
#line 104 "parser.y"
                    {(yyval.nb) = push_end_label; add_code('L', (yyval.nb),0,0);}
#line 1333 "parser.tab.c"
    break;

  case 25: /* Term: tNUM  */
#line 106 "parser.y"
               {(yyval.addr) = new_temp(); add_code('6', (yyval.addr), (yyvsp[0].nb), 0);}
#line 1339 "parser.tab.c"
    break;

  case 26: /* Term: tID  */
#line 107 "parser.y"
              {(yyval.addr) = lookup((yyvsp[0].var)); if ((yyval.addr) < 0) {printf("Error, symbol unknown. Exiting...\n"); exit(1);}}
#line 1345 "parser.tab.c"
    break;

  case 27: /* Expr: Term  */
#line 110 "parser.y"
               {(yyval.addr) = (yyvsp[0].addr);}
#line 1351 "parser.tab.c"
    break;

  case 28: /* Expr: tOPAR Expr tCPAR  */
#line 111 "parser.y"
                           { (yyval.addr) = (yyvsp[-1].addr);}
#line 1357 "parser.tab.c"
    break;

  case 29: /* Expr: Expr tPLUS Expr  */
#line 112 "parser.y"
                          {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('1', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1363 "parser.tab.c"
    break;

  case 30: /* Expr: Expr tMINUS Expr  */
#line 113 "parser.y"
                           {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('3', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1369 "parser.tab.c"
    break;

  case 31: /* Expr: Expr tMULT Expr  */
#line 114 "parser.y"
                          {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('2', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1375 "parser.tab.c"
    break;

  case 32: /* Expr: Expr tDIV Expr  */
#line 115 "parser.y"
                         {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('4', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1381 "parser.tab.c"
    break;

  case 33: /* Expr: tMINUS Expr  */
#line 116 "parser.y"
                      {free_temp((yyvsp[0].addr)); (yyval.addr) = (yyvsp[0].addr); int temp = new_temp(); add_code('6', temp, 0, 0); add_code('3', (yyvsp[0].addr), temp, (yyvsp[0].addr));}
#line 1387 "parser.tab.c"
    break;

  case 34: /* Expr: Expr tINF Expr  */
#line 117 "parser.y"
                         {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('9', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1393 "parser.tab.c"
    break;

  case 35: /* Expr: Expr tSUP Expr  */
#line 118 "parser.y"
                         {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('A', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1399 "parser.tab.c"
    break;

  case 36: /* Expr: Expr tEQU Expr  */
#line 119 "parser.y"
                         {free_temps((yyvsp[-2].addr),(yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('B', (yyval.addr), (yyvsp[-2].addr), (yyvsp[0].addr));}
#line 1405 "parser.tab.c"
    break;

  case 37: /* Expr: tADDR Expr  */
#line 120 "parser.y"
                     {free_temp((yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('6', (yyval.addr), (yyvsp[0].addr), 0);}
#line 1411 "parser.tab.c"
    break;

  case 38: /* Expr: tSTAR Expr  */
#line 121 "parser.y"
                     {free_temp((yyvsp[0].addr)); (yyval.addr) = new_temp(); add_code('5', (yyval.addr), (yyvsp[0].addr), 0);}
#line 1417 "parser.tab.c"
    break;

  case 39: /* Assignment: tID tEQ Expr  */
#line 124 "parser.y"
                               {free_temp((yyvsp[0].addr)); int addr = lookup((yyvsp[-2].var)); 
                                if (isConst(addr)) {printf("ERROR, editing const. Exiting...\n"); exit(1);}  
                                add_code('5', lookup((yyvsp[-2].var)), (yyvsp[0].addr), 0);
                                }
#line 1426 "parser.tab.c"
    break;

  case 40: /* Declaration: tINT DeclaratorList  */
#line 129 "parser.y"
                                      {}
#line 1432 "parser.tab.c"
    break;

  case 41: /* Declaration: tCONST tINT ConstDeclaratorList  */
#line 130 "parser.y"
                                                  {}
#line 1438 "parser.tab.c"
    break;

  case 44: /* Declarator: tID  */
#line 137 "parser.y"
                      {addSymbol((yyvsp[0].var), 0);}
#line 1444 "parser.tab.c"
    break;

  case 45: /* Declarator: tID tEQ Expr  */
#line 138 "parser.y"
                               {free_temp((yyvsp[0].addr)); addSymbol((yyvsp[-2].var), 0); add_code('5', lookup((yyvsp[-2].var)), (yyvsp[0].addr), 0);}
#line 1450 "parser.tab.c"
    break;

  case 48: /* ConstDeclarator: tID tEQ Expr  */
#line 145 "parser.y"
                              {free_temp((yyvsp[0].addr)); addSymbol((yyvsp[-2].var), 1); add_code('5', lookup((yyvsp[-2].var)), (yyvsp[0].addr), 0);}
#line 1456 "parser.tab.c"
    break;


#line 1460 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 147 "parser.y"

int yyparse();

int yyerror(const char *s) { fprintf(stderr, "Syntax Error : %s\n", s); return 1; }

void format_bin(); // Code below main function, for readability Exports file to binary code
void format_asm(); // Code below main function, for readability. Exports file to asm code

// https://github.com/black13/flex-and-bison/blob/master/ch04-input_management/03-input_from_strings/main.c
int main(int argc, char * argv[]) {
        if (argc == 2) {
        yyin = fopen(argv[1], "r");
        } else {
                yyin = stdin;
        }

        yyparse();

        if (argc == 2) {
                fclose(yyin);
        }

        int labelsSeen = 0; // How many temporary label lines we have seen so far
        int labelLine[1024]; // Associate labels with line
        // Convert lables to lines
        for (int i = 0; i < code_ptr; i++) {
                if (code[i].code == 'L') {
                        labelLine[code[i].a] = i - labelsSeen++ + 1;
                } 
        }

        for(int i = 0; i < code_ptr; i++) {
                if (code[i].code == '7') {
                        code[i].a = labelLine[code[i].a];
                }
                if (code[i].code == '8') {
                        code[i].b = labelLine[code[i].b];
                }
                
        }

        format_asm();
        format_bin();

        return 0;
}






























void format_asm() {
        f_asm = fopen("output_assembly.txt", "w");
        for(int i = 0; i < code_ptr; i++) {
                switch (code[i].code) {
                        case '1': fprintf(f_asm, "%s @%d @%d @%d\n", "ADD", code[i].a, code[i].b, code[i].c); break;
                        case '2': fprintf(f_asm, "%s @%d @%d @%d\n", "MUL", code[i].a, code[i].b, code[i].c); break;
                        case '3': fprintf(f_asm, "%s @%d @%d @%d\n", "SOU", code[i].a, code[i].b, code[i].c); break;
                        case '4': fprintf(f_asm, "%s @%d @%d @%d\n", "DIV", code[i].a, code[i].b, code[i].c); break;
                        case '5': fprintf(f_asm, "%s @%d @%d\n", "COP", code[i].a, code[i].b); break;
                        case '6': fprintf(f_asm, "%s @%d %d\n", "AFC", code[i].a, code[i].b); break;
                        case '7': fprintf(f_asm, "%s %d\n", "JMP", code[i].a); break;
                        case '8': fprintf(f_asm, "%s @%d %d\n", "JMF", code[i].a, code[i].b); break;
                        case '9': fprintf(f_asm, "%s @%d @%d @%d\n", "INF", code[i].a, code[i].b, code[i].c); break;
                        case 'A': fprintf(f_asm, "%s @%d @%d @%d\n", "SUP", code[i].a, code[i].b, code[i].c); break;
                        case 'B': fprintf(f_asm, "%s @%d @%d @%d\n", "EQU", code[i].a, code[i].b, code[i].c); break;
                        case 'C': fprintf(f_asm, "%s @%d\n", "PRI", code[i].a);
                        case 'L': break;
                }
        }
        fclose(f_asm);
}

void format_bin() {
        f_bin = fopen("output_binary.txt", "w");
        for(int i = 0; i < code_ptr; i++) {
                switch (code[i].code) {
                        case '1': fprintf(f_bin, "%d @%d @%d @%d\n", 1, code[i].a, code[i].b, code[i].c); break;
                        case '2': fprintf(f_bin, "%d @%d @%d @%d\n", 2, code[i].a, code[i].b, code[i].c); break;
                        case '3': fprintf(f_bin, "%d @%d @%d @%d\n", 3, code[i].a, code[i].b, code[i].c); break;
                        case '4': fprintf(f_bin, "%d @%d @%d @%d\n", 4, code[i].a, code[i].b, code[i].c); break;
                        case '5': fprintf(f_bin, "%d @%d @%d\n", 5, code[i].a, code[i].b); break;
                        case '6': fprintf(f_bin, "%d @%d %d\n", 6, code[i].a, code[i].b); break;
                        case '7': fprintf(f_bin, "%d %d\n", 7, code[i].a); break;
                        case '8': fprintf(f_bin, "%d @%d %d\n", 8, code[i].a, code[i].b); break;
                        case '9': fprintf(f_bin, "%d @%d @%d @%d\n", 9, code[i].a, code[i].b, code[i].c); break;
                        case 'A': fprintf(f_bin, "%c @%d @%d @%d\n", 'A', code[i].a, code[i].b, code[i].c); break;
                        case 'B': fprintf(f_bin, "%c @%d @%d @%d\n", 'B', code[i].a, code[i].b, code[i].c); break;
                        case 'C': fprintf(f_bin, "%c @%d\n", 'C', code[i].a);
                        case 'L': break;
                }
        }
        fclose(f_bin);
}
