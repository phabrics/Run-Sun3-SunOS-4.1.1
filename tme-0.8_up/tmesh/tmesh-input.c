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



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TMESH_TOKEN_SOURCE = 258,
     TMESH_TOKEN_MKDIR = 259,
     TMESH_TOKEN_RMDIR = 260,
     TMESH_TOKEN_CD = 261,
     TMESH_TOKEN_PWD = 262,
     TMESH_TOKEN_LS = 263,
     TMESH_TOKEN_CONNECT = 264,
     TMESH_TOKEN_RM = 265,
     TMESH_TOKEN_MV = 266,
     TMESH_TOKEN_COMMAND = 267,
     TMESH_TOKEN_LOG = 268,
     TMESH_TOKEN_ALIAS = 269,
     TMESH_TOKEN_AT = 270,
     TMESH_TOKEN_PATHNAME = 271,
     TMESH_TOKEN_ARG = 272,
     TMESH_TOKEN_OPTS = 273
   };
#endif
/* Tokens.  */
#define TMESH_TOKEN_SOURCE 258
#define TMESH_TOKEN_MKDIR 259
#define TMESH_TOKEN_RMDIR 260
#define TMESH_TOKEN_CD 261
#define TMESH_TOKEN_PWD 262
#define TMESH_TOKEN_LS 263
#define TMESH_TOKEN_CONNECT 264
#define TMESH_TOKEN_RM 265
#define TMESH_TOKEN_MV 266
#define TMESH_TOKEN_COMMAND 267
#define TMESH_TOKEN_LOG 268
#define TMESH_TOKEN_ALIAS 269
#define TMESH_TOKEN_AT 270
#define TMESH_TOKEN_PATHNAME 271
#define TMESH_TOKEN_ARG 272
#define TMESH_TOKEN_OPTS 273




/* Copy the first part of user declarations.  */
#line 1 "tmesh-input.y"

/* $Id: tmesh-input.y,v 1.4 2006/11/15 23:11:31 fredette Exp $ */

/* tmesh/tmesh-input.y - the tme shell scanner and parser: */

/*
 * Copyright (c) 2003 Matt Fredette
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Matt Fredette.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <tme/common.h>
_TME_RCSID("$Id: tmesh-input.y,v 1.4 2006/11/15 23:11:31 fredette Exp $");

/* includes: */
#include <tme/threads.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tmesh-impl.h"

/* macros: */

/* internal token numbers: */
#define TMESH_TOKEN_UNDEF		(-1)
#define TMESH_TOKEN_EOF			(0)

/* internal character numbers: */
#define TMESH_C_EOF_SEMICOLON		(TMESH_C_YIELD - 1)
#define TMESH_C_UNDEF			(TMESH_C_EOF_SEMICOLON - 2)

#define YYSTYPE struct tmesh_parser_value
#define YYDEBUG 1
#define YYMAXDEPTH 10000

//brad
#define YYLTYPE_IS_TRIVIAL 0
#define YYENABLE_NLS 0

/* types: */

/* globals: */
static tme_mutex_t _tmesh_input_mutex;
static struct tmesh *_tmesh_input;
static char **_tmesh_output;
static int _tmesh_input_yielding;
static YYSTYPE *_tmesh_input_parsed;

