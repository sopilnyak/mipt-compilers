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
#line 25 "syntax_analyzer.y" /* yacc.c:1909  */

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

#line 125 "syntax_analyzer.tab.h" /* yacc.c:1909  */
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
