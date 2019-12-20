#include "Singleton.hpp"
#include <iostream>
using namespace std;

int main(){
    Singleton* sgn=Singleton::Instance();
    Singleton* sgn2=Singleton::Instance();
    return 0;
}