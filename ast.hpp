#ifndef AST_H
#define AST_H


#include<string>
#include<vector>
#include <memory>
#include<iostream>


enum class VALUE_TYPE
{
  LL_TYPE,
  DOUBLE_TYPE,
  BOOL_TYPE,  
};

enum class SYMBOL_TYPE
{
    ASSIGN_TYPE,    // "="
    TEQUAL_TYPE,    // "=="
    TCEQ_TYPE,      // "="
    TCNE_TYPE,      // "!="
    TCLT_TYPE,      // "<"
    TCLE_TYPE,      // "<="
    TCGT_TYPE,      // ">"
    TCGE_TYPE,      // ">="
    TMOD_TYPE,      // "%"
    TMUL_TYPE,      // "*"
    TDIV_TYPE,      // "/"
    TPLUS_TYPE,     // "+"
    TMINUS_TYPE,    // "-"
    TUMINUS_TYPE,   // "unary -"
    TAND_TYPE,      // "&"
    TOR_TYPE,       // "|"
    TXOR_TYPE,      // "^"
    TSHIFTL_TYPE,   // "<<"
    TSHIFTR_TYPE,   // ">>"
    TPAREN_TYPE, //"()"
    MTMUL_TYPE, //".*"
};


enum  NODE_TYPE {
    NNODE_TYPE,
    NExpression_TYPE,
    NStatement_TYPE,
    NDouble_TYPE,
    NInteger_TYPE,
    NIdentifier_TYPE,
    NBinaryOperator_TYPE,
    NAssignment_TYPE,
    NBlock_TYPE,
    NExpressionStatement_TYPE,
    NIfStatement_TYPE,
    NForStatement_TYPE,
    NWhileStatement_TYPE,
    NArrayIndex_TYPE,
    NArrayAssignment_TYPE,
    NVariableDeclaration_TYPE,
    NArrayType_TYPE
};

class Node {
protected:
public:
    NODE_TYPE nt = NNODE_TYPE;
    Node(){}
	virtual ~Node() {}
};

class NStatement : public Node {
public:
    NStatement(){}
    NODE_TYPE nodetype = NStatement_TYPE;
};

class NArrayType : public NStatement{
public:
    VALUE_TYPE vt;
    std::vector<int> arraysize;
    int arraydim;
    NArrayType (){}
    NArrayType(VALUE_TYPE vt, std::vector<int> arraysize = {}, int arraydim = 0)
        : vt(vt), arraysize(arraysize), arraydim(arraydim){}
    
    NODE_TYPE nodetype = NArrayType_TYPE;
};

class NExpression : public Node {
public:
    NArrayType* nat = nullptr; 
    NODE_TYPE nodetype;
    NExpression(){}
}; 

class NDouble : public NExpression {
public:
	double value;
    NODE_TYPE nodetype = NDouble_TYPE;
    NDouble(){}

	NDouble(double value)
		: value(value) {
		// return "NDoub le=" << value << endl;
	}
};



class NInteger : public NExpression {
public:
    long long  value;
    NODE_TYPE nodetype = NInteger_TYPE;
    
    NInteger(){}

    NInteger(long long value)
            : value(value) {

    }
};

class NIdentifier : public NExpression {
public:
	std::string name;
    bool isArray = false;
    std::vector<int> arraysize ; 
    int array_dim = 0;
    NIdentifier(){}
    NODE_TYPE nodetype = NIdentifier_TYPE;

	NIdentifier(const std::string &name)
		: name(name) {
		// return "NIdentifier=" << name << endl;
	}
};

class NBinaryOperator : public NExpression {
public:
	SYMBOL_TYPE st;
	NExpression* lhs;
	NExpression* rhs;

    NBinaryOperator(){}

    NBinaryOperator(NExpression* lhs, SYMBOL_TYPE st, NExpression* rhs = nullptr)
            : lhs(lhs), rhs(rhs), st(st) {
    }
    NODE_TYPE nodetype = NBinaryOperator_TYPE;
};

