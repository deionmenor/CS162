
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main( void )
{

 int input;

 cin >> input;


 int num1;
 int num2;
 string str;
 for(int i =1 ; i <= input; i++){


	 scanf("%i %i", &num1, &num2);
	 getline(cin, str);
	 printf( "Agent#%i is at (%i , %i )\nSays:" , i, num1, num2);
	 cout << str << endl;

 }
 return 0;


}
