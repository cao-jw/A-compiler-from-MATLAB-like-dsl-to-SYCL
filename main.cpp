#include"Scanner1.hpp"
#include"Parser1.hpp"
#include<iostream>
#include <fstream>
#include "codegen.hpp"
extern NBlock* startnode;
using namespace par; 


int main(int argc, char **argv) {
    yyscan_t scanner;
    yylex_init(&scanner);
    const char * filename = "input.txt";
    const char *outname = "out.txt";
    FILE* yi = fopen(filename,"r");
    YY_BUFFER_STATE buffer;
    buffer = yy_create_buffer(yi, YY_BUF_SIZE, scanner);
    yy_switch_to_buffer(buffer, scanner);
    par::Parser parser{ scanner };
    std::cout.precision(10);
    parser.parse();
    CodeGenHeader(outname);
    std::map<std::string, NIdentifier*> SymbolTable;
    CodeGen(outname, startnode,1,SymbolTable);
    yylex_destroy(scanner);
    
    return 0;
}

