/* Lexical Analyzer for MiniJava */

%{
    // #define YY_USER_ACTION updateLocation()

    #include <stdio.h>
    #include <ctype.h>

    int line_number = 1;
    int column_number = 1;
    void updateLocation();
%}

DIGIT       [0-9]
LETTER      [a-zA-Z_]
id          {LETTER}({DIGIT}|{LETTER})*
IntegerLiteral [1-9]{DIGIT}*|0
LOGICOP     (&&|\|\|)

%%

"//".*$     printf("SINGLELINECOMMENT"); updateLocation();
"/*".*"*/"  printf("COMMENT"); updateLocation();
"class"     printf("CLASS"); updateLocation();
"extends"   printf("EXTENDS"); updateLocation(); 
"public"    printf("PUBLIC"); updateLocation();
"private"   printf("PRIVATE"); updateLocation();
"static void main"    printf("STATICVOIDMAIN"); updateLocation(); 

"System.out.println"    printf("SYSTEMOUT"); updateLocation();
"String"    printf("STRING"); updateLocation();
"int"       printf("INT"); updateLocation();
"boolean"   printf("BOOLEAN"); updateLocation();
"if"        printf("IF"); updateLocation(); 
"else"      printf("ELSE"); updateLocation();
"while"     printf("WHILE"); updateLocation();
"length"    printf("LENGTH"); updateLocation();
"true"      printf("TRUE"); updateLocation();
"false"     printf("FALSE"); updateLocation();
"this"      printf("THIS"); updateLocation();
"new"       printf("NEW"); updateLocation();
"return"    printf("RETURN"); updateLocation();

{LOGICOP}   printf("LOGICOP(%s)", yytext); updateLocation();
"("         printf("LEFTRBRACKET"); updateLocation();
")"         printf("RIGHTRBRACKET"); updateLocation();
"{"         printf("LEFTCBRACKET"); updateLocation();
"}"         printf("RIGHTCBRACKET"); updateLocation();
"]"         printf("LEFTSBRACKET"); updateLocation();
"?"         printf("QUESTION"); updateLocation();
";"         printf("SEMICOLON"); updateLocation();
"!"         printf("EXCLAMATION"); updateLocation();
"<"         printf("LESS"); updateLocation();
">"         printf("GREATER"); updateLocation();
"="         printf("EQUALS"); updateLocation();
"<="        printf("LEQ"); updateLocation();
">="        printf("GEQ"); updateLocation();
"*"         printf("ASTERISK"); updateLocation();
"."         printf("DOT"); updateLocation();
","         printf("COMMA"); updateLocation();
[\+\-\*\/\%]      printf("ARITHMETICOP(%s)", yytext); updateLocation();

{id}        {printf("ID(%s)", yytext); updateLocation();}
{IntegerLiteral} {printf("INTEGERLITERAL(%s)", yytext); updateLocation();}

[[:space:]]+ printf("%s", yytext); updateLocation();

.           {printf("ERROR"); updateLocation();}

%%

void updateLocation()
{
    for( int i = 0; i < yyleng; ++i )
    {
        if( yytext[i] == '\n' ) 
        {
            ++line_number;
            column_number = 1;
        } 
        else 
        {
            ++column_number;
        }
    }
    printf( "(%d,%d) ", line_number, column_number );
}
