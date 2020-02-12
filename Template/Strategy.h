#ifndef _STRATEGY_H_ 
#define _STRATEGY_H_ 
#include <iostream>
using namespace std;
class Strategy{
public:
	Strategy(){}
	virtual ~Strategy(){
		cout<<"~Strategy....."<<endl;
	}
	virtual void AlgrithmInterface() = 0;
};

class ConcreteStrategyA:public Strategy {
public: 
	ConcreteStrategyA(){}
	virtual ~ConcreteStrategyA(){
		cout<<"~ConcreteStrategyA....."<<endl;
	}
	void AlgrithmInterface(){
		cout<<"test ConcreteStrategyA....."<<endl;
	}
};

class ConcreteStrategyB:public Strategy {
public:
	ConcreteStrategyB(){}
	virtual ~ConcreteStrategyB(){
		cout<<"~ConcreteStrategyB....."<<endl;
	}
	void AlgrithmInterface(){
		cout<<"test ConcreteStrategyB....."<<endl;
	}

};

/**
*这个类是 Strategy 模式的关键，也是 Strategy 模式和 Template 模式的根本区别所在。 *Strategy 通过“组合”(委托)方式实现算法 (实现)的异构，而 Template 模式则采取的 是继承的方式 *这两个模式的区别也是继承和组合两种实 现接口重用的方式的区别
*/
class Context
{
public:
	Context(Strategy* stg){
		_stg=stg;
	}
	~Context(){
		if(!_stg)
			delete _stg;
	}
	void DoAction(){
		_stg->AlgrithmInterface();
	}
private:
	Strategy* _stg;
};

#endif