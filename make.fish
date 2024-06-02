#!/bin/fish
clear
rm Parser1.cpp Parser1.hpp Scanner1.cpp Scanner1.hpp
flex lexer.l
bison --debug parser.y
g++ -o compiler main.cpp Scanner1.cpp Parser1.cpp ast.hpp codegen.hpp
