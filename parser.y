%{
#include<iostream>
#include<string>
#include "Scanner1.hpp"
#include "ast.hpp"
#include <vector>
#include <map>
NBlock* startnode;

std::map<NBlock, NIdentifier> symbol; 
%}

%code requires {
#include "ast.hpp" // 包含你自己定义的类的头文件
}

%require "3.7.4"
%language "C++"
%defines "Parser1.hpp"
%output "Parser1.cpp"
 
%define api.parser.class {Parser}
%define api.namespace {par}
%define api.value.type variant
%param {yyscan_t scanner}

%code provides
{
    #define YY_DECL \
        int yylex(par::Parser::semantic_type *yylval, yyscan_t yyscanner)
    YY_DECL;
}


%token <std::string> TIDENTIFIER  
%token <double> TDOUBLE
%token <long long> TINTEGER
%token TIF TELSE TFOR TWHILE
%token TYLL TYDOUBLE TYBOOL
%token TEQUAL TCEQ TCNE TCLT TCLE TCGT TCGE
%token TLPAREN TRPAREN TLBRACE TRBRACE TLBRACKET TRBRACKET
%token TDOT TCOMMA TSEMICOLON TCOLON
%token TPLUS TMINUS TMUL TDIV TAND TOR TXOR TMOD MTMUL
%token TSHIFTR TSHIFTL

%nterm <NWhileStatement*> while_stmt
%nterm <NForStatement*> for_stmt for_condition
%nterm <NIfStatement*> if_stmt
%nterm <SYMBOL_TYPE> comparison
%nterm <NArrayIndex*> array_index full_index
%nterm <NExpression*> expr
%nterm <NExpression*> numeric
%nterm <NIdentifier*> ident
%nterm <NArrayType*> array_type size_expr
%nterm <VALUE_TYPE> primary_typename
%nterm <NBlock*> block prog
%nterm <NStatement*> stmt
%nterm <std::vector<NStatement*>> stmts 
%nterm <NAssignment*> assign
%nterm <NVariableDeclaration*> var_decl



%left TPLUS TMINUS
%left TMUL TDIV TMOD MTMUL
%left UMINUS
%right TEQUAL 


%start prog

%%


prog    :   block {$$ = $1; startnode = $1;}
                    ;

stmts   :   stmt {std::vector<NStatement*> sts = {}; sts.push_back($1);$$ = sts;}
        |   stmts stmt {std::vector<NStatement*> sts = $1; sts.push_back($2); $$ = sts;}
                    ;

stmt    :   var_decl {$$ = $1;$$->nodetype = $1->nodetype;}
        |   expr {$$ = new NExpressionStatement($1);$$->nodetype = $1->nodetype;}
        |   if_stmt{$$ = $1;$$->nodetype = $1->nodetype;}
        |   for_stmt{$$ = $1;$$->nodetype = $1->nodetype;}
        |   while_stmt{$$ = $1;$$->nodetype = $1->nodetype;}
                    ;

block   :   TLBRACE stmts TRBRACE  {$$ = new NBlock($2);}
			        ;

primary_typename    :   TYLL {$$ = VALUE_TYPE::LL_TYPE;}
					|   TYDOUBLE {$$ = VALUE_TYPE::DOUBLE_TYPE;}
					|   TYBOOL {$$ = VALUE_TYPE::BOOL_TYPE;}
                    ;

array_type          :   primary_typename TLBRACKET TINTEGER TRBRACKET {std::vector<int> vec = {};vec.push_back($3);$$ = new NArrayType($1, vec, 1);}
                    |   array_type TLBRACKET TINTEGER TRBRACKET {$1->arraydim ++; $1->arraysize.push_back($3); $$ = $1;}

var_decl    : primary_typename ident {$$ = new NVariableDeclaration($1, $2);}
			| array_type ident {$$ = new NVariableDeclaration($1->vt, $2); $2->isArray = true;$2->arraysize = $1->arraysize; $2->array_dim = $1->arraydim;}
            ;

ident   :   TIDENTIFIER {$$ = new NIdentifier($1);}
                ;

numeric :   TINTEGER {$$ = new NInteger($1); $$->nodetype = NInteger_TYPE;}
		|   TDOUBLE {$$ = new NDouble($1); $$->nodetype = NDouble_TYPE;}
                ;

