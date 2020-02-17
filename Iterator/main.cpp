#include "Iterator.h"
#include <iostream> 
using namespace std;
int main() {
	Aggregate* ag = new ConcreteAggregate();
	Iterator* it = new ConcreteIterator(ag);
	for (; !(it->IsDone()) ; it->Next()) {
		cout<<it->CurrentItem()<<endl; 
	}
	return 0; 
}