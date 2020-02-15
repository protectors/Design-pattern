#include "Command.h" 
#include <iostream>
using namespace std;
int main() {
	Reciever* rev = new Reciever();
	Command* cmd = new SimpleCommand<Reciever>(rev,&Reciever::Action);
	cmd->Excute();
	Command* cmd2 = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(cmd2); 
	inv->Invoke();
	return 0; 
}