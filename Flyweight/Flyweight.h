#ifndef _FLYWEIGHT_H_ 
#define _FLYWEIGHT_H_

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
class Flyweight {
public:
	virtual ~Flyweight(){}
	virtual void Operation(const string& extrinsicState){}
	string GetIntrinsicState(){
		return this->_intrinsicState;
	}
protected:
	Flyweight(string intrinsicState){
		this->_intrinsicState=intrinsicState;
	}
private:
	string _intrinsicState;
};

class ConcreteFlyweight:public Flyweight {
public:
	ConcreteFlyweight(string intrinsicState):Flyweight(intrinsicState){
		cout<<"ConcreteFlyweight Build....."<<intrinsicState<<endl;
	}
	~ConcreteFlyweight(){}
	void Operation(const string & extrinsicState){
		cout<<"ConcreteFlyweight: 内 蕴 ["<<this->GetIntrinsicState()<<"] 外 蕴 ["<<extrinsicState<<"]"<<endl;
	}
};

class FlyweightFactory {
public:
	FlyweightFactory(){}
	~FlyweightFactory(){}
	Flyweight* GetFlyweight(const string& key){
		vector<Flyweight*>::iterator it =_fly.begin();
		for (; it != _fly.end();it++) {		
			if ((*it)->GetIntrinsicState() == key) {
				cout<<"already created by users...."<<endl;
				return *it;
			}
		}
		Flyweight* fn = new ConcreteFlyweight(key);
		_fly.push_back(fn);
		return fn;
	}

private:
	vector<Flyweight*> _fly;
};
#endif 