/* prototypes: */
static int yylex _TME_P((void));
static void yyerror _TME_P((char *));
static void _tmesh_scanner_in_args _TME_P((void));
static void _tmesh_parser_argv_arg _TME_P((struct tmesh_parser_argv *, char *, int));



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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 223 "tmesh-input.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   56

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNRULES -- Number of states.  */
#define YYNSTATES  74

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    20,    19,
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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    30,    32,    36,    40,    44,
      48,    51,    56,    60,    63,    67,    72,    76,    80,    85,
      87,    89,    90,    92,    95,    97,   100,   102,   104,   108,
     114,   118,   120
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      22,     0,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,     1,    19,    -1,
      19,    -1,     3,    35,    19,    -1,     4,    35,    19,    -1,
       5,    35,    19,    -1,     6,    35,    19,    -1,     7,    19,
      -1,     8,    42,    36,    19,    -1,     9,    41,    19,    -1,
      41,    19,    -1,    10,    35,    19,    -1,    11,    35,    35,
      19,    -1,    12,    37,    19,    -1,    13,    37,    19,    -1,
      14,    35,    35,    19,    -1,    16,    -1,    16,    -1,    -1,
      16,    -1,    37,    17,    -1,    17,    -1,    38,    17,    -1,
      20,    -1,    15,    -1,    37,    39,    38,    -1,    37,    40,
      38,    39,    38,    -1,    37,    40,    38,    -1,    18,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   121,   125,   130,   135,
     140,   143,   152,   154,   159,   164,   173,   178,   183,   192,
     196,   198,   202,   209,   219,   225,   234,   237,   240,   250,
     256,   265,   267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TMESH_TOKEN_SOURCE",
  "TMESH_TOKEN_MKDIR", "TMESH_TOKEN_RMDIR", "TMESH_TOKEN_CD",
  "TMESH_TOKEN_PWD", "TMESH_TOKEN_LS", "TMESH_TOKEN_CONNECT",
  "TMESH_TOKEN_RM", "TMESH_TOKEN_MV", "TMESH_TOKEN_COMMAND",
  "TMESH_TOKEN_LOG", "TMESH_TOKEN_ALIAS", "TMESH_TOKEN_AT",
  "TMESH_TOKEN_PATHNAME", "TMESH_TOKEN_ARG", "TMESH_TOKEN_OPTS", "';'",
  "':'", "$accept", "command", "command_source", "command_mkdir",
  "command_rmdir", "command_cd", "command_pwd", "command_ls",
  "command_connect", "command_rm", "command_mv", "command_command",
  "command_log", "command_alias", "pathname", "pathname_opt",
  "pathname_args", "args", "colon", "at", "connection", "opts_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    59,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    21,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    23,    24,    25,    26,
      27,    28,    29,    29,    30,    31,    32,    33,    34,    35,
      36,    36,    37,    37,    38,    38,    39,    40,    41,    41,
      41,    42,    42
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     3,     3,     3,
       2,     4,     3,     2,     3,     4,     3,     3,     4,     1,
       1,     0,     1,     2,     1,     2,     1,     1,     3,     5,
       3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,    32,    15,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    29,     0,     0,     0,     0,    20,    41,    31,
       0,     0,     0,     0,     0,     0,     1,    37,    33,    36,
       0,     0,    23,    16,    17,    18,    19,    30,     0,    22,
      24,     0,    26,    27,     0,    34,    38,    40,    21,    25,
      28,    35,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    33,    58,    29,    66,    50,    51,
      30,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int8 yypact[] =
{
      22,   -15,     1,     1,     1,     1,    -7,     3,     6,     1,
       1,     6,     6,     1,   -49,   -49,    37,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    -6,
      21,   -49,   -49,    24,    25,    26,    27,   -49,   -49,    31,
      29,    30,     1,    -4,    -1,     1,   -49,   -49,   -49,   -49,
      33,    33,   -49,   -49,   -49,   -49,   -49,   -49,    32,   -49,
     -49,    34,   -49,   -49,    35,   -49,    38,   -12,   -49,   -49,
     -49,   -49,    33,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,    -3,   -49,     8,   -48,   -11,   -49,
      44,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    35,    36,    67,    31,    71,    41,    42,    49,    47,
      45,    48,    37,    48,    49,    62,    48,    32,    63,    43,
      44,    38,    14,     1,    73,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    46,    14,    61,
      52,    15,    64,    53,    54,    55,    56,    57,    59,    60,
      65,    68,    40,    69,    70,    71,    72
};

