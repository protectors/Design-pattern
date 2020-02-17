#ifndef _ITERATOR_H_ 
#define _ITERATOR_H_ 

#include <iostream>
using namespace std;

class Aggregate;
typedef int Object;
class Iterator
{
public:
	virtual ~Iterator(){}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
protected: 
	Iterator(){}
};

class ConcreteIterator:public Iterator {
public:
	ConcreteIterator(Aggregate* ag , int idx = 0){
		this->_ag = ag;
		this->_idx = idx;
	}
	~ConcreteIterator(){}
	void First(){
		_idx = 0;
	}
	void Next();
	bool IsDone();
	Object CurrentItem();
private:
	Aggregate* _ag;
	int _idx; 
};


class Aggregate
{
public:
	virtual ~Aggregate(){}
	virtual Iterator* CreateIterator() = 0; 
	virtual Object GetItem(int idx) = 0; 
	virtual int GetSize() = 0;
protected: 
	Aggregate(){}
};

class ConcreteAggregate:public Aggregate {
public:
	enum {SIZE = 3}; 
	ConcreteAggregate(){
		for (int i = 0; i < SIZE; i++) 
			_objs[i] = i;
	}
	~ConcreteAggregate(){} 
	Iterator* CreateIterator(){
		return new ConcreteIterator(this);
	}
	Object GetItem(int idx){
		if (idx < this->GetSize()) 
			return _objs[idx];
		else
			return -1;
	}
	int GetSize(){
		return SIZE;
	}
private:
	Object _objs[SIZE]; 
};


void ConcreteIterator::Next() {
if (_idx < _ag->GetSize()) 
	_idx++;
}

bool ConcreteIterator::IsDone() {
	return (_idx == _ag->GetSize()); 
}

Object ConcreteIterator::CurrentItem() {
	return _ag->GetItem(_idx); 
}
#endif