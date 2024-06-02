#ifndef CDG_H
#define CDG_H


#include "ast.hpp"
#include <fstream>
#include <map>


void CodeGenMMul(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);


void CodeGenHeader(const char* file)
{
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<"#include<sycl/sycl.hpp>"<<std::endl;
    f<<"using namespace sycl;"<<std::endl;
    f<<"int main()"<<std::endl;
    f.close();
}

void CodeGenWhiStmt(const char* file, NWhileStatement* nws, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, int queuenum);

void CodeGenForStmt(const char* file, NForStatement* nfs, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, int queuenum);

void CodeGencomp(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, SYMBOL_TYPE ST) ;

void CodeGenLibBin(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable,SYMBOL_TYPE st);

void check_in_table(std::string name, std::map<std::string, NIdentifier*> SymbolTable) {
    try {
        std::map<std::string, NIdentifier*>::iterator iter;
        iter = SymbolTable.find(name);
        if(iter == SymbolTable.end()) {
            throw "Undefined identifier!";
        }
    }
    catch(const char* errorMessage) {
        std::cerr<<"Caught exception in check_in_table: "<<errorMessage<<std::endl;
        throw "Undefined identifier!";
    }
}

void check_array_legal(NArrayIndex* nai, std::map<std::string, NIdentifier*> SymbolTable) {
    try {
        check_in_table(nai->arrayName->name, SymbolTable);
        if(nai->expressions.size() > SymbolTable[nai->arrayName->name]->arraysize.size())
            throw "Array dimensions exceeded!";
    }
    catch(const char* errorMessage) {
        std::cerr << "Caught exception in check_array_legal: " << errorMessage << std::endl;
        throw "Array dimensions exceeded!";
    }
}

std::string valueTypeToString(VALUE_TYPE type) {
    switch (type) {
        case VALUE_TYPE::LL_TYPE:
            return "long long";
        case VALUE_TYPE::DOUBLE_TYPE:
            return "double";
        case VALUE_TYPE::BOOL_TYPE:
            return "bool";
        default:
            return "unknown";
    }
}

std::string symbolTypeToString(SYMBOL_TYPE type) {
    switch (type) {
        case SYMBOL_TYPE::ASSIGN_TYPE:
            return "=";
        case SYMBOL_TYPE::TEQUAL_TYPE:
            return "==";
        case SYMBOL_TYPE::TCEQ_TYPE:
            return "=";
        case SYMBOL_TYPE::TCNE_TYPE:
            return "!=";
        case SYMBOL_TYPE::TCLT_TYPE:
            return "<";
        case SYMBOL_TYPE::TCLE_TYPE:
            return "<=";
        case SYMBOL_TYPE::TCGT_TYPE:
            return ">";
        case SYMBOL_TYPE::TCGE_TYPE:
            return ">=";
        case SYMBOL_TYPE::TMOD_TYPE:
            return "%";
        case SYMBOL_TYPE::TMUL_TYPE:
            return "*";
        case SYMBOL_TYPE::TDIV_TYPE:
            return "/";
        case SYMBOL_TYPE::TPLUS_TYPE:
            return "+";
        case SYMBOL_TYPE::TMINUS_TYPE:
            return "-";
        case SYMBOL_TYPE::TUMINUS_TYPE:
            return "unary -";
        case SYMBOL_TYPE::TAND_TYPE:
            return "&";
        case SYMBOL_TYPE::TOR_TYPE:
            return "|";
        case SYMBOL_TYPE::TXOR_TYPE:
            return "^";
        case SYMBOL_TYPE::TSHIFTL_TYPE:
            return "<<";
        case SYMBOL_TYPE::TSHIFTR_TYPE:
            return ">>";
        default:
            return "unknown";
    }
}

void CodeGenNVarDec(const char* file, NVariableDeclaration * nvd, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, int queuenum)
{

    SymbolTable.insert(std::pair<std::string, NIdentifier*>(nvd->id->name, nvd->id));
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    const char* ty = valueTypeToString(nvd->vt).c_str();
        if(nvd->id->isArray == true)
    {
        int size = 1;
        for (int j = 0; j!= nvd->id->arraysize.size(); j++)
        {
            size *= nvd->id->arraysize[j];
        }
        f<<"auto "<<nvd->id->name<<" = "<<"malloc_shared<"<<ty<<">("<<size<<","<<"q"<<queuenum<<");"<<std::endl;
    }
    else 
    {
        f<<ty<<" "<<nvd->id->name<<";"<<std::endl;
    }
    f.close();

}

