#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_
#include <iostream>
using namespace std;
class Prototype{
public:
    Prototype(){}
    ~Prototype(){}
    virtual Prototype* Clone() const=0;
};

class ConcretePrototype:public Prototype{
public:
    ConcretePrototype(){}
    ConcretePrototype(const ConcretePrototype& cp){
        cout<<"ConcretePrototype copy..."<<endl;
    }
    ~ConcretePrototype();
    Prototype* Clone() const{
        return new ConcretePrototype(*this);
    }
};

#endif