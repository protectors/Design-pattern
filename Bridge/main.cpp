#include "Bridge.hpp"

int main(){
    AbstractionImp* imp=new ConcreteAbstractionImpA();
    Abstraction* abs=new RefinedAbstraction(imp);
    abs->Operation();
    return 0;
}