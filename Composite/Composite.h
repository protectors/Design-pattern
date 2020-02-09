#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_
#include <vector>
#include <iostream>
using namespace std;

class Component {
public:
	Component(){}
	virtual ~Component(){}

	virtual void Operation() = 0;
	virtual void Add(const Component& com){}
	virtual void Remove(const Component& com){}
	virtual Component* GetChild(int ){
		return 0;
	}
};

class Leaf:public Component {
public:
	Leaf(){}
	~Leaf(){}
	void Operation(){
		cout<<"Leaf operation.....\n";
	}
};


class Composite:public Component {
public:
	Composite(){}
	~Composite(){}

	void Operation(){
		vector<Component*>::iterator comIter = comVec.begin();
		for (;comIter != comVec.end();comIter++) {
			(*comIter)->Operation();
		}
	}
	void Add(Component* com){
		comVec.push_back(com); 
	}
	void Remove(Component* com){
		// comVec.erase(&com); 
	}
	Component* GetChild(int index){
		return comVec[index]; 
	}
private:
	vector<Component *> comVec;
};
#endif