/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
# define YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
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
    SINGLELINECOMMENT = 258,
    COMMENT = 259,
    CLASS = 260,
    EXTENDS = 261,
    PUBLIC = 262,
    PRIVATE = 263,
    STATICVOIDMAIN = 264,
    SYSTEMOUT = 265,
    STRING = 266,
    INT = 267,
    BOOLEAN = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    LENGTH = 272,
    TRUE = 273,
    FALSE = 274,
    THIS = 275,
    NEW = 276,
    RETURN = 277,
    AND = 278,
    OR = 279,
    LEFTRBRACKET = 280,
    RIGHTRBRACKET = 281,
    LEFTCBRACKET = 282,
    RIGHTCBRACKET = 283,
    LEFTSBRACKET = 284,
    RIGHTSBRACKET = 285,
    QUESTION = 286,
    SEMICOLON = 287,
    EXCLAMATION = 288,
    LESS = 289,
    GREATER = 290,
    LEQ = 291,
    GEQ = 292,
    EQUALS = 293,
    DOT = 294,
    COMMA = 295,
    PLUS = 296,
    MINUS = 297,
    MULTIPLY = 298,
    DIVIDE = 299,
    MOD = 300,
    IDENTIFIER = 301,
    INTEGERLITERAL = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "syntax_analyzer.y" /* yacc.c:1909  */

    int intval;
    char* id;  // TODO: all possible datatypes for semantic values
    char* value;

#line 108 "syntax_analyzer.tab.h" /* yacc.c:1909  */
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
