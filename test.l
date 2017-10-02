/* Lexical Analalyzer for MiniJava */

%{
    // #define YY_USER_ACTION updateLocation()

    static int line_number = 1;
    static int column_number = 1;
    static void updateLocation();
%}

DIGIT [0-9]
LETER [a-zA-Z_]
id {LETER}({DIGIT}|{LETER})*
IntegerLiteral [1-9]{DIGIT}*|0

%%

"//".*$     printf("SINGLELINECOMMENT"); updateLocation();
"/*".*"*/"  printf("COMMENT"); updateLocation();
"class"     printf("CLASS"); updateLocation();
"extends"   printf("EXTENDS"); updateLocation(); 
"public"    printf("PUBLIC"); updateLocation();
"private"   printf("PRIVATE"); updateLocation();
"static"    printf("STATIC"); updateLocation(); 
"void"      printf("VOID"); updateLocation(); 
"main"      printf("MAIN"); updateLocation(); 
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
"&&"        printf("AND"); updateLocation();
"||"        printf("OR"); updateLocation();
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

[[:space:]]+ updateLocation();

.           {printf("error"); updateLocation();}

%%

static void updateLocation()
{
    for( int i = 0; i < yyleng; i++ )
    {
        if( yytext[i] == '\n' ) 
        {
            line_number++;
            column_number = 1;
        } 
        else 
        {
            column_number++;
        }
    }
    printf( "(%d,%d): ", line_number, column_number );
}
