#ifndef _BRIDGE_H_
#define _BRIDGE_H_
#include <iostream>
using namespace std;

class AbstractionImp{
public:
    AbstractionImp(){}
    virtual ~AbstractionImp(){}
    virtual void Operation()=0;
};

void AbstractionImp::Operation(){
    cout<<"AbstractionImp...imp..."<<endl;
}

class Abstraction{
public:
    Abstraction(){}
    virtual ~Abstraction(){}
    virtual void Operation()=0;
};

class RefinedAbstraction:public Abstraction{
public:
    RefinedAbstraction(AbstractionImp* imp){
        _imp=imp;
    }
    ~RefinedAbstraction(){}
    void Operation(){
        _imp->Operation();
    }
private:
    AbstractionImp* _imp;
};

class ConcreteAbstractionImpA:public AbstractionImp{
public:
    ConcreteAbstractionImpA(){}
    ~ConcreteAbstractionImpA(){}
    virtual void Operation(){
        cout<<"ConcretAbstractionImpA..."<<endl;
    }
};

class ConcreteAbstractionImpB:public AbstractionImp{
public:
    ConcreteAbstractionImpB(){}
    ~ConcreteAbstractionImpB(){}
    virtual void Operation(){
        cout<<"ConcretAbstractionImpB..."<<endl;
    }
};
#endif