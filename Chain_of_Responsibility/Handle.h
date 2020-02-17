#ifndef _HANDLE_H_ 
#define _HANDLE_H_ 

#include <iostream>
using namespace std;

class Handle{
public:
	virtual ~Handle(){
		delete _succ;
	}
	virtual void HandleRequest() = 0; 
	void SetSuccessor(Handle* succ){
		_succ = succ;
	}
	Handle* GetSuccessor(){
		return _succ;
	}
protected: 
	Handle(){
		_succ=0;
	}
	Handle(Handle* succ){
		this->_succ = succ;
	}
private:
	Handle* _succ; 
};

class ConcreteHandleA:public Handle {
public:
	ConcreteHandleA(){}
	~ConcreteHandleA(){}
	ConcreteHandleA(Handle* succ):Handle(succ){}
	void HandleRequest(){
		if (this->GetSuccessor() != 0) {
			cout<<"ConcreteHandleA 我把处理权给后继节点....."<<endl;
			this->GetSuccessor()->HandleRequest(); 
		}
		else{
			cout<<"ConcreteHandleA 没有后继了，我必须自己处理...."<<endl;
		}
	}
};

class ConcreteHandleB:public Handle {
public: 
	ConcreteHandleB(){}
	~ConcreteHandleB(){}
	ConcreteHandleB(Handle* succ):Handle(succ){}
	void HandleRequest(){
		if (this->GetSuccessor() != 0) {
			cout<<"ConcreteHandleB 我把处理权给后继节点....."<<endl;
			this->GetSuccessor()->HandleRequest(); 
		}
		else{
			cout<<"ConcreteHandleB 没有后继了，我必须自己处理...."<<endl;
		}
	}
};
#endif 