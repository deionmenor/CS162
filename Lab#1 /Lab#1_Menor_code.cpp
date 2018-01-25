#include <iostream>
using namespace std;

// accepts a char pointer and replaces letter values with the next letter in the alphabet
void alphabetShifter( char* c ){
  char a = *c;
  if (isalpha(a)>0){
    if(a=='z'){
      *c= 'a';
    }
    else if(a=='Z'){
      *c= 'A';
    }
    else{
      a++;
      *c= a;
    }
  }
}


int main(void)
{
  string name;
  cout << "What's your name? ";
  cin >> name;
  cout << name << endl;

  string name2 = name;
  for(int i=1;i<name2.length();i++){
    name2[i]= '#';
  }
  cout << name2 << endl;

  string name3 = name;
  for(int i=0;i<name3.length();i++){
    alphabetShifter(&name3[i]);
  }
  cout << name3 << endl;
  return(0);
}
