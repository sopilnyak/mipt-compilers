/* Syntax Analyzer for MiniJava */

%{
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
%}

%locations
%token-table

%union 
{
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
}

%locations

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
%token LEFTRBRACKET RIGHTRBRACKET
%token LEFTCBRACKET RIGHTCBRACKET
%token RIGHTSBRACKET
%token SEMICOLON
%token EQUALS
%token COMMA
%token <id> IDENTIFIER
%token <intval> INTEGERLITERAL
%token END 0

%left LEFTSBRACKET
%left AND OR
%left LESS
%left DOT 
%left PLUS MINUS
%left MULTIPLY MOD
%right EXCLAMATION

%type <program> goal
%type <mainClass> main_class
%type <classes> classes
%type <classDeclaration> class
%type <varDeclarations> var_declarations
%type <varDeclaration> var_declaration
%type <methodDeclarations> method_declarations
%type <methodDeclaration> method_declaration
%type <methodModifier> method_modifier
%type <arguments> arguments
%type <type> type
%type <statements> statements
%type <statement> statement
%type <expressions> expressions
%type <expression> expression
%type <identifier> id

%destructor { delete $$; } <program> <mainClass> <classes> <classDeclaration> <varDeclarations> <varDeclaration>
<methodDeclarations> <methodDeclaration> <methodModifier> <arguments> <type> <statements> <statement>
<expressions> <expression> <identifier>

%start goal

%%

goal                : main_class classes END { $$ = new Program($1, $2); $$->accept(printer); print_(); }
                    | main_class END { $$ = new Program($1, nullptr); $$->accept(printer); print_(); }
                    ;

main_class          : CLASS id LEFTCBRACKET
                      PUBLIC STATICVOIDMAIN LEFTRBRACKET STRING LEFTSBRACKET RIGHTSBRACKET id RIGHTRBRACKET
                      LEFTCBRACKET statements RIGHTCBRACKET
                      RIGHTCBRACKET { $$ = new MainClass($2, $10, $13); print_(); }
                    ;

classes             : classes class { $$ = new ClassDeclarationList($1, $2); print_(); }
                    | class { $$ = new ClassDeclarationList(nullptr, $1); print_(); }
                    ;

class               : CLASS id LEFTCBRACKET RIGHTCBRACKET { $$ = new ClassDeclaration($2, nullptr, nullptr, nullptr); print_(); }
                    | CLASS id LEFTCBRACKET var_declarations RIGHTCBRACKET { $$ = new ClassDeclaration($2, nullptr, $4, nullptr); print_(); }
                    | CLASS id LEFTCBRACKET method_declarations RIGHTCBRACKET { $$ = new ClassDeclaration($2, nullptr, nullptr, $4); print_(); }
                    | CLASS id LEFTCBRACKET var_declarations method_declarations RIGHTCBRACKET { $$ = new ClassDeclaration($2, nullptr, $4, $5); print_(); }
                    | CLASS id EXTENDS id LEFTCBRACKET RIGHTCBRACKET { $$ = new ClassDeclaration($2, $4, nullptr, nullptr); print_(); }
                    | CLASS id EXTENDS id LEFTCBRACKET var_declarations RIGHTCBRACKET { $$ = new ClassDeclaration($2, $4, $6, nullptr); print_(); }
                    | CLASS id EXTENDS id LEFTCBRACKET method_declarations RIGHTCBRACKET { $$ = new ClassDeclaration($2, $4, nullptr, $6); print_(); }
                    | CLASS id EXTENDS id LEFTCBRACKET var_declarations method_declarations RIGHTCBRACKET { $$ = new ClassDeclaration($2, $4, $6, $7); print_(); }
                    ;

var_declarations    : var_declarations var_declaration { $$ = new VarDeclarationList($1, $2); print_(); }
                    | var_declaration { $$ = new VarDeclarationList(nullptr, $1); print_(); }
                    ;

var_declaration     : type id SEMICOLON { $$ = new VarDeclaration($1, $2); print_(); }
                    ;

method_declarations : method_declarations method_declaration { $$ = new MethodDeclarationList($1, $2); print_(); }
                    | method_declaration { $$ = new MethodDeclarationList(nullptr, $1); print_(); }
                    ;

method_declaration  : method_modifier type id LEFTRBRACKET arguments RIGHTRBRACKET LEFTCBRACKET var_declarations statements 
                      RETURN expression SEMICOLON RIGHTCBRACKET { $$ = new MethodDeclaration($1, $2, $3, $5, $8, $9, $11); print_(); }
                    | method_modifier type id LEFTRBRACKET arguments RIGHTRBRACKET LEFTCBRACKET var_declarations 
                      RETURN expression SEMICOLON RIGHTCBRACKET { $$ = new MethodDeclaration($1, $2, $3, $5, $8, nullptr, $10); print_(); }
                    | method_modifier type id LEFTRBRACKET arguments RIGHTRBRACKET LEFTCBRACKET statements 
                      RETURN expression SEMICOLON RIGHTCBRACKET { $$ = new MethodDeclaration($1, $2, $3, $5, nullptr, $8, $10); print_(); }
                    | method_modifier type id LEFTRBRACKET arguments RIGHTRBRACKET LEFTCBRACKET 
                      RETURN expression SEMICOLON RIGHTCBRACKET { $$ = new MethodDeclaration($1, $2, $3, $5, nullptr, nullptr, $9); print_(); }
                    ;