void CodeGenBinOp(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);//ntf

void CodeGenLL(const char* file, NInteger* ni, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);

void CodeGenDou(const char* file, NDouble* nd, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);

void CodeGenArrInd(const char* file, NArrayIndex* ai, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);

void CodeGenAss(const char* file, NAssignment* na, NBlock* block,std::map<std::string, NIdentifier*>& SymbolTable);

void CodeGenIdenconst(const char* file, NIdentifier* id, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);

void CodeGenArrAss(const char* file, NArrayAssignment* naa, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable);

void CodeGenExpr(const char* file, NExpression* expr, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, int nodetype) {
    switch (nodetype) {
        case NODE_TYPE::NBinaryOperator_TYPE:
            CodeGenBinOp(file, dynamic_cast<NBinaryOperator*>(expr), block, SymbolTable);
            break;
        case NODE_TYPE::NAssignment_TYPE:
            CodeGenAss(file, dynamic_cast<NAssignment*>(expr), block, SymbolTable);
            break;
        case NODE_TYPE::NInteger_TYPE:
            CodeGenLL(file, dynamic_cast<NInteger*>(expr), block, SymbolTable);
            break;
        case NODE_TYPE::NDouble_TYPE:
            CodeGenDou(file, dynamic_cast<NDouble*>(expr), block, SymbolTable);
            break;
        case NODE_TYPE::NIdentifier_TYPE:
            CodeGenIdenconst(file, dynamic_cast<NIdentifier*>(expr), block, SymbolTable);
            break;
        case NODE_TYPE::NArrayIndex_TYPE:
            CodeGenArrInd(file, dynamic_cast<NArrayIndex*>(expr), block, SymbolTable);
            break;
        case NODE_TYPE::NArrayAssignment_TYPE:
            CodeGenArrAss(file,dynamic_cast<NArrayAssignment*>(expr),block,SymbolTable);
            break;
        default:
            throw("no match action");
            break;
    }
}


void CodeGenIdenconst(const char* file, NIdentifier* id, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable){
    check_in_table(id->name, SymbolTable);

    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<id->name;
    f.close();
}

void CodeGenLL(const char* file, NInteger* ni, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable){
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<ni->value;
    f.close();
}

void CodeGenDou(const char* file, NDouble* nd, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable){

    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);

    f<<nd->value;

    f.close();
}

void CodeGenArrInd(const char* file, NArrayIndex* ai, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable){
    std::map<std::string, NIdentifier*>::iterator iter;

    check_array_legal(ai, SymbolTable);

    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<ai->arrayName->name<<"[";
    f.close();
        
        f.open(file, std::ios::out|std::ios::app);
        for(int i = 0 ;i!= ai->expressions.size();i++)
        f<<"(";
        f.close();
        //n-1 ()
    for(int i = 0 ;i!= ai->expressions.size();i++)
    {
            CodeGenExpr(file, ai->expressions[i], block, SymbolTable, ai->expressions[i]->nodetype);
            f.open(file, std::ios::out|std::ios::app);
            f<<"-1)";
            if (i != ai->expressions.size()-1)
            f<<"*"<<SymbolTable[ai->arrayName->name]->arraysize[i+1]<<"+";
            f.close();
    }

            f.open(file, std::ios::out|std::ios::app);
            f<<"]";
            f.close();
    
}

void CodeGenBinOp(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable)
{
    switch(bo->st)
    {
        case SYMBOL_TYPE::MTMUL_TYPE:
        CodeGenMMul(file, bo, block, SymbolTable);
        break;
        case SYMBOL_TYPE::TMUL_TYPE:
        case SYMBOL_TYPE::TPLUS_TYPE:
        case SYMBOL_TYPE::TMINUS_TYPE:
        CodeGenLibBin(file, bo, block, SymbolTable,bo->st);
        break;
        case SYMBOL_TYPE::TCNE_TYPE:
        case SYMBOL_TYPE::TEQUAL_TYPE:
        case SYMBOL_TYPE::TCLT_TYPE:
        case SYMBOL_TYPE::TCLE_TYPE:
        case SYMBOL_TYPE::TCGT_TYPE:
        case SYMBOL_TYPE::TCGE_TYPE:
        case SYMBOL_TYPE::TAND_TYPE:
        case SYMBOL_TYPE::TOR_TYPE:
        case SYMBOL_TYPE::TXOR_TYPE:
        CodeGencomp(file, bo, block, SymbolTable, bo->st);
        break;
        case SYMBOL_TYPE::TPAREN_TYPE:
        std::fstream f;
        f.open(file, std::ios::out|std::ios::app);
        f<<"(";
        f.close();
        CodeGenExpr(file,bo->lhs,block,SymbolTable,bo->lhs->nodetype);
        f.open(file, std::ios::out|std::ios::app);
        f<<")";
        f.close();
        break;


    }
}

