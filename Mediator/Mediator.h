#ifndef _MEDIATOR_H_ 
#define _MEDIATOR_H_ 

#include <string>
#include <iostream>
using namespace std;
class Mediator;

class Colleage {
public:
	virtual ~Colleage(){}
	virtual void Aciton() = 0;
	virtual void SetState(const string& sdt) = 0;
	virtual string GetState() = 0; 
protected:
	Colleage(){}
	Colleage(Mediator* mdt){
		this->_mdt=mdt;
	}
	Mediator* _mdt;
};

class ConcreteColleageA:public Colleage{ 
public:
	ConcreteColleageA(){}
	ConcreteColleageA(Mediator* mdt):Colleage(mdt){}
	~ConcreteColleageA(){}
	void Aciton();
	void SetState(const string& sdt){
		_sdt=sdt;
	}
	string GetState(){
		return _sdt;
	}
private:
	string _sdt;
};

class ConcreteColleageB:public Colleage {
public: 
	ConcreteColleageB(){}
	ConcreteColleageB(Mediator* mdt):Colleage(mdt){}
	~ConcreteColleageB(){}
	void Aciton();
	void SetState(const string& sdt){
		_sdt=sdt;
	}
	string GetState(){
		return _sdt;
	}
private:
	string _sdt; 
};

class Mediator {
public:
	virtual ~Mediator(){}
	virtual void DoActionFromAtoB() = 0; 
	virtual void DoActionFromBtoA() = 0;
protected: 
	Mediator(){}
};

class ConcreteMediator:public Mediator {
public:
	ConcreteMediator(){}
	ConcreteMediator(Colleage* clgA,Colleage* clgB){
		this->_clgA=clgA;
		this->_clgB=clgB;
	}
	~ConcreteMediator(){}
	void SetConcreteColleageA(Colleage* clgA){
		this->_clgA = clgA;
	}
	void SetConcreteColleageB(Colleage* clgB){
		this->_clgB = clgB;
	}
	Colleage* GetConcreteColleageA(){
		return _clgA; 
	}
	Colleage* GetConcreteColleageB(){
		return _clgB; 
	}
	void IntroColleage(Colleage* clgA,Colleage* clgB){
		this->_clgA = clgA;
		this->_clgB = clgB;
	}
	void DoActionFromAtoB(){
		_clgB->SetState(_clgA->GetState()); 
	}
	void DoActionFromBtoA(){
		_clgA->SetState(_clgB->GetState());
	}
private:
	Colleage* _clgA;
	Colleage* _clgB;
};

void ConcreteColleageA::Aciton(){
	_mdt->DoActionFromAtoB();
	cout<<"State of ConcreteColleageA:"<<" "<<this->GetState()<<endl;
}

void ConcreteColleageB::Aciton(){
	_mdt->DoActionFromBtoA();
	cout<<"State of ConcreteColleageB:"<<" "<<this->GetState()<<endl;
}

#endif