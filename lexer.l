%{
#include <cstdlib>
#include "Parser1.hpp"
#include <string>
#include <iostream>
using namespace par;
%}

%option  noyywrap reentrant outfile="Scanner1.cpp" header="Scanner1.hpp"

%%

"#".*                   ;
[ \t\r\n]				;
"if"                    return Parser::token::TIF;
"else"                  return Parser::token::TELSE;
"for"                   return Parser::token::TFOR;
"while"                 return Parser::token::TWHILE;
"int"                   return Parser::token::TYLL;
"double"                return Parser::token::TYDOUBLE;
"bool"                  return Parser::token::TYBOOL;
[a-zA-Z_][a-zA-Z0-9_]*	yylval->emplace<std::string>(yytext);return Parser::token::TIDENTIFIER;
[0-9]+\.[0-9]*			yylval->emplace<double>(strtod(yytext,nullptr));return Parser::token::TDOUBLE;
[0-9]+  				yylval->emplace<long long>(strtoll(yytext,nullptr,10));return Parser::token::TINTEGER;
\"(\\.|[^"])*\"         ;
"="                     return Parser::token::TEQUAL;
"=="                    return Parser::token::TCEQ;
"!="                    return Parser::token::TCNE;
"<"                     return Parser::token::TCLT;
"<="                    return Parser::token::TCLE;
">"                     return Parser::token::TCGT;
">="                    return Parser::token::TCGE;
"("                     return Parser::token::TLPAREN;
")"                     return Parser::token::TRPAREN;
"{"                     return Parser::token::TLBRACE;
"}"                     return Parser::token::TRBRACE;
"["                     return Parser::token::TLBRACKET;
"]"                     return Parser::token::TRBRACKET;
"."                     return Parser::token::TDOT;
","                     return Parser::token::TCOMMA;
"+"                     return Parser::token::TPLUS;
"-"                     return Parser::token::TMINUS;
"*"                     return Parser::token::TMUL;
".*"                    return Parser::token::MTMUL;
"/"                     return Parser::token::TDIV;
"&"                     return Parser::token::TAND;
"|"                     return Parser::token::TOR;
"^"                     return Parser::token::TXOR;
"%"                     return Parser::token::TMOD;
">>"                    return Parser::token::TSHIFTR;
"<<"                    return Parser::token::TSHIFTL;
";"                     return Parser::token::TSEMICOLON;
":"                     return Parser::token::TCOLON;


.						printf("Unknown token:%s\n", yytext); yyterminate();
%%