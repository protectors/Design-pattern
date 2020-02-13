#ifndef _STATE_H_ 
#define _STATE_H_ 
#include <iostream>
using namespace std;

class Context;

class State
{
public:
	State(){}
	virtual ~State(){}
	virtual void OperationInterface(Context* con)=0;
	virtual void OperationChangeState(Context*) = 0; 

protected:
	bool ChangeState(Context* con,State* st);
private:
	//bool ChangeState(Context* con,State* st); 
};


class ConcreteStateA:public State {
public:
	ConcreteStateA(){}
	virtual ~ConcreteStateA(){}
	virtual void OperationInterface(Context* ){
		cout<<"ConcreteStateA::OperationInterface......"<<endl;
	}
	virtual void OperationChangeState(Context* con);
};

class ConcreteStateB:public State {
public:
ConcreteStateB(){}
	virtual ~ConcreteStateB(){}
	virtual void OperationInterface(Context* ){
		cout<<"ConcreteStateB::OperationInterface......"<<endl;
	}
	virtual void OperationChangeState(Context*);
};


class Context{
public:
	Context(){}
	Context(State* state){
		this->_state=state;
	}
	~Context(){
		delete _state;
	}
	void OperationInterface(){
		_state->OperationInterface(this);
	}
	void OperationChangState(){
		_state->OperationChangeState(this);
	}
private:
	friend class State; //表明在State类中可以访问 Context 类的 private 字段
	bool ChangeState(State* state){
		this->_state = state;
		return true;
	}
private:
	State* _state; 
};


void State::OperationInterface(Context* con) {
	cout<<"State::.."<<endl; 
}

bool State::ChangeState(Context* con,State* st) {
	con->ChangeState(st);
	return true; 
}

void ConcreteStateA::OperationChangeState(Context* con){
	OperationInterface(con);
	this->ChangeState(con,new ConcreteStateB());
}
void ConcreteStateB::OperationChangeState(Context* con){
	OperationInterface(con);
	this->ChangeState(con,new ConcreteStateA());
}
#endif