static const yytype_uint8 yycheck[] =
{
       3,     4,     5,    51,    19,    17,     9,    10,    20,    15,
      13,    17,    19,    17,    20,    19,    17,    16,    19,    11,
      12,    18,    16,     1,    72,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,    16,    42,
      19,    19,    45,    19,    19,    19,    19,    16,    19,    19,
      17,    19,     8,    19,    19,    17,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    16,    19,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    37,
      41,    19,    16,    35,    35,    35,    35,    19,    18,    42,
      41,    35,    35,    37,    37,    35,     0,    15,    17,    20,
      39,    40,    19,    19,    19,    19,    19,    16,    36,    19,
      19,    35,    19,    19,    35,    17,    38,    38,    19,    19,
      19,    17,    39,    38
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# if YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

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
int yyparse (void);
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
yyparse (void)
#else
int
yyparse ()

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
#line 103 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 3:
#line 104 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 4:
#line 105 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 5:
#line 106 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 6:
#line 107 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 7:
#line 108 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 8:
#line 109 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 9:
#line 110 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 10:
#line 111 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 11:
#line 112 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 12:
#line 113 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 13:
#line 114 "tmesh-input.y"
    { *_tmesh_input_parsed = (yyvsp[(1) - (1)]); YYACCEPT; }
    break;

  case 14:
#line 115 "tmesh-input.y"
    { YYABORT; }
    break;

  case 15:
#line 117 "tmesh-input.y"
    { _tmesh_input_parsed->tmesh_parser_value_token = TMESH_TOKEN_UNDEF; YYACCEPT; }
    break;

  case 16:
#line 122 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 17:
#line 126 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 18:
#line 131 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 19:
#line 136 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 21:
#line 144 "tmesh-input.y"
    {
  (yyval) = (yyvsp[(2) - (4)]);
  (yyval).tmesh_parser_value_strings[1] = (yyvsp[(3) - (4)]).tmesh_parser_value_strings[0];
  (yyval).tmesh_parser_value_token = (yyvsp[(1) - (4)]).tmesh_parser_value_token;
}
    break;

  case 22:
#line 153 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 23:
#line 155 "tmesh-input.y"
    { (yyval) = (yyvsp[(1) - (2)]); (yyval).tmesh_parser_value_token = TMESH_TOKEN_CONNECT; }
    break;

  case 24:
#line 160 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 25:
#line 165 "tmesh-input.y"
    {
  (yyval) = (yyvsp[(2) - (4)]);
  (yyval).tmesh_parser_value_strings[1] = (yyvsp[(3) - (4)]).tmesh_parser_value_strings[0];
  (yyval).tmesh_parser_value_token = (yyvsp[(1) - (4)]).tmesh_parser_value_token;
}
    break;

  case 26:
#line 174 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 27:
#line 179 "tmesh-input.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).tmesh_parser_value_token = (yyvsp[(1) - (3)]).tmesh_parser_value_token; }
    break;

  case 28:
#line 184 "tmesh-input.y"
    {
  (yyval) = (yyvsp[(2) - (4)]);
  (yyval).tmesh_parser_value_strings[1] = (yyvsp[(3) - (4)]).tmesh_parser_value_strings[0];
  (yyval).tmesh_parser_value_token = (yyvsp[(1) - (4)]).tmesh_parser_value_token;
}
    break;

  case 31:
#line 198 "tmesh-input.y"
    { (yyval).tmesh_parser_value_strings[0] = NULL; }
    break;

  case 32:
#line 203 "tmesh-input.y"
    { 
  _tmesh_parser_argv_arg(&(yyval).tmesh_parser_value_argvs[0], 
			 (yyvsp[(1) - (1)]).tmesh_parser_value_pathname0, 
			 TRUE);
  _tmesh_scanner_in_args();
}
    break;

  case 33:
#line 210 "tmesh-input.y"
    {
  (yyval) = (yyvsp[(1) - (2)]); 
  _tmesh_parser_argv_arg(&(yyval).tmesh_parser_value_argvs[0], 
			 (yyvsp[(2) - (2)]).tmesh_parser_value_arg, 
			 FALSE);
}
    break;

  case 34:
#line 220 "tmesh-input.y"
    {
  _tmesh_parser_argv_arg(&(yyval).tmesh_parser_value_argvs[0], 
			 (yyvsp[(1) - (1)]).tmesh_parser_value_arg, 
			 TRUE);
}
    break;

  case 35:
#line 226 "tmesh-input.y"
    { 
  (yyval) = (yyvsp[(1) - (2)]); 
  _tmesh_parser_argv_arg(&(yyval).tmesh_parser_value_argvs[0], 
			 (yyvsp[(2) - (2)]).tmesh_parser_value_arg, 
			 FALSE);
}
    break;

  case 36:
#line 234 "tmesh-input.y"
    { _tmesh_scanner_in_args(); }
    break;

  case 37:
#line 237 "tmesh-input.y"
    { _tmesh_scanner_in_args(); }
    break;

  case 38:
#line 241 "tmesh-input.y"
    {
  if ((yyvsp[(1) - (3)]).tmesh_parser_value_argvs[0].tmesh_parser_argv_argc > 1) {
    yyerror(_("expected 'at'"));
    YYERROR;
  }
  (yyval).tmesh_parser_value_argvs[0] = (yyvsp[(1) - (3)]).tmesh_parser_value_argvs[0];
  (yyval).tmesh_parser_value_argvs[1].tmesh_parser_argv_argv = NULL;
  (yyval).tmesh_parser_value_argvs[2] = (yyvsp[(3) - (3)]).tmesh_parser_value_argvs[0];
}
    break;

  case 39:
#line 251 "tmesh-input.y"
    {
  (yyval).tmesh_parser_value_argvs[0] = (yyvsp[(1) - (5)]).tmesh_parser_value_argvs[0];
  (yyval).tmesh_parser_value_argvs[1] = (yyvsp[(3) - (5)]).tmesh_parser_value_argvs[0];
  (yyval).tmesh_parser_value_argvs[2] = (yyvsp[(5) - (5)]).tmesh_parser_value_argvs[0];
}
    break;

  case 40:
#line 257 "tmesh-input.y"
    {
  (yyval).tmesh_parser_value_argvs[0] = (yyvsp[(1) - (3)]).tmesh_parser_value_argvs[0];
  (yyval).tmesh_parser_value_argvs[1] = (yyvsp[(3) - (3)]).tmesh_parser_value_argvs[0];
  (yyval).tmesh_parser_value_argvs[2].tmesh_parser_argv_argv = NULL;
}
    break;

  case 42:
#line 267 "tmesh-input.y"
    { (yyval).tmesh_parser_value_strings[0] = NULL; }
    break;


/* Line 1267 of yacc.c.  */
#line 1710 "tmesh-input.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
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
		      yytoken, &yylval);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 270 "tmesh-input.y"


