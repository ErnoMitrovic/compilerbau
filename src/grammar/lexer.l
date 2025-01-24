%{
#include "parser.tab.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
%}

%%

"int"         { return INT; }
"float"       { return FLOAT; }
"return"      { return RETURN; }
"if"          { return IF; }
"else"        { return ELSE; }
"while"       { return WHILE; }
"for"         { return FOR; }

[0-9]+         { yylval.intval = atoi(yytext); return NUMBER; }
[0-9]+\.[0-9]+ { yylval.floatval = atof(yytext); return FLOAT; }
"[^"]*"      { yylval.strval = strdup(yytext); return STRING; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.strval = strdup(yytext); return IDENTIFIER; }

"=="          { return EQUAL; }
"!="          { return NOT_EQUAL; }
"<="          { return LESS_EQUAL; }
">="          { return GREATER_EQUAL; }
"<"           { return LESS; }
">"           { return GREATER; }

"+"           { return PLUS; }
"-"           { return MINUS; }
"*"           { return MULTIPLY; }
"/"           { return DIVIDE; }
"%"           { return MODULO; }

"&&"          { return AND; }
"||"          { return OR; }
"!"           { return NOT; }

"="           { return ASSIGN; }

"("           { return LPAREN; }
")"           { return RPAREN; }
"{"           { return LBRACE; }
"}"           { return RBRACE; }
";"           { return SEMICOLON; }
","           { return COMMA; }

[ \t\n]+      { /* Ignore whitespace */ }
.              { printf("Unknown character: %s\n", yytext); }

%%
