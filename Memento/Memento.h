#ifndef _MEMENTO_H_ 
#define _MEMENTO_H_ 
#include <string>
#include <iostream>
using namespace std; 
class Memento;

class Originator{
public:
	typedef string State; 
	Originator(){
		_sdt="";
		_mt=0;
	}
	Originator(const State& sdt){
		_sdt=sdt;
		_mt=0;
	}
	~Originator(){}
	Memento* CreateMemento();
	void SetMemento(Memento* men){}
	void RestoreToMemento(Memento* mt);
	State GetState(){
		return _sdt;
	}
	void SetState(const State& sdt){
		_sdt=sdt;
	}
	void PrintState(){
		cout<<this->_sdt<<"....."<<endl;
	}
private:
	State _sdt;
	Memento* _mt; 
};

class Memento {
private:
	//这是最关键的地方，将 Originator 为 friend类，可以访问内部信息，但是其他类不能访问
	friend class Originator; 
	typedef string State; 
	Memento(){}
	Memento(const State& sdt){
		_sdt=sdt;
	} 
	~Memento(){}
	void SetState(const State& sdt){
		_sdt=sdt;
	}
	State GetState(){
		return _sdt;
	}
private:
	State _sdt; 
};

void Originator::RestoreToMemento(Memento* mt){
	this->_sdt=mt->GetState();
}
Memento* Originator::CreateMemento(){
	return new Memento(_sdt);
}
#endif 