/* this adds a new argument to an argument vector: */
static void
_tmesh_parser_argv_arg(struct tmesh_parser_argv *argv, char *arg, int new)
{

  /* if we're starting a new argv, allocate the initial vector, else
     make sure the argv has enough room for the new argument and a
     trailing NULL that _tmesh_command_connect will add later: */
  if (new) {
    argv->tmesh_parser_argv_size = 8;
    argv->tmesh_parser_argv_argv = 
      _tmesh_gc_new(_tmesh_input,
		    char *, 
		    argv->tmesh_parser_argv_size);
    argv->tmesh_parser_argv_argc = 0;
  }
  else if ((argv->tmesh_parser_argv_argc + 1)
	   >= argv->tmesh_parser_argv_size) {
    argv->tmesh_parser_argv_size +=
      (2
       + (argv->tmesh_parser_argv_size >> 1));
    argv->tmesh_parser_argv_argv = 
      _tmesh_gc_renew(_tmesh_input,
		      char *, 
		      argv->tmesh_parser_argv_argv,
		      argv->tmesh_parser_argv_size);
  }

  /* put in the new argument: */
  argv->tmesh_parser_argv_argv[argv->tmesh_parser_argv_argc++] = arg;
}

/* this is called by the parser when it encounters an error: */
static void
yyerror(char *msg)
{
  tme_output_append(_tmesh_output, "%s", msg);
  _tmesh_input->tmesh_scanner.tmesh_scanner_in_args = FALSE;
}

