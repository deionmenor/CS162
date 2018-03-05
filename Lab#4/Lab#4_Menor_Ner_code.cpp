#include <iostream>
using namespace std;


int mul_19( int c ){

  int a = c;
  int b = c;

  a = a << 3;
  a = a + b;
  a = a + a;
  a = a + b;

  return a;
}

// ASSEMBLY CODE
//movl	-20(%rbp), %edx
//movl	%edx, %eax // x x
//sall	$3, %eax		// 8x x
//addl	%edx, %eax  // 9x x
//addl	%eax, %eax  // 18x x
//addl	%edx, %eax // 19x x

int mul_0( int c ){
  return 0;
}
// ASSEMBLY CODE
// movl	$0, -4(%rbp)
// movl	-4(%rbp), %eax

int mul_neg_2(int c){
  int a = c;
  int b = 0;
  a = b-a;
  a = a + a;
  return a;
}
//ASEEMBLY CODE
//movl	-20(%rbp), %edx // x
//movl	$0, %eax				// x 0
//subl	%edx, %eax  		// x -x
//addl	%eax, %eax  		// x -2x





int main(void){

  int x;
  std::cin >> x;
  std::cout << x <<"*19 = "<< mul_19(x) << '\n';
  std::cout << x <<"*-2 = "<< mul_neg_2(x) << '\n';
  std::cout << x <<"*0 = "<< mul_0(x) << '\n';
}
