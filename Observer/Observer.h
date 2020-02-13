#ifndef _SUBJECT_H_ 
#define _SUBJECT_H_ 
#include <list> 
#include <string>
#include <iostream>
using namespace std; 
typedef string State; 

class Observer;
class Subject{
public:
	virtual ~Subject(){}
	virtual void Attach(Observer* obv){
		_obvs->push_front(obv);
	}
	virtual void Detach(Observer* obv){
		if (obv != NULL) 
			_obvs->remove(obv);
	}
	virtual void Notify();
	virtual void SetState(const State& st) = 0; 
	virtual State GetState() = 0;
protected: 
	Subject(){
		_obvs = new list<Observer*>;
	}
private:
	list<Observer* >* _obvs;
};

class ConcreteSubject:public Subject {
public:
	ConcreteSubject(){
		_st='\0';
	}
	~ConcreteSubject(){}
	State GetState(){
		return _st;
	}
	void SetState(const State& st){
		_st=st;
	}
private:
	State _st; 
};


class Observer
{
public:
	virtual ~Observer(){}
	virtual void Update(Subject* sub) = 0; 
	virtual void PrintInfo() = 0;
protected: 
	Observer(){
		_st='\0';
	}
	State _st;
};

class ConcreteObserverA:public Observer {
public:
	virtual Subject* GetSubject(){
		return _sub;
	}
	ConcreteObserverA(Subject* sub){
		_sub=sub;
		_sub->Attach(this);
	}
	virtual ~ConcreteObserverA(){
		_sub->Detach(this); 
		if (_sub != 0)
			delete _sub;
	}
	//传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
	void Update(Subject* sub){
		_st = sub->GetState();
		PrintInfo();
	}
	void PrintInfo(){
		cout<<"ConcreteObserverA oberserver..."<<_sub->GetState()<<endl;
	}
private:
	Subject* _sub;
};

class ConcreteObserverB:public Observer {
public:
	virtual Subject* GetSubject(){
		return _sub;
	} 
	ConcreteObserverB(Subject* sub){
		_sub = sub;
		_sub->Attach(this);
	} 
	virtual ~ConcreteObserverB(){
		_sub->Detach(this); 
		if (_sub != 0){
			delete _sub;
		}
	}
//传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
	void Update(Subject* sub){
		_st = sub->GetState();
		PrintInfo();
	}
	void PrintInfo(){
		cout<<"ConcreteObserverB oberserver..."<<_sub->GetState()<<endl;
	}
private:
	Subject* _sub;
};


void Subject::Notify(){
	list<Observer*>::iterator it;
	it = _obvs->begin();
	for (;it != _obvs->end();it++){
	 	//关于模板和 iterator 的用法
		(*it)->Update(this); 
	}
}
#endif 