/* this is called by the parser when args can be expected: */
static void
_tmesh_scanner_in_args(void)
{
  _tmesh_input->tmesh_scanner.tmesh_scanner_in_args = TRUE;
}

/* this matches a collected token: */
static int
_tmesh_scanner_token(struct tmesh_scanner *scanner)
{
  int token;
  char *string;
  int keep_string;

  /* if we have no collected token, return no token: */
  if (scanner->tmesh_scanner_token_string_size == 0
      || scanner->tmesh_scanner_token_string_len == 0) {
    return (TMESH_TOKEN_UNDEF);
  }

  /* get the collected token: */
  string = scanner->tmesh_scanner_token_string;
  string[scanner->tmesh_scanner_token_string_len] = '\0';

  /* assume we won't need to keep this string: */
  keep_string = FALSE;

  /* the reserved word "at" is always recognized, since it can
     terminate a list of arguments: */
  if (!strcmp(string, "at")) {
    token = TMESH_TOKEN_AT;
    scanner->tmesh_scanner_in_args = FALSE;
  }
  
  /* if we're in arguments, every other collected token is an argument: */
  else if (scanner->tmesh_scanner_in_args) {
    token = TMESH_TOKEN_ARG;
    keep_string = TRUE;
  }

  /* otherwise, if we're not in arguments, every other collected token
     is either a reserved word, options, or a pathname: */
  else {
    if (!strcmp(string, "source")) {
      token = TMESH_TOKEN_SOURCE;
    }  
    else if (!strcmp(string, "cd")) {
      token = TMESH_TOKEN_CD;
    }  
    else if (!strcmp(string, "pwd")) {
      token = TMESH_TOKEN_CD;
    }  
    else if (!strcmp(string, "ls")) {
      token = TMESH_TOKEN_LS;
    }  
    else if (!strcmp(string, "rm")) {
      token = TMESH_TOKEN_RM;
    }  
    else if (!strcmp(string, "connect")) {
      token = TMESH_TOKEN_CONNECT;
    }  
    else if (!strcmp(string, "mkdir")) {
      token = TMESH_TOKEN_MKDIR;
    }  
    else if (!strcmp(string, "rmdir")) {
      token = TMESH_TOKEN_RMDIR;
    }  
    else if (!strcmp(string, "mv")) {
      token = TMESH_TOKEN_MV;
    }
    else if (!strcmp(string, "command")) {
      token = TMESH_TOKEN_COMMAND;
    }  
    else if (!strcmp(string, "log")) {
      token = TMESH_TOKEN_LOG;
    }  
    else if (!strcmp(string, "alias")) {
      token = TMESH_TOKEN_ALIAS;
    }  
    else if (string[0] == '-') {
      token = TMESH_TOKEN_OPTS;
      keep_string = TRUE;
    }
    else {
      token = TMESH_TOKEN_PATHNAME;
      keep_string = TRUE;
    }
  }

  /* if we need to keep this string, put it in yylval, else recycle it: */
  yylval.tmesh_parser_value_token = token;
  if (keep_string) {
    yylval.tmesh_parser_value_strings[0] = string;
    scanner->tmesh_scanner_token_string_size = 0;
  }
  else {
    yylval.tmesh_parser_value_strings[0] = NULL;
    scanner->tmesh_scanner_token_string_len = 0;
  }

  return (token);
}