void CodeGenAss(const char* file, NAssignment* na, NBlock* block,std::map<std::string, NIdentifier*>& SymbolTable){

    check_in_table(na->lhs->name, SymbolTable);
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<na->lhs->name<<" = ";
    f.close();


    CodeGenExpr(file, na->rhs, block, SymbolTable, na->rhs->nodetype);

    f.open(file, std::ios::out|std::ios::app);
    f<<";"<<std::endl;
    f.close();
}

void CodeGenArrAss(const char* file, NArrayAssignment* naa, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable)
{

    check_array_legal(naa->arrayIndex, SymbolTable);
    CodeGenArrInd(file, naa->arrayIndex, block, SymbolTable);
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<" = ";
    f.close();

    
    CodeGenExpr(file, naa->expression, block,SymbolTable, naa->expression->nodetype);
    f.open(file, std::ios::out|std::ios::app);
    f<<";"<<std::endl;
    f.close();
}

void CodeGen(const char* file, NBlock* block, int queuenum, std::map<std::string, NIdentifier*> ST)
{
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    
    f<<"{"<<std::endl;
    if(queuenum == 1)
    f<<"queue q"<<queuenum<<";"<<std::endl;
    f.close();


    
    std::map<std::string, NIdentifier*> SymbolTable = ST;
    for (int i=0; i!=block->statements.size();i++)
    {

        switch (block->statements[i]->nodetype)
        {
            case NODE_TYPE::NVariableDeclaration_TYPE:
            CodeGenNVarDec(file ,dynamic_cast<NVariableDeclaration *> (block->statements[i]), block, SymbolTable, queuenum);
            break;
            case NODE_TYPE::NWhileStatement_TYPE:
            CodeGenWhiStmt(file ,dynamic_cast<NWhileStatement *> (block->statements[i]), block, SymbolTable, queuenum);
            break;
            case NODE_TYPE::NForStatement_TYPE:
            CodeGenForStmt(file ,dynamic_cast<NForStatement *> (block->statements[i]), block, SymbolTable, queuenum);
            break;
            default:
            CodeGenExpr(file,dynamic_cast<NExpressionStatement*>(block->statements[i])->expression,block,SymbolTable,block->statements[i]->nodetype);
            break;
        }
    }

    f.open(file, std::ios::out|std::ios::app);
    f<<"}"<<std::endl;
    f.close();
}

void CodeGenMMul(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable)
{
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<"libMMul(";
    f.close();

    CodeGenExpr(file, bo->lhs, block, SymbolTable, bo->lhs->nodetype);

    if(bo->lhs->nat&&bo->lhs->nat->arraydim)
    {
        f.open(file, std::ios::out|std::ios::app);
        f<<",";
        for(int i = 0;i != bo->lhs->nat->arraydim;i++)
        {
            f<<bo->lhs->nat->arraysize[i]<<",";
        }
            f.close();
    }
    CodeGenExpr(file, bo->rhs, block, SymbolTable, bo->rhs->nodetype);
    
    if(bo->rhs->nat&&bo->rhs->nat->arraydim)
    {
        f.open(file, std::ios::out|std::ios::app);
        f<<",";
        for(int i = 0;i != bo->rhs->nat->arraydim;i++)
        {
            f<<bo->rhs->nat->arraysize[i]<<",";
        }
            f.close();
    }

    f.open(file, std::ios::out|std::ios::app);
    f<<")";
    f.close();
}

