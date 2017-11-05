/* Syntax Analyzer for MiniJava */

%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>

    extern FILE* yyin;
    extern int yylex();
    extern int yyparse();

    void yyerror(const char* s);
    void print_();
%}

%locations
%token-table

%union 
{
    int intval;
    char* id;  // TODO: all possible datatypes for semantic values
    char* value;
}

%token SINGLELINECOMMENT COMMENT
%token CLASS EXTENDS PUBLIC PRIVATE
%token STATICVOIDMAIN
%token SYSTEMOUT
%token STRING INT BOOLEAN
%token IF ELSE
%token WHILE
%token LENGTH
%token TRUE FALSE
%token THIS
%token NEW
%token RETURN
%token AND OR
%token LEFTRBRACKET RIGHTRBRACKET
%token LEFTCBRACKET RIGHTCBRACKET
%token LEFTSBRACKET RIGHTSBRACKET
%token QUESTION
%token SEMICOLON
%token EXCLAMATION
%token LESS GREATER LEQ GEQ
%token EQUALS
%token DOT COMMA
%token PLUS MINUS
%token MULTIPLY DIVIDE MOD
%token IDENTIFIER
%token INTEGERLITERAL

%start statements

%%

statements: | statements statement;

// TODO: split into multiple types
statement:    CLASS {print_();} 
            | EXTENDS {print_();} 
            | PUBLIC {print_();} 
            | PRIVATE {print_();} 
            | STATICVOIDMAIN {print_();} 
            | SYSTEMOUT {print_();} 
            | STRING {print_();} 
            | INT {print_();} 
            | BOOLEAN {print_();} 
            | IF {print_();} 
            | ELSE {print_();} 
            | WHILE {print_();} 
            | LENGTH {print_();} 
            | TRUE {print_();} 
            | FALSE {print_();} 
            | THIS {print_();} 
            | NEW {print_();} 
            | RETURN {print_();} 
            | AND {print_();} 
            | OR {print_();} 
            | LEFTRBRACKET {print_();} 
            | RIGHTRBRACKET {print_();} 
            | LEFTCBRACKET
            | RIGHTCBRACKET {print_();} 
            | LEFTSBRACKET {print_();} 
            | RIGHTSBRACKET {print_();} 
            | QUESTION {print_();} 
            | SEMICOLON {print_();} 
            | EXCLAMATION {print_();} 
            | LESS {print_();} 
            | GREATER {print_();} 
            | EQUALS {print_();} 
            | LEQ {print_();} 
            | GEQ {print_();} 
            | DOT {print_();} 
            | COMMA {print_();} 
            | PLUS {print_();} 
            | MINUS {print_();} 
            | MULTIPLY {print_();} 
            | DIVIDE {print_();} 
            | MOD {print_();} 
            | IDENTIFIER {print_();} 
            | INTEGERLITERAL {print_();} 
            | SINGLELINECOMMENT {print_();} 
            | COMMENT {print_();} 

%%

int main() 
{
    yyin = stdin;
    do {
        yyparse();
    } while(!feof(yyin));
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