expr    :     ident {$$ = $1;$$->nodetype = $1->nodetype;}
        |   numeric {$$ = $1;$$->nodetype = $1->nodetype; }
		|   expr comparison expr {$$ = new NBinaryOperator($1, $2, $3);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
		|   expr TMOD expr {$$ =  new NBinaryOperator($1, SYMBOL_TYPE::TMOD_TYPE, $3);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
		|   expr size_expr TMUL expr size_expr{$1->nat = $2;$4->nat = $5;$$ = new NBinaryOperator($1, SYMBOL_TYPE::TMUL_TYPE, $4);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
		|   expr TDIV expr {$$ = new NBinaryOperator($1, SYMBOL_TYPE::TDIV_TYPE, $3);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}/**/
		|   expr size_expr TPLUS expr size_expr {$1->nat = $2;$4->nat = $5;$$ = new NBinaryOperator($1, SYMBOL_TYPE::TPLUS_TYPE, $4);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
		|   expr size_expr TMINUS expr size_expr {$1->nat = $2;$4->nat = $5;$$ = new NBinaryOperator($1, SYMBOL_TYPE::TMINUS_TYPE, $4);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
		|   TLPAREN expr TRPAREN {$$ = new NBinaryOperator($2,SYMBOL_TYPE::TPAREN_TYPE); $$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;} 
		|   TMINUS expr %prec UMINUS{$$ = new NBinaryOperator($2,SYMBOL_TYPE::TUMINUS_TYPE); $$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
		|   full_index {$$ = $1; $$->nodetype = $1->nodetype;}
        |   expr size_expr MTMUL numeric { $1->nat = $2; $$ = new NBinaryOperator($1, SYMBOL_TYPE::MTMUL_TYPE, $4);$$->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
        |   assign {$$ = $1;$$->nodetype = $1->nodetype;}
        |   full_index  TEQUAL expr{$$ = new NArrayAssignment($1, $3); $$->nodetype = NArrayAssignment_TYPE;}
                ;

assign  :   ident TEQUAL expr {$$ = new NAssignment($1, $3);}
        

array_index :   ident TLBRACKET expr TRBRACKET{std::vector<NExpression*> exp = {};exp.push_back($3); $$ = new NArrayIndex($1, exp);$$->expressions.back()->nodetype = $3->nodetype;}
			|   array_index TLBRACKET expr TRBRACKET {$1->expressions.push_back($3); $$ = $1;$$->expressions.back()->nodetype = $3->nodetype;}
                ;

full_index :    array_index size_expr {$$ = new NArrayIndex($1->arrayName, $1->expressions, $2);}
           ;

comparison:
    TCEQ { $$ = SYMBOL_TYPE::TCEQ_TYPE; }
    | TCNE { $$ = SYMBOL_TYPE::TCNE_TYPE; }
    | TCLT { $$ = SYMBOL_TYPE::TCLT_TYPE; }
    | TCLE { $$ = SYMBOL_TYPE::TCLE_TYPE; }
    | TCGT { $$ = SYMBOL_TYPE::TCGT_TYPE; }
    | TCGE { $$ = SYMBOL_TYPE::TCGE_TYPE; }
    | TAND { $$ = SYMBOL_TYPE::TAND_TYPE; }
    | TOR { $$ = SYMBOL_TYPE::TOR_TYPE; }
    | TXOR { $$ = SYMBOL_TYPE::TXOR_TYPE; }
    | TSHIFTL { $$ = SYMBOL_TYPE::TSHIFTL_TYPE; }
    | TSHIFTR { $$ = SYMBOL_TYPE::TSHIFTR_TYPE; }
    ;
if_stmt :   TIF expr block  {$$ = new NIfStatement($2, $3);}
        |   TIF expr block TELSE block {$$ = new NIfStatement($2, $3, $5);}
        |   TIF expr block TELSE if_stmt {$$ = new NIfStatement($2, $3);}/*need to fin*/
                ;

for_condition : TFOR TLPAREN ident TEQUAL TINTEGER TCOLON TINTEGER TCOLON TINTEGER TRPAREN{std::vector<int> ini = {$5};std::vector<int> end = {$9}; std::vector<int> incre = {$7}; std::vector<NIdentifier*> var= {$3}; $$ = new NForStatement(ini, end, incre, var,nullptr);}
              | for_condition TFOR TLPAREN ident TEQUAL TINTEGER TCOLON TINTEGER TCOLON TINTEGER TRPAREN{$1->initial.push_back($6); $1->end.push_back($10); $1->increment.push_back($8); $1->forvar.push_back($4); $$ = $1;}

for_stmt    :   for_condition block {$1->block = $2;$$ = $1;std::cout<<"new for_stmt "<<$$->block->statements.size()<<std::endl;}
                ;

while_stmt  :   TWHILE TLPAREN expr TRPAREN block {$$ = new NWhileStatement($5, $3);  }
                ;

size_expr   :   TSHIFTL TINTEGER TSHIFTR {std::vector<int> vec = {};vec.push_back($2);$$ = new NArrayType(VALUE_TYPE::LL_TYPE, vec, 1);}
            |   size_expr TSHIFTL TINTEGER TSHIFTR {$1->arraydim ++; $1->arraysize.push_back($3); $$ = $1;}
            |   /*empty*/ {std::vector<int> vec = {};$$ = new NArrayType(VALUE_TYPE::LL_TYPE, vec, 0);}
            ;
%%
void par::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
