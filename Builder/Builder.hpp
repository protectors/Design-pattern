//Builder.hpp

#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
#include <iostream>
using namespace std;

class Product{
public:
    Product(){}
    ~Product(){}
    void ProductPart(){
        cout<<"build part a product..."<<endl;
    }
};

class ProductPart{
public:
    ProductPart(){}
    ~ProductPart(){}
    ProductPart* BuildPart(){
        return new ProductPart;
    }
};

class Builder{
public:
    Builder(){}
    ~Builder(){}
    virtual void BuildPartA(const string& buildPara)=0;
    virtual void BuildPartB(const string& buildPara)=0;
    virtual void BuildPartC(const string& buildPara)=0;
    virtual Product* GetProduct()=0;
};

class ConcreteBuilder:public Builder{
public:
    ConcreteBuilder(){}
    ~ConcreteBuilder(){}
    void BuildPartA(const string& buildPara){
        cout<<"Step1:Build PartA.."<<buildPara<<endl;
    }
    void BuildPartB(const string& buildPara){
        cout<<"Step1:Build PartB.."<<buildPara<<endl;
    }
    void BuildPartC(const string& buildPara){
        cout<<"Step1:Build PartC.."<<buildPara<<endl;
    }
    Product* GetProduct(){
        BuildPartA("pre-defined");
        BuildPartB("pre-defined");
        BuildPartC("pre-defined");
        return new Product();
    }
};

class Director{
public:
    Director(Builder* bld){ _bld=bld; }
    ~Director(){}
    void Construct(){
        _bld->BuildPartA("user-defined");
        _bld->BuildPartB("user-defined");
        _bld->BuildPartC("user-defined");
    }
private:
    Builder* _bld;
};
#endif