class NAssignment : public NExpression {
public:
	NIdentifier* lhs;
	NExpression* rhs;

    NAssignment() : lhs(nullptr), rhs(nullptr) {}

	NAssignment(NIdentifier* lhs, NExpression* rhs)
		: lhs(lhs), rhs(rhs) {}
    NODE_TYPE nodetype = NAssignment_TYPE;
};

class NBlock : public NExpression {
public:
	std::vector<NStatement*> statements = {};

    NBlock() {}

    NBlock(std::vector<NStatement*> statements)
    : statements(statements) {}
    NODE_TYPE nodetype = NBlock_TYPE;
};

class NExpressionStatement : public NStatement {
public:
	NExpression* expression;
    bool * isArray;
    NExpressionStatement() : expression(nullptr) {}

	NExpressionStatement(NExpression* expression)
		: expression(expression) {}
    NODE_TYPE nodetype = NExpressionStatement_TYPE;
};

class NIfStatement: public NStatement {
public:
    NExpression* condition;
    NBlock* trueBlock;
    NBlock* falseBlock;

    NIfStatement() : condition(nullptr), trueBlock(nullptr), falseBlock(nullptr) {}

    NIfStatement(NExpression* condition, NBlock* trueBlock, NBlock* falseBlock = nullptr)
            : condition(condition), trueBlock(trueBlock), falseBlock(falseBlock) {}
    NODE_TYPE nodetype = NIfStatement_TYPE;
};

class NForStatement: public NStatement {
public:
    std::vector<int> initial;
    std::vector<int> end;
    std::vector<int> increment;
    NBlock* block;
    std::vector<NIdentifier*> forvar;

    NForStatement() : initial(0), end(0), increment(0), block(nullptr) {}

    NForStatement(std::vector<int>  initial, std::vector<int>  end , std::vector<int>  increment , std::vector<NIdentifier*> forvar,NBlock* block)
            : initial(initial), end(end), increment(increment), forvar(forvar), block(block){}
    NODE_TYPE nodetype = NForStatement_TYPE;
    
};

class NWhileStatement: public NStatement {
public:
    NExpression* condition;
    NBlock* block;

    NWhileStatement() : condition(nullptr), block(nullptr) {}

    NWhileStatement(NBlock* block, NExpression* condition)
            : block(block), condition(condition) {}
    NODE_TYPE nodetype = NWhileStatement_TYPE;
};

class NArrayIndex: public NExpression {
public:
    NIdentifier* arrayName;
    std::vector<NExpression*> expressions;
    NArrayType* nat;

    NArrayIndex() : arrayName(nullptr) {}

    NArrayIndex(NIdentifier* name, std::vector<NExpression*> expressions = {}, NArrayType* nat = nullptr)
            : arrayName(name), expressions(expressions), nat(nat){}

    ~NArrayIndex() {
        delete arrayName;
        for (auto expr : expressions) {
            delete expr;
        }
    }
    NODE_TYPE nodetype = NArrayIndex_TYPE;
};

class NArrayAssignment: public NExpression {
public:
    NArrayIndex* arrayIndex;
    NExpression* expression;

    NArrayAssignment() : arrayIndex(nullptr), expression(nullptr) {}

    NArrayAssignment(NArrayIndex* index, NExpression* exp)
            : arrayIndex(index), expression(exp) {}

    ~NArrayAssignment() {
        delete arrayIndex;
        delete expression;
    }
    NODE_TYPE nodetype = NArrayAssignment_TYPE;
};

class NVariableDeclaration : public NStatement {
public:
    VALUE_TYPE vt;
    NIdentifier* id;
    NExpression* assignmentExpr;

    NVariableDeclaration() {}

    NVariableDeclaration(VALUE_TYPE type, NIdentifier* id, NExpression* assignmentExpr = nullptr)
        : vt(type), id(id), assignmentExpr(assignmentExpr) {}

    ~NVariableDeclaration() {
        delete id;
        delete assignmentExpr;
    }
    NODE_TYPE nodetype = NVariableDeclaration_TYPE;
};




#endif