#include "Prototype.hpp"
int main(){
    Prototype* p=new ConcretePrototype();
    Prototype* p1=p->Clone();
    return 0;
}