void CodeGenLibBin(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable,SYMBOL_TYPE st)
{
    std::fstream f;
    bool mmul = 0;
    if(bo->lhs->nat&&bo->lhs->nat->arraydim)
    {
        mmul = 1;
        f.open(file, std::ios::out|std::ios::app);
        f<<"libbin(";
        f.close();
    }
    CodeGenExpr(file, bo->lhs, block, SymbolTable, bo->lhs->nodetype);

    if(mmul)
    {
        f.open(file, std::ios::out|std::ios::app);
        f<<",";
        for(int i = 0;i != bo->lhs->nat->arraydim;i++)
        {
            f<<bo->lhs->nat->arraysize[i]<<",";
        }
            f.close();
    }

    f.open(file, std::ios::out|std::ios::app);
    switch (st)
    {
        case SYMBOL_TYPE::TMUL_TYPE:
            f<<"*";
            break;
        case SYMBOL_TYPE::TPLUS_TYPE:
            f<<"+";
            break;
        case SYMBOL_TYPE::TMINUS_TYPE:
            f<<"-";
            break;
    }
    if(mmul)
    f<<",";
    f.close();
    CodeGenExpr(file, bo->rhs, block, SymbolTable, bo->rhs->nodetype);

        if(mmul)
    {
        f.open(file, std::ios::out|std::ios::app);
        f<<",";
        for(int i = 0;i != bo->rhs->nat->arraydim;i++)
        {
            f<<bo->rhs->nat->arraysize[i];
            if(i != bo->rhs->nat->arraydim-1)
            f<<",";
        }
        f<<")";
            f.close();
    }
}

void CodeGencomp(const char* file, NBinaryOperator* bo, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, SYMBOL_TYPE ST)
{
    CodeGenExpr(file, bo->lhs, block, SymbolTable, bo->lhs->nodetype);
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    switch (ST)
    {
        case SYMBOL_TYPE::TCNE_TYPE:
        f<<"!=";
        break;
        case SYMBOL_TYPE::TEQUAL_TYPE:
        f<<"==";
        break;       
        case SYMBOL_TYPE::TCLT_TYPE:
        f<<"<";
        break;
        case SYMBOL_TYPE::TCLE_TYPE:
        f<<"<=";
        break;
        case SYMBOL_TYPE::TCGT_TYPE:
        f<<">";
        break;
        case SYMBOL_TYPE::TCGE_TYPE:
        f<<">=";
        break;
        case SYMBOL_TYPE::TAND_TYPE:
        f<<"&";
        break;
        case SYMBOL_TYPE::TOR_TYPE:
        f<<"|";
        break;
        case SYMBOL_TYPE::TXOR_TYPE:
        f<<"^";
        break;
    }

    f.close();
    CodeGenExpr(file, bo->rhs, block, SymbolTable, bo->rhs->nodetype);
}

void CodeGenWhiStmt(const char* file, NWhileStatement* nws, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, int queuenum)
{
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<"while(";
    f.close();

    CodeGenExpr(file, nws->condition, block, SymbolTable,nws->condition->nodetype);

    f.open(file, std::ios::out|std::ios::app);
    f<<")";
    f.close();
    CodeGen(file,nws->block,queuenum, SymbolTable);

}

void CodeGenForStmt(const char* file, NForStatement* nfs, NBlock* block, std::map<std::string, NIdentifier*>& SymbolTable, int queuenum)
{
    std::vector<int> times;
    for(int i = 0;i!=nfs->forvar.size();i++)
    SymbolTable.insert(std::pair<std::string, NIdentifier*>(nfs->forvar[i]->name, nfs->forvar[i]));
    for(int i=0;i!=nfs->initial.size();i++)
    times.push_back((nfs->end[i]-nfs->initial[i])/nfs->increment[i]+1);
    std::fstream f;
    f.open(file, std::ios::out|std::ios::app);
    f<<"q"<<queuenum<<".parallel_for(range<"<<nfs->initial.size()<<">(";
    for(int i=0;i!=nfs->initial.size();i++)
    {
        f<<times[i];
        if(i!=nfs->initial.size()-1)
        f<<",";
    }
    f<<"), [=] (id<"<<nfs->initial.size()<<"> idx) {"<<std::endl;
    for(int i=0;i!=nfs->initial.size();i++)
    {
        f<<"int "<<nfs->forvar[i]->name<<" = "<<"idx["<<i<<"] * "<<nfs->increment[i]<<" + "<<nfs->initial[i]<<";"<<std::endl;
    }
    f.close();
    for(int i=0;i!=nfs->block->statements.size();i++)
    {
        if(nfs->block->statements[i]->nodetype !=NArrayAssignment_TYPE)
        std::cerr << "invalid type in for statement"<< std::endl;

        CodeGenExpr(file,dynamic_cast<NExpressionStatement*>(nfs->block->statements[i])->expression,block,SymbolTable,nfs->block->statements[i]->nodetype);
    }    
    f.open(file, std::ios::out|std::ios::app);
    f<<"}).wait();"<<std::endl;
}
#endif