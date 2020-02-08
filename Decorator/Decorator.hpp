#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include <iostream>

class Component{
public:
	virtual ~Component(){}
	virtual void Operation(){}
protected:
	Component(){}
};

class ConcreteComponent:public Component{
public:
	ConcreteComponent(){}
	~ConcreteComponent(){}
	void Operation(){
		std::cout<<"ConcreteComponent Operation...\n";
	}
};

class Decorator:public Component{
public:
	Decorator(Component* com){
		this->_com=com;
	}
	virtual ~Decorator(){
		delete _com;
	}
	void Operation(){}
protected:
	Component* _com;
};

class ConcreteDecorator:public Decorator{
public:
	ConcreteDecorator(Component* com):Decorator(com){}
	virtual ~ConcreteDecorator(){}
	void AddedBehavior(){
		std::cout<<"ConcreteDecorator::AddedBehavior...\n";
	}
	void Operation(){
		_com->Operation();
		this->AddedBehavior();
	}
};

#endif