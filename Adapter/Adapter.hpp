#ifndef _ADAPTER_H_
#define _ADAPTER_H_
#include <iostream>

class Target{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request(){
		std::cout<<"Target::Request"<<std::endl;
	}
};

class Adaptee{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecificRequest(){
		std::cout<<"Adaptee::SpecificRequest"<<std::endl;
	}
};

class Adapter:public Target{
public:
	Adapter(Adaptee* ade){
		this->_ade=ade;
	}
	~Adapter(){}
	void Request(){
		_ade->SpecificRequest();
	}
private:
	Adaptee* _ade;
};

#endif