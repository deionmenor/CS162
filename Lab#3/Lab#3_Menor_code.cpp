// #include "Point3D.hpp"
#include <iostream>
#include <cstddef>
#include "Lab#3_Menor_node.hpp"
#include "Lab#3_Menor_IntStack.hpp"
using namespace std;


int main( void ) {

  //
  IntStack* stack = new IntStack();
  stack->push(5);
  stack->push(10);
  stack->push(18);
  stack->push(12);
  stack->pop();
  stack->pop();
  stack->pop();
  stack->pop();
  stack->push(4);
  stack->push(55);
  stack->push(110293);
  stack->pop();
  stack->pop();
  stack->pop();
  stack->pop();
  stack->pop();

}
