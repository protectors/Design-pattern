#include <iostream>
#include "Strategy.h"
using namespace std;
int main(){
	Strategy* ps;
	ps = new ConcreteStrategyA();
	Context* pc = new Context(ps);
	pc->DoAction();
	if(NULL!=pc)
		delete pc;
	return 0;
}