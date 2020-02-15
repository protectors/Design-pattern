#ifndef _COMMAND_H_ 
#define _COMMAND_H_
#include <iostream>
using namespace std;
class Reciever{
public:
	Reciever(){}
	~Reciever(){} 
	void Action(){
		 std::cout<<"Reciever action......."<<std::endl;
	}
};

class Command {
public:
	virtual ~Command(){}
	virtual void Excute() = 0;
protected: 
	Command(){}
};

class Invoker {
public:
	Invoker(Command* cmd){
		_cmd=cmd;
	}
	~Invoker(){}
	void Invoke(){}
private:
	Command* _cmd;
};

class ConcreteCommand:public Command {
public:
	ConcreteCommand(Reciever* rev){
		_rev=rev;
	}
	~ConcreteCommand(){}
	void Excute(){}
private:
	Reciever* _rev;
};

template <class Reciever>
class SimpleCommand:public Command {
public:
	typedef void (Reciever::* Action)(); 
	SimpleCommand(Reciever* rev,Action act){
		_rev = rev;
		_act = act; 
	}
	virtual void Excute() {
		(_rev->* _act)(); 
	}
	~SimpleCommand() {
		delete _rev; 
	}
private:
	Reciever* _rev;
	Action _act; 
};
#endif 