/* our scanner: */
int
yylex(void)
{
  struct tmesh_scanner *scanner;
  struct tmesh_io_stack *stack;
  struct tmesh_io *source;
  int token, c;
  
  /* recover our scanner state: */
  scanner = &_tmesh_input->tmesh_scanner;
  stack = _tmesh_input->tmesh_io_stack;
  source = &stack->tmesh_io_stack_io;

  /* bump the input line: */
  source->tmesh_io_input_line += scanner->tmesh_scanner_next_line;
  scanner->tmesh_scanner_next_line = 0;

  /* if we previously scanned the next token to return, return it
     and clear it, unless it's EOF, which sticks: */
  token = scanner->tmesh_scanner_token_next;
  if (token != TMESH_TOKEN_UNDEF) {
    if (token != TMESH_TOKEN_EOF) {
      scanner->tmesh_scanner_token_next = TMESH_TOKEN_UNDEF;
    }
    return (token);
  }

  /* loop forever: */
  for (;;) {

    /* get the next character: */
    c = scanner->tmesh_scanner_c_next;
    if (c == TMESH_C_UNDEF) {
      c = (*source->tmesh_io_getc)(source);
    }
    scanner->tmesh_scanner_c_next = TMESH_C_UNDEF;

    /* if this is an EOF: */
    if (c == TMESH_C_EOF) {

      /* turn c into the EOF semicolon: */
      c = TMESH_C_EOF_SEMICOLON;

      /* if we have collected a token, save the EOF semicolon and return the token: */
      token = _tmesh_scanner_token(scanner);
      if (token != TMESH_TOKEN_UNDEF) {
	scanner->tmesh_scanner_c_next = c;
	return (token);
      }
    }

    /* if this is an EOF semicolon: */
    if (c == TMESH_C_EOF_SEMICOLON) {

      /* quoted strings and comments (and commands, for that matter) cannot cross EOF boundaries: */
      scanner->tmesh_scanner_in_quotes = FALSE;
      scanner->tmesh_scanner_in_comment = FALSE;

      /* close the now-finished source: */
      (*source->tmesh_io_close)(source, 
				(stack->tmesh_io_stack_next != NULL
				 ? &stack->tmesh_io_stack_next->tmesh_io_stack_io
				 : NULL));

      /* pop the io stack: */
      _tmesh_input->tmesh_io_stack = stack->tmesh_io_stack_next;
      tme_free(source->tmesh_io_name);
      tme_free(stack);
      
      /* if we have emptied the source stack, we are really at EOF,
	 and the next time we're called we will return that: */
      stack = _tmesh_input->tmesh_io_stack;
      source = &stack->tmesh_io_stack_io;
      if (stack == NULL) {
	scanner->tmesh_scanner_token_next = TMESH_TOKEN_EOF;
	return (TMESH_TOKEN_EOF);
      }

      /* return the EOF semicolon: */
      return (';');
    }

    /* if this is a yield: */
    if (c == TMESH_C_YIELD) {

      /* we are yielding: */
      _tmesh_input_yielding = TRUE;

      /* return an EOF token: */
      return (TMESH_TOKEN_EOF);
    }    

    /* if we're in a comment: */
    if (scanner->tmesh_scanner_in_comment) {
      if (c != '\n') {
	continue;
      }
      scanner->tmesh_scanner_in_comment = FALSE;
    }

    /* if this is quotation marks: */
    if (c == '"') {
      scanner->tmesh_scanner_in_quotes = !scanner->tmesh_scanner_in_quotes;
      continue;
    }

    /* other than quotation marks, every character either delimits
       tokens or is collected into the current token: */
    if (

	/* any character inside quotes is collected: */
	scanner->tmesh_scanner_in_quotes

	/* any alphanumeric character is collected: */
	|| isalnum(c)

	/* any period, slash, hyphen, and underscore character is collected: */
	|| c == '.'
	|| c == '/'
	|| c == '-'
	|| c == '_'
	) {

      /* allocate or grow the token buffer as needed.  we always
	 make sure there's room for this new character, and a trailing
	 NUL that _tmesh_scanner_token may add: */
      if (scanner->tmesh_scanner_token_string_size == 0) {
	scanner->tmesh_scanner_token_string_len = 0;
	scanner->tmesh_scanner_token_string_size = 8;
	scanner->tmesh_scanner_token_string = 
	  _tmesh_gc_new(_tmesh_input,
			char, 
			scanner->tmesh_scanner_token_string_size);
      }
      else if ((scanner->tmesh_scanner_token_string_len + 1)
	       >= scanner->tmesh_scanner_token_string_size) {
	scanner->tmesh_scanner_token_string_size +=
	  (2
	   + (scanner->tmesh_scanner_token_string_size >> 1));
	scanner->tmesh_scanner_token_string = 
	  _tmesh_gc_renew(_tmesh_input,
			  char, 
			  scanner->tmesh_scanner_token_string,
			  scanner->tmesh_scanner_token_string_size);
      }

      /* collect the character into the buffer: */
      scanner->tmesh_scanner_token_string[scanner->tmesh_scanner_token_string_len++] = c;
    }

    /* delimit this token: */
    else {

      /* if we have collected a token, save the delimiter and return the token: */
      token = _tmesh_scanner_token(scanner);
      if (token != TMESH_TOKEN_UNDEF) {
	scanner->tmesh_scanner_c_next = c;
	return (token);
      }

      /* a carriage return or a newline becomes a semicolon, and
	 a pound sign begins a comment: */
      if (c == '\n') {
	c = ';';
	scanner->tmesh_scanner_next_line = 1;
      }
      else if (c == '\r') {
	c = ';';
      }
      else if (c == '#') {
	scanner->tmesh_scanner_in_comment = TRUE;
	scanner->tmesh_scanner_in_args = FALSE;
	continue;
      }

      /* return a non-whitespace delimiter as a token, and this resets
         the args state: */
      if (!isspace(c)) {
	scanner->tmesh_scanner_in_args = FALSE;
	return (c);
      }
    }
  }
  /* NOTREACHED */
}

