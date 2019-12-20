#include "Builder.hpp"
#include <iostream>
using namespace std;
int main(){
    Director* d = new Director(new ConcreteBuilder());
    d->Construct();
    return 0;
}