method_modifier     : PUBLIC { $$ = new MethodModifier(T_PUBLIC); print_(); }
                    | PRIVATE { $$ = new MethodModifier(T_PRIVATE); print_(); }
                    ;

arguments           : arguments COMMA type id { $$ = new ArgumentList($1, $3, $4); print_(); }
                    | type id { $$ = new ArgumentList($1, $2); print_(); }
                    | %empty { $$ = nullptr; print_(); }
                    ;

type                : INT LEFTSBRACKET RIGHTSBRACKET { $$ = new PrimitiveType(T_INT_ARRAY); print_(); }
                    | BOOLEAN { $$ = new PrimitiveType(T_BOOLEAN); print_(); }
                    | INT { $$ = new PrimitiveType(T_INT); print_(); }
                    | id { $$ = new ClassType($1); print_(); }
                    ;

statements          : statements statement { $$ = new StatementList($1, $2); print_(); }
                    | statement { $$ = new StatementList(nullptr, $1); print_(); }
                    ;

statement           : LEFTCBRACKET statements RIGHTCBRACKET { $$ = new Statements($2); print_(); }
                    | IF LEFTRBRACKET expression RIGHTRBRACKET statement ELSE statement { $$ = new IfElseStatement($3, $5, $7); print_(); }
                    | WHILE LEFTRBRACKET expression RIGHTRBRACKET statement { $$ = new WhileStatement($3, $5); print_(); }
                    | SYSTEMOUT LEFTRBRACKET expression RIGHTRBRACKET SEMICOLON { $$ = new SystemOutStatement($3); print_(); }
                    | id EQUALS expression SEMICOLON { $$ = new AssignStatement($1, $3); print_(); }
                    | id LEFTSBRACKET expression RIGHTSBRACKET EQUALS expression SEMICOLON { $$ = new ArrayAssignStatement($1, $3, $6); print_(); }
                    ;

expressions         : expressions COMMA expression { $$ = new ExpressionList($1, $3); print_(); }
                    | expression { $$ = new ExpressionList($1); print_(); }
                    ;

expression          : expression AND expression { $$ = new BinaryExpression(T_AND, $1, $3); print_(); }
                    | expression LESS expression { $$ = new BinaryExpression(T_LESS, $1, $3); print_(); }
                    | expression PLUS expression { $$ = new BinaryExpression(T_PLUS, $1, $3); print_(); }
                    | expression MINUS expression { $$ = new BinaryExpression(T_MINUS, $1, $3); print_(); }
                    | expression MULTIPLY expression { $$ = new BinaryExpression(T_MULTIPLY, $1, $3); print_(); }
                    | expression MOD expression { $$ = new BinaryExpression(T_MOD, $1, $3); print_(); }
                    | expression OR expression { $$ = new BinaryExpression(T_OR, $1, $3); print_(); } 
                    | expression LEFTSBRACKET expression RIGHTSBRACKET { $$ = new ArrayMemberExpression($1, $3); print_(); }
                    | expression DOT LENGTH { $$ = new ArrayLengthExpression($1); print_(); }
                    | expression DOT id LEFTRBRACKET expressions RIGHTRBRACKET { $$ = new CallMemberExpression($1, $3, $5); print_(); }
                    | expression DOT id LEFTRBRACKET RIGHTRBRACKET { $$ = new CallMemberExpression($1, $3, nullptr); print_(); }
                    | INTEGERLITERAL { $$ = new IntegerExpression(yylval.intval); }
                    | TRUE { $$ = new BooleanExpression(T_TRUE); print_(); }
                    | FALSE { $$ = new BooleanExpression(T_FALSE); print_(); }
                    | id { $$ = new IdExpression($1); print_(); }
                    | THIS { $$ = new ThisExpression(); print_(); }
                    | NEW INT LEFTSBRACKET expression RIGHTSBRACKET { $$ = new IntArrayExpression($4); print_(); }
                    | NEW id LEFTRBRACKET RIGHTRBRACKET { $$ = new ObjectExpression($2); print_(); }
                    | EXCLAMATION expression { $$ = new NotExpression($2); print_(); }
                    | LEFTRBRACKET expression RIGHTRBRACKET { $$ = $2; print_(); }
                    ;

id                  : IDENTIFIER { $$ = new Id(yylval.id); print_(); }
                    ;

%%

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
