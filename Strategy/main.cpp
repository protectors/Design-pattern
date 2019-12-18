#include <iostream>
#include "Duck.hpp"
using namespace std;
int main(){
    Duck *mallard = new MallardDuck();
    mallard->performFly();
    mallard->performQuack();
    cout<<"_________________"<<endl;
    Duck *modeled = new ModelDuck();
    modeled->performFly();
    modeled->performQuack();
    modeled->setFlyBehavior(new FlyRocketPowered());
    modeled->performFly();
    return 0;
}