#ifndef _INTERPRET_H_
#define _INTERPRET_H_

#include <string>
#include <iostream>
using namespace std;

class Context{
public:
    Context(){}
    ~Context(){}
};

class AbstractExpression{
public:
    virtual ~AbstractExpression(){}
    virtual void Interpret(const Context& c){}
protected:
    AbstractExpression(){}
};

class TerminalExpression:public AbstractExpression{
public:
    TerminalExpression(const string& statement){
        this->_statement=statement;
    }
    ~ TerminalExpression(){}
    void Interpret(const Context& c){
        cout<<this->_statement<<"TerminalExpression"<<endl;
    }
private:
    string _statement;
};

class NonterminalExpression:public AbstractExpression{
public:
    NonterminalExpression(AbstractExpression* expression,int times){
        this->_expression = expression;
        this->_times = times;
    }
    ~ NonterminalExpression(){}
    void Interpret(const Context& c){
        for (int i = 0; i < _times ; i++){
            this->_expression->Interpret(c);
        }
    }
private:
    AbstractExpression* _expression;
    int _times;
};
#endif