#include <iostream>
#include <unistd.h> // some Unix stuff
using namespace std;


int main(int argc, char* argv[]) {
// just use execv to run ANY program
if(execv( "/usr/bin/gedit"
, argv ) == -1) {
// error
cout << "Error. Booooo!" << endl;
}
cout << "Will this line still be printed?"
<< endl;
}
