#include <iostream>

class FlyBehavior{
public:
    virtual ~FlyBehavior(){};
    virtual void fly() = 0;
};

class QuackBehavior{
public:
    virtual ~QuackBehavior(){};
    virtual void quack() = 0;
};

class Duck{
    FlyBehavior *pFlyBehavior;
    QuackBehavior *pQuackBehavior;
public:
    Duck(FlyBehavior *p_f, QuackBehavior *p_q){
        pFlyBehavior = p_f;
        pQuackBehavior = p_q;
    }
    virtual ~Duck(){};
    virtual void display(){};
    void performFly(){
        pFlyBehavior->fly();
    }
    void performQuack(){
        pQuackBehavior->quack();
    }
    void swim(){
        std::cout<<"All ducks float, even decoys!\n";
    }
    void setFlyBehavior(FlyBehavior *fb){
        pFlyBehavior = fb;
    }
    void setFlyBehavior(QuackBehavior *qb){
        pQuackBehavior = qb;
    }
};

class FlyWithWings: public FlyBehavior{
public:
    void fly(){
        std::cout<<"I'm flying!!\n";
    }
};

class FlyNoWay: public FlyBehavior{
public:
    void fly(){
        std::cout<<"I can't fly\n";
    }
};

class FlyRocketPowered: public FlyBehavior{
public:
    void fly(){
        std::cout<<"I'm flying with a rocket!!\n";
    }
};

class Quack: public QuackBehavior{
public:
    void quack(){
        std::cout<<"Quack!!\n";
    }
};

class MuteQuack: public QuackBehavior{
public:
    void quack(){
        std::cout<<"Slience!!\n";
    }
};

class Squeak: public QuackBehavior{
public:
    void quack(){
        std::cout<<"Squeak!!\n";
    }
};

class MallardDuck: public Duck{
public:
    MallardDuck(FlyBehavior *fly_behavior=new FlyWithWings(),
        QuackBehavior *quack_behavior = new Quack())
        :Duck(fly_behavior,quack_behavior){}

    void display(){
        std::cout<<"I'm a real Mallard duck\n";
    }
};

class ModelDuck: public Duck{
public:
    ModelDuck(FlyBehavior *fly_behavior=new FlyNoWay(),
        QuackBehavior *quack_behavior = new Quack())
        :Duck(fly_behavior,quack_behavior){}
    void display(){
        std::cout<<"I'm a model duck\n";
    }
};