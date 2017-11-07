/* Lexical Analyzer for MiniJava */

%option noyywrap

%{
    #define YY_USER_ACTION updateLocation();
    #define YY_DECL int yylex()

    #include "visitor.h"
    #include "syntax_analyzer.tab.h"
    #include <stdio.h>
    #include <ctype.h>
    #include <iostream>

    int line_number = 1;
    int column_number = 1;
    void updateLocation();
%}

%option yylineno

DIGIT       [0-9]
LETTER      [a-zA-Z_]
id          {LETTER}({DIGIT}|{LETTER})*
IntegerLiteral [1-9]{DIGIT}*|0

%%

"//".*$      
"/*".*"*/"  
"class"     { return CLASS; }
"extends"   { return EXTENDS; } 
"public"    { return PUBLIC; }
"private"   { return PRIVATE; }
"static void main"    { return STATICVOIDMAIN; } 

"System.out.println"    { return SYSTEMOUT; }
"String"    { return STRING; }
"int"       { return INT; }
"boolean"   { return BOOLEAN; }
"if"        { return IF; } 
"else"      { return ELSE; }
"while"     { return WHILE; }
"length"    { return LENGTH; }
"true"      { return TRUE; }
"false"     { return FALSE; }
"this"      { return THIS; }
"new"       { return NEW; }
"return"    { return RETURN; }

"&&"        { return AND; }
"||"        { return OR; }

"("         { return LEFTRBRACKET; }
")"         { return RIGHTRBRACKET; }
"{"         { return LEFTCBRACKET; }
"}"         { return RIGHTCBRACKET; }
"["         { return LEFTSBRACKET; }
"]"         { return RIGHTSBRACKET; }

";"         { return SEMICOLON; }
"!"         { return EXCLAMATION; }

"<"         { return LESS; }
"="         { return EQUALS; }

"."         { return DOT; }
","         { return COMMA; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"%"         { return MOD; }

{id}        { yylval.id = yytext; return IDENTIFIER; } // yylval.id = yytext; 
{IntegerLiteral} { yylval.intval = atoi(yytext); return INTEGERLITERAL; } // yylval.intval = atoi(yytext); 

[[:space:]]+

%%

void updateLocation()
{
    yylloc.first_line = line_number;
    yylloc.first_column = column_number;

    for( int i = 0; i < yyleng; i++ ) {
        if( yytext[i] == '\n' ) {
            line_number++;
            column_number = 1;
        } else {
            column_number++;
        }
    }

    yylloc.last_line = line_number;
    yylloc.last_column = column_number;
    yylval.value = strdup(yytext);
}