/* this is called to parse input: */
int
_tmesh_yyparse(struct tmesh *tmesh, struct tmesh_parser_value *value, char **_output, int *_yield)
{
  struct tmesh_scanner *scanner;
  int rc;
  int command;

  /* initialize the scanner: */
  scanner = &tmesh->tmesh_scanner;
  scanner->tmesh_scanner_token_next = TMESH_TOKEN_UNDEF;
  scanner->tmesh_scanner_c_next = TMESH_C_UNDEF;
  scanner->tmesh_scanner_in_comment = FALSE;
  scanner->tmesh_scanner_in_quotes = FALSE;
  scanner->tmesh_scanner_in_args = FALSE;
  scanner->tmesh_scanner_token_string_size = 0;

  /* lock the input mutex: */
  tme_mutex_lock(&_tmesh_input_mutex);

  /* set this tmesh for input: */
  _tmesh_input = tmesh;
  _tmesh_output = _output;
  
  /* assume that we will not have to yield: */
  _tmesh_input_yielding = FALSE;

  /* call the parser: */
  _tmesh_input_parsed = value;
  rc = (yyparse()
	? EINVAL
	: TME_OK);

  /* tell our caller if we're yielding: */
  *_yield = _tmesh_input_yielding;

  /* unlock the input mutex: */
  tme_mutex_unlock(&_tmesh_input_mutex);

  /* if the parse was successful, map the command token number to a command number: */
  if (rc == TME_OK && !*_yield) {
    switch (value->tmesh_parser_value_token) {
    default: assert(FALSE);
    case TMESH_TOKEN_UNDEF:	command = TMESH_COMMAND_NOP; break;
    case TMESH_TOKEN_SOURCE:	command = TMESH_COMMAND_SOURCE; break;
    case TMESH_TOKEN_MKDIR:	command = TMESH_COMMAND_MKDIR; break;
    case TMESH_TOKEN_RMDIR:	command = TMESH_COMMAND_RMDIR; break;
    case TMESH_TOKEN_CD:	command = TMESH_COMMAND_CD; break;
    case TMESH_TOKEN_PWD:	command = TMESH_COMMAND_PWD; break;
    case TMESH_TOKEN_LS:	command = TMESH_COMMAND_LS; break;
    case TMESH_TOKEN_CONNECT:	command = TMESH_COMMAND_CONNECT; break;
    case TMESH_TOKEN_RM:	command = TMESH_COMMAND_RM; break;
    case TMESH_TOKEN_COMMAND:	command = TMESH_COMMAND_COMMAND; break;
    case TMESH_TOKEN_LOG:	command = TMESH_COMMAND_LOG; break;
    case TMESH_TOKEN_ALIAS:	command = TMESH_COMMAND_ALIAS; break;
    }
    value->tmesh_parser_value_command = command;
  }

  /* done: */
  return (rc);
}

