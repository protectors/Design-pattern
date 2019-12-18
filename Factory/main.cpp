#include "Factory.hpp"

int main(void){
    Factory* fac = new ConcreteFactory();
    Product* p = fac->CreateProduct();
    return 0;
}