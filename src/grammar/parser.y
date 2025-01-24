%{
#include <iostream>
#include <cstdlib>
#include <cstring>

extern int yylex();
extern void yyerror(const char *s);
%}

%union {
    int intval;
    float floatval;
    char *strval;
}

%token <intval> NUMBER
%token <floatval> FLOAT
%token <strval> IDENTIFIER STRING
%token INT RETURN IF ELSE WHILE FOR
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token EQUAL NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL
%token AND OR NOT
%token ASSIGN
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

%%

program:
    program statement
    | /* empty */
    ;

statement:
    declaration SEMICOLON
    | assignment SEMICOLON
    | expression SEMICOLON
    ;

declaration:
    INT IDENTIFIER
    | FLOAT IDENTIFIER
    ;

assignment:
    IDENTIFIER ASSIGN expression
    ;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | NUMBER
    | FLOAT
    | IDENTIFIER
    | LPAREN expression RPAREN
    ;

%%

void yyerror(const char *s) {
    std::cerr << "Error: " << s << std::endl;
}
