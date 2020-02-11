#ifndef _PROXY_H_ 
#define _PROXY_H_ 
#include <iostream>
using namespace std;
class Subject
{
public:
	virtual ~Subject(){}
	virtual void Request() = 0; 
protected:
	Subject(){}
};
class ConcreteSubject:public Subject {
public:
	ConcreteSubject(){}
	~ConcreteSubject(){} 
	void Request(){
		cout<<"ConcreteSubject......request...."<< endl;
	}
};

class Proxy {
	public: Proxy(){}
	Proxy(Subject* sub){
		_sub=sub;
	}
	~Proxy(){
		delete _sub;
	}
	void Request(){
		cout<<"Proxy request...."<<endl;
		_sub->Request();
	}
private:
	Subject* _sub; 
};
#endif 