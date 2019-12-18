#ifndef _FACTORY_H_
#define _FACTORY_H_
#include <iostream>

class Product{
public:
    virtual ~Product(){};
    Product(){}
};

class ConcreteProduct:public Product{
public:
    ConcreteProduct(){
        std::cout<<"ConcreteProduct...."<<std::endl;
    }
};

class Factory{
public:
    virtual ~Factory(){};
    virtual Product* CreateProduct()=0;
    Factory(){}
};

class ConcreteFactory:public Factory{
public:
    ConcreteFactory(){
        std::cout<<"ConcreteFactory...."<<std::endl;
    }
    Product* CreateProduct(){
        return new ConcreteProduct();
